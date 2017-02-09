import smbus
import time

bus = smbus.SMBus(1)

SLAVE_ADDRESS = 0x21

def setLED0(SLAVE_ADDRESS):
        cmd = "F" #First
        message = raw_input("Enter 000 - 255 for LED0 ")
        sendMessage(SLAVE_ADDRESS, cmd, message)
        print("LED0 value: " + message)

def setLED1(SLAVE_ADDRESS):
        cmd = "S" #Second
        message = raw_input("Enter 000 - 255 for LED1 ")
        sendMessage(SLAVE_ADDRESS, cmd, message)
        print("LED1 value: " + message)

def StringToBytes(val):
        retVal = []
        for c in val:
                retVal.append(ord(c))
        return retVal

def sendMessage(SLAVE_ADDRESS, cmd, message):
        cmd = cmd.upper()
        message = message.upper()
        valCmd = ord(cmd)
        valMessage = StringToBytes(message)
        print("Message: " + cmd + message + " send to device " + str(SLAVE_ADDRESS))
        bus.write_i2c_block_data(SLAVE_ADDRESS, valCmd, valMessage)
        time.sleep(1)


while True:
        setLED0(SLAVE_ADDRESS)
        setLED1(SLAVE_ADDRESS)

