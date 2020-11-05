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
  telemetry_data_t data = parse_telemetry_packet(&(frame.segments[0].packets[60])); //reads C register

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

printf("Variable 0: %f0.2\n",tempconverter(data.variable0));
printf("Variable 1: %f0.2\n",tempconverter(data.variable1));
printf("Variable 2: %f0.2\n",tempconverter(data.variable2));
printf("Variable 3: %f0.2\n",tempconverter(data.variable3));
printf("Variable 4: %f0.2\n",tempconverter(data.variable4));
printf("Variable 5: %f0.2\n",tempconverter(data.variable5));
printf("Variable 6: %f0.2\n",tempconverter(data.variable6));
printf("Variable 7: %f0.2\n",tempconverter(data.variable7));
printf("Variable 8: %f0.2\n",tempconverter(data.variable8));
printf("Variable 9: %f0.2\n",tempconverter(data.variable9));
printf("Variable 10: %f0.2\n",tempconverter(data.variable10));
printf("Variable 11: %f0.2\n",tempconverter(data.variable11));
printf("Variable 12: %f0.2\n",tempconverter(data.variable12));
printf("Variable 13: %f0.2\n",tempconverter(data.variable13));
printf("Variable 14: %f0.2\n",tempconverter(data.variable14));
printf("Variable 15: %f0.2\n",tempconverter(data.variable15));
printf("Variable 16: %f0.2\n",tempconverter(data.variable16));
printf("Variable 17: %f0.2\n",tempconverter(data.variable17));
printf("Variable 18: %f0.2\n",tempconverter(data.variable18));
printf("Variable 19: %f0.2\n",tempconverter(data.variable19));
printf("Variable 20: %f0.2\n",tempconverter(data.variable20));
printf("Variable 21: %f0.2\n",tempconverter(data.variable21));
printf("Variable 22: %f0.2\n",tempconverter(data.variable22));
printf("Variable 23: %f0.2\n",tempconverter(data.variable23));
printf("Variable 24: %f0.2\n",tempconverter(data.variable24));
printf("Variable 25: %f0.2\n",tempconverter(data.variable25));
printf("Variable 26: %f0.2\n",tempconverter(data.variable26));
printf("Variable 27: %f0.2\n",tempconverter(data.variable27));
printf("Variable 28: %f0.2\n",tempconverter(data.variable28));
printf("Variable 29: %f0.2\n",tempconverter(data.variable29));
printf("Variable 30: %f0.2\n",tempconverter(data.variable30));
printf("Variable 31: %f0.2\n",tempconverter(data.variable31));
printf("Variable 32: %f0.2\n",tempconverter(data.variable32));
printf("Variable 33: %f0.2\n",tempconverter(data.variable33));
printf("Variable 34: %f0.2\n",tempconverter(data.variable34));
printf("Variable 35: %f0.2\n",tempconverter(data.variable35));
printf("Variable 36: %f0.2\n",tempconverter(data.variable36));
printf("Variable 37: %f0.2\n",tempconverter(data.variable37));
printf("Variable 38: %f0.2\n",tempconverter(data.variable38));
printf("Variable 39: %f0.2\n",tempconverter(data.variable39));
printf("Variable 40: %f0.2\n",tempconverter(data.variable40));
printf("Variable 41: %f0.2\n",tempconverter(data.variable41));
printf("Variable 42: %f0.2\n",tempconverter(data.variable42));
printf("Variable 43: %f0.2\n",tempconverter(data.variable43));
printf("Variable 44: %f0.2\n",tempconverter(data.variable44));
printf("Variable 45: %f0.2\n",tempconverter(data.variable45));
printf("Variable 46: %f0.2\n",tempconverter(data.variable46));
printf("Variable 47: %f0.2\n",tempconverter(data.variable47));
printf("Variable 48: %f0.2\n",tempconverter(data.variable48));
printf("Variable 49: %f0.2\n",tempconverter(data.variable49));
printf("Variable 50: %f0.2\n",tempconverter(data.variable50));
printf("Variable 51: %f0.2\n",tempconverter(data.variable51));
printf("Variable 52: %f0.2\n",tempconverter(data.variable52));
printf("Variable 53: %f0.2\n",tempconverter(data.variable53));
printf("Variable 54: %f0.2\n",tempconverter(data.variable54));
printf("Variable 55: %f0.2\n",tempconverter(data.variable55));
printf("Variable 56: %f0.2\n",tempconverter(data.variable56));
printf("Variable 57: %f0.2\n",tempconverter(data.variable57));
printf("Variable 58: %f0.2\n",tempconverter(data.variable58));
printf("Variable 59: %f0.2\n",tempconverter(data.variable59));
printf("Variable 60: %f0.2\n",tempconverter(data.variable60));
printf("Variable 61: %f0.2\n",tempconverter(data.variable61));
printf("Variable 62: %f0.2\n",tempconverter(data.variable62));
printf("Variable 63: %f0.2\n",tempconverter(data.variable63));
printf("Variable 64: %f0.2\n",tempconverter(data.variable64));
printf("Variable 65: %f0.2\n",tempconverter(data.variable65));
printf("Variable 66: %f0.2\n",tempconverter(data.variable66));
printf("Variable 67: %f0.2\n",tempconverter(data.variable67));
printf("Variable 68: %f0.2\n",tempconverter(data.variable68));
printf("Variable 69: %f0.2\n",tempconverter(data.variable69));
printf("Variable 70: %f0.2\n",tempconverter(data.variable70));
printf("Variable 71: %f0.2\n",tempconverter(data.variable71));
printf("Variable 72: %f0.2\n",tempconverter(data.variable72));
printf("Variable 73: %f0.2\n",tempconverter(data.variable73));
printf("Variable 74: %f0.2\n",tempconverter(data.variable74));
printf("Variable 75: %f0.2\n",tempconverter(data.variable75));
printf("Variable 76: %f0.2\n",tempconverter(data.variable76));
printf("Variable 77: %f0.2\n",tempconverter(data.variable77));
printf("Variable 78: %f0.2\n",tempconverter(data.variable78));
printf("Variable 79: %f0.2\n",tempconverter(data.variable79));
printf("Variable 80: %f0.2\n",tempconverter(data.variable80));
printf("Variable 81: %f0.2\n",tempconverter(data.variable81));
printf("Variable 82: %f0.2\n",tempconverter(data.variable82));
printf("Variable 83: %f0.2\n",tempconverter(data.variable83));
printf("Variable 84: %f0.2\n",tempconverter(data.variable84));
printf("Variable 85: %f0.2\n",tempconverter(data.variable85));
printf("Variable 86: %f0.2\n",tempconverter(data.variable86));
printf("Variable 87: %f0.2\n",tempconverter(data.variable87));
printf("Variable 88: %f0.2\n",tempconverter(data.variable88));
printf("Variable 89: %f0.2\n",tempconverter(data.variable89));
printf("Variable 90: %f0.2\n",tempconverter(data.variable90));
printf("Variable 91: %f0.2\n",tempconverter(data.variable91));
printf("Variable 92: %f0.2\n",tempconverter(data.variable92));
printf("Variable 93: %f0.2\n",tempconverter(data.variable93));
printf("Variable 94: %f0.2\n",tempconverter(data.variable94));
printf("Variable 95: %f0.2\n",tempconverter(data.variable95));
printf("Variable 96: %f0.2\n",tempconverter(data.variable96));
printf("Variable 97: %f0.2\n",tempconverter(data.variable97));
printf("Variable 98: %f0.2\n",tempconverter(data.variable98));
printf("Variable 99: %f0.2\n",tempconverter(data.variable99));
printf("Variable 100: %f0.2\n",tempconverter(data.variable100));
printf("Variable 101: %f0.2\n",tempconverter(data.variable101));
printf("Variable 102: %f0.2\n",tempconverter(data.variable102));
printf("Variable 103: %f0.2\n",tempconverter(data.variable103));
printf("Variable 104: %f0.2\n",tempconverter(data.variable104));
printf("Variable 105: %f0.2\n",tempconverter(data.variable105));
printf("Variable 106: %f0.2\n",tempconverter(data.variable106));
printf("Variable 107: %f0.2\n",tempconverter(data.variable107));
printf("Variable 108: %f0.2\n",tempconverter(data.variable108));
printf("Variable 109: %f0.2\n",tempconverter(data.variable109));
printf("Variable 110: %f0.2\n",tempconverter(data.variable110));
printf("Variable 111: %f0.2\n",tempconverter(data.variable111));
printf("Variable 112: %f0.2\n",tempconverter(data.variable112));
printf("Variable 113: %f0.2\n",tempconverter(data.variable113));
printf("Variable 114: %f0.2\n",tempconverter(data.variable114));
printf("Variable 115: %f0.2\n",tempconverter(data.variable115));
printf("Variable 116: %f0.2\n",tempconverter(data.variable116));
printf("Variable 117: %f0.2\n",tempconverter(data.variable117));
printf("Variable 118: %f0.2\n",tempconverter(data.variable118));
printf("Variable 119: %f0.2\n",tempconverter(data.variable119));
printf("Variable 120: %f0.2\n",tempconverter(data.variable120));
printf("Variable 121: %f0.2\n",tempconverter(data.variable121));
printf("Variable 122: %f0.2\n",tempconverter(data.variable122));
printf("Variable 123: %f0.2\n",tempconverter(data.variable123));
printf("Variable 124: %f0.2\n",tempconverter(data.variable124));
printf("Variable 125: %f0.2\n",tempconverter(data.variable125));
printf("Variable 126: %f0.2\n",tempconverter(data.variable126));
printf("Variable 127: %f0.2\n",tempconverter(data.variable127));
printf("Variable 128: %f0.2\n",tempconverter(data.variable128));
printf("Variable 129: %f0.2\n",tempconverter(data.variable129));
printf("Variable 130: %f0.2\n",tempconverter(data.variable130));
printf("Variable 131: %f0.2\n",tempconverter(data.variable131));
printf("Variable 132: %f0.2\n",tempconverter(data.variable132));
printf("Variable 133: %f0.2\n",tempconverter(data.variable133));
printf("Variable 134: %f0.2\n",tempconverter(data.variable134));
printf("Variable 135: %f0.2\n",tempconverter(data.variable135));
printf("Variable 136: %f0.2\n",tempconverter(data.variable136));
printf("Variable 137: %f0.2\n",tempconverter(data.variable137));
printf("Variable 138: %f0.2\n",tempconverter(data.variable138));
printf("Variable 139: %f0.2\n",tempconverter(data.variable139));
printf("Variable 140: %f0.2\n",tempconverter(data.variable140));
printf("Variable 141: %f0.2\n",tempconverter(data.variable141));
printf("Variable 142: %f0.2\n",tempconverter(data.variable142));
printf("Variable 143: %f0.2\n",tempconverter(data.variable143));
printf("Variable 144: %f0.2\n",tempconverter(data.variable144));
printf("Variable 145: %f0.2\n",tempconverter(data.variable145));
printf("Variable 146: %f0.2\n",tempconverter(data.variable146));
printf("Variable 147: %f0.2\n",tempconverter(data.variable147));
printf("Variable 148: %f0.2\n",tempconverter(data.variable148));
printf("Variable 149: %f0.2\n",tempconverter(data.variable149));
printf("Variable 150: %f0.2\n",tempconverter(data.variable150));
printf("Variable 151: %f0.2\n",tempconverter(data.variable151));
printf("Variable 152: %f0.2\n",tempconverter(data.variable152));
printf("Variable 153: %f0.2\n",tempconverter(data.variable153));
printf("Variable 154: %f0.2\n",tempconverter(data.variable154));
printf("Variable 155: %f0.2\n",tempconverter(data.variable155));
printf("Variable 156: %f0.2\n",tempconverter(data.variable156));
printf("Variable 157: %f0.2\n",tempconverter(data.variable157));
printf("Variable 158: %f0.2\n",tempconverter(data.variable158));
printf("Variable 159: %f0.2\n",tempconverter(data.variable159));
printf("Variable 160: %f0.2\n",tempconverter(data.variable160));
printf("Variable 161: %f0.2\n",tempconverter(data.variable161));
printf("Variable 162: %f0.2\n",tempconverter(data.variable162));
printf("Variable 163: %f0.2\n",tempconverter(data.variable163));
printf("Variable 164: %f0.2\n",tempconverter(data.variable164));
printf("Variable 165: %f0.2\n",tempconverter(data.variable165));
printf("Variable 166: %f0.2\n",tempconverter(data.variable166));
printf("Variable 167: %f0.2\n",tempconverter(data.variable167));
printf("Variable 168: %f0.2\n",tempconverter(data.variable168));
printf("Variable 169: %f0.2\n",tempconverter(data.variable169));
printf("Variable 170: %f0.2\n",tempconverter(data.variable170));
printf("Variable 171: %f0.2\n",tempconverter(data.variable171));
printf("Variable 172: %f0.2\n",tempconverter(data.variable172));
printf("Variable 173: %f0.2\n",tempconverter(data.variable173));
printf("Variable 174: %f0.2\n",tempconverter(data.variable174));
printf("Variable 175: %f0.2\n",tempconverter(data.variable175));
printf("Variable 176: %f0.2\n",tempconverter(data.variable176));
printf("Variable 177: %f0.2\n",tempconverter(data.variable177));
printf("Variable 178: %f0.2\n",tempconverter(data.variable178));
printf("Variable 179: %f0.2\n",tempconverter(data.variable179));



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