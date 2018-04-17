# bluetooth temperature sensor service [![Build Status](https://travis-ci.org/Microsoft/pxt-bluetooth-temperature-sensor.svg?branch=master)](https://travis-ci.org/Microsoft/pxt-bluetooth-temperature-sensor)

A Bluetooth service to expose a temperature reading.

## Usage

This package allows to create a Bluetooth temperature sensor and provide the data from
any custom sensor attached to the @boardname@. In fact, it can be used to stream any data!

```blocks
bluetooth.startTemperatureSensorService(() => {
    bluetooth.setTemperatureSensorValue(input.lightLevel());
})
```

Then use the temperature charting from [Bitty data logger](http://www.bittysoftware.com/apps/bitty_data_logger.html) to visualize it.

## Supported targets

* for PXT/microbit
(The metadata above is needed for package search.)

```package
bluetooth
bluetooth-temperature-sensor
```

## License

MIT

## Code of Conduct

This project has adopted the [Microsoft Open Source Code of Conduct](https://opensource.microsoft.com/codeofconduct/). For more information see the [Code of Conduct FAQ](https://opensource.microsoft.com/codeofconduct/faq/) or contact [opencode@microsoft.com](mailto:opencode@microsoft.com) with any additional questions or comments.
