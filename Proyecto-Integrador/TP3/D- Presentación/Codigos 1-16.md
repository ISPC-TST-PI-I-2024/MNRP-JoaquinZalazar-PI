# CODIGO 1

const int ledPin = 18; // Definimos el pin del LED

void setup() {
  pinMode(ledPin, OUTPUT); // Configuramos el pin como salida
}

void loop() {
  digitalWrite(ledPin, HIGH); // Encendemos el LED
}


# CODIGO 2

const int ledPin = 18; // Definimos el pin del LED
const int delayTime = 1000; // Tiempo de intervalo (en milisegundos)

void setup() {
  pinMode(ledPin, OUTPUT); // Configuramos el pin como salida
}

void loop() {
  digitalWrite(ledPin, HIGH);   // Encendemos el LED
  delay(delayTime);           // Esperamos el intervalo
  digitalWrite(ledPin, LOW);    // Apagamos el LED
  delay(delayTime);           // Esperamos el intervalo
}


# CODIGO 3

//
const int ledPins[] = {18, 5, 17}; // Arreglo con los pines de los LEDs
const int delayTime = 500; // Tiempo de intervalo (en milisegundos)

void setup() {
  for (int i = 0; i < sizeof(ledPins) / sizeof(int); i++) {
    pinMode(ledPins[i], OUTPUT); // Configuramos los pines como salidas
  }
}

void loop() {
  for (int i = 0; i < sizeof(ledPins) / sizeof(int); i++) {
    digitalWrite(ledPins[i], HIGH); // Encendemos el LED actual
    delay(delayTime);
    digitalWrite(ledPins[i], LOW); // Apagamos el LED actual
  }
}


# CODIGO 4

//
const int ledPin = 18; // Definimos el pin del LED
const int buttonPin = 35; // Definimos el pin del botón

void setup() {
  pinMode(ledPin, OUTPUT); // Configuramos el pin del LED como salida
  pinMode(buttonPin, INPUT); // Configuramos el pin del botón como entrada
}

void loop() {
  int buttonState = digitalRead(buttonPin); // Leemos el estado del botón
  if (buttonState == HIGH) {
    digitalWrite(ledPin, HIGH); // Encendemos el LED mientras se presiona el botón
  } else {
    digitalWrite(ledPin, LOW); // Apagamos el LED cuando se suelta el botón
  }
}


# CODIGO 5

//
const int ledPin = 18; // Definimos el pin del LED
const int buttonPin = 35; // Definimos el pin del botón

void setup() {
  pinMode(ledPin, OUTPUT); // Configuramos el pin del LED como salida
  pinMode(buttonPin, INPUT); // Configuramos el pin del botón como entrada
}

void loop() {
  int buttonState = digitalRead(buttonPin); // Leemos el estado del botón
  if (buttonState == HIGH) {
    digitalWrite(ledPin, HIGH); // Encendemos el LED mientras se presiona el botón
  } else {
    digitalWrite(ledPin, LOW); // Apagamos el LED cuando se suelta el botón
  }
}


# CODIGO 6

//
const int ledPin = 18; // Pin del LED
const int buttonPin = 34; // Pin del botón
int ledState = LOW; // Estado del LED
int buttonState = LOW; // Estado anterior del botón
const int debounceDelay = 50; // Tiempo de debounce (ms)
unsigned long lastDebounceTime = 0; // Último tiempo de rebote

void setup() {
  pinMode(ledPin, OUTPUT); // Configura el pin del LED como salida
  pinMode(buttonPin, INPUT); // Configura el pin del botón como entrada
}

void loop() {
  int currentButtonState = digitalRead(buttonPin); // Lee el estado actual del botón
  if (currentButtonState != buttonState) { // Detecta cambio de estado (presionado/soltado)
    unsigned long currentTime = millis(); // Obtiene el tiempo actual
    if (currentTime - lastDebounceTime > debounceDelay) {
      ledState = !ledState; // Invierte el estado del LED
      digitalWrite(ledPin, ledState); // Actualiza el estado del LED
      lastDebounceTime = currentTime; // Actualiza el último tiempo de rebote
    }
    buttonState = currentButtonState; // Actualiza el estado anterior del botón
  }
}


