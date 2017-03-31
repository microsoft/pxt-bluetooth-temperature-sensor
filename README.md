# bluetooth temperature sensor service

A generic Bluetooth service to expose the temperature read from a sensor

## Usage

This package allows to create a Bluetooth temperature sensor and provide the data from
any custom sensor attached to the @boardname@. In fact, it can be used to stream any data!

```blocks
bluetooth.startTemperatureSensorService(() => {
    bluetooth.setTemperatureSensorValue(input.lightLevel());
})
```

## License

MIT

## Supported targets

* for PXT/microbit
(The metadata above is needed for package search.)

```package
bluetooth
bluetooth-temperature-sensor
```