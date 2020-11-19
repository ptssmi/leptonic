.PHONY: examples clean

# Headers
API_INCLUDES = -Iinclude/api

# Sources
API_SOURCES = $(wildcard src/api/*.c)

CC = gcc
CFLAGS = -g -DLOG_USE_COLOR=1 -Wall

main:
	@mkdir -p bin/main/
	$(CC) $(CFLAGS) $(API_INCLUDES) ${API_SOURCES} main/telemetry.c -o bin/main/telemetry
clean:
	@rm -f *.o
	@rm leptonic
