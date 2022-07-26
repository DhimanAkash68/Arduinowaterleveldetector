// Sensor pins
#define sensorPower 7 //light check(vcc) sensor kaj kore kina check kora
#define sensorPin A0  //connected with senson s pin
#define check 5
#define level1 250  // will change later
#define level2 500  // will change later
#define level3 1000 // will change later
#define out1 2
#define out2 4
#define out3 6


// Value for storing water level
int val = 0;

void setup() {
  // Set D7 as an OUTPUT
  pinMode(sensorPower, OUTPUT);
  
  // Set to LOW so no power flows through the sensor
  digitalWrite(sensorPower, LOW);
  digitalWrite(check,LOW);
  
  Serial.begin(9600);
}

void loop() {
  //get the reading from the function below and print it
  int level =getValue();
  
  Serial.print("Water level: ");
  Serial.println(level);

  //if(level>100){
  //    digitalWrite(check,HIGH);
  //    delay(2000);
  //    digitalWrite(check,LOW);
 //  }

  if(level<=level1)function1(); 
  else if(level<=level2)function2();
  else function3();//
  
  delay(1000);
}

//This is a function used to get the reading
int getValue() {
  digitalWrite(sensorPower, HIGH);  // Turn the sensor ON
  delay(100);              // wait 10 milliseconds
  val = analogRead(sensorPin);    // Read the analog value form sensor
  digitalWrite(sensorPower, LOW);   // Turn the sensor OFF
  return val;             // send current reading
}

void function1(){ // for low water level
   Serial.print("Low level: ");
   digitalWrite(out1,HIGH);
   digitalWrite(out2,LOW);
   digitalWrite(out3,LOW);
  
}
void function2(){ 
  digitalWrite(out2,HIGH);
   digitalWrite(out1,LOW);
   digitalWrite(out3,LOW);
}
void function3(){  //for high water level
   digitalWrite(out3,HIGH);
   digitalWrite(out2,LOW);
   digitalWrite(out1,LOW);
}
