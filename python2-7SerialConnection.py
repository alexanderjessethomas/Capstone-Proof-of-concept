import serial

serialConnection = serial.Serial('/dev/ttyACM0', 9600)

characterEntered = ''

while characterEntered != 'q':
    characterEntered = rawInput("Enter f, b, a, d, or q to quit: ")
    print "Character entered: ", characterEntered

    if characterEntered == 'q':
        break
    
    elif characterEntered == 'f':
        serialConnection.write('f')
        
    elif characterEntered == 'b':
        serialConnection.write('b')
        
    elif characterEntered == 'a':
        serialConnection.write('a')
        
    elif characterEntered == 'd':
        serialConnection.write('d')
