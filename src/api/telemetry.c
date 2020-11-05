#include "telemetry.h"
#include "vospi.h"

telemetry_data_t parse_telemetry_packet(vospi_packet_t* packet)
{
  //uint32_t reordered_status_bits = LEPTON_DWORD(packet->symbols, 6);

  // Decode the status bits first
  // telemetry_data_status_bits_t status_bits = {
  //   .ffc_desired = (reordered_status_bits & 0x08) >> 3,
  //   .ffc_state = (reordered_status_bits & 0x30) >> 4,
  //   .agc_state = (reordered_status_bits & 0x1000) >> 12,
  //   .shutter_lockout = (reordered_status_bits & 0x4000) >> 15,
  //   .overtemp_shutdown_imminent = (reordered_status_bits & 0x100000) >> 20
  // };

  telemetry_data_t telemetry_data = {

    //A Register
    // .revision = LEPTON_WORD(packet->symbols, 0),
    // .msec_since_boot = LEPTON_DWORD(packet->symbols, 2),
    // .status_bits = status_bits,
    // .frame_count = LEPTON_DWORD(packet->symbols, 40),
    // .frame_mean = LEPTON_WORD(packet->symbols, 44),
    // .fpa_temp_count = LEPTON_WORD(packet->symbols, 46),
    // .fpa_temp_kelvin_100 = LEPTON_WORD(packet->symbols, 48),
    // .fpa_temp_last_ffc_kelvin_100 = LEPTON_WORD(packet->symbols, 58),
    // .msec_last_ffc = LEPTON_DWORD(packet->symbols, 60),
    // .agc_roi_top = LEPTON_WORD(packet->symbols, 68),
    // .agc_roi_left = LEPTON_WORD(packet->symbols, 70),
    // .agc_roi_bottom = LEPTON_WORD(packet->symbols, 72),
    // .agc_roi_right = LEPTON_WORD(packet->symbols, 74),
    // .agc_clip_limit_high = LEPTON_WORD(packet->symbols, 76),
    // .agc_clip_limit_low = LEPTON_WORD(packet->symbols, 78),
    // .video_output_format = LEPTON_DWORD(packet->symbols, 144)

    //B Register
    // .background_temp = LEPTON_WORD(packet->symbols,20)

    //C Register
    // .tlinear_resolution = LEPTON_WORD(packet->symbols,98),
    // .spotmeter_mean_temp = LEPTON_WORD(packet->symbols,100),
    // .spotmeter_max_temp = LEPTON_WORD(packet->symbols,102),
    // .spotmeter_min_temp = LEPTON_WORD(packet->symbols,104),
    .spotmeter_population = LEPTON_WORD(packet->symbols,53)
    // .spotmeter_start_row = LEPTON_WORD(packet->symbols,108),
    // .spotmeter_start_col = LEPTON_WORD(packet->symbols,110),
    // .spotmeter_end_row = LEPTON_WORD(packet->symbols,112),
    // .spotmeter_end_col = LEPTON_WORD(packet->symbols,114)

//     .variable0 = LEPTON_WORD(packet->symbols,0),
// .variable1 = LEPTON_WORD(packet->symbols,1),
// .variable2 = LEPTON_WORD(packet->symbols,2),
// .variable3 = LEPTON_WORD(packet->symbols,3),
// .variable4 = LEPTON_WORD(packet->symbols,4),
// .variable5 = LEPTON_WORD(packet->symbols,5),
// .variable6 = LEPTON_WORD(packet->symbols,6),
// .variable7 = LEPTON_WORD(packet->symbols,7),
// .variable8 = LEPTON_WORD(packet->symbols,8),
// .variable9 = LEPTON_WORD(packet->symbols,9),
// .variable10 = LEPTON_WORD(packet->symbols,10),
// .variable11 = LEPTON_WORD(packet->symbols,11),
// .variable12 = LEPTON_WORD(packet->symbols,12),
// .variable13 = LEPTON_WORD(packet->symbols,13),
// .variable14 = LEPTON_WORD(packet->symbols,14),
// .variable15 = LEPTON_WORD(packet->symbols,15),
// .variable16 = LEPTON_WORD(packet->symbols,16),
// .variable17 = LEPTON_WORD(packet->symbols,17),
// .variable18 = LEPTON_WORD(packet->symbols,18),
// .variable19 = LEPTON_WORD(packet->symbols,19),
// .variable20 = LEPTON_WORD(packet->symbols,20),
// .variable21 = LEPTON_WORD(packet->symbols,21),
// .variable22 = LEPTON_WORD(packet->symbols,22),
// .variable23 = LEPTON_WORD(packet->symbols,23),
// .variable24 = LEPTON_WORD(packet->symbols,24),
// .variable25 = LEPTON_WORD(packet->symbols,25),
// .variable26 = LEPTON_WORD(packet->symbols,26),
// .variable27 = LEPTON_WORD(packet->symbols,27),
// .variable28 = LEPTON_WORD(packet->symbols,28),
// .variable29 = LEPTON_WORD(packet->symbols,29),
// .variable30 = LEPTON_WORD(packet->symbols,30),
// .variable31 = LEPTON_WORD(packet->symbols,31),
// .variable32 = LEPTON_WORD(packet->symbols,32),
// .variable33 = LEPTON_WORD(packet->symbols,33),
// .variable34 = LEPTON_WORD(packet->symbols,34),
// .variable35 = LEPTON_WORD(packet->symbols,35),
// .variable36 = LEPTON_WORD(packet->symbols,36),
// .variable37 = LEPTON_WORD(packet->symbols,37),
// .variable38 = LEPTON_WORD(packet->symbols,38),
// .variable39 = LEPTON_WORD(packet->symbols,39),
// .variable40 = LEPTON_WORD(packet->symbols,40),
// .variable41 = LEPTON_WORD(packet->symbols,41),
// .variable42 = LEPTON_WORD(packet->symbols,42),
// .variable43 = LEPTON_WORD(packet->symbols,43),
// .variable44 = LEPTON_WORD(packet->symbols,44),
// .variable45 = LEPTON_WORD(packet->symbols,45),
// .variable46 = LEPTON_WORD(packet->symbols,46),
// .variable47 = LEPTON_WORD(packet->symbols,47),
// .variable48 = LEPTON_WORD(packet->symbols,48),
// .variable49 = LEPTON_WORD(packet->symbols,49),
// .variable50 = LEPTON_WORD(packet->symbols,50),
// .variable51 = LEPTON_WORD(packet->symbols,51),
// .variable52 = LEPTON_WORD(packet->symbols,52),
// .variable53 = LEPTON_WORD(packet->symbols,53),
// .variable54 = LEPTON_WORD(packet->symbols,54),
// .variable55 = LEPTON_WORD(packet->symbols,55),
// .variable56 = LEPTON_WORD(packet->symbols,56),
// .variable57 = LEPTON_WORD(packet->symbols,57),
// .variable58 = LEPTON_WORD(packet->symbols,58),
// .variable59 = LEPTON_WORD(packet->symbols,59),

  };

  return telemetry_data;
}
