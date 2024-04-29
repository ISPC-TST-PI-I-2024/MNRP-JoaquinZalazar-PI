#define BOTON_PIN 13 // PIN DEL POTON
#define LED_PIN 2 // PIN DEL LED

void setup() {
  // EL BOTON S LA ENTRADA
  pinMode(BOTON_PIN, INPUT);

  // EL LED ES LA SALIDA
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  // READ/LEER ESTADO DEL BOTON
  int boton = digitalRead(BOTON_PIN);

  // BOTON=ON=>ENCENDER
  if (boton == HIGH) {
    digitalWrite(LED_PIN, HIGH);
  } else {
    // BOTON=OFF=>APAGAR
    digitalWrite(LED_PIN, LOW);
  }
}
