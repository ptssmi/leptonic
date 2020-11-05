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
    // .spotmeter_start_row = LEPTON_WORD(packet->symbols,108),
    // .spotmeter_start_col = LEPTON_WORD(packet->symbols,110),
    // .spotmeter_end_row = LEPTON_WORD(packet->symbols,112),
    // .spotmeter_end_col = LEPTON_WORD(packet->symbols,114)

    .variable0 = LEPTON_WORD(packet->symbols,0),
.variable1 = LEPTON_WORD(packet->symbols,1),
.variable2 = LEPTON_WORD(packet->symbols,2),
.variable3 = LEPTON_WORD(packet->symbols,3),
.variable4 = LEPTON_WORD(packet->symbols,4),
.variable5 = LEPTON_WORD(packet->symbols,5),
.variable6 = LEPTON_WORD(packet->symbols,6),
.variable7 = LEPTON_WORD(packet->symbols,7),
.variable8 = LEPTON_WORD(packet->symbols,8),
.variable9 = LEPTON_WORD(packet->symbols,9),
.variable10 = LEPTON_WORD(packet->symbols,10),
.variable11 = LEPTON_WORD(packet->symbols,11),
.variable12 = LEPTON_WORD(packet->symbols,12),
.variable13 = LEPTON_WORD(packet->symbols,13),
.variable14 = LEPTON_WORD(packet->symbols,14),
.variable15 = LEPTON_WORD(packet->symbols,15),
.variable16 = LEPTON_WORD(packet->symbols,16),
.variable17 = LEPTON_WORD(packet->symbols,17),
.variable18 = LEPTON_WORD(packet->symbols,18),
.variable19 = LEPTON_WORD(packet->symbols,19),
.variable20 = LEPTON_WORD(packet->symbols,20),
.variable21 = LEPTON_WORD(packet->symbols,21),
.variable22 = LEPTON_WORD(packet->symbols,22),
.variable23 = LEPTON_WORD(packet->symbols,23),
.variable24 = LEPTON_WORD(packet->symbols,24),
.variable25 = LEPTON_WORD(packet->symbols,25),
.variable26 = LEPTON_WORD(packet->symbols,26),
.variable27 = LEPTON_WORD(packet->symbols,27),
.variable28 = LEPTON_WORD(packet->symbols,28),
.variable29 = LEPTON_WORD(packet->symbols,29),
.variable30 = LEPTON_WORD(packet->symbols,30),
.variable31 = LEPTON_WORD(packet->symbols,31),
.variable32 = LEPTON_WORD(packet->symbols,32),
.variable33 = LEPTON_WORD(packet->symbols,33),
.variable34 = LEPTON_WORD(packet->symbols,34),
.variable35 = LEPTON_WORD(packet->symbols,35),
.variable36 = LEPTON_WORD(packet->symbols,36),
.variable37 = LEPTON_WORD(packet->symbols,37),
.variable38 = LEPTON_WORD(packet->symbols,38),
.variable39 = LEPTON_WORD(packet->symbols,39),
.variable40 = LEPTON_WORD(packet->symbols,40),
.variable41 = LEPTON_WORD(packet->symbols,41),
.variable42 = LEPTON_WORD(packet->symbols,42),
.variable43 = LEPTON_WORD(packet->symbols,43),
.variable44 = LEPTON_WORD(packet->symbols,44),
.variable45 = LEPTON_WORD(packet->symbols,45),
.variable46 = LEPTON_WORD(packet->symbols,46),
.variable47 = LEPTON_WORD(packet->symbols,47),
.variable48 = LEPTON_WORD(packet->symbols,48),
.variable49 = LEPTON_WORD(packet->symbols,49),
.variable50 = LEPTON_WORD(packet->symbols,50),
.variable51 = LEPTON_WORD(packet->symbols,51),
.variable52 = LEPTON_WORD(packet->symbols,52),
.variable53 = LEPTON_WORD(packet->symbols,53),
.variable54 = LEPTON_WORD(packet->symbols,54),
.variable55 = LEPTON_WORD(packet->symbols,55),
.variable56 = LEPTON_WORD(packet->symbols,56),
.variable57 = LEPTON_WORD(packet->symbols,57),
.variable58 = LEPTON_WORD(packet->symbols,58),
.variable59 = LEPTON_WORD(packet->symbols,59),
.variable60 = LEPTON_WORD(packet->symbols,60),
.variable61 = LEPTON_WORD(packet->symbols,61),
.variable62 = LEPTON_WORD(packet->symbols,62),
.variable63 = LEPTON_WORD(packet->symbols,63),
.variable64 = LEPTON_WORD(packet->symbols,64),
.variable65 = LEPTON_WORD(packet->symbols,65),
.variable66 = LEPTON_WORD(packet->symbols,66),
.variable67 = LEPTON_WORD(packet->symbols,67),
.variable68 = LEPTON_WORD(packet->symbols,68),
.variable69 = LEPTON_WORD(packet->symbols,69),
.variable70 = LEPTON_WORD(packet->symbols,70),
.variable71 = LEPTON_WORD(packet->symbols,71),
.variable72 = LEPTON_WORD(packet->symbols,72),
.variable73 = LEPTON_WORD(packet->symbols,73),
.variable74 = LEPTON_WORD(packet->symbols,74),
.variable75 = LEPTON_WORD(packet->symbols,75),
.variable76 = LEPTON_WORD(packet->symbols,76),
.variable77 = LEPTON_WORD(packet->symbols,77),
.variable78 = LEPTON_WORD(packet->symbols,78),
.variable79 = LEPTON_WORD(packet->symbols,79),
.variable80 = LEPTON_WORD(packet->symbols,80),
.variable81 = LEPTON_WORD(packet->symbols,81),
.variable82 = LEPTON_WORD(packet->symbols,82),
.variable83 = LEPTON_WORD(packet->symbols,83),
.variable84 = LEPTON_WORD(packet->symbols,84),
.variable85 = LEPTON_WORD(packet->symbols,85),
.variable86 = LEPTON_WORD(packet->symbols,86),
.variable87 = LEPTON_WORD(packet->symbols,87),
.variable88 = LEPTON_WORD(packet->symbols,88),
.variable89 = LEPTON_WORD(packet->symbols,89),
.variable90 = LEPTON_WORD(packet->symbols,90),
.variable91 = LEPTON_WORD(packet->symbols,91),
.variable92 = LEPTON_WORD(packet->symbols,92),
.variable93 = LEPTON_WORD(packet->symbols,93),
.variable94 = LEPTON_WORD(packet->symbols,94),
.variable95 = LEPTON_WORD(packet->symbols,95),
.variable96 = LEPTON_WORD(packet->symbols,96),
.variable97 = LEPTON_WORD(packet->symbols,97),
.variable98 = LEPTON_WORD(packet->symbols,98),
.variable99 = LEPTON_WORD(packet->symbols,99),
.variable100 = LEPTON_WORD(packet->symbols,100),
.variable101 = LEPTON_WORD(packet->symbols,101),
.variable102 = LEPTON_WORD(packet->symbols,102),
.variable103 = LEPTON_WORD(packet->symbols,103),
.variable104 = LEPTON_WORD(packet->symbols,104),
.variable105 = LEPTON_WORD(packet->symbols,105),
.variable106 = LEPTON_WORD(packet->symbols,106),
.variable107 = LEPTON_WORD(packet->symbols,107),
.variable108 = LEPTON_WORD(packet->symbols,108),
.variable109 = LEPTON_WORD(packet->symbols,109),
.variable110 = LEPTON_WORD(packet->symbols,110),
.variable111 = LEPTON_WORD(packet->symbols,111),
.variable112 = LEPTON_WORD(packet->symbols,112),
.variable113 = LEPTON_WORD(packet->symbols,113),
.variable114 = LEPTON_WORD(packet->symbols,114),
.variable115 = LEPTON_WORD(packet->symbols,115),
.variable116 = LEPTON_WORD(packet->symbols,116),
.variable117 = LEPTON_WORD(packet->symbols,117),
.variable118 = LEPTON_WORD(packet->symbols,118),
.variable119 = LEPTON_WORD(packet->symbols,119),
.variable120 = LEPTON_WORD(packet->symbols,120),
.variable121 = LEPTON_WORD(packet->symbols,121),
.variable122 = LEPTON_WORD(packet->symbols,122),
.variable123 = LEPTON_WORD(packet->symbols,123),
.variable124 = LEPTON_WORD(packet->symbols,124),
.variable125 = LEPTON_WORD(packet->symbols,125),
.variable126 = LEPTON_WORD(packet->symbols,126),
.variable127 = LEPTON_WORD(packet->symbols,127),
.variable128 = LEPTON_WORD(packet->symbols,128),
.variable129 = LEPTON_WORD(packet->symbols,129),
.variable130 = LEPTON_WORD(packet->symbols,130),
.variable131 = LEPTON_WORD(packet->symbols,131),
.variable132 = LEPTON_WORD(packet->symbols,132),
.variable133 = LEPTON_WORD(packet->symbols,133),
.variable134 = LEPTON_WORD(packet->symbols,134),
.variable135 = LEPTON_WORD(packet->symbols,135),
.variable136 = LEPTON_WORD(packet->symbols,136),
.variable137 = LEPTON_WORD(packet->symbols,137),
.variable138 = LEPTON_WORD(packet->symbols,138),
.variable139 = LEPTON_WORD(packet->symbols,139),
.variable140 = LEPTON_WORD(packet->symbols,140),
.variable141 = LEPTON_WORD(packet->symbols,141),
.variable142 = LEPTON_WORD(packet->symbols,142),
.variable143 = LEPTON_WORD(packet->symbols,143),
.variable144 = LEPTON_WORD(packet->symbols,144),
.variable145 = LEPTON_WORD(packet->symbols,145),
.variable146 = LEPTON_WORD(packet->symbols,146),
.variable147 = LEPTON_WORD(packet->symbols,147),
.variable148 = LEPTON_WORD(packet->symbols,148),
.variable149 = LEPTON_WORD(packet->symbols,149),
.variable150 = LEPTON_WORD(packet->symbols,150),
.variable151 = LEPTON_WORD(packet->symbols,151),
.variable152 = LEPTON_WORD(packet->symbols,152),
.variable153 = LEPTON_WORD(packet->symbols,153),
.variable154 = LEPTON_WORD(packet->symbols,154),
.variable155 = LEPTON_WORD(packet->symbols,155),
.variable156 = LEPTON_WORD(packet->symbols,156),
.variable157 = LEPTON_WORD(packet->symbols,157),
.variable158 = LEPTON_WORD(packet->symbols,158),
.variable159 = LEPTON_WORD(packet->symbols,159),
.variable160 = LEPTON_WORD(packet->symbols,160),
.variable161 = LEPTON_WORD(packet->symbols,161),
.variable162 = LEPTON_WORD(packet->symbols,162),
.variable163 = LEPTON_WORD(packet->symbols,163),
.variable164 = LEPTON_WORD(packet->symbols,164),
.variable165 = LEPTON_WORD(packet->symbols,165),
.variable166 = LEPTON_WORD(packet->symbols,166),
.variable167 = LEPTON_WORD(packet->symbols,167),
.variable168 = LEPTON_WORD(packet->symbols,168),
.variable169 = LEPTON_WORD(packet->symbols,169),
.variable170 = LEPTON_WORD(packet->symbols,170),
.variable171 = LEPTON_WORD(packet->symbols,171),
.variable172 = LEPTON_WORD(packet->symbols,172),
.variable173 = LEPTON_WORD(packet->symbols,173),
.variable174 = LEPTON_WORD(packet->symbols,174),
.variable175 = LEPTON_WORD(packet->symbols,175),
.variable176 = LEPTON_WORD(packet->symbols,176),
.variable177 = LEPTON_WORD(packet->symbols,177),
.variable178 = LEPTON_WORD(packet->symbols,178),
.variable179 = LEPTON_WORD(packet->symbols,179),
.variable180 = LEPTON_WORD(packet->symbols,180),
.variable181 = LEPTON_WORD(packet->symbols,181),
.variable182 = LEPTON_WORD(packet->symbols,182),
.variable183 = LEPTON_WORD(packet->symbols,183),
.variable184 = LEPTON_WORD(packet->symbols,184),
.variable185 = LEPTON_WORD(packet->symbols,185),
.variable186 = LEPTON_WORD(packet->symbols,186),
.variable187 = LEPTON_WORD(packet->symbols,187),
.variable188 = LEPTON_WORD(packet->symbols,188),
.variable189 = LEPTON_WORD(packet->symbols,189),
.variable190 = LEPTON_WORD(packet->symbols,190),
.variable191 = LEPTON_WORD(packet->symbols,191),
.variable192 = LEPTON_WORD(packet->symbols,192),
.variable193 = LEPTON_WORD(packet->symbols,193),
.variable194 = LEPTON_WORD(packet->symbols,194),
.variable195 = LEPTON_WORD(packet->symbols,195),
.variable196 = LEPTON_WORD(packet->symbols,196),
.variable197 = LEPTON_WORD(packet->symbols,197),
.variable198 = LEPTON_WORD(packet->symbols,198),
.variable199 = LEPTON_WORD(packet->symbols,199),
.variable200 = LEPTON_WORD(packet->symbols,200),
.variable201 = LEPTON_WORD(packet->symbols,201),
.variable202 = LEPTON_WORD(packet->symbols,202),
.variable203 = LEPTON_WORD(packet->symbols,203),
.variable204 = LEPTON_WORD(packet->symbols,204),
.variable205 = LEPTON_WORD(packet->symbols,205),
.variable206 = LEPTON_WORD(packet->symbols,206),
.variable207 = LEPTON_WORD(packet->symbols,207),
.variable208 = LEPTON_WORD(packet->symbols,208),
.variable209 = LEPTON_WORD(packet->symbols,209),
.variable210 = LEPTON_WORD(packet->symbols,210),
.variable211 = LEPTON_WORD(packet->symbols,211),
.variable212 = LEPTON_WORD(packet->symbols,212),
.variable213 = LEPTON_WORD(packet->symbols,213),
.variable214 = LEPTON_WORD(packet->symbols,214),
.variable215 = LEPTON_WORD(packet->symbols,215),
.variable216 = LEPTON_WORD(packet->symbols,216),
.variable217 = LEPTON_WORD(packet->symbols,217),
.variable218 = LEPTON_WORD(packet->symbols,218),
.variable219 = LEPTON_WORD(packet->symbols,219),
.variable220 = LEPTON_WORD(packet->symbols,220),
.variable221 = LEPTON_WORD(packet->symbols,221),
.variable222 = LEPTON_WORD(packet->symbols,222),
.variable223 = LEPTON_WORD(packet->symbols,223),
.variable224 = LEPTON_WORD(packet->symbols,224),
.variable225 = LEPTON_WORD(packet->symbols,225),
.variable226 = LEPTON_WORD(packet->symbols,226),
.variable227 = LEPTON_WORD(packet->symbols,227),
.variable228 = LEPTON_WORD(packet->symbols,228),
.variable229 = LEPTON_WORD(packet->symbols,229),
.variable230 = LEPTON_WORD(packet->symbols,230),
.variable231 = LEPTON_WORD(packet->symbols,231),
.variable232 = LEPTON_WORD(packet->symbols,232),
.variable233 = LEPTON_WORD(packet->symbols,233),
.variable234 = LEPTON_WORD(packet->symbols,234),
.variable235 = LEPTON_WORD(packet->symbols,235),
.variable236 = LEPTON_WORD(packet->symbols,236),
.variable237 = LEPTON_WORD(packet->symbols,237),
.variable238 = LEPTON_WORD(packet->symbols,238),
.variable239 = LEPTON_WORD(packet->symbols,239),
.variable240 = LEPTON_WORD(packet->symbols,240),
.variable241 = LEPTON_WORD(packet->symbols,241),
.variable242 = LEPTON_WORD(packet->symbols,242),
.variable243 = LEPTON_WORD(packet->symbols,243),
.variable244 = LEPTON_WORD(packet->symbols,244),
.variable245 = LEPTON_WORD(packet->symbols,245),
.variable246 = LEPTON_WORD(packet->symbols,246),
.variable247 = LEPTON_WORD(packet->symbols,247),
.variable248 = LEPTON_WORD(packet->symbols,248),
.variable249 = LEPTON_WORD(packet->symbols,249),
.variable250 = LEPTON_WORD(packet->symbols,250),
.variable251 = LEPTON_WORD(packet->symbols,251),
.variable252 = LEPTON_WORD(packet->symbols,252),
.variable253 = LEPTON_WORD(packet->symbols,253),
.variable254 = LEPTON_WORD(packet->symbols,254),
.variable255 = LEPTON_WORD(packet->symbols,255),
.variable256 = LEPTON_WORD(packet->symbols,256),
.variable257 = LEPTON_WORD(packet->symbols,257),
.variable258 = LEPTON_WORD(packet->symbols,258),
.variable259 = LEPTON_WORD(packet->symbols,259),
.variable260 = LEPTON_WORD(packet->symbols,260),
.variable261 = LEPTON_WORD(packet->symbols,261),
.variable262 = LEPTON_WORD(packet->symbols,262),
.variable263 = LEPTON_WORD(packet->symbols,263),
.variable264 = LEPTON_WORD(packet->symbols,264),
.variable265 = LEPTON_WORD(packet->symbols,265),
.variable266 = LEPTON_WORD(packet->symbols,266),
.variable267 = LEPTON_WORD(packet->symbols,267),
.variable268 = LEPTON_WORD(packet->symbols,268),
.variable269 = LEPTON_WORD(packet->symbols,269),
.variable270 = LEPTON_WORD(packet->symbols,270),
.variable271 = LEPTON_WORD(packet->symbols,271),
.variable272 = LEPTON_WORD(packet->symbols,272),
.variable273 = LEPTON_WORD(packet->symbols,273),
.variable274 = LEPTON_WORD(packet->symbols,274),
.variable275 = LEPTON_WORD(packet->symbols,275),
.variable276 = LEPTON_WORD(packet->symbols,276),
.variable277 = LEPTON_WORD(packet->symbols,277),
.variable278 = LEPTON_WORD(packet->symbols,278),
.variable279 = LEPTON_WORD(packet->symbols,279),
.variable280 = LEPTON_WORD(packet->symbols,280),
.variable281 = LEPTON_WORD(packet->symbols,281),
.variable282 = LEPTON_WORD(packet->symbols,282),
.variable283 = LEPTON_WORD(packet->symbols,283),
.variable284 = LEPTON_WORD(packet->symbols,284),
.variable285 = LEPTON_WORD(packet->symbols,285),
.variable286 = LEPTON_WORD(packet->symbols,286),
.variable287 = LEPTON_WORD(packet->symbols,287),
.variable288 = LEPTON_WORD(packet->symbols,288),
.variable289 = LEPTON_WORD(packet->symbols,289),
.variable290 = LEPTON_WORD(packet->symbols,290),
.variable291 = LEPTON_WORD(packet->symbols,291),
.variable292 = LEPTON_WORD(packet->symbols,292),
.variable293 = LEPTON_WORD(packet->symbols,293),
.variable294 = LEPTON_WORD(packet->symbols,294),
.variable295 = LEPTON_WORD(packet->symbols,295),
.variable296 = LEPTON_WORD(packet->symbols,296),
.variable297 = LEPTON_WORD(packet->symbols,297),
.variable298 = LEPTON_WORD(packet->symbols,298),
.variable299 = LEPTON_WORD(packet->symbols,299),
.variable300 = LEPTON_WORD(packet->symbols,300),
.variable301 = LEPTON_WORD(packet->symbols,301),
.variable302 = LEPTON_WORD(packet->symbols,302),
.variable303 = LEPTON_WORD(packet->symbols,303),
.variable304 = LEPTON_WORD(packet->symbols,304),
.variable305 = LEPTON_WORD(packet->symbols,305),
.variable306 = LEPTON_WORD(packet->symbols,306),
.variable307 = LEPTON_WORD(packet->symbols,307),
.variable308 = LEPTON_WORD(packet->symbols,308),
.variable309 = LEPTON_WORD(packet->symbols,309),
.variable310 = LEPTON_WORD(packet->symbols,310),
.variable311 = LEPTON_WORD(packet->symbols,311),
.variable312 = LEPTON_WORD(packet->symbols,312),
.variable313 = LEPTON_WORD(packet->symbols,313),
.variable314 = LEPTON_WORD(packet->symbols,314),
.variable315 = LEPTON_WORD(packet->symbols,315),
.variable316 = LEPTON_WORD(packet->symbols,316),
.variable317 = LEPTON_WORD(packet->symbols,317),
.variable318 = LEPTON_WORD(packet->symbols,318),
.variable319 = LEPTON_WORD(packet->symbols,319),
.variable320 = LEPTON_WORD(packet->symbols,320),
.variable321 = LEPTON_WORD(packet->symbols,321),
.variable322 = LEPTON_WORD(packet->symbols,322),
.variable323 = LEPTON_WORD(packet->symbols,323),
.variable324 = LEPTON_WORD(packet->symbols,324),
.variable325 = LEPTON_WORD(packet->symbols,325),
.variable326 = LEPTON_WORD(packet->symbols,326),
.variable327 = LEPTON_WORD(packet->symbols,327),
.variable328 = LEPTON_WORD(packet->symbols,328),
.variable329 = LEPTON_WORD(packet->symbols,329),
.variable330 = LEPTON_WORD(packet->symbols,330),
.variable331 = LEPTON_WORD(packet->symbols,331),
.variable332 = LEPTON_WORD(packet->symbols,332),
.variable333 = LEPTON_WORD(packet->symbols,333),
.variable334 = LEPTON_WORD(packet->symbols,334),
.variable335 = LEPTON_WORD(packet->symbols,335),
.variable336 = LEPTON_WORD(packet->symbols,336),
.variable337 = LEPTON_WORD(packet->symbols,337),
.variable338 = LEPTON_WORD(packet->symbols,338),
.variable339 = LEPTON_WORD(packet->symbols,339),
.variable340 = LEPTON_WORD(packet->symbols,340),
.variable341 = LEPTON_WORD(packet->symbols,341),
.variable342 = LEPTON_WORD(packet->symbols,342),
.variable343 = LEPTON_WORD(packet->symbols,343),
.variable344 = LEPTON_WORD(packet->symbols,344),
.variable345 = LEPTON_WORD(packet->symbols,345),
.variable346 = LEPTON_WORD(packet->symbols,346),
.variable347 = LEPTON_WORD(packet->symbols,347),
.variable348 = LEPTON_WORD(packet->symbols,348),
.variable349 = LEPTON_WORD(packet->symbols,349),
.variable350 = LEPTON_WORD(packet->symbols,350),
.variable351 = LEPTON_WORD(packet->symbols,351),
.variable352 = LEPTON_WORD(packet->symbols,352),
.variable353 = LEPTON_WORD(packet->symbols,353),
.variable354 = LEPTON_WORD(packet->symbols,354),
.variable355 = LEPTON_WORD(packet->symbols,355),
.variable356 = LEPTON_WORD(packet->symbols,356),
.variable357 = LEPTON_WORD(packet->symbols,357),
.variable358 = LEPTON_WORD(packet->symbols,358),
.variable359 = LEPTON_WORD(packet->symbols,359),
.variable360 = LEPTON_WORD(packet->symbols,360),
.variable361 = LEPTON_WORD(packet->symbols,361),
.variable362 = LEPTON_WORD(packet->symbols,362),
.variable363 = LEPTON_WORD(packet->symbols,363),
.variable364 = LEPTON_WORD(packet->symbols,364),
.variable365 = LEPTON_WORD(packet->symbols,365),
.variable366 = LEPTON_WORD(packet->symbols,366),
.variable367 = LEPTON_WORD(packet->symbols,367),
.variable368 = LEPTON_WORD(packet->symbols,368),
.variable369 = LEPTON_WORD(packet->symbols,369),
.variable370 = LEPTON_WORD(packet->symbols,370),
.variable371 = LEPTON_WORD(packet->symbols,371),
.variable372 = LEPTON_WORD(packet->symbols,372),
.variable373 = LEPTON_WORD(packet->symbols,373),
.variable374 = LEPTON_WORD(packet->symbols,374),
.variable375 = LEPTON_WORD(packet->symbols,375),
.variable376 = LEPTON_WORD(packet->symbols,376),
.variable377 = LEPTON_WORD(packet->symbols,377),
.variable378 = LEPTON_WORD(packet->symbols,378),
.variable379 = LEPTON_WORD(packet->symbols,379),
.variable380 = LEPTON_WORD(packet->symbols,380),
.variable381 = LEPTON_WORD(packet->symbols,381),
.variable382 = LEPTON_WORD(packet->symbols,382),
.variable383 = LEPTON_WORD(packet->symbols,383),
.variable384 = LEPTON_WORD(packet->symbols,384),
.variable385 = LEPTON_WORD(packet->symbols,385),
.variable386 = LEPTON_WORD(packet->symbols,386),
.variable387 = LEPTON_WORD(packet->symbols,387),
.variable388 = LEPTON_WORD(packet->symbols,388),
.variable389 = LEPTON_WORD(packet->symbols,389),
.variable390 = LEPTON_WORD(packet->symbols,390),
.variable391 = LEPTON_WORD(packet->symbols,391),
.variable392 = LEPTON_WORD(packet->symbols,392),
.variable393 = LEPTON_WORD(packet->symbols,393),
.variable394 = LEPTON_WORD(packet->symbols,394),
.variable395 = LEPTON_WORD(packet->symbols,395),
.variable396 = LEPTON_WORD(packet->symbols,396),
.variable397 = LEPTON_WORD(packet->symbols,397),
.variable398 = LEPTON_WORD(packet->symbols,398),
.variable399 = LEPTON_WORD(packet->symbols,399)



  };

  return telemetry_data;
}
