/*
ELEKTRON © 2022
Written by melektron
www.elektron.work
18.04.23, 15:39

tetris notes
*/

#pragma once

#include <stdint.h>

namespace tetris
{
    // Melody
    extern uint16_t treble_melody[64];

    extern uint16_t bass_melody[64];

    // note durations: 4 = quarter note, 8 = eighth note, etc
    extern uint8_t treble_durations[64];

    extern uint8_t bass_durations[64];
}