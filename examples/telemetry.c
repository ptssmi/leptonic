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
  cci_set_telemetry_enable_state(i2c_fd, CCI_TELEMETRY_DISABLED);
  //cci_set_telemetry_location(i2c_fd, CCI_TELEMETRY_LOCATION_HEADER);

  //cci_set_spotmeter_coordinates(i2c_fd,startrow,endrow,startcol,endcol);

  //log_info("CCI uptime: %d \n", cci_get_uptime(i2c_fd));
  //log_info("CCI telemetry enable state: %d \n", cci_get_telemetry_enable_state(i2c_fd));
  //log_info("CCI telemetry location: %d \n", cci_get_telemetry_location(i2c_fd));
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
  // telemetry_data_t data = parse_telemetry_packet(&(frame.segments[0].packets[3])); //reads C register
  for(int j = 0 j<VOSPI_SEGMENTS_PER_FRAME;j++){
    for(int i = 0; i<60;i++){
    telemetry_data_t data = parse_telemetry_packet(&(frame.segments[j].packets[i])); 

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
    // printf("Spotmeter Mean Temp: %0.2f\n\n °F \n",tempconverter(data.spotmeter_mean_temp));
    // printf("Spotmeter Max Temp: %0.2f\n\n °F \n",tempconverter(data.spotmeter_max_temp));
    // printf("Spotmeter Min Temp: %0.2f\n\n °F \n",tempconverter(data.spotmeter_min_temp));
    // printf("Spotmeter Population: %d \n \n",data.spotmeter_population);
    //printf("Spotmeter Start Row: %d \n \n",data.spotmeter_start_row);
    // printf("Spotmeter Start Column: %d \n \n",data.spotmeter_start_col);
    // printf("Spotmeter End Row: %d \n \n",data.spotmeter_end_row);
    // printf("Spotmeter End Column: %d \n \n",data.spotmeter_end_col);

    printf("Pixel 0: %0.2f",tempconverter(data.pixel0));
    printf("Pixel 2: %0.2f",tempconverter(data.pixel2));
    printf("Pixel 4: %0.2f",tempconverter(data.pixel4));
    printf("Pixel 6: %0.2f",tempconverter(data.pixel6));
    printf("Pixel 8: %0.2f",tempconverter(data.pixel8));
    printf("Pixel 10: %0.2f",tempconverter(data.pixel10));
    printf("Pixel 12: %0.2f",tempconverter(data.pixel12));
    printf("Pixel 14: %0.2f",tempconverter(data.pixel14));
    printf("Pixel 16: %0.2f",tempconverter(data.pixel16));
    printf("Pixel 18: %0.2f",tempconverter(data.pixel18));
    printf("Pixel 20: %0.2f",tempconverter(data.pixel20));
    printf("Pixel 22: %0.2f",tempconverter(data.pixel22));
    printf("Pixel 24: %0.2f",tempconverter(data.pixel24));
    printf("Pixel 26: %0.2f",tempconverter(data.pixel26));
    printf("Pixel 28: %0.2f",tempconverter(data.pixel28));
    printf("Pixel 30: %0.2f",tempconverter(data.pixel30));
    printf("Pixel 32: %0.2f",tempconverter(data.pixel32));
    printf("Pixel 34: %0.2f",tempconverter(data.pixel34));
    printf("Pixel 36: %0.2f",tempconverter(data.pixel36));
    printf("Pixel 38: %0.2f",tempconverter(data.pixel38));
    printf("Pixel 40: %0.2f",tempconverter(data.pixel40));
    printf("Pixel 42: %0.2f",tempconverter(data.pixel42));
    printf("Pixel 44: %0.2f",tempconverter(data.pixel44));
    printf("Pixel 46: %0.2f",tempconverter(data.pixel46));
    printf("Pixel 48: %0.2f",tempconverter(data.pixel48));
    printf("Pixel 50: %0.2f",tempconverter(data.pixel50));
    printf("Pixel 52: %0.2f",tempconverter(data.pixel52));
    printf("Pixel 54: %0.2f",tempconverter(data.pixel54));
    printf("Pixel 56: %0.2f",tempconverter(data.pixel56));
    printf("Pixel 58: %0.2f",tempconverter(data.pixel58));
    printf("Pixel 60: %0.2f",tempconverter(data.pixel60));
    printf("Pixel 62: %0.2f",tempconverter(data.pixel62));
    printf("Pixel 64: %0.2f",tempconverter(data.pixel64));
    printf("Pixel 66: %0.2f",tempconverter(data.pixel66));
    printf("Pixel 68: %0.2f",tempconverter(data.pixel68));
    printf("Pixel 70: %0.2f",tempconverter(data.pixel70));
    printf("Pixel 72: %0.2f",tempconverter(data.pixel72));
    printf("Pixel 74: %0.2f",tempconverter(data.pixel74));
    printf("Pixel 76: %0.2f",tempconverter(data.pixel76));
    printf("Pixel 78: %0.2f",tempconverter(data.pixel78));
    printf("Pixel 80: %0.2f",tempconverter(data.pixel80));
    printf("Pixel 82: %0.2f",tempconverter(data.pixel82));
    printf("Pixel 84: %0.2f",tempconverter(data.pixel84));
    printf("Pixel 86: %0.2f",tempconverter(data.pixel86));
    printf("Pixel 88: %0.2f",tempconverter(data.pixel88));
    printf("Pixel 90: %0.2f",tempconverter(data.pixel90));
    printf("Pixel 92: %0.2f",tempconverter(data.pixel92));
    printf("Pixel 94: %0.2f",tempconverter(data.pixel94));
    printf("Pixel 96: %0.2f",tempconverter(data.pixel96));
    printf("Pixel 98: %0.2f",tempconverter(data.pixel98));
    printf("Pixel 100: %0.2f",tempconverter(data.pixel100));
    printf("Pixel 102: %0.2f",tempconverter(data.pixel102));
    printf("Pixel 104: %0.2f",tempconverter(data.pixel104));
    printf("Pixel 106: %0.2f",tempconverter(data.pixel106));
    printf("Pixel 108: %0.2f",tempconverter(data.pixel108));
    printf("Pixel 110: %0.2f",tempconverter(data.pixel110));
    printf("Pixel 112: %0.2f",tempconverter(data.pixel112));
    printf("Pixel 114: %0.2f",tempconverter(data.pixel114));
    printf("Pixel 116: %0.2f",tempconverter(data.pixel116));
    printf("Pixel 118: %0.2f",tempconverter(data.pixel118));
    printf("Pixel 120: %0.2f",tempconverter(data.pixel120));
    printf("Pixel 122: %0.2f",tempconverter(data.pixel122));
    printf("Pixel 124: %0.2f",tempconverter(data.pixel124));
    printf("Pixel 126: %0.2f",tempconverter(data.pixel126));
    printf("Pixel 128: %0.2f",tempconverter(data.pixel128));
    printf("Pixel 130: %0.2f",tempconverter(data.pixel130));
    printf("Pixel 132: %0.2f",tempconverter(data.pixel132));
    printf("Pixel 134: %0.2f",tempconverter(data.pixel134));
    printf("Pixel 136: %0.2f",tempconverter(data.pixel136));
    printf("Pixel 138: %0.2f",tempconverter(data.pixel138));
    printf("Pixel 140: %0.2f",tempconverter(data.pixel140));
    printf("Pixel 142: %0.2f",tempconverter(data.pixel142));
    printf("Pixel 144: %0.2f",tempconverter(data.pixel144));
    printf("Pixel 146: %0.2f",tempconverter(data.pixel146));
    printf("Pixel 148: %0.2f",tempconverter(data.pixel148));
    printf("Pixel 150: %0.2f",tempconverter(data.pixel150));
    printf("Pixel 152: %0.2f",tempconverter(data.pixel152));
    printf("Pixel 154: %0.2f",tempconverter(data.pixel154));
    printf("Pixel 156: %0.2f",tempconverter(data.pixel156));
    printf("Pixel 158: %0.2f",tempconverter(data.pixel158));

    }
  }



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