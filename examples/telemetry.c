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

 printf("Variable 0: %d",tempconverter(data.variable0));
printf("Variable 1: %d",tempconverter(data.variable1));
printf("Variable 2: %d",tempconverter(data.variable2));
printf("Variable 3: %d",tempconverter(data.variable3));
printf("Variable 4: %d",tempconverter(data.variable4));
printf("Variable 5: %d",tempconverter(data.variable5));
printf("Variable 6: %d",tempconverter(data.variable6));
printf("Variable 7: %d",tempconverter(data.variable7));
printf("Variable 8: %d",tempconverter(data.variable8));
printf("Variable 9: %d",tempconverter(data.variable9));
printf("Variable 10: %d",tempconverter(data.variable10));
printf("Variable 11: %d",tempconverter(data.variable11));
printf("Variable 12: %d",tempconverter(data.variable12));
printf("Variable 13: %d",tempconverter(data.variable13));
printf("Variable 14: %d",tempconverter(data.variable14));
printf("Variable 15: %d",tempconverter(data.variable15));
printf("Variable 16: %d",tempconverter(data.variable16));
printf("Variable 17: %d",tempconverter(data.variable17));
printf("Variable 18: %d",tempconverter(data.variable18));
printf("Variable 19: %d",tempconverter(data.variable19));
printf("Variable 20: %d",tempconverter(data.variable20));
printf("Variable 21: %d",tempconverter(data.variable21));
printf("Variable 22: %d",tempconverter(data.variable22));
printf("Variable 23: %d",tempconverter(data.variable23));
printf("Variable 24: %d",tempconverter(data.variable24));
printf("Variable 25: %d",tempconverter(data.variable25));
printf("Variable 26: %d",tempconverter(data.variable26));
printf("Variable 27: %d",tempconverter(data.variable27));
printf("Variable 28: %d",tempconverter(data.variable28));
printf("Variable 29: %d",tempconverter(data.variable29));
printf("Variable 30: %d",tempconverter(data.variable30));
printf("Variable 31: %d",tempconverter(data.variable31));
printf("Variable 32: %d",tempconverter(data.variable32));
printf("Variable 33: %d",tempconverter(data.variable33));
printf("Variable 34: %d",tempconverter(data.variable34));
printf("Variable 35: %d",tempconverter(data.variable35));
printf("Variable 36: %d",tempconverter(data.variable36));
printf("Variable 37: %d",tempconverter(data.variable37));
printf("Variable 38: %d",tempconverter(data.variable38));
printf("Variable 39: %d",tempconverter(data.variable39));
printf("Variable 40: %d",tempconverter(data.variable40));
printf("Variable 41: %d",tempconverter(data.variable41));
printf("Variable 42: %d",tempconverter(data.variable42));
printf("Variable 43: %d",tempconverter(data.variable43));
printf("Variable 44: %d",tempconverter(data.variable44));
printf("Variable 45: %d",tempconverter(data.variable45));
printf("Variable 46: %d",tempconverter(data.variable46));
printf("Variable 47: %d",tempconverter(data.variable47));
printf("Variable 48: %d",tempconverter(data.variable48));
printf("Variable 49: %d",tempconverter(data.variable49));
printf("Variable 50: %d",tempconverter(data.variable50));
printf("Variable 51: %d",tempconverter(data.variable51));
printf("Variable 52: %d",tempconverter(data.variable52));
printf("Variable 53: %d",tempconverter(data.variable53));
printf("Variable 54: %d",tempconverter(data.variable54));
printf("Variable 55: %d",tempconverter(data.variable55));
printf("Variable 56: %d",tempconverter(data.variable56));
printf("Variable 57: %d",tempconverter(data.variable57));
printf("Variable 58: %d",tempconverter(data.variable58));
printf("Variable 59: %d",tempconverter(data.variable59));
printf("Variable 60: %d",tempconverter(data.variable60));
printf("Variable 61: %d",tempconverter(data.variable61));
printf("Variable 62: %d",tempconverter(data.variable62));
printf("Variable 63: %d",tempconverter(data.variable63));
printf("Variable 64: %d",tempconverter(data.variable64));
printf("Variable 65: %d",tempconverter(data.variable65));
printf("Variable 66: %d",tempconverter(data.variable66));
printf("Variable 67: %d",tempconverter(data.variable67));
printf("Variable 68: %d",tempconverter(data.variable68));
printf("Variable 69: %d",tempconverter(data.variable69));
printf("Variable 70: %d",tempconverter(data.variable70));
printf("Variable 71: %d",tempconverter(data.variable71));
printf("Variable 72: %d",tempconverter(data.variable72));
printf("Variable 73: %d",tempconverter(data.variable73));
printf("Variable 74: %d",tempconverter(data.variable74));
printf("Variable 75: %d",tempconverter(data.variable75));
printf("Variable 76: %d",tempconverter(data.variable76));
printf("Variable 77: %d",tempconverter(data.variable77));
printf("Variable 78: %d",tempconverter(data.variable78));
printf("Variable 79: %d",tempconverter(data.variable79));
printf("Variable 80: %d",tempconverter(data.variable80));
printf("Variable 81: %d",tempconverter(data.variable81));
printf("Variable 82: %d",tempconverter(data.variable82));
printf("Variable 83: %d",tempconverter(data.variable83));
printf("Variable 84: %d",tempconverter(data.variable84));
printf("Variable 85: %d",tempconverter(data.variable85));
printf("Variable 86: %d",tempconverter(data.variable86));
printf("Variable 87: %d",tempconverter(data.variable87));
printf("Variable 88: %d",tempconverter(data.variable88));
printf("Variable 89: %d",tempconverter(data.variable89));
printf("Variable 90: %d",tempconverter(data.variable90));
printf("Variable 91: %d",tempconverter(data.variable91));
printf("Variable 92: %d",tempconverter(data.variable92));
printf("Variable 93: %d",tempconverter(data.variable93));
printf("Variable 94: %d",tempconverter(data.variable94));
printf("Variable 95: %d",tempconverter(data.variable95));
printf("Variable 96: %d",tempconverter(data.variable96));
printf("Variable 97: %d",tempconverter(data.variable97));
printf("Variable 98: %d",tempconverter(data.variable98));
printf("Variable 99: %d",tempconverter(data.variable99));
printf("Variable 100: %d",tempconverter(data.variable100));
printf("Variable 101: %d",tempconverter(data.variable101));
printf("Variable 102: %d",tempconverter(data.variable102));
printf("Variable 103: %d",tempconverter(data.variable103));
printf("Variable 104: %d",tempconverter(data.variable104));
printf("Variable 105: %d",tempconverter(data.variable105));
printf("Variable 106: %d",tempconverter(data.variable106));
printf("Variable 107: %d",tempconverter(data.variable107));
printf("Variable 108: %d",tempconverter(data.variable108));
printf("Variable 109: %d",tempconverter(data.variable109));
printf("Variable 110: %d",tempconverter(data.variable110));
printf("Variable 111: %d",tempconverter(data.variable111));
printf("Variable 112: %d",tempconverter(data.variable112));
printf("Variable 113: %d",tempconverter(data.variable113));
printf("Variable 114: %d",tempconverter(data.variable114));
printf("Variable 115: %d",tempconverter(data.variable115));
printf("Variable 116: %d",tempconverter(data.variable116));
printf("Variable 117: %d",tempconverter(data.variable117));
printf("Variable 118: %d",tempconverter(data.variable118));
printf("Variable 119: %d",tempconverter(data.variable119));
printf("Variable 120: %d",tempconverter(data.variable120));
printf("Variable 121: %d",tempconverter(data.variable121));
printf("Variable 122: %d",tempconverter(data.variable122));
printf("Variable 123: %d",tempconverter(data.variable123));
printf("Variable 124: %d",tempconverter(data.variable124));
printf("Variable 125: %d",tempconverter(data.variable125));
printf("Variable 126: %d",tempconverter(data.variable126));
printf("Variable 127: %d",tempconverter(data.variable127));
printf("Variable 128: %d",tempconverter(data.variable128));
printf("Variable 129: %d",tempconverter(data.variable129));
printf("Variable 130: %d",tempconverter(data.variable130));
printf("Variable 131: %d",tempconverter(data.variable131));
printf("Variable 132: %d",tempconverter(data.variable132));
printf("Variable 133: %d",tempconverter(data.variable133));
printf("Variable 134: %d",tempconverter(data.variable134));
printf("Variable 135: %d",tempconverter(data.variable135));
printf("Variable 136: %d",tempconverter(data.variable136));
printf("Variable 137: %d",tempconverter(data.variable137));
printf("Variable 138: %d",tempconverter(data.variable138));
printf("Variable 139: %d",tempconverter(data.variable139));
printf("Variable 140: %d",tempconverter(data.variable140));
printf("Variable 141: %d",tempconverter(data.variable141));
printf("Variable 142: %d",tempconverter(data.variable142));
printf("Variable 143: %d",tempconverter(data.variable143));
printf("Variable 144: %d",tempconverter(data.variable144));
printf("Variable 145: %d",tempconverter(data.variable145));
printf("Variable 146: %d",tempconverter(data.variable146));
printf("Variable 147: %d",tempconverter(data.variable147));
printf("Variable 148: %d",tempconverter(data.variable148));
printf("Variable 149: %d",tempconverter(data.variable149));
printf("Variable 150: %d",tempconverter(data.variable150));
printf("Variable 151: %d",tempconverter(data.variable151));
printf("Variable 152: %d",tempconverter(data.variable152));
printf("Variable 153: %d",tempconverter(data.variable153));
printf("Variable 154: %d",tempconverter(data.variable154));
printf("Variable 155: %d",tempconverter(data.variable155));
printf("Variable 156: %d",tempconverter(data.variable156));
printf("Variable 157: %d",tempconverter(data.variable157));
printf("Variable 158: %d",tempconverter(data.variable158));
printf("Variable 159: %d",tempconverter(data.variable159));
printf("Variable 160: %d",tempconverter(data.variable160));
printf("Variable 161: %d",tempconverter(data.variable161));
printf("Variable 162: %d",tempconverter(data.variable162));
printf("Variable 163: %d",tempconverter(data.variable163));
printf("Variable 164: %d",tempconverter(data.variable164));
printf("Variable 165: %d",tempconverter(data.variable165));
printf("Variable 166: %d",tempconverter(data.variable166));
printf("Variable 167: %d",tempconverter(data.variable167));
printf("Variable 168: %d",tempconverter(data.variable168));
printf("Variable 169: %d",tempconverter(data.variable169));
printf("Variable 170: %d",tempconverter(data.variable170));
printf("Variable 171: %d",tempconverter(data.variable171));
printf("Variable 172: %d",tempconverter(data.variable172));
printf("Variable 173: %d",tempconverter(data.variable173));
printf("Variable 174: %d",tempconverter(data.variable174));
printf("Variable 175: %d",tempconverter(data.variable175));
printf("Variable 176: %d",tempconverter(data.variable176));
printf("Variable 177: %d",tempconverter(data.variable177));
printf("Variable 178: %d",tempconverter(data.variable178));
printf("Variable 179: %d",tempconverter(data.variable179));


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