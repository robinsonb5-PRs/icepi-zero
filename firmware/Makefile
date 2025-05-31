VERILOG_SOURCES := $(wildcard *.v) $(wildcard *.sv)
OUTPUT := bitstream

all: debug

clean:
	rm -f $(OUTPUT).bit $(OUTPUT).config $(OUTPUT).json

build: clean $(VERILOG_SOURCES)
	yosys -p 'synth_ecp5 -top top -json $(OUTPUT).json' $(VERILOG_SOURCES)
	nextpnr-ecp5 --25k --package CABGA256 --lpf icepi-zero.lpf --json $(OUTPUT).json --textcfg $(OUTPUT).config
	ecppack $(OUTPUT).config $(OUTPUT).bit

debug: build
	openFPGALoader -cft231X --pins=7:3:5:6 $(OUTPUT).bit

install: build
	openFPGALoader -cft231X --pins=7:3:5:6 $(OUTPUT).bit --write-flash

install-bitstream: 
	openFPGALoader -cft231X --pins=7:3:5:6 $(OUTPUT).bit --write-flash

lint:
	verilator --lint-only -Wall -Wno-DECLFILENAME -Wno-WIDTHEXPAND $(VERILOG_SOURCES)

help: 
	echo "Usage: make [option]"
	echo "Options:"
	echo "- install: install to flash"
	echo "- debug: install to chip's temp memory (bitstream lost on power loss)"
	echo "- build: builds the bitstream"
	echo "- clean: delete all temparary files"

.PHONY: build clean install
