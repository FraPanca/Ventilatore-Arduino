#define MOTOR 11
#define BUTTON 12

int bcd[] = {2, 3, 4, 5, 6, 7, 8};


int val, pwm, num, bcdhl[7];

bool on = false;


void setSpeed(int speed) {
  if(on) analogWrite(MOTOR, speed);
}

void decodeBcd(int num) {
  for(int i=0; i<7; i++) bcdhl[i] = HIGH;

  switch(num) {
    case 0:
      bcdhl[0] = LOW;
      break;
    
    case 1:
      bcdhl[0] = LOW;
      bcdhl[1] = LOW;
      bcdhl[2] = LOW;
      bcdhl[4] = LOW;
      bcdhl[5] = LOW;
      break;
    
    case 2:
      bcdhl[1] = LOW;
      bcdhl[6] = LOW;
      break;
    
    case 3:
      bcdhl[1] = LOW;
      bcdhl[4] = LOW;
      break;

    case 4:
      bcdhl[2] = LOW;
      bcdhl[4] = LOW;
      bcdhl[5] = LOW;
      break;

    case 5:
      bcdhl[3] = LOW;
      bcdhl[4] = LOW;
      break;

    case 6:
      bcdhl[3] = LOW;
      break;

    case 7:
      bcdhl[0] = LOW;
      bcdhl[1] = LOW;
      bcdhl[4] = LOW;
      bcdhl[5] = LOW;
      break;

    case 9:
      bcdhl[4] = LOW;
      break;
  }
}

void displayNum(int num) {
  if(!on) num = 0;

  decodeBcd(num);
  for(int i=0; i<7; i++) {
    digitalWrite(bcd[i], bcdhl[i]);
  }
}
 

void setup() { 
  Serial.begin(9600);

  pinMode(BUTTON, INPUT);
  pinMode(A0, INPUT);

  pinMode(MOTOR, OUTPUT);

  for(int i=0; i<7; i++) {
    pinMode(bcd[i], OUTPUT);
  }

  displayNum(num);
} 
 
 
void loop() {

  val = analogRead(A0);
  
  pwm = map(val, 0, 1023, 0, 255);
  num = map(pwm, 0, 255, 0, 9);


  if(digitalRead(BUTTON) == HIGH) {
    while(digitalRead(BUTTON) == HIGH);

    on = (on) ? false : true;

    if(!on) analogWrite(MOTOR, 0);
  }

  setSpeed(pwm);
  displayNum(num);

  delay(100);
} 