const char ADDR[] = {2, 3, 4, 5, 6, 7, 8, 9};
#define CSW 51

void setup() {
  // put your setup code here, to run once:
  for (int i = 0 ; i <= 7 ; i++) {
    pinMode(ADDR[i], OUTPUT);
  }
  pinMode(CSW, OUTPUT);
  digitalWrite(CSW, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0x01; i<= 0x0f ; i++) {
    writeRegister(i, 7);
    delay(2500);
  }
}

void writeRegister(char cb, char reg) {
  writeByte(cb);
  writeByte(0x80 | reg);
}

void writeByte(char v) {
  for (int i = 0 ; i < 8 ; i++) {
    digitalWrite(ADDR[i], v & 0x01);
    v >>= 1;
  }
  digitalWrite(CSW, LOW);
  delay(1);
  digitalWrite(CSW, HIGH);
  delay(1);
}
