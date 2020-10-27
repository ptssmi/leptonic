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


  uint16_t variable0;
uint16_t variable1;
uint16_t variable2;
uint16_t variable3;
uint16_t variable4;
uint16_t variable5;
uint16_t variable6;
uint16_t variable7;
uint16_t variable8;
uint16_t variable9;
uint16_t variable10;
uint16_t variable11;
uint16_t variable12;
uint16_t variable13;
uint16_t variable14;
uint16_t variable15;
uint16_t variable16;
uint16_t variable17;
uint16_t variable18;
uint16_t variable19;
uint16_t variable20;
uint16_t variable21;
uint16_t variable22;
uint16_t variable23;
uint16_t variable24;
uint16_t variable25;
uint16_t variable26;
uint16_t variable27;
uint16_t variable28;
uint16_t variable29;
uint16_t variable30;
uint16_t variable31;
uint16_t variable32;
uint16_t variable33;
uint16_t variable34;
uint16_t variable35;
uint16_t variable36;
uint16_t variable37;
uint16_t variable38;
uint16_t variable39;
uint16_t variable40;
uint16_t variable41;
uint16_t variable42;
uint16_t variable43;
uint16_t variable44;
uint16_t variable45;
uint16_t variable46;
uint16_t variable47;
uint16_t variable48;
uint16_t variable49;
uint16_t variable50;
uint16_t variable51;
uint16_t variable52;
uint16_t variable53;
uint16_t variable54;
uint16_t variable55;
uint16_t variable56;
uint16_t variable57;
uint16_t variable58;
uint16_t variable59;
uint16_t variable60;
uint16_t variable61;
uint16_t variable62;
uint16_t variable63;
uint16_t variable64;
uint16_t variable65;
uint16_t variable66;
uint16_t variable67;
uint16_t variable68;
uint16_t variable69;
uint16_t variable70;
uint16_t variable71;
uint16_t variable72;
uint16_t variable73;
uint16_t variable74;
uint16_t variable75;
uint16_t variable76;
uint16_t variable77;
uint16_t variable78;
uint16_t variable79;
uint16_t variable80;
uint16_t variable81;
uint16_t variable82;
uint16_t variable83;
uint16_t variable84;
uint16_t variable85;
uint16_t variable86;
uint16_t variable87;
uint16_t variable88;
uint16_t variable89;
uint16_t variable90;
uint16_t variable91;
uint16_t variable92;
uint16_t variable93;
uint16_t variable94;
uint16_t variable95;
uint16_t variable96;
uint16_t variable97;
uint16_t variable98;
uint16_t variable99;
uint16_t variable100;
uint16_t variable101;
uint16_t variable102;
uint16_t variable103;
uint16_t variable104;
uint16_t variable105;
uint16_t variable106;
uint16_t variable107;
uint16_t variable108;
uint16_t variable109;
uint16_t variable110;
uint16_t variable111;
uint16_t variable112;
uint16_t variable113;
uint16_t variable114;
uint16_t variable115;
uint16_t variable116;
uint16_t variable117;
uint16_t variable118;
uint16_t variable119;
uint16_t variable120;
uint16_t variable121;
uint16_t variable122;
uint16_t variable123;
uint16_t variable124;
uint16_t variable125;
uint16_t variable126;
uint16_t variable127;
uint16_t variable128;
uint16_t variable129;
uint16_t variable130;
uint16_t variable131;
uint16_t variable132;
uint16_t variable133;
uint16_t variable134;
uint16_t variable135;
uint16_t variable136;
uint16_t variable137;
uint16_t variable138;
uint16_t variable139;
uint16_t variable140;
uint16_t variable141;
uint16_t variable142;
uint16_t variable143;
uint16_t variable144;
uint16_t variable145;
uint16_t variable146;
uint16_t variable147;
uint16_t variable148;
uint16_t variable149;
uint16_t variable150;
uint16_t variable151;
uint16_t variable152;
uint16_t variable153;
uint16_t variable154;
uint16_t variable155;
uint16_t variable156;
uint16_t variable157;
uint16_t variable158;
uint16_t variable159;
uint16_t variable160;
uint16_t variable161;
uint16_t variable162;
uint16_t variable163;
uint16_t variable164;
uint16_t variable165;
uint16_t variable166;
uint16_t variable167;
uint16_t variable168;
uint16_t variable169;
uint16_t variable170;
uint16_t variable171;
uint16_t variable172;
uint16_t variable173;
uint16_t variable174;
uint16_t variable175;
uint16_t variable176;
uint16_t variable177;
uint16_t variable178;
uint16_t variable179;





} telemetry_data_t;

telemetry_data_t parse_telemetry_packet(vospi_packet_t* packet);

#endif