# CODIGO 7

//
const int ledPins[] = {18, 5}; // Pines de los LEDs
const int buttonPins[] = {34, 35}; // Pines de los botones
int ledStates[] = {LOW, LOW}; // Estados de los LEDs
int buttonStates[] = {LOW, LOW}; // Estados anteriores de los botones

void setup() {
  for (int i = 0; i < sizeof(ledPins) / sizeof(int); i++) {
    pinMode(ledPins[i], OUTPUT); // Configura los pines de los LEDs como salidas
  }
  for (int i = 0; i < sizeof(buttonPins) / sizeof(int); i++) {
    pinMode(buttonPins[i], INPUT); // Configura los pines de los botones como entradas
  }
}

void loop() {
  for (int i = 0; i < sizeof(buttonPins) / sizeof(int); i++) {
    int currentButtonState = digitalRead(buttonPins[i]); // Lee el estado actual del botón i
    if (currentButtonState != buttonStates[i]) { // Detecta cambio de estado (presionado/soltado)
      ledStates[i] = !ledStates[i]; // Invierte el estado del LED i
      digitalWrite(ledPins[i], ledStates[i]); // Actualiza el estado del LED i
      buttonStates[i] = currentButtonState; // Actualiza el estado anterior del botón i
    }
  }
}


# CODIGO 8 

void setup() {
  for (int i = 13; i <= 33; i++) { // Set GPIO pins for dip switches as input
    pinMode(i, INPUT);
  }

  for (int i = 18; i <= 2; i--) { // Set GPIO pins for LEDs as output
    pinMode(i, OUTPUT);
  }
}

void loop() {
  for (int i = 13; i <= 33; i++) {
    ledState = digitalRead(i); // Read dip switch state
    digitalWrite(33 - i + 18, ledState); // Set corresponding LED state
  }
}

# CODIGO 9 

//
const int ledPins[] = {18, 5, 17, 16, 4}; // Pines de los LEDs
const int buttonPin = 34; // Pin del botón
int ledStates[sizeof(ledPins) / sizeof(int)] = {LOW, LOW, LOW, LOW, LOW}; // Estados de los LEDs
int currentLedIndex = 0; // Índice de la secuencia actual

void setup() {
  for (int i = 0; i < sizeof(ledPins) / sizeof(int); i++) {
    pinMode(ledPins[i], OUTPUT); // Configura los pines de los LEDs como salidas
  }
  pinMode(buttonPin, INPUT); // Configura el pin del botón como entrada
}

void loop() {
  if (digitalRead(buttonPin) == HIGH) { // Detecta la presión del botón
    currentLedIndex = (currentLedIndex + 1) % sizeof(ledPins); // Avanza el índice circularmente
    updateLEDStates(); // Actualiza los estados de los LEDs
  }
}

void updateLEDStates() {
  for (int i = 0; i < sizeof(ledPins) / sizeof(int); i++) {
    ledStates[i] = LOW; // Apaga todos los LEDs
  }
  ledStates[currentLedIndex] = HIGH; // Enciende el LED actual
  for (int i = 0; i < sizeof(ledPins) / sizeof(int); i++) {
    digitalWrite(ledPins[i], ledStates[i]); // Actualiza los estados físicos de los LEDs
  }
}



# CODIGO 10

//
const int ledPin = 18; // Pin del LED1
const int switchPins[] = {32, 33, 25}; // Pines de los dip switches (3)
int currentSpeed = 1; // Velocidad de parpadeo actual (1 por defecto)
unsigned long lastBlinkTime = 0; // Tiempo del último parpadeo

void setup() {
  pinMode(ledPin, OUTPUT); // Configura el pin del LED como salida
  for (int i = 0; i < sizeof(switchPins) / sizeof(int); i++) {
    pinMode(switchPins[i], INPUT_PULLUP); // Configura los pines de los dip switches como entradas con pull-up
  }
}

