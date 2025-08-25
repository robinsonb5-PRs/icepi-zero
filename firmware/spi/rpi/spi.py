import board
import busio
import digitalio

cs = digitalio.DigitalInOut(board.D25)
cs.direction = digitalio.Direction.OUTPUT
cs.value = True

spi = busio.SPI(board.SCK, MISO=board.MISO, MOSI=board.MOSI)
while not spi.try_lock():
    pass

spi.configure(baudrate=3000000, phase=0, polarity=0)

cs.value = False

result = bytearray(1)
spi.readinto(result)

spi.write(result)

cs.value = True

