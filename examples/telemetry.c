#include "log.h"
#include "vospi.h"
#include "cci.h"
#include "telemetry.h"
#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

/**
 * Main entry point for example.
 *
 * This example enables telemetry data, transfers a single frame then displays the received information.
 */
int main(int argc, char *argv[])
{
  //initialize variables
  double spotmeter_mean;
  double spotmeter_max;
  double spotmeter_min;

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
  log_info("CCI uptime: %d", cci_get_uptime(i2c_fd));
  log_info("CCI telemetry enable state: %d", cci_get_telemetry_enable_state(i2c_fd));
  log_info("CCI telemetry location: %d", cci_get_telemetry_location(i2c_fd));

  //Infinite loop to constantly read temperature
  //while(1){

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
  telemetry_data_t data = parse_telemetry_packet(&(frame.segments[0].packets[2])); //reads A register
  // telemetry_data_t data = parse_telemetry_packet(&(frame.segments[1].packets[0])); //reads B register 
  // telemetry_data_t data = parse_telemetry_packet(&(frame.segments[2].packets[0])); //reads C register

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

  // printf("%lx \n",data);
  
  //C Register
  // spotmeter_mean = (((data.spotmeter_mean_temp/100) - 273.15) * 1.8) + 32;
  // spotmeter_max = (((data.spotmeter_max_temp/100) - 273.15) * 1.8) + 32;
  // spotmeter_min = (((data.spotmeter_min_temp/100) - 273.15) * 1.8) + 32;

  // printf("Gain Mode: %02x \n",data.gain_mode);
  // printf("Effective Gain: %02x \n",data.effective_gain);
  // printf("Temperature Gain Mode Threshold High to Low (°C): %02x \n",data.temp_gain_mode_high_to_low);

  // printf("T-Linear Resolution: %02x \n",data.tlinear_resolution);
  // printf("Spotmeter Mean Temp: %0.2f °F \n",spotmeter_mean);
  // printf("Spotmeter Max Temp: %0.2f °F \n",spotmeter_max);
  // printf("Spotmeter Min Temp: %0.2f °F \n",spotmeter_min);
  // printf("Spotmeter Population: %02x \n",data.spotmeter_population);
  // printf("Spotmeter Start Row: %d \n",data.spotmeter_start_row);
  // printf("Spotmeter Start Column: %d \n",data.spotmeter_start_col);
  // printf("Spotmeter End Row: %d \n",data.spotmeter_end_row);
  // printf("Spotmeter End Column: %d \n",data.spotmeter_end_col);

  printf("Test: %d",data.a);
  printf("Test: %d",data.b);
  printf("Test: %d",data.c);
  printf("Test: %d",data.d);
  printf("Test: %d",data.e);
  printf("Test: %d",data.f);
  printf("Test: %d",data.g);
  printf("Test: %d",data.h);
  printf("Test: %d",data.i);
  printf("Test: %d",data.j);
  printf("Test: %d",data.k);
  printf("Test: %d",data.l);
  printf("Test: %d",data.m);
  printf("Test: %d",data.n);
  printf("Test: %d",data.o);
  printf("Test: %d",data.p);
  printf("Test: %d",data.q);
  printf("Test: %d",data.r);
  printf("Test: %d",data.s);
  printf("Test: %d",data.t);
  printf("Test: %d",data.u);
  printf("Test: %d",data.v);
  printf("Test: %d",data.w);
  printf("Test: %d",data.x);
  printf("Test: %d",data.y);
  printf("Test: %d",data.z);
  printf("Test: %d",data.{);
  printf("Test: %d",data.|);
  printf("Test: %d",data.});
  printf("Test: %d",data.~);
  printf("Test: %d",data.);
  printf("Test: %d",data.);
  printf("Test: %d",data.);
  printf("Test: %d",data.);
  printf("Test: %d",data.);
  printf("Test: %d",data.);
  printf("Test: %d",data.);
  printf("Test: %d",data.);
  printf("Test: %d",data.);
  printf("Test: %d",data.);
  printf("Test: %d",data.);
  printf("Test: %d",data.);
  printf("Test: %d",data.);
  printf("Test: %d",data.);
  printf("Test: %d",data.);
  printf("Test: %d",data.);
  printf("Test: %d",data.);
  printf("Test: %d",data.);
  printf("Test: %d",data.);
  printf("Test: %d",data.);
  printf("Test: %d",data.);
  printf("Test: %d",data.);
  printf("Test: %d",data.);
  printf("Test: %d",data.);
  printf("Test: %d",data.);
  printf("Test: %d",data.);
  printf("Test: %d",data.);
  printf("Test: %d",data.);
  printf("Test: %d",data.);
  printf("Test: %d",data.);
  printf("Test: %d",data.);
  printf("Test: %d",data.);
  printf("Test: %d",data.);
  printf("Test: %d",data. );
  printf("Test: %d",data.¡);
  printf("Test: %d",data.¢);
  printf("Test: %d",data.£);
  printf("Test: %d",data.¤);
  printf("Test: %d",data.¥);
  printf("Test: %d",data.¦);
  printf("Test: %d",data.§);
  printf("Test: %d",data.¨);
  printf("Test: %d",data.©);
  printf("Test: %d",data.ª);
  printf("Test: %d",data.«);
  printf("Test: %d",data.¬);
  printf("Test: %d",data.­);
  printf("Test: %d",data.®);
  printf("Test: %d",data.¯);
  printf("Test: %d",data.°);
  printf("Test: %d",data.±);
  printf("Test: %d",data.²);
  printf("Test: %d",data.³);
  printf("Test: %d",data.´);
  printf("Test: %d",data.µ);
  printf("Test: %d",data.¶);
  printf("Test: %d",data.·);
  printf("Test: %d",data.¸);
  printf("Test: %d",data.¹);
  printf("Test: %d",data.º);
  printf("Test: %d",data.»);
  printf("Test: %d",data.¼);
  printf("Test: %d",data.½);
  printf("Test: %d",data.¾);
  printf("Test: %d",data.¿);
  printf("Test: %d",data.À);
  printf("Test: %d",data.Á);
  printf("Test: %d",data.Â);
  printf("Test: %d",data.Ã);
  printf("Test: %d",data.Ä);
  printf("Test: %d",data.Å);
  printf("Test: %d",data.Æ);
  printf("Test: %d",data.Ç);
  printf("Test: %d",data.È);
  printf("Test: %d",data.É);
  printf("Test: %d",data.Ê);
  printf("Test: %d",data.Ë);
  printf("Test: %d",data.Ì);
  printf("Test: %d",data.Í);
  printf("Test: %d",data.Î);
  printf("Test: %d",data.Ï);
  printf("Test: %d",data.Ð);
  printf("Test: %d",data.Ñ);
  printf("Test: %d",data.Ò);
  printf("Test: %d",data.Ó);
  printf("Test: %d",data.Ô);
  printf("Test: %d",data.Õ);
  printf("Test: %d",data.Ö);
  printf("Test: %d",data.×);
  printf("Test: %d",data.Ø);
  printf("Test: %d",data.Ù);
  printf("Test: %d",data.Ú);
  printf("Test: %d",data.Û);
  printf("Test: %d",data.Ü);
  printf("Test: %d",data.Ý);
  printf("Test: %d",data.Þ);
  printf("Test: %d",data.ß);
  printf("Test: %d",data.à);
  printf("Test: %d",data.á);
  printf("Test: %d",data.â);
  printf("Test: %d",data.ã);
  printf("Test: %d",data.ä);
  printf("Test: %d",data.å);
  printf("Test: %d",data.æ);
  printf("Test: %d",data.ç);
  printf("Test: %d",data.è);
  printf("Test: %d",data.é);
  printf("Test: %d",data.ê);
  printf("Test: %d",data.ë);
  printf("Test: %d",data.ì);
  printf("Test: %d",data.í);
  printf("Test: %d",data.î);
  printf("Test: %d",data.ï);
  printf("Test: %d",data.ð);
  printf("Test: %d",data.ñ);
  printf("Test: %d",data.ò);
  printf("Test: %d",data.ó);
  printf("Test: %d",data.ô);
  printf("Test: %d",data.õ);
  printf("Test: %d",data.ö);
  printf("Test: %d",data.÷);
  printf("Test: %d",data.ø);
  printf("Test: %d",data.ù);
  printf("Test: %d",data.ú);
  printf("Test: %d",data.û);
  printf("Test: %d",data.ü);
  printf("Test: %d",data.ý);
  printf("Test: %d",data.þ);
  printf("Test: %d",data.ÿ);
  printf("Test: %d",data.Ā);
  printf("Test: %d",data.ā);
  printf("Test: %d",data.Ă);
  printf("Test: %d",data.ă);
  printf("Test: %d",data.Ą);
  printf("Test: %d",data.ą);
  printf("Test: %d",data.Ć);
  printf("Test: %d",data.ć);
  printf("Test: %d",data.Ĉ);
  printf("Test: %d",data.ĉ);
  printf("Test: %d",data.Ċ);
  printf("Test: %d",data.ċ);
  printf("Test: %d",data.Č);
  printf("Test: %d",data.č);
  printf("Test: %d",data.Ď);
  printf("Test: %d",data.ď);
  printf("Test: %d",data.Đ);
  printf("Test: %d",data.đ);
  printf("Test: %d",data.Ē);
  printf("Test: %d",data.ē);
  printf("Test: %d",data.Ĕ);






 // }

  // Disable telemetry again to leave the module in a usable state for other examples
  cci_set_telemetry_enable_state(i2c_fd, CCI_TELEMETRY_DISABLED);

  // Close files
  close(spi_fd);
  close(i2c_fd);

  return 0;
  
}
