import serial
import subprocess

with open('COM-Port.txt') as f:
    sername = f.readline().strip()

ser = serial.Serial(sername, 115200, timeout=30)

while True:
    line = ser.readline()
    line = line.decode('utf8').strip()

    sp = line.split(':')
    print(sp)
    pid = subprocess.Popen(sp, shell=True).pid