void loop() {
  // Lee el estado de los dip switches
  int switchState = 0;
  for (int i = 0; i < sizeof(switchPins) / sizeof(int); i++) {
    switchState |= (digitalRead(switchPins[i]) << i);
  }

  // Calcula la velocidad de parpadeo en base al estado de los dip switches
  switch (switchState) {
    case 0: // 000: Velocidad más rápida
      currentSpeed = 1;
      break;
    case 1: // 001: Velocidad rápida
      currentSpeed = 2;
      break;
    case 2: // 010: Velocidad media
      currentSpeed = 3;
      break;
    case 3: // 011: Velocidad lenta
      currentSpeed = 4;
      break;
    case 4: // 100: Velocidad más lenta
      currentSpeed = 5;
      break;
    default: // Cualquier otra combinación: Velocidad por defecto
      currentSpeed = 1;
  }

  // Calcula el intervalo de parpadeo en base a la velocidad actual
  unsigned long blinkInterval = 500 / currentSpeed; // 500 ms / velocidad

  // Controla el parpadeo del LED1
  unsigned long currentTime = millis();
  if (currentTime - lastBlinkTime >= blinkInterval) {
    digitalWrite(ledPin, !digitalRead(ledPin)); // Invierte el estado del LED
    lastBlinkTime = currentTime;
  }
}

# CODIGO 11

const int ledPins[] = {18, 5, 17, 16, 4, 0, 2, 15}; // Pines de los LEDs (8)
const int switchPins[] = {32, 33, 25, 26}; // Pines de los dip switches (4)
const int patternTable[16][8] = {
  // Patrón 0: Todos apagados
  {LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW},
  // Patrón 1: LED1 encendido
  {HIGH, LOW, LOW, LOW, LOW, LOW, LOW, LOW},
  // Patrón 2: LED1 y LED2 encendidos
  {HIGH, HIGH, LOW, LOW, LOW, LOW, LOW, LOW},
  // Patrón 3: LEDs 1 a 3 encendidos
  {HIGH, HIGH, HIGH, LOW, LOW, LOW, LOW, LOW},
  // Patrón 4: Parpadeo rápido (todos)
  {HIGH, LOW, HIGH, LOW, HIGH, LOW, HIGH, LOW},
  // Patrón 5: Parpadeo lento (todos)
  {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH},
  // Patrón 6: Secuencia ascendente
  {LOW, HIGH, HIGH, HIGH, LOW, LOW, LOW, LOW},
  // Patrón 7: Secuencia descendente
  {HIGH, HIGH, HIGH, LOW, LOW, LOW, LOW, LOW},
  // ... (Define más patrones según tus necesidades)
};

int currentPattern = 0; // Patrón de parpadeo actual (índice en la tabla)
unsigned long lastBlinkTime = 0; // Tiempo del último parpadeo

void setup() {
  for (int i = 0; i < sizeof(ledPins) / sizeof(int); i++) {
    pinMode(ledPins[i], OUTPUT); // Configura los pines de los LEDs como salidas
  }
  for (int i = 0; i < sizeof(switchPins) / sizeof(int); i++) {
    pinMode(switchPins[i], INPUT_PULLUP); // Configura los pines de los dip switches como entradas con pull-up
  }
}

void loop() {
  // Lee el estado de los dip switches
  int switchState = 0;
  for (int i = 0; i < sizeof(switchPins) / sizeof(int); i++) {
    switchState |= (digitalRead(switchPins[i]) << i);
  }

  // Determina el patrón de parpadeo actual en base al estado de los dip switches
  currentPattern = mapStateToIndex(switchState); // Implementar función de mapeo

  // Controla el parpadeo de los LEDs según el patrón actual
  unsigned long currentTime = millis();
  if (currentTime - lastBlinkTime >= getBlinkInterval(currentPattern)) { // Intervalo de parpadeo (ajustar según el patrón)
    updateLEDStates();
    lastBlinkTime = currentTime;
  }
}

int mapStateToIndex(int switchState) {
  // Implementar lógica para mapear el estado de los dip switches a un índice de la tabla
  // Ejemplo:
  if (switchState == 0) { // Combinación 0000
    return 0;
  } else if (switchState == 1) { // Combinación 0001
    return 1;
  } else if (switchState == 2) { // Combinación 0010
    return 2;
  }
  // ... (Lógica para las demás combinaciones)
  else {
    return 0; // Índice por defecto (por ejemplo, primer patrón)
  }
}

