Light light1(13, "test")
//
void setup() {
  light1.turnOn();
}

void loop() {
  light1.enterFrame();
}

//--(light class)---------------------------------
class Light(aPin, aName) {
  public:
    Light(int aPin, char aName);
    turnOn();
    enterFrame();
  private:
    int pPin;
    char pName;
    int pMaxTime;
    int pTimeLeft;
    bool pState;
    bool pLastState;
};

Light::Light(int aPin, char aName) {

  pMaxTime = 5000;
  pTimeLeft = 0;
  pState = false;
  //
  pPin = aPin;
  pName = aName;
  pinMode(pPin, OUTPUT);
}
//
void Light::turnOn() {
  pState = true;
  pTimeLeft = pMaxTime;
  digitalWrite(pPin, HIGH);
  Serial.print(pName);
  Serial.println(" ON");
  return;
}
//
void Light::enterFrame() {
  if (pState) {
    pTimeLeft--;
    if (pTimeLeft == 0) {
      pState = false;
      digitalWrite(pPin, LOW);
      Serial.print(pName);
      Serial.println(" OFF");
    }
  }
  return;
}

