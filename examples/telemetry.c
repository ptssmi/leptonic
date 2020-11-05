#include "log.h"
#include "vospi.h"
#include "cci.h"
#include "telemetry.h"
#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

double tempconverter(int tempinkelvin);

uint16_t startrow = 10;
uint16_t endrow = 15;
uint16_t startcol = 10;
uint16_t endcol = 15;

/**
 * Main entry point for example.
 *
 * This example enables telemetry data, transfers a single frame then displays the received information.
 */
int main(int argc, char *argv[])
{
  log_set_level(LOG_INFO);
  int spi_fd, i2c_fd;

  // Check we have enough arguments to work
  if (argc < 3) {
    log_error("Can't start - SPI and CCI I2C device file paths must be specified.");
    exit(-1);
  }

  // Open the spidev device
  log_info("opening SPI device...");
  spi_fd = open(argv[1], O_RDWR);
  if (spi_fd < 0) {
    log_fatal("SPI: failed to open device - check permissions & spidev enabled");
    exit(-1);
  }

  // Open the CCI device
  log_info("opening CCI I2C device...");
  i2c_fd = open(argv[2], O_RDWR);
  if (i2c_fd < 0) {
    log_fatal("I2C: failed to open device - check permissions & I2C enabled");
    exit(-1);
  }

  // Initialise the VoSPI interface
  if (vospi_init(spi_fd, 18000000) == -1) {
      log_fatal("SPI: failed condition SPI device for VoSPI use.");
      exit(-1);
  }

  // Initialise the I2C interface
  if (cci_init(i2c_fd) == -1) {
      log_fatal("I2C: failed condition I2C device for CCI use.");
      exit(-1);
  }

  // Enable telemetry in the footer of segments
  cci_init(i2c_fd);
  cci_set_telemetry_enable_state(i2c_fd, CCI_TELEMETRY_ENABLED);
  cci_set_telemetry_location(i2c_fd, CCI_TELEMETRY_LOCATION_HEADER);

  cci_set_spotmeter_coordinates(i2c_fd,startrow,endrow,startcol,endcol);

  log_info("CCI uptime: %d", cci_get_uptime(i2c_fd));
  log_info("CCI telemetry enable state: %d", cci_get_telemetry_enable_state(i2c_fd));
  log_info("CCI telemetry location: %d", cci_get_telemetry_location(i2c_fd));
  //log_info("Spot Coordinates: %d", cci_get_spotmeter_coordinates(i2c_fd));


  

  //Infinite loop to constantly read temperature
  while(1){

  // Allocate space to receive the segments
  log_debug("allocating space for segments...");
  vospi_frame_t frame;
  for (int seg = 0; seg < VOSPI_SEGMENTS_PER_FRAME; seg ++ ){
    frame.segments[seg].packet_count = VOSPI_PACKETS_PER_SEGMENT_TELEMETRY;
  }

  // Synchronise and transfer a single frame
  //log_info("aquiring VoSPI synchronisation");
  if (0 == sync_and_transfer_frame(spi_fd, &frame)) {
    log_error("failed to obtain frame from device.");
    exit(-10);
  }
  //log_info("VoSPI stream synchronised");

  // Parse the telemetry data
  // telemetry_data_t data = parse_telemetry_packet(&(frame.segments[0].packets[0])); //reads A register 
  // telemetry_data_t data = parse_telemetry_packet(&(frame.segments[0].packets[1])); //reads B register
  telemetry_data_t data = parse_telemetry_packet(&(frame.segments[0].packets[2])); //reads C register

  //A Register
  // log_info("Telmetry data decoded:");
  // log_info("Msec since boot: %02x", data.msec_since_boot);
  // log_info("Msec since last FFC: %02x", data.msec_last_ffc);
  // log_info("Frame mean: %02x", data.frame_mean);
  // log_info("FPA Temp Kelvin100: %02x", data.fpa_temp_kelvin_100);
  // log_info("FFC Desired: %02x", data.status_bits.ffc_desired);
  // log_info("FFC State: %02x", data.status_bits.ffc_state);
  // log_info("AGC State: %02x", data.status_bits.agc_state);
  // log_info("Shutter locked?: %02x", data.status_bits.shutter_lockout);
  // log_info("Overtemp shutdown imminent?: %02x", data.status_bits.overtemp_shutdown_imminent);

  //B Register
  // temp_farenheit = (((data.background_temp/100) - 273.15) * 1.8) + 32;

  //C Register
  // printf("T-Linear Resolution: %02x \n",data.tlinear_resolution);
  // printf("Spotmeter Mean Temp: %0.2f °F \n",tempconverter(data.spotmeter_mean_temp));
  // printf("Spotmeter Max Temp: %0.2f °F \n",tempconverter(data.spotmeter_max_temp));
  // printf("Spotmeter Min Temp: %0.2f °F \n",tempconverter(data.spotmeter_min_temp));
  // printf("Spotmeter Population: %d \n",data.spotmeter_population);
  // printf("Spotmeter Start Row: %d \n",data.spotmeter_start_row);
  // printf("Spotmeter Start Column: %d \n",data.spotmeter_start_col);
  // printf("Spotmeter End Row: %d \n",data.spotmeter_end_row);
  // printf("Spotmeter End Column: %d \n",data.spotmeter_end_col);

  printf("Variable 0: %d",data.variable0);
printf("Variable 1: %d",data.variable1);
printf("Variable 2: %d",data.variable2);
printf("Variable 3: %d",data.variable3);
printf("Variable 4: %d",data.variable4);
printf("Variable 5: %d",data.variable5);
printf("Variable 6: %d",data.variable6);
printf("Variable 7: %d",data.variable7);
printf("Variable 8: %d",data.variable8);
printf("Variable 9: %d",data.variable9);
printf("Variable 10: %d",data.variable10);
printf("Variable 11: %d",data.variable11);
printf("Variable 12: %d",data.variable12);
printf("Variable 13: %d",data.variable13);
printf("Variable 14: %d",data.variable14);
printf("Variable 15: %d",data.variable15);
printf("Variable 16: %d",data.variable16);
printf("Variable 17: %d",data.variable17);
printf("Variable 18: %d",data.variable18);
printf("Variable 19: %d",data.variable19);
printf("Variable 20: %d",data.variable20);
printf("Variable 21: %d",data.variable21);
printf("Variable 22: %d",data.variable22);
printf("Variable 23: %d",data.variable23);
printf("Variable 24: %d",data.variable24);
printf("Variable 25: %d",data.variable25);
printf("Variable 26: %d",data.variable26);
printf("Variable 27: %d",data.variable27);
printf("Variable 28: %d",data.variable28);
printf("Variable 29: %d",data.variable29);
printf("Variable 30: %d",data.variable30);
printf("Variable 31: %d",data.variable31);
printf("Variable 32: %d",data.variable32);
printf("Variable 33: %d",data.variable33);
printf("Variable 34: %d",data.variable34);
printf("Variable 35: %d",data.variable35);
printf("Variable 36: %d",data.variable36);
printf("Variable 37: %d",data.variable37);
printf("Variable 38: %d",data.variable38);
printf("Variable 39: %d",data.variable39);
printf("Variable 40: %d",data.variable40);
printf("Variable 41: %d",data.variable41);
printf("Variable 42: %d",data.variable42);
printf("Variable 43: %d",data.variable43);
printf("Variable 44: %d",data.variable44);
printf("Variable 45: %d",data.variable45);
printf("Variable 46: %d",data.variable46);
printf("Variable 47: %d",data.variable47);
printf("Variable 48: %d",data.variable48);
printf("Variable 49: %d",data.variable49);
printf("Variable 50: %d",data.variable50);
printf("Variable 51: %d",data.variable51);
printf("Variable 52: %d",data.variable52);
printf("Variable 53: %d",data.variable53);
printf("Variable 54: %d",data.variable54);
printf("Variable 55: %d",data.variable55);
printf("Variable 56: %d",data.variable56);
printf("Variable 57: %d",data.variable57);
printf("Variable 58: %d",data.variable58);
printf("Variable 59: %d",data.variable59);
printf("Variable 60: %d",data.variable60);
printf("Variable 61: %d",data.variable61);
printf("Variable 62: %d",data.variable62);
printf("Variable 63: %d",data.variable63);
printf("Variable 64: %d",data.variable64);
printf("Variable 65: %d",data.variable65);
printf("Variable 66: %d",data.variable66);
printf("Variable 67: %d",data.variable67);
printf("Variable 68: %d",data.variable68);
printf("Variable 69: %d",data.variable69);
printf("Variable 70: %d",data.variable70);
printf("Variable 71: %d",data.variable71);
printf("Variable 72: %d",data.variable72);
printf("Variable 73: %d",data.variable73);
printf("Variable 74: %d",data.variable74);
printf("Variable 75: %d",data.variable75);
printf("Variable 76: %d",data.variable76);
printf("Variable 77: %d",data.variable77);
printf("Variable 78: %d",data.variable78);
printf("Variable 79: %d",data.variable79);
printf("Variable 80: %d",data.variable80);
printf("Variable 81: %d",data.variable81);
printf("Variable 82: %d",data.variable82);
printf("Variable 83: %d",data.variable83);
printf("Variable 84: %d",data.variable84);
printf("Variable 85: %d",data.variable85);
printf("Variable 86: %d",data.variable86);
printf("Variable 87: %d",data.variable87);
printf("Variable 88: %d",data.variable88);
printf("Variable 89: %d",data.variable89);
printf("Variable 90: %d",data.variable90);
printf("Variable 91: %d",data.variable91);
printf("Variable 92: %d",data.variable92);
printf("Variable 93: %d",data.variable93);
printf("Variable 94: %d",data.variable94);
printf("Variable 95: %d",data.variable95);
printf("Variable 96: %d",data.variable96);
printf("Variable 97: %d",data.variable97);
printf("Variable 98: %d",data.variable98);
printf("Variable 99: %d",data.variable99);
printf("Variable 100: %d",data.variable100);
printf("Variable 101: %d",data.variable101);
printf("Variable 102: %d",data.variable102);
printf("Variable 103: %d",data.variable103);
printf("Variable 104: %d",data.variable104);
printf("Variable 105: %d",data.variable105);
printf("Variable 106: %d",data.variable106);
printf("Variable 107: %d",data.variable107);
printf("Variable 108: %d",data.variable108);
printf("Variable 109: %d",data.variable109);
printf("Variable 110: %d",data.variable110);
printf("Variable 111: %d",data.variable111);
printf("Variable 112: %d",data.variable112);
printf("Variable 113: %d",data.variable113);
printf("Variable 114: %d",data.variable114);
printf("Variable 115: %d",data.variable115);
printf("Variable 116: %d",data.variable116);
printf("Variable 117: %d",data.variable117);
printf("Variable 118: %d",data.variable118);
printf("Variable 119: %d",data.variable119);
printf("Variable 120: %d",data.variable120);
printf("Variable 121: %d",data.variable121);
printf("Variable 122: %d",data.variable122);
printf("Variable 123: %d",data.variable123);
printf("Variable 124: %d",data.variable124);
printf("Variable 125: %d",data.variable125);
printf("Variable 126: %d",data.variable126);
printf("Variable 127: %d",data.variable127);
printf("Variable 128: %d",data.variable128);
printf("Variable 129: %d",data.variable129);
printf("Variable 130: %d",data.variable130);
printf("Variable 131: %d",data.variable131);
printf("Variable 132: %d",data.variable132);
printf("Variable 133: %d",data.variable133);
printf("Variable 134: %d",data.variable134);
printf("Variable 135: %d",data.variable135);
printf("Variable 136: %d",data.variable136);
printf("Variable 137: %d",data.variable137);
printf("Variable 138: %d",data.variable138);
printf("Variable 139: %d",data.variable139);
printf("Variable 140: %d",data.variable140);
printf("Variable 141: %d",data.variable141);
printf("Variable 142: %d",data.variable142);
printf("Variable 143: %d",data.variable143);
printf("Variable 144: %d",data.variable144);
printf("Variable 145: %d",data.variable145);
printf("Variable 146: %d",data.variable146);
printf("Variable 147: %d",data.variable147);
printf("Variable 148: %d",data.variable148);
printf("Variable 149: %d",data.variable149);
printf("Variable 150: %d",data.variable150);
printf("Variable 151: %d",data.variable151);
printf("Variable 152: %d",data.variable152);
printf("Variable 153: %d",data.variable153);
printf("Variable 154: %d",data.variable154);
printf("Variable 155: %d",data.variable155);
printf("Variable 156: %d",data.variable156);
printf("Variable 157: %d",data.variable157);
printf("Variable 158: %d",data.variable158);
printf("Variable 159: %d",data.variable159);
printf("Variable 160: %d",data.variable160);
printf("Variable 161: %d",data.variable161);
printf("Variable 162: %d",data.variable162);
printf("Variable 163: %d",data.variable163);
printf("Variable 164: %d",data.variable164);
printf("Variable 165: %d",data.variable165);
printf("Variable 166: %d",data.variable166);
printf("Variable 167: %d",data.variable167);
printf("Variable 168: %d",data.variable168);
printf("Variable 169: %d",data.variable169);
printf("Variable 170: %d",data.variable170);
printf("Variable 171: %d",data.variable171);
printf("Variable 172: %d",data.variable172);
printf("Variable 173: %d",data.variable173);
printf("Variable 174: %d",data.variable174);
printf("Variable 175: %d",data.variable175);
printf("Variable 176: %d",data.variable176);
printf("Variable 177: %d",data.variable177);
printf("Variable 178: %d",data.variable178);
printf("Variable 179: %d",data.variable179);


 }

  // Disable telemetry again to leave the module in a usable state for other examples
  cci_set_telemetry_enable_state(i2c_fd, CCI_TELEMETRY_DISABLED);

  // Close files
  close(spi_fd);
  close(i2c_fd);

  return 0;
  
}

double tempconverter(int tempinkelvin){
  double result;
  result = (((tempinkelvin/100) - 273.15) * 1.8) + 32;
  return result;
}