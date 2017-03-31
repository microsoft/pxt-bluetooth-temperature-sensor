# Bluetooth Set Temperature Sensor Value

### ~hint
![](/static/bluetooth/Bluetooth_SIG.png)

For another device like a smartphone to use any of the Bluetooth "services" which the @boardname@ has, it must first be [paired with the @boardname@](/reference/bluetooth/bluetooth-pairing). Once paired, the other device may connect to the @boardname@ and exchange data relating to many of the @boardname@'s features.

### ~

Set the current temperature measured by the temperature sensor. This function should be called within the handler
when start the temperature sensor service.

```sig
bluetooth.setTemperatureSensorValue(1000)
```

### Parameters

* `value`: a [number](/types/number) that represents the temperature in degrees Celcius

```package
bluetooth
bluetooth-temperature-sensor
```
