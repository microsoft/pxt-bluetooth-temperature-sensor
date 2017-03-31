/**
  * Class definition for the custom MicroBit Temperature Service.
  * Provides a BLE service to remotely read the silicon temperature of the nRF51822.
  */
#include "MicroBitConfig.h"
#include "ble/UUID.h"

#include "TemperatureSensorService.h"

/**
  * Constructor.
  * Create a representation of the TemperatureService
  * @param _ble The instance of a BLE device that we're running on.
  */
TemperatureSensorService::TemperatureSensorService(BLEDevice &_ble) :
        ble(_ble)
{
    // Create the data structures that represent each of our characteristics in Soft Device.
    GattCharacteristic  temperatureDataCharacteristic(TemperatureSensorServiceDataUUID, (uint8_t *)&temperatureDataCharacteristicBuffer, 0,
    sizeof(temperatureDataCharacteristicBuffer), GattCharacteristic::BLE_GATT_CHAR_PROPERTIES_READ | GattCharacteristic::BLE_GATT_CHAR_PROPERTIES_NOTIFY);

    GattCharacteristic  temperaturePeriodCharacteristic(TemperatureSensorServicePeriodUUID, (uint8_t *)&temperaturePeriodCharacteristicBuffer, 0,
    sizeof(temperaturePeriodCharacteristicBuffer), GattCharacteristic::BLE_GATT_CHAR_PROPERTIES_READ | GattCharacteristic::BLE_GATT_CHAR_PROPERTIES_WRITE);

    // Initialise our characteristic values.
    temperatureDataCharacteristicBuffer = 0;
    temperaturePeriodCharacteristicBuffer = 1000;

    // Set default security requirements
    temperatureDataCharacteristic.requireSecurity(SecurityManager::MICROBIT_BLE_SECURITY_LEVEL);
    temperaturePeriodCharacteristic.requireSecurity(SecurityManager::MICROBIT_BLE_SECURITY_LEVEL);

    GattCharacteristic *characteristics[] = {&temperatureDataCharacteristic, &temperaturePeriodCharacteristic};
    GattService         service(TemperatureSensorServiceUUID, characteristics, sizeof(characteristics) / sizeof(GattCharacteristic *));

    ble.addService(service);

    temperatureDataCharacteristicHandle = temperatureDataCharacteristic.getValueHandle();
    temperaturePeriodCharacteristicHandle = temperaturePeriodCharacteristic.getValueHandle();

    ble.gattServer().write(temperatureDataCharacteristicHandle,(uint8_t *)&temperatureDataCharacteristicBuffer, sizeof(temperatureDataCharacteristicBuffer));
    ble.gattServer().write(temperaturePeriodCharacteristicHandle,(uint8_t *)&temperaturePeriodCharacteristicBuffer, sizeof(temperaturePeriodCharacteristicBuffer));

    ble.onDataWritten(this, &TemperatureSensorService::onDataWritten);
    if (EventModel::defaultEventBus)
        EventModel::defaultEventBus->listen(MICROBIT_ID_SENSOR_TEMPERATURE, MICROBIT_THERMOMETER_EVT_UPDATE, this, &TemperatureSensorService::temperatureUpdate, MESSAGE_BUS_LISTENER_IMMEDIATE);
}

void TemperatureSensorService::setTemperature(int value) 
{
    temperatureDataCharacteristicBuffer = value;    
}

void TemperatureSensorService::setPeriod(int value)
{
    temperaturePeriodCharacteristicBuffer = max(1, value);
}

void TemperatureSensorService::temperatureUpdate(MicroBitEvent)
{
    if (ble.getGapState().connected)
    {
        ble.gattServer().notify(temperatureDataCharacteristicHandle,(uint8_t *)&temperatureDataCharacteristicBuffer, sizeof(temperatureDataCharacteristicBuffer));
    }
}

int TemperatureSensorService::getPeriod() 
{
    return temperaturePeriodCharacteristicBuffer;
}

/**
  * Callback. Invoked when any of our attributes are written via BLE.
  */
void TemperatureSensorService::onDataWritten(const GattWriteCallbackParams *params)
{
    if (params->handle == temperaturePeriodCharacteristicHandle && params->len >= sizeof(temperaturePeriodCharacteristicBuffer))
    {
        setPeriod(*((uint16_t *)params->data));
        ble.gattServer().write(temperaturePeriodCharacteristicHandle, (const uint8_t *)&temperaturePeriodCharacteristicBuffer, sizeof(temperaturePeriodCharacteristicBuffer));
    }
}


const uint8_t  TemperatureSensorServiceUUID[] = {
    0xe9,0x5d,0x61,0x00,0x25,0x1d,0x47,0x0a,0xa0,0x62,0xfa,0x19,0x22,0xdf,0xa9,0xa8
};

const uint8_t  TemperatureSensorServiceDataUUID[] = {
    0xe9,0x5d,0x92,0x50,0x25,0x1d,0x47,0x0a,0xa0,0x62,0xfa,0x19,0x22,0xdf,0xa9,0xa8
};

const uint8_t  TemperatureSensorServicePeriodUUID[] = {
    0xe9,0x5d,0x1b,0x25,0x25,0x1d,0x47,0x0a,0xa0,0x62,0xfa,0x19,0x22,0xdf,0xa9,0xa8
};
