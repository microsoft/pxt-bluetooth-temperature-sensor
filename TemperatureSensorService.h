#ifndef BLUETOOTH_TEMPERATURE_SENSOR_SERVICE_H
#define BLUETOOTH_TEMPERATURE_SENSOR_SERVICE_H

#include "MicroBitConfig.h"
#include "ble/BLE.h"
#include "MicroBitThermometer.h"
#include "EventModel.h"

#define MICROBIT_ID_SENSOR_TEMPERATURE 9500

// UUIDs for our service and characteristics
extern const uint8_t  TemperatureSensorServiceUUID[];
extern const uint8_t  TemperatureSensorServiceDataUUID[];
extern const uint8_t  TemperatureSensorServicePeriodUUID[];

/**
  * Class definition for the custom MicroBit Temperature Service.
  * Provides a BLE service to beam any temperature
  */
class TemperatureSensorService
{
    public:

    /**
      * Constructor.
      * Create a representation of the TemperatureService
      * @param _ble The instance of a BLE device that we're running on.
      */
    TemperatureSensorService(BLEDevice &_ble);

    /**
      * Callback. Invoked when any of our attributes are written via BLE.
      */
    void onDataWritten(const GattWriteCallbackParams *params);

    /**
    * Updates the temperature in the characteristic
    */
    void setTemperature(int temp);

    /**
    * Gets the current period in ms
    */
    int getPeriod();

    private:

    // Temperature update callback
    void temperatureUpdate(MicroBitEvent e);

    void setPeriod(int value);

    // Bluetooth stack we're running on.
    BLEDevice           	&ble;

    // memory for our 8 bit temperature characteristic.
    int8_t             temperatureDataCharacteristicBuffer;
    uint16_t           temperaturePeriodCharacteristicBuffer;

    // Handles to access each characteristic when they are held by Soft Device.
    GattAttribute::Handle_t temperatureDataCharacteristicHandle;
    GattAttribute::Handle_t temperaturePeriodCharacteristicHandle;
};


#endif
