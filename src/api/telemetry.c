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
    // .spotmeter_population = LEPTON_WORD(packet->symbols,106),
    //.spotmeter_start_row = LEPTON_WORD(packet->symbols,54),
    // .spotmeter_start_col = LEPTON_WORD(packet->symbols,110),
    // .spotmeter_end_row = LEPTON_WORD(packet->symbols,112),
    // .spotmeter_end_col = LEPTON_WORD(packet->symbols,114)

.pixel0 = LEPTON_WORD(packet->symbols,0),
.pixel2 = LEPTON_WORD(packet->symbols,2),
.pixel4 = LEPTON_WORD(packet->symbols,4),
.pixel6 = LEPTON_WORD(packet->symbols,6),
.pixel8 = LEPTON_WORD(packet->symbols,8),
.pixel10 = LEPTON_WORD(packet->symbols,10),
.pixel12 = LEPTON_WORD(packet->symbols,12),
.pixel14 = LEPTON_WORD(packet->symbols,14),
.pixel16 = LEPTON_WORD(packet->symbols,16),
.pixel18 = LEPTON_WORD(packet->symbols,18),
.pixel20 = LEPTON_WORD(packet->symbols,20),
.pixel22 = LEPTON_WORD(packet->symbols,22),
.pixel24 = LEPTON_WORD(packet->symbols,24),
.pixel26 = LEPTON_WORD(packet->symbols,26),
.pixel28 = LEPTON_WORD(packet->symbols,28),
.pixel30 = LEPTON_WORD(packet->symbols,30),
.pixel32 = LEPTON_WORD(packet->symbols,32),
.pixel34 = LEPTON_WORD(packet->symbols,34),
.pixel36 = LEPTON_WORD(packet->symbols,36),
.pixel38 = LEPTON_WORD(packet->symbols,38),
.pixel40 = LEPTON_WORD(packet->symbols,40),
.pixel42 = LEPTON_WORD(packet->symbols,42),
.pixel44 = LEPTON_WORD(packet->symbols,44),
.pixel46 = LEPTON_WORD(packet->symbols,46),
.pixel48 = LEPTON_WORD(packet->symbols,48),
.pixel50 = LEPTON_WORD(packet->symbols,50),
.pixel52 = LEPTON_WORD(packet->symbols,52),
.pixel54 = LEPTON_WORD(packet->symbols,54),
.pixel56 = LEPTON_WORD(packet->symbols,56),
.pixel58 = LEPTON_WORD(packet->symbols,58),
.pixel60 = LEPTON_WORD(packet->symbols,60),
.pixel62 = LEPTON_WORD(packet->symbols,62),
.pixel64 = LEPTON_WORD(packet->symbols,64),
.pixel66 = LEPTON_WORD(packet->symbols,66),
.pixel68 = LEPTON_WORD(packet->symbols,68),
.pixel70 = LEPTON_WORD(packet->symbols,70),
.pixel72 = LEPTON_WORD(packet->symbols,72),
.pixel74 = LEPTON_WORD(packet->symbols,74),
.pixel76 = LEPTON_WORD(packet->symbols,76),
.pixel78 = LEPTON_WORD(packet->symbols,78),
.pixel80 = LEPTON_WORD(packet->symbols,80),
.pixel82 = LEPTON_WORD(packet->symbols,82),
.pixel84 = LEPTON_WORD(packet->symbols,84),
.pixel86 = LEPTON_WORD(packet->symbols,86),
.pixel88 = LEPTON_WORD(packet->symbols,88),
.pixel90 = LEPTON_WORD(packet->symbols,90),
.pixel92 = LEPTON_WORD(packet->symbols,92),
.pixel94 = LEPTON_WORD(packet->symbols,94),
.pixel96 = LEPTON_WORD(packet->symbols,96),
.pixel98 = LEPTON_WORD(packet->symbols,98),
.pixel100 = LEPTON_WORD(packet->symbols,100),
.pixel102 = LEPTON_WORD(packet->symbols,102),
.pixel104 = LEPTON_WORD(packet->symbols,104),
.pixel106 = LEPTON_WORD(packet->symbols,106),
.pixel108 = LEPTON_WORD(packet->symbols,108),
.pixel110 = LEPTON_WORD(packet->symbols,110),
.pixel112 = LEPTON_WORD(packet->symbols,112),
.pixel114 = LEPTON_WORD(packet->symbols,114),
.pixel116 = LEPTON_WORD(packet->symbols,116),
.pixel118 = LEPTON_WORD(packet->symbols,118),
.pixel120 = LEPTON_WORD(packet->symbols,120),
.pixel122 = LEPTON_WORD(packet->symbols,122),
.pixel124 = LEPTON_WORD(packet->symbols,124),
.pixel126 = LEPTON_WORD(packet->symbols,126),
.pixel128 = LEPTON_WORD(packet->symbols,128),
.pixel130 = LEPTON_WORD(packet->symbols,130),
.pixel132 = LEPTON_WORD(packet->symbols,132),
.pixel134 = LEPTON_WORD(packet->symbols,134),
.pixel136 = LEPTON_WORD(packet->symbols,136),
.pixel138 = LEPTON_WORD(packet->symbols,138),
.pixel140 = LEPTON_WORD(packet->symbols,140),
.pixel142 = LEPTON_WORD(packet->symbols,142),
.pixel144 = LEPTON_WORD(packet->symbols,144),
.pixel146 = LEPTON_WORD(packet->symbols,146),
.pixel148 = LEPTON_WORD(packet->symbols,148),
.pixel150 = LEPTON_WORD(packet->symbols,150),
.pixel152 = LEPTON_WORD(packet->symbols,152),
.pixel154 = LEPTON_WORD(packet->symbols,154),
.pixel156 = LEPTON_WORD(packet->symbols,156),
.pixel158 = LEPTON_WORD(packet->symbols,158),

  };

  return telemetry_data;
}