unsigned long getBlinkInterval(int patternIndex) {
  // Implementar lógica para obtener el intervalo de parpadeo según el índice del patrón
  // Ejemplo:
  switch (patternIndex) {
    case 0: // Patrón 0: Apagado (sin parpadeo)
      return 0;
    case 1: // Patrón 1: Parpadeo rápido
      return 250;
    case 2: // Patrón 2: Parpadeo medio
      return 500;
    case 3: // Patrón 3: Parpadeo lento

  return 1000;
    case 4: // Patrón 4: Parpadeo rápido (todos)
  return 100;
    case 5: // Patrón 5: Parpadeo lento (todos)
  return 500;
    case 6: // Patrón 6: Secuencia ascendente
  return 250;
    case 7: // Patrón 7: Secuencia descendente
  return 250;
  // ... (Ajusta los intervalos de parpadeo para los demás patrones)
  default:
    return 500; // Intervalo por defecto (por ejemplo, 500 ms)
  }
}

void updateLEDStates() {
  for (int i = 0; i < sizeof(ledPins) / sizeof(int); i++) {
    digitalWrite(ledPins[i], patternTable[currentPattern][i]);
  }
}


# CODIGO 12

const int btn1Pin = 34; // Pin del botón btn1 (contar hacia adelante)
const int btn2Pin = 35; // Pin del botón btn2 (contar hacia atrás)
const int ledPins[] = {18, 5, 17, 16}; // Pines de los LEDs (4)
int pulseCount = 0; // Contador de pulsaciones

void setup() {
  pinMode(btn1Pin, INPUT_PULLUP); // Configura btn1 como entrada con pull-up
  pinMode(btn2Pin, INPUT_PULLUP); // Configura btn2 como entrada con pull-up
  for (int i = 0; i < sizeof(ledPins) / sizeof(int); i++) {
    pinMode(ledPins[i], OUTPUT); // Configura los LEDs como salidas
  }
}

void loop() {
  // Detecta pulsaciones en los botones
  if (digitalRead(btn1Pin) == LOW) {
    pulseCount++; // Incrementa el contador (contar hacia adelante)
    updateLEDDisplay();
    delay(50); // Debounce del botón
  } else if (digitalRead(btn2Pin) == LOW) {
    pulseCount--; // Decrementa el contador (contar hacia atrás)
    updateLEDDisplay();
    delay(50); // Debounce del botón
  }
}

void updateLEDDisplay() {
  // Limpia los LEDs
  for (int i = 0; i < sizeof(ledPins) / sizeof(int); i++) {
    digitalWrite(ledPins[i], LOW);
  }

  // Enciende o apaga los LEDs según el contador
  for (int i = 0; i < pulseCount; i++) {
    if (i < sizeof(ledPins) / sizeof(int)) {
      digitalWrite(ledPins[i], HIGH);
    }
  }
}


# CODIGO 13

const int btnPins[] = {34, 35, 36}; // Pines de los botones (btn1, btn2, btn3)
const int ledPins[] = {18, 5}; // Pines de los LEDs (LED1, LED2)
const int correctSequence[] = {1, 2, 3}; // Secuencia de contraseña correcta
int sequenceIndex = 0; // Índice de la secuencia actual

void setup() {
  for (int i = 0; i < sizeof(btnPins) / sizeof(int); i++) {
    pinMode(btnPins[i], INPUT_PULLUP); // Configura los botones como entradas con pull-up
  }
  for (int i = 0; i < sizeof(ledPins) / sizeof(int); i++) {
    pinMode(ledPins[i], OUTPUT); // Configura los LEDs como salidas
  }
}

void loop() {
  // Detecta pulsaciones en los botones
  for (int i = 0; i < sizeof(btnPins) / sizeof(int); i++) {
    if (digitalRead(btnPins[i]) == LOW) {
      checkButtonPress(i + 1); // Verifica la pulsación del botón (1, 2 o 3)
      delay(50); // Debounce del botón
    }
  }
}

