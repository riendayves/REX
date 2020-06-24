import serial
from serial.tools import list_ports

# Get list of available ports
availablePorts = list_ports.comports()

# Print list by name
portNumber = 0
for port in availablePorts:
     print(portNumber, port.device)
     portNumber += 1

# Connect to the port we want
ser = serial.Serial(availablePorts[2].device, 9600)
while True:
     print(str(ser.read(5)))
     ser.flush()

