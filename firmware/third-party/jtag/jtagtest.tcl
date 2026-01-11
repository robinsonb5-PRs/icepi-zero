init

# ECP5 has two IR scan codes available for user application - 0x32, and 0x38.

set USER1 0x32
set USER2 0x38


# The demo design attaches the IcePi-Zero's LEDs to the first IR code,
# and shifts in a fixed value of 0x15 (5'b10101) which can be used for
# identification

proc led { v } {
	global USER1
	irscan target.tap $USER1
	set v [drscan target.tap 5 $v]
	if {$v != 15} {
		puts ""
		puts "Unexpected response - is the JTAG demo design configured in the FPGA?"
		puts "(Got $v, expected 15)"
		exit
	}
}


# The demo design attaches a freerunning counter to the second IR code

proc readcounter { } {
	global USER2
	irscan target.tap $USER2
	set v [drscan target.tap 32 0]
	return $v
} 

# Write the values 1 through 32 to the LED register, and print the
# contents of the freerunning counter once per iteration

for {set i 1} {$i < 33} {incr i} {
	led $i
	puts [readcounter]
	after 100
}

exit

