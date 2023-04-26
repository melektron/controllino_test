/*
ELEKTRON © 2022
Written by melektron
www.elektron.work
18.04.23, 15:44
*/

#include <stdint.h>
#include <Controllino.h>
#include "relay_player.hpp"
#include "tetris.hpp"

#define FIRST_OUTPUT CONTROLLINO_R0
#define NR_OUTPUTS 10

static bool running = false;
static int current_note = 0;

static int current_note_duration_ms;
static int current_periode_us = 0;
static uint64_t last_note_time_ms = 0;
static uint64_t last_click_us = 0;

static int rstage = 0;
static const int fullnotetime_ms = 2000;

static size_t track_len = 64;
static uint16_t *ptrack_melody = nullptr;
static uint8_t *ptrack_durations = nullptr;


void relay_player::init()
{
    for (int i = 0; i < NR_OUTPUTS; i++)
    {
        pinMode(FIRST_OUTPUT + 1, OUTPUT);
    }
}

static void click()
{
    static bool val = 0;
    digitalWrite(FIRST_OUTPUT, val = !val);
    return;
    if (rstage < NR_OUTPUTS)
    {
        digitalWrite(FIRST_OUTPUT + NR_OUTPUTS, 1);
    }
    else
    {
        digitalWrite(FIRST_OUTPUT + (rstage % NR_OUTPUTS), 0);
    }
    rstage++;
    if (rstage >= 2 * NR_OUTPUTS) rstage = 0;
}

static void loadNote(int _index)
{
    current_note_duration_ms = fullnotetime_ms / ptrack_durations[_index]; 
    current_periode_us = 1e6 / ptrack_melody[_index];

    last_note_time_ms = millis();
    last_click_us = micros();
}

void relay_player::start_tetris()
{
    ptrack_melody = tetris::treble_melody;
    ptrack_durations = tetris::treble_durations;

    current_note = 0;
    running = true;

    loadNote(0);
}

void relay_player::run()
{
    if (!running) return;

    if (last_note_time_ms + current_note_duration_ms < millis())
    {
        loadNote(++current_note);
        if (current_note >= track_len)
            current_note = 0;
    }

    auto cus = micros();
    if (last_click_us + current_periode_us < micros())
    {
        click();
        last_click_us = cus;
    }

}