#include "log.h"
#include "vospi.h"
#include "cci.h"
#include "telemetry.h"
#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
// #include </usr/include/python3.7/Python.h>

double tempconverter(int tempinkelvin);

int counter;
double pixelarray[19200];

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

  counter = 0;

  for(int j = 0;j<VOSPI_SEGMENTS_PER_FRAME;j++){
    for(int i = 0; i<60;i++){
    telemetry_data_t data = parse_telemetry_packet(&(frame.segments[j].packets[i])); 

    pixelarray[counter] = tempconverter(data.pixel0);
    counter++;
    pixelarray[counter] = tempconverter(data.pixel2);
    counter++;
    pixelarray[counter] = tempconverter(data.pixel4);
    counter++;
    pixelarray[counter] = tempconverter(data.pixel6);
    counter++;
    pixelarray[counter] = tempconverter(data.pixel8);
    counter++;
    pixelarray[counter] = tempconverter(data.pixel10);
    counter++;
    pixelarray[counter] = tempconverter(data.pixel12);
    counter++;
    pixelarray[counter] = tempconverter(data.pixel14);
    counter++;
    pixelarray[counter] = tempconverter(data.pixel16);
    counter++;
    pixelarray[counter] = tempconverter(data.pixel18);
    counter++;
    pixelarray[counter] = tempconverter(data.pixel20);
    counter++;
    pixelarray[counter] = tempconverter(data.pixel22);
    counter++;
    pixelarray[counter] = tempconverter(data.pixel24);
    counter++;
    pixelarray[counter] = tempconverter(data.pixel26);
    counter++;
    pixelarray[counter] = tempconverter(data.pixel28);
    counter++;
    pixelarray[counter] = tempconverter(data.pixel30);
    counter++;
    pixelarray[counter] = tempconverter(data.pixel32);
    counter++;
    pixelarray[counter] = tempconverter(data.pixel34);
    counter++;
    pixelarray[counter] = tempconverter(data.pixel36);
    counter++;
    pixelarray[counter] = tempconverter(data.pixel38);
    counter++;
    pixelarray[counter] = tempconverter(data.pixel40);
    counter++;
    pixelarray[counter] = tempconverter(data.pixel42);
    counter++;
    pixelarray[counter] = tempconverter(data.pixel44);
    counter++;
    pixelarray[counter] = tempconverter(data.pixel46);
    counter++;
    pixelarray[counter] = tempconverter(data.pixel48);
    counter++;
    pixelarray[counter] = tempconverter(data.pixel50);
    counter++;
    pixelarray[counter] = tempconverter(data.pixel52);
    counter++;
    pixelarray[counter] = tempconverter(data.pixel54);
    counter++;
    pixelarray[counter] = tempconverter(data.pixel56);
    counter++;
    pixelarray[counter] = tempconverter(data.pixel58);
    counter++;
    pixelarray[counter] = tempconverter(data.pixel60);
    counter++;
    pixelarray[counter] = tempconverter(data.pixel62);
    counter++;
    pixelarray[counter] = tempconverter(data.pixel64);
    counter++;
    pixelarray[counter] = tempconverter(data.pixel66);
    counter++;
    pixelarray[counter] = tempconverter(data.pixel68);
    counter++;
    pixelarray[counter] = tempconverter(data.pixel70);
    counter++;
    pixelarray[counter] = tempconverter(data.pixel72);
    counter++;
    pixelarray[counter] = tempconverter(data.pixel74);
    counter++;
    pixelarray[counter] = tempconverter(data.pixel76);
    counter++;
    pixelarray[counter] = tempconverter(data.pixel78);
    counter++;
    pixelarray[counter] = tempconverter(data.pixel80);
    counter++;
    pixelarray[counter] = tempconverter(data.pixel82);
    counter++;
    pixelarray[counter] = tempconverter(data.pixel84);
    counter++;
    pixelarray[counter] = tempconverter(data.pixel86);
    counter++;
    pixelarray[counter] = tempconverter(data.pixel88);
    counter++;
    pixelarray[counter] = tempconverter(data.pixel90);
    counter++;
    pixelarray[counter] = tempconverter(data.pixel92);
    counter++;
    pixelarray[counter] = tempconverter(data.pixel94);
    counter++;
    pixelarray[counter] = tempconverter(data.pixel96);
    counter++;
    pixelarray[counter] = tempconverter(data.pixel98);
    counter++;
    pixelarray[counter] = tempconverter(data.pixel100);
    counter++;
    pixelarray[counter] = tempconverter(data.pixel102);
    counter++;
    pixelarray[counter] = tempconverter(data.pixel104);
    counter++;
    pixelarray[counter] = tempconverter(data.pixel106);
    counter++;
    pixelarray[counter] = tempconverter(data.pixel108);
    counter++;
    pixelarray[counter] = tempconverter(data.pixel110);
    counter++;
    pixelarray[counter] = tempconverter(data.pixel112);
    counter++;
    pixelarray[counter] = tempconverter(data.pixel114);
    counter++;
    pixelarray[counter] = tempconverter(data.pixel116);
    counter++;
    pixelarray[counter] = tempconverter(data.pixel118);
    counter++;
    pixelarray[counter] = tempconverter(data.pixel120);
    counter++;
    pixelarray[counter] = tempconverter(data.pixel122);
    counter++;
    pixelarray[counter] = tempconverter(data.pixel124);
    counter++;
    pixelarray[counter] = tempconverter(data.pixel126);
    counter++;
    pixelarray[counter] = tempconverter(data.pixel128);
    counter++;
    pixelarray[counter] = tempconverter(data.pixel130);
    counter++;
    pixelarray[counter] = tempconverter(data.pixel132);
    counter++;
    pixelarray[counter] = tempconverter(data.pixel134);
    counter++;
    pixelarray[counter] = tempconverter(data.pixel136);
    counter++;
    pixelarray[counter] = tempconverter(data.pixel138);
    counter++;
    pixelarray[counter] = tempconverter(data.pixel140);
    counter++;
    pixelarray[counter] = tempconverter(data.pixel142);
    counter++;
    pixelarray[counter] = tempconverter(data.pixel144);
    counter++;
    pixelarray[counter] = tempconverter(data.pixel146);
    counter++;
    pixelarray[counter] = tempconverter(data.pixel148);
    counter++;
    pixelarray[counter] = tempconverter(data.pixel150);
    counter++;
    pixelarray[counter] = tempconverter(data.pixel152);
    counter++;
    pixelarray[counter] = tempconverter(data.pixel154);
    counter++;
    pixelarray[counter] = tempconverter(data.pixel156);
    counter++;
    pixelarray[counter] = tempconverter(data.pixel158);
    counter++;
    }
  }

   datatransfer(&pixelarray);

  char filename[]="output.txt";
  FILE *fp = fopen(filename, "w");
  for(int i = 0; i < 19200; i++)
  {
      fprintf(fp, "%0.2f\n ", pixelarray[i]);
  }
  fclose(fp);

  

  // Py_Initialize();
  // PyRun_SimpleString("import sys");
  // PyRun_SimpleString("sys.path.append('/home/pi/ThermalRead/leptonic/bin/examples')");
  // PyObject *mod = PyImport_ImportModule("test");
  // PyObject *var1Py = PyObject_GetAttrString(mod, "x");
  // int x = PyLong_AsLong(var1Py);
  // printf("var1=%d ; var1==NULL: %d\n", x, var1Py==NULL);
  // Py_XDECREF(var1Py);
  // Py_Finalize();

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

double datatransfer(double *data){
  return data;
}