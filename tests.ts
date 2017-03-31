// tests go here; this will not be compiled when this package is used as a library
bluetooth.startTemperatureSensorService(() => {
    led.toggle(0,0)
    bluetooth.setTemperatureSensorValue(input.lightLevel());
})