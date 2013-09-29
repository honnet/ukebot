import serial


# Open serial port to listen to the arduino:
try:
    ser = serial.Serial('/dev/ttyACM0', 115200);
except:
    ser = serial.Serial('/dev/ttyACM1', 115200);


STR = 'Enter a string value between 1 and 4 or 0 for auto-mode: '

while True:

    try:
        stringNum = raw_input(STR)
        num = int(stringNum)
    except ValueError:
        continue

    if (num >= 0 and num <= 4):
        ser.write(stringNum)

