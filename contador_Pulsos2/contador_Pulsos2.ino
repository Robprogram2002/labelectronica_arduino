int measure = 2;
int prevMeasure = 0;
unsigned long startTime;
unsigned long currentTime;
const unsigned long period = 10000;
int counter = 0;

void setup() {
  Serial.begin(9600);
  pinMode(measure, INPUT);
  startTime = millis();  //initial start time
}

void loop() {
  currentTime = millis();

  if (currentTime - startTime < period)  
  {
    if(digitalRead(measure) == 1) {
      counter += 1;
      delay(18);
    };
  } else {
    Serial.println(counter);
    counter = 0;
    startTime = currentTime;
  }

  // if (currentTime - startTime < period)  
  // {
  //   if(digitalRead(measure) != prevMeasure) {
  //     counter += 1;
  //     prevMeasure = measure;
  //   };
  // } else {
  //   Serial.println(counter);
  //   counter = 0;
  //   startTime = currentTime;
  // }

}
