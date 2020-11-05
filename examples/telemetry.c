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

  log_info("CCI uptime: %d \n", cci_get_uptime(i2c_fd));
  log_info("CCI telemetry enable state: %d \n", cci_get_telemetry_enable_state(i2c_fd));
  log_info("CCI telemetry location: %d \n", cci_get_telemetry_location(i2c_fd));
  //log_info("Spot Coordinates: %d \n", cci_get_spotmeter_coordinates(i2c_fd));


  

  //Infinite loop to constantly read temperature
  // while(1){

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
  telemetry_data_t data = parse_telemetry_packet(&(frame.segments[0].packets[0])); //reads C register

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
  // printf("Spotmeter Population: %d \n \n",data.spotmeter_population);
  // printf("Spotmeter Start Row: %d \n \n",data.spotmeter_start_row);
  // printf("Spotmeter Start Column: %d \n \n",data.spotmeter_start_col);
  // printf("Spotmeter End Row: %d \n \n",data.spotmeter_end_row);
  // printf("Spotmeter End Column: %d \n \n",data.spotmeter_end_col);

  printf("Variable 0: %d \n",data.variable0);
printf("Variable 1: %d \n",data.variable1);
printf("Variable 2: %d \n",data.variable2);
printf("Variable 3: %d \n",data.variable3);
printf("Variable 4: %d \n",data.variable4);
printf("Variable 5: %d \n",data.variable5);
printf("Variable 6: %d \n",data.variable6);
printf("Variable 7: %d \n",data.variable7);
printf("Variable 8: %d \n",data.variable8);
printf("Variable 9: %d \n",data.variable9);
printf("Variable 10: %d \n",data.variable10);
printf("Variable 11: %d \n",data.variable11);
printf("Variable 12: %d \n",data.variable12);
printf("Variable 13: %d \n",data.variable13);
printf("Variable 14: %d \n",data.variable14);
printf("Variable 15: %d \n",data.variable15);
printf("Variable 16: %d \n",data.variable16);
printf("Variable 17: %d \n",data.variable17);
printf("Variable 18: %d \n",data.variable18);
printf("Variable 19: %d \n",data.variable19);
printf("Variable 20: %d \n",data.variable20);
printf("Variable 21: %d \n",data.variable21);
printf("Variable 22: %d \n",data.variable22);
printf("Variable 23: %d \n",data.variable23);
printf("Variable 24: %d \n",data.variable24);
printf("Variable 25: %d \n",data.variable25);
printf("Variable 26: %d \n",data.variable26);
printf("Variable 27: %d \n",data.variable27);
printf("Variable 28: %d \n",data.variable28);
printf("Variable 29: %d \n",data.variable29);
printf("Variable 30: %d \n",data.variable30);
printf("Variable 31: %d \n",data.variable31);
printf("Variable 32: %d \n",data.variable32);
printf("Variable 33: %d \n",data.variable33);
printf("Variable 34: %d \n",data.variable34);
printf("Variable 35: %d \n",data.variable35);
printf("Variable 36: %d \n",data.variable36);
printf("Variable 37: %d \n",data.variable37);
printf("Variable 38: %d \n",data.variable38);
printf("Variable 39: %d \n",data.variable39);
printf("Variable 40: %d \n",data.variable40);
printf("Variable 41: %d \n",data.variable41);
printf("Variable 42: %d \n",data.variable42);
printf("Variable 43: %d \n",data.variable43);
printf("Variable 44: %d \n",data.variable44);
printf("Variable 45: %d \n",data.variable45);
printf("Variable 46: %d \n",data.variable46);
printf("Variable 47: %d \n",data.variable47);
printf("Variable 48: %d \n",data.variable48);
printf("Variable 49: %d \n",data.variable49);
printf("Variable 50: %d \n",data.variable50);
printf("Variable 51: %d \n",data.variable51);
printf("Variable 52: %d \n",data.variable52);
printf("Variable 53: %d \n",data.variable53);
printf("Variable 54: %d \n",data.variable54);
printf("Variable 55: %d \n",data.variable55);
printf("Variable 56: %d \n",data.variable56);
printf("Variable 57: %d \n",data.variable57);
printf("Variable 58: %d \n",data.variable58);
printf("Variable 59: %d \n",data.variable59);
printf("Variable 60: %d \n",data.variable60);
printf("Variable 61: %d \n",data.variable61);
printf("Variable 62: %d \n",data.variable62);
printf("Variable 63: %d \n",data.variable63);
printf("Variable 64: %d \n",data.variable64);
printf("Variable 65: %d \n",data.variable65);
printf("Variable 66: %d \n",data.variable66);
printf("Variable 67: %d \n",data.variable67);
printf("Variable 68: %d \n",data.variable68);
printf("Variable 69: %d \n",data.variable69);
printf("Variable 70: %d \n",data.variable70);
printf("Variable 71: %d \n",data.variable71);
printf("Variable 72: %d \n",data.variable72);
printf("Variable 73: %d \n",data.variable73);
printf("Variable 74: %d \n",data.variable74);
printf("Variable 75: %d \n",data.variable75);
printf("Variable 76: %d \n",data.variable76);
printf("Variable 77: %d \n",data.variable77);
printf("Variable 78: %d \n",data.variable78);
printf("Variable 79: %d \n",data.variable79);
printf("Variable 80: %d \n",data.variable80);
printf("Variable 81: %d \n",data.variable81);
printf("Variable 82: %d \n",data.variable82);
printf("Variable 83: %d \n",data.variable83);
printf("Variable 84: %d \n",data.variable84);
printf("Variable 85: %d \n",data.variable85);
printf("Variable 86: %d \n",data.variable86);
printf("Variable 87: %d \n",data.variable87);
printf("Variable 88: %d \n",data.variable88);
printf("Variable 89: %d \n",data.variable89);
printf("Variable 90: %d \n",data.variable90);
printf("Variable 91: %d \n",data.variable91);
printf("Variable 92: %d \n",data.variable92);
printf("Variable 93: %d \n",data.variable93);
printf("Variable 94: %d \n",data.variable94);
printf("Variable 95: %d \n",data.variable95);
printf("Variable 96: %d \n",data.variable96);
printf("Variable 97: %d \n",data.variable97);
printf("Variable 98: %d \n",data.variable98);
printf("Variable 99: %d \n",data.variable99);
printf("Variable 100: %d \n",data.variable100);
printf("Variable 101: %d \n",data.variable101);
printf("Variable 102: %d \n",data.variable102);
printf("Variable 103: %d \n",data.variable103);
printf("Variable 104: %d \n",data.variable104);
printf("Variable 105: %d \n",data.variable105);
printf("Variable 106: %d \n",data.variable106);
printf("Variable 107: %d \n",data.variable107);
printf("Variable 108: %d \n",data.variable108);
printf("Variable 109: %d \n",data.variable109);
printf("Variable 110: %d \n",data.variable110);
printf("Variable 111: %d \n",data.variable111);
printf("Variable 112: %d \n",data.variable112);
printf("Variable 113: %d \n",data.variable113);
printf("Variable 114: %d \n",data.variable114);
printf("Variable 115: %d \n",data.variable115);
printf("Variable 116: %d \n",data.variable116);
printf("Variable 117: %d \n",data.variable117);
printf("Variable 118: %d \n",data.variable118);
printf("Variable 119: %d \n",data.variable119);
printf("Variable 120: %d \n",data.variable120);
printf("Variable 121: %d \n",data.variable121);
printf("Variable 122: %d \n",data.variable122);
printf("Variable 123: %d \n",data.variable123);
printf("Variable 124: %d \n",data.variable124);
printf("Variable 125: %d \n",data.variable125);
printf("Variable 126: %d \n",data.variable126);
printf("Variable 127: %d \n",data.variable127);
printf("Variable 128: %d \n",data.variable128);
printf("Variable 129: %d \n",data.variable129);
printf("Variable 130: %d \n",data.variable130);
printf("Variable 131: %d \n",data.variable131);
printf("Variable 132: %d \n",data.variable132);
printf("Variable 133: %d \n",data.variable133);
printf("Variable 134: %d \n",data.variable134);
printf("Variable 135: %d \n",data.variable135);
printf("Variable 136: %d \n",data.variable136);
printf("Variable 137: %d \n",data.variable137);
printf("Variable 138: %d \n",data.variable138);
printf("Variable 139: %d \n",data.variable139);
printf("Variable 140: %d \n",data.variable140);
printf("Variable 141: %d \n",data.variable141);
printf("Variable 142: %d \n",data.variable142);
printf("Variable 143: %d \n",data.variable143);
printf("Variable 144: %d \n",data.variable144);
printf("Variable 145: %d \n",data.variable145);
printf("Variable 146: %d \n",data.variable146);
printf("Variable 147: %d \n",data.variable147);
printf("Variable 148: %d \n",data.variable148);
printf("Variable 149: %d \n",data.variable149);
printf("Variable 150: %d \n",data.variable150);
printf("Variable 151: %d \n",data.variable151);
printf("Variable 152: %d \n",data.variable152);
printf("Variable 153: %d \n",data.variable153);
printf("Variable 154: %d \n",data.variable154);
printf("Variable 155: %d \n",data.variable155);
printf("Variable 156: %d \n",data.variable156);
printf("Variable 157: %d \n",data.variable157);
printf("Variable 158: %d \n",data.variable158);
printf("Variable 159: %d \n",data.variable159);
printf("Variable 160: %d \n",data.variable160);
printf("Variable 161: %d \n",data.variable161);
printf("Variable 162: %d \n",data.variable162);
printf("Variable 163: %d \n",data.variable163);
printf("Variable 164: %d \n",data.variable164);
printf("Variable 165: %d \n",data.variable165);
printf("Variable 166: %d \n",data.variable166);
printf("Variable 167: %d \n",data.variable167);
printf("Variable 168: %d \n",data.variable168);
printf("Variable 169: %d \n",data.variable169);
printf("Variable 170: %d \n",data.variable170);
printf("Variable 171: %d \n",data.variable171);
printf("Variable 172: %d \n",data.variable172);
printf("Variable 173: %d \n",data.variable173);
printf("Variable 174: %d \n",data.variable174);
printf("Variable 175: %d \n",data.variable175);
printf("Variable 176: %d \n",data.variable176);
printf("Variable 177: %d \n",data.variable177);
printf("Variable 178: %d \n",data.variable178);
printf("Variable 179: %d \n",data.variable179);


//  }

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