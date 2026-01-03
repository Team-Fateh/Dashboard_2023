# Dashboard_2023
Dashboard and Data acquisition system for Team Fateh 2023

## Team Fateh
Team Fateh is a FSAE formula student team representing Thapar Institute of Engineering & Technology, Patiala and aims to buld formula cars based on the rules laid by FSAE.

## Introduction

The system in the car is based largely on an **ESP32 microcontroller** and compatible shields. Some devices used in this project were not necessarily made to be used together, but through the use of communication protocols such as **CAN-BUS, I2C, UART, and SPI**, the system was able to produce a reliable flow of data. This data is transmitted via wireless communications using an **XBee module** and stored onboard using **MicroSD**. The end result was a reliable, affordable data acquisition system which helps improve the car and reach its limits.

### DAQ connection flowchart

![DAQ connection flowchart](figure/DAQ_connection_flowchart.PNG)

---

## Hardware Implementation

### Schematic Diagram representing DAQ System

![Schematic Diagram of DAQ Unit](figure/Schematic_Diagram_of_DAQ_Unit.PNG)

### DAQ System Implementation

![DAQ System Implementation](figure/DAQ_System_Implementation.PNG)

---

## Hardware System Components

### The DOIT Esp32 DevKit v1

The DOIT Esp32 DevKit v1 is a development board created by DOIT to evaluate the ESP-WROOM-32 module.

- Microcontroller: Tensilica 32-bit Single-/Dual-core CPU Xtensa LX6  
- Operating Voltage: 3.3V  
- Input Voltage: 7–12V  
- Digital I/O Pins (DIO): 25  
- Analog Input Pins (ADC): 6  
- Analog Outputs Pins (DAC): 2  
- UARTs: 3  
- SPIs: 2  
- I2Cs: 3  
- Flash Memory: 4 MB  
- SRAM: 520 KB  
- Clock Speed: 240 MHz  
- Wi-Fi: IEEE 802.11 b/g/n/e/i (supports WEP or WPA/WPA2, or open networks)

### Buck Converter Voltage Regulator (XLSEMI XL4016)

The XLSEMI XL4016 is a 180 KHz fixed frequency PWM buck (step-down) DC/DC converter used to provide power to critical data collection devices. Steady and constant voltage is important since variation of supply voltage can cause errors in data collection and transmission.

- Input: 8–36 V DC  
- Regulated Output: 1.25–32 V DC  
- Rated: 30 W  
- Max output current: 12 A  
- Output set to a constant 5 V DC for the system

### CAN-BUS Module (SN65HVD230)

The SN65HVD230 CAN transceiver is designed to provide differential transmit capability to the bus and differential receive capability to a CAN controller at speeds up to **1 Mbps**. It interfaces a single-ended CAN controller with the differential CAN bus commonly used in automotive applications.

- Common-mode range: −2 V to 7 V  
- Withstands common-mode transients: ±25 V  
- Pin 8 provides modes: high-speed, slope control, and low-power

### HMI touch display (Nextion)

Nextion is an HMI solution combining an onboard processor and memory touch display with Nextion Editor software for HMI GUI development.

- Connects to peripheral MCU via TTL Serial (5V, TX, RX, GND)  
- Peripheral MCU can update progress/status back to display using simple ASCII text-based instructions

---

## Custom Sensors

### Inductive Proximity sensor (for vehicle speed)

8mm PNP RM18 inductive proximity sensor used to detect a metal object.

- Operating voltage range: VDC 6–36V  
- Nominal voltage: 30V  
- Detecting distance: 8mm  
- M18: cylinder type diameter 18mm  
- Unshielded field pattern  
- 3-wire, NO (Normally open) type output  
- RED LED indicator

### Brake Pressure Sensor

Gems series 3100 M12 brake pressure sensor used for measuring hydraulic brake fluid pressure.

- Reading range: 0–100 bar  
- Accuracy: 0.25%  
- Voltage operating range: 8–32V  
- Output range: 0.5–4.5V

### XBee pro S2C Module

Zigbee XBee Pro S2C 802.15.4 Module (63mW, ~3 km). Provides cost-effective wireless connectivity and enables receiving data wirelessly from the car during testing for better and faster analysis.

---

## Engine Sensors

### Crankshaft Position Sensor

Measures rotation speed (RPMs) and the precise position of the engine crankshaft. The inbuilt crankshaft position sensor is placed at the tip of the reluctor wheel. The sensor measures RPM and position which governs ignition timing.

### Manifold Absolute Pressure and Air Temperature Sensor

Bosch 0261230245 MAP sensor used for measuring the absolute pressure of the intake manifold behind the throttle. It detects change according to engine speed and load, converts it into a signal voltage, and sends it to the ECU. The ECU controls the basic fuel injection volume according to the input signals.

### Coolant Temperature Sensor

Measures engine coolant temperature. Readings are taken to the ECU and used to adjust fuel injection and ignition timings. The sensor is also used to switch on the radiator when temperature goes beyond a defined temperature.

---

## Software Implementation

Along with the hardware components, software is a crucial part for Data Acquisition: supporting other departments, giving the driver real time feedback, and enhancing overall vehicle performance.

### PlatformIO

Used for compiling code to the microcontroller. PlatformIO is free, easy to use, and satisfies requirements for microcontroller programming. Entire software development was done using this software.
![IDE_used_for_programming_MCU](figure/IDE_used_for_programming_MCU.PNG)

### PE3

Software used to program the Engine Control Unit (ECU), controlling fuel and spark timing, and acquiring data from engine sensors such as coolant temperature and Manifold Absolute Pressure sensors. Used by the Powertrain department for tuning the engine and enhancing performance.

![PE3 Software Interface](figure/PE3_Software_Interface.PNG)

### Custom GUI for live telemetry

A custom GUI was created using the Processing language to show live data via wireless communication, displaying acquired sensor data for validation. Wireless communication is done using an **XBEE Pro S2C** module (range ~3 km).

#### Diagram Representation of Wireless Communication

![Diagram Representation of Telemetry System](figure/Diagram_Representation_of_Telemetry_System.PNG)

#### Custom GUI

![GUI of Custom Telemetry](figure/GUI_of_Custom_Telemetry.PNG)

