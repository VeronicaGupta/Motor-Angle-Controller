import serial
import time
import sys
from PySide2.QtWidgets import *
from PySide2.QtGui import *

ser= serial.Serial('com9', 9600)
app = QApplication(sys.argv)

win = QWidget()
win.setWindowTitle("Motor Controller")

l1 = QLabel()
l1.setText("Enter the degrees: ")
l1.setFont(QFont("Arial", 24))

e1 = QLineEdit()
e1.setFont(QFont("Arial", 20))

def Motor_Angle():
    val= e1.text()
    ser.write(val.encode())
    time.sleep(5)
    a = ser.readline().strip()
    print("Sensed Angle", a.decode())
    app.exit()

button = QPushButton("ENTER")
button.clicked.connect(Motor_Angle)

layout = QVBoxLayout()
layout.addWidget(l1)
layout.addWidget(e1)
layout.addWidget(button)

win.setLayout(layout)

win.show()

sys.exit(app.exec_())
