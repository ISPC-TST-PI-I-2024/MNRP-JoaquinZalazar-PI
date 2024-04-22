# Definir los pines del botón y el LED
boton_pin = 2
led_pin = 13

# Importar la biblioteca GPIO
import machine

# Crear objetos GPIO para el botón y el LED
boton = machine.Pin(boton_pin, machine.Pin.IN)
led = machine.Pin(led_pin, machine.Pin.OUT)

while True:
  # Leer el estado del botón
  estado_boton = boton.value()

  # Si el botón está presionado, encender el LED
  if estado_boton:
    led.on()
  else:
    # Si el botón no está presionado, apagar el LED
    led.off()