void checkButtonPress(int buttonNumber) {
  // Compara la pulsación con la secuencia correcta
  if (buttonNumber == correctSequence[sequenceIndex]) {
    sequenceIndex++; // Avanza en la secuencia
    if (sequenceIndex == sizeof(correctSequence) / sizeof(int)) { // Secuencia correcta
      digitalWrite(ledPins[0], HIGH); // Enciende LED1 (éxito)
      digitalWrite(ledPins[1], LOW); // Apaga LED2
      sequenceIndex = 0; // Reinicia el índice de la secuencia
    }
  } else {
    digitalWrite(ledPins[0], LOW); // Apaga LED1
    digitalWrite(ledPins[1], HIGH); // Enciende LED2 (error)
    sequenceIndex = 0; // Reinicia el índice de la secuencia
  }
}


# CODIGO 14

#include <Arduino.h>
#include <esp_timer.h>

const int ledPins[] = {2, 3, 4, 5}; // Pines de los LEDs (4)
const int ledIntervals[] = {500, 250, 1000, 750}; // Intervalos de parpadeo (ms)
bool ledStates[] = {LOW, LOW, LOW, LOW}; // Estados actuales de los LEDs

esp_timer_handle_t timers[sizeof(ledPins) / sizeof(int)]; // Array de handles de timers

void setup() {
  for (int i = 0; i < sizeof(ledPins) / sizeof(int); i++) {
    pinMode(ledPins[i], OUTPUT); // Configura los LEDs como salidas
    ledCOnfigTimer(i, ledIntervals[i]); // Configura el timer para cada LED
  }
}

void ledCOnfigTimer(int ledIndex, int interval) {
  // Configura el timer para controlar el parpadeo del LED especificado
  noInterrupts(); // Desactiva interrupciones
  esp_timer_create_args_t timerArgs = {};
  timerArgs.callback = ledInterrupt; // Función de callback del timer
  timerArgs.arg = ledIndex; // Argumento para la función de callback (índice del LED)
  timerArgs.name = "led_timer"; // Nombre del timer (opcional)

  esp_timer_create(&timerArgs, &timers[ledIndex]); // Crea el timer
  esp_timer_start_periodic(timers[ledIndex], interval * 1000); // Inicia el timer en modo periódico (intervalo en microsegundos)
  interrupts(); // Habilita interrupciones
}

void ledInterrupt(void* args) {
  // Maneja la interrupción del timer
  int ledIndex = (int)args; // Obtiene el índice del LED del argumento
  ledStates[ledIndex] = !ledStates[ledIndex]; // Invierte el estado del LED
  digitalWrite(ledPins[ledIndex], ledStates[ledIndex]); // Actualiza el estado del LED
}

void loop() {
  // El programa puede ejecutar otras tareas aquí sin usar delay()
  // ...
}


# CODIGO 15 

// Incluye la librería para la placa ESP32
#include <Arduino.h>

// Define los pines para los LEDs
const int led1 = 18;
const int led2 = 5;
// ... otros pines para más LEDs

void setup() {
  // Configura los pines de los LEDs como salidas
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  // ... configura otros pines para más LEDs

  // Inicializa la comunicación serial
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    char comando = Serial.read();
    switch (comando) {
      case '1':
        digitalWrite(led1, HIGH); // Enciende led1
        break;
      case '2':
        digitalWrite(led2, LOW); // Apaga led2
        break;
      // ... otros casos para más LEDs
      default:
        // Comando no válido
        break;
    }
  }
}


# CODIGO 16

// Incluye la librería para la placa ESP32
#include <Arduino.h>

// Define los pines para los LEDs
const int led1 = 18;
const int led2 = 5;
const int led3 = 17;
const int led4 = 16;

void setup() {
  // Configura los pines de los LEDs como salidas
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
}

void loop() {
  // Parpadeo rápido para LED1 y LED2
  digitalWrite(led1, HIGH);
  digitalWrite(led2, LOW);
  delay(100); // Cambia la velocidad según tus preferencias
  digitalWrite(led1, LOW);
  digitalWrite(led2, HIGH);
  delay(100);

  // Parpadeo más lento para LED3 y LED4
  digitalWrite(led3, HIGH);
  digitalWrite(led4, LOW);
  delay(500); // Cambia la velocidad según tus preferencias
  digitalWrite(led3, LOW);
  digitalWrite(led4, HIGH);
  delay(500);
}
