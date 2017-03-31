// Auto-generated. Do not edit.
declare namespace bluetooth {

    /**
     * Starts a custom sensor service. The handler must call ``setSensorTemperature`` 
     * to update the temperature sent to the service.
     */
    //% blockId=bluetooth_startTemperatureSensorService block="bluetooth temperature sensor service" shim=bluetooth::startTemperatureSensorService
    function startTemperatureSensorService(handler: () => void): void;

    /**
     * Sets the current temperature value on the external temperature sensor
     */
    //% blockId=bluetooth_setTemperatureSensorValue block="bluetooth set temperature sensor value (°C) %temperature" shim=bluetooth::setTemperatureSensorValue
    function setTemperatureSensorValue(temperature: number): void;
}

// Auto-generated. Do not edit. Really.
