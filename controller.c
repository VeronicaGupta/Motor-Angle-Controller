int SENSOR_B=2;
int motor=5;
int encoderCounter;
int counter;
int encoder_angle;
int c;
int sensed_angle=0;
int Max_count= 100;
void encoderIncrementISR()
{
  counter++;
}

void setup() {
 
Serial.begin(9600);
pinMode(SENSOR_B, INPUT_PULLUP);
pinMode(motor, OUTPUT);

attachInterrupt(digitalPinToInterrupt(SENSOR_B), encoderIncrementISR, CHANGE);
}

void loop() {
//Serial.print(sensed_angle, DEC);
counter=0;
encoder_angle= 0;

if(Serial.available()>0)
{

encoder_angle = Serial.readString().toInt();

//Serial.print("MOTOR ANGLE: ");
//encoder_angle = (encoder_angle, DEC);
Serial.print("\t");
encoderCounter = map(encoder_angle, 0, 360, 0, Max_count);

//Serial.print("ENCODER COUNTER: ");
//encoderCounter = (encoderCounter, DEC);
//Serial.print("\n");
delay(3000);

while(counter <= encoderCounter)
{
  digitalWrite(motor, HIGH);
  c = counter;
} 

sensed_angle = map(c, 0, Max_count , 0, 360);
digitalWrite(motor, LOW);
Serial.print(sensed_angle, DEC);
Serial.print("\n");
delay(2000);
}
}
