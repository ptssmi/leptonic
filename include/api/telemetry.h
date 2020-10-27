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
uint16_t {
uint16_t |
uint16_t }
uint16_t ~
uint16_t 
uint16_t 
uint16_t 
uint16_t 
uint16_t 
uint16_t 
uint16_t 
uint16_t 
uint16_t 
uint16_t 
uint16_t 
uint16_t 
uint16_t 
uint16_t 
uint16_t 
uint16_t 
uint16_t 
uint16_t 
uint16_t 
uint16_t 
uint16_t 
uint16_t 
uint16_t 
uint16_t 
uint16_t 
uint16_t 
uint16_t 
uint16_t 
uint16_t 
uint16_t 
uint16_t 
uint16_t 
uint16_t 
uint16_t  
uint16_t ¡
uint16_t ¢
uint16_t £
uint16_t ¤
uint16_t ¥
uint16_t ¦
uint16_t §
uint16_t ¨
uint16_t ©
uint16_t ª
uint16_t «
uint16_t ¬
uint16_t ­
uint16_t ®
uint16_t ¯
uint16_t °
uint16_t ±
uint16_t ²
uint16_t ³
uint16_t ´
uint16_t µ
uint16_t ¶
uint16_t ·
uint16_t ¸
uint16_t ¹
uint16_t º
uint16_t »
uint16_t ¼
uint16_t ½
uint16_t ¾
uint16_t ¿
uint16_t À
uint16_t Á
uint16_t Â
uint16_t Ã
uint16_t Ä
uint16_t Å
uint16_t Æ
uint16_t Ç
uint16_t È
uint16_t É
uint16_t Ê
uint16_t Ë
uint16_t Ì
uint16_t Í
uint16_t Î
uint16_t Ï
uint16_t Ð
uint16_t Ñ
uint16_t Ò
uint16_t Ó
uint16_t Ô
uint16_t Õ
uint16_t Ö
uint16_t ×
uint16_t Ø
uint16_t Ù
uint16_t Ú
uint16_t Û
uint16_t Ü
uint16_t Ý
uint16_t Þ
uint16_t ß
uint16_t à
uint16_t á
uint16_t â
uint16_t ã
uint16_t ä
uint16_t å
uint16_t æ
uint16_t ç
uint16_t è
uint16_t é
uint16_t ê
uint16_t ë
uint16_t ì
uint16_t í
uint16_t î
uint16_t ï
uint16_t ð
uint16_t ñ
uint16_t ò
uint16_t ó
uint16_t ô
uint16_t õ
uint16_t ö
uint16_t ÷
uint16_t ø
uint16_t ù
uint16_t ú
uint16_t û
uint16_t ü
uint16_t ý
uint16_t þ
uint16_t ÿ
uint16_t Ā
uint16_t ā
uint16_t Ă
uint16_t ă
uint16_t Ą
uint16_t ą
uint16_t Ć
uint16_t ć
uint16_t Ĉ
uint16_t ĉ
uint16_t Ċ
uint16_t ċ
uint16_t Č
uint16_t č
uint16_t Ď
uint16_t ď
uint16_t Đ
uint16_t đ
uint16_t Ē
uint16_t ē
uint16_t Ĕ






} telemetry_data_t;

telemetry_data_t parse_telemetry_packet(vospi_packet_t* packet);

#endif
