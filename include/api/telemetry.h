#ifndef TELEMETRY_H
#define TELEMETRY_H
#include "vospi.h"
#include <stdint.h>

#define LEPTON_WORD(buf, i) buf[i] << 8 | buf[i + 1]
#define LEPTON_DWORD(buf, i) LEPTON_WORD(buf, i + 2) << 16 | LEPTON_WORD(buf,i)
#define LEPTON_QWORD(buf, i) LEPTON_DWORD(buf, i + 4) << 32 | LEPTON_DWORD(buf,i)

/** Telemetry Data Status Bits field **/
// typedef struct {
//   uint8_t ffc_desired;
//   uint8_t ffc_state;
//   uint8_t agc_state;
//   uint8_t reserved_2;
//   uint8_t shutter_lockout;
//   uint8_t reserved_3;
//   uint8_t overtemp_shutdown_imminent;
//   uint16_t reserved_4;
// } telemetry_data_status_bits_t;

/* Telemetry Data Content (see pg. 23 of the Lepton3 LWIR Datasheet) */
/* Only covers Telemetry Row A, as there's nothing interesting in B... */
typedef struct {
  //A Register Values

  // uint16_t revision;
  // uint32_t msec_since_boot;
  // telemetry_data_status_bits_t status_bits;
  // uint64_t software_rev;
  // uint32_t frame_count;
  // uint16_t frame_mean;
  // uint16_t fpa_temp_count;
  // uint16_t fpa_temp_kelvin_100;
  // uint16_t fpa_temp_last_ffc_kelvin_100;
  // uint32_t msec_last_ffc;
  // uint16_t agc_roi_top;
  // uint16_t agc_roi_left;
  // uint16_t agc_roi_bottom;
  // uint16_t agc_roi_right;
  // uint16_t agc_clip_limit_high;
  // uint16_t agc_clip_limit_low;
  // uint32_t video_output_format;

  //B Register Values
  // uint16_t background_temp;

  //C Register Values
  // uint16_t gain_mode;
  // uint16_t effective_gain;
  // uint16_t temp_gain_mode_high_to_low;


  // uint16_t tlinear_resolution;
  // uint16_t spotmeter_mean_temp;
  // uint16_t spotmeter_max_temp;
  // uint16_t spotmeter_min_temp;
  // uint16_t spotmeter_population;
  // uint16_t spotmeter_start_row;
  // uint16_t spotmeter_start_col;
  // uint16_t spotmeter_end_row;
  // uint16_t spotmeter_end_col;


uint16_t A
uint16_t B
uint16_t C
uint16_t D
uint16_t E
uint16_t F
uint16_t G
uint16_t H
uint16_t I
uint16_t J
uint16_t K
uint16_t L
uint16_t M
uint16_t N
uint16_t O
uint16_t P
uint16_t Q
uint16_t R
uint16_t S
uint16_t T
uint16_t U
uint16_t V
uint16_t W
uint16_t X
uint16_t Y
uint16_t Z
uint16_t a
uint16_t b
uint16_t c
uint16_t d
uint16_t e
uint16_t f
uint16_t g
uint16_t h
uint16_t i
uint16_t j
uint16_t k
uint16_t l
uint16_t m
uint16_t n
uint16_t o
uint16_t p
uint16_t q
uint16_t r
uint16_t s
uint16_t t
uint16_t u
uint16_t v
uint16_t w
uint16_t x
uint16_t y
uint16_t z






} telemetry_data_t;

telemetry_data_t parse_telemetry_packet(vospi_packet_t* packet);

#endif
