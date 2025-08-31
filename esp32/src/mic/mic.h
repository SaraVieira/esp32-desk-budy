#ifndef MIC_H
#define MIC_H

#include <lvgl.h>

// Microphone configuration constants
extern const int sampleWindow; // Sample window width in mS (50 mS = 20Hz)
extern const int AMP_PIN;      // Preamp output pin connected to analog input
extern unsigned int sample;    // Current sample value

/**
 * @brief Read microphone input and display loud warning if threshold exceeded
 *
 * This function samples the microphone for a specified time window,
 * calculates the peak-to-peak amplitude, and displays a "Loud!!!" warning
 * overlay if the sound level exceeds the threshold (3500).
 *
 * The warning overlay persists until the sound level drops below the threshold.
 */
void read_mic();

#endif // MIC_H
