import serial
import pydirectinput

# Set the serial port and baud rate for communication with the Arduino board
ser = serial.Serial('COM3', 9600)

while True:
    # Read the input from the Arduino board
    input_str = ser.readline().decode().rstrip()

    # If the input is "press1", emulate the "Z" key press
    if input_str == "press1":
        pydirectinput.keyDown('z')
        ser.write(b'pressed1\n')

    # If the input is "release1", emulate the "Z" key release
    elif input_str == "release1":
        pydirectinput.keyUp('z')
        ser.write(b'released1\n')

    # If the input is "press2", emulate the "X" key press
    elif input_str == "press2":
        pydirectinput.keyDown('x')
        ser.write(b'pressed2\n')

    # If the input is "release2", emulate the "X" key release
    elif input_str == "release2":
        pydirectinput.keyUp('x')
        ser.write(b'released2\n')