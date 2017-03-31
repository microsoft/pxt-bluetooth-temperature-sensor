# Bluetooth Start Temperature Sensor Service 

### ~hint
![](/static/bluetooth/Bluetooth_SIG.png)

For another device like a smartphone to use any of the Bluetooth "services" which the @boardname@ has, it must first be [paired with the @boardname@](/reference/bluetooth/bluetooth-pairing). Once paired, the other device may connect to the @boardname@ and exchange data relating to many of the @boardname@'s features.

### ~

This function allows to create a Bluetooth temperature sensor and provide the data from
any custom sensor attached to the @boardname@. In fact, it can be used to stream any data!


```sig
bluetooth.startTemperatureSensorService(() => {})
```

### Example: Starting the Bluetooth temperature service

The following code shows the Bluetooth temperature service being started:

```blocks
bluetooth.startTemperatureSensorService(() => {
    bluetooth.setTemperatureSensorValue(input.lightLevel());
});
```

```package
bluetooth
bluetooth-temperature-sensor
```

