# Electrical Wiring and PCB Design: Project Comfy Demonstrator

**Project:** Project Comfy (Domestic Android Companion)
**Author:** Manus AI
**Date:** November 10, 2025

## 1. Power Management Unit (PMU) PCB Design

The PMU is the central power distribution and safety board, located in the pelvis chassis.

### 1.1. PMU Block Diagram and Component Selection

| Component | Function | Part Number (Example) | Notes |
| :--- | :--- | :--- | :--- |
| **Microcontroller** | System Monitoring, E-Stop Logic | STM32F405RGT6 | Handles low-level safety logic and communication with the BMS. |
| **BMS Chip** | Battery Management System | BQ76940 | Monitors cell voltage, temperature, and balances the LiFePO4 8S pack. |
| **Main Power Switch** | High-Current Safety Disconnect | SiC MOSFET (e.g., C3M0065090J) | High-efficiency, low-Rds(on) for minimal heat generation during high-current draw. |
| **DC-DC Converters** | 24V to 5V/3.3V Step-Down | LTM8053 (µModule) | Isolated converters to minimize electrical noise transfer to the logic circuits. |
| **CAN Transceiver** | PMU to MCU/SBC Communication | MCP2551 | Interface for the central CAN Bus. |

### 1.2. PMU PCB Layout Guidelines

*   **Layer Stack-up:** Minimum 4-layer board (Top, Ground, Power, Bottom).
*   **High-Current Traces:** 24V power and ground traces must be on the inner layers and be at least **100 mil wide** with generous copper pours to handle the **45A peak current**. Use multiple vias to stitch power planes.
*   **Isolation:** The high-current section (Battery, Main Switch) must be physically separated from the low-voltage logic (MCU, CAN Transceiver) to prevent noise coupling.
*   **Thermal:** Place the main SiC MOSFET switch near the edge of the PCB to allow for direct connection to the chassis heatsink.

## 2. Motor Controller Unit (MCU) PCB Design

The MCU is a distributed board, integrated into each limb segment, responsible for the FOC control loop.

### 2.1. MCU Block Diagram and Component Selection

| Component | Function | Part Number (Example) | Notes |
| :--- | :--- | :--- | :--- |
| **Microcontroller** | FOC Algorithm, CAN Interface | STM32F405RGT6 (or ESP32-S3) | High-speed ADC for current sensing; sufficient processing power for 1 kHz FOC loop. |
| **Gate Driver** | Drives the 6 MOSFETs | DRV8305 | Integrated protection features and high-side/low-side driver logic. |
| **Power Stage** | 6x SiC MOSFETs | C3M0065090J | Handles 24V/45A switching for the BLDC motor. |
| **Current Sense** | Measures Phase Current | Low-side shunt resistors (e.g., 1 mΩ) | Feeds into the MCU's high-speed ADC for FOC. |
| **CAN Transceiver** | Communication with PMU/SBC | MCP2551 | Standardized interface. |

### 2.2. MCU PCB Layout Guidelines

*   **Layer Stack-up:** Minimum 4-layer board.
*   **Power Loop Minimization:** The high-current path (Power Stage to Motor Connector) must be as short and compact as possible to minimize parasitic inductance, which is critical for stable FOC.
*   **Current Sense Accuracy:** Place the current sense resistors and their differential traces close to the MCU's ADC pins and away from noisy power traces.
*   **Thermal:** The 6 MOSFETs must be placed to allow for efficient heat sinking, ideally to a metal plate integrated into the limb housing.

## 3. Wiring Diagram and Harness Specification

The wiring harness must be robust, flexible, and clearly labeled to facilitate assembly and debugging.

### 3.1. Cable Specification

| Connection | Cable Type | Conductor Gauge | Connector Type (Example) | Notes |
| :--- | :--- | :--- | :--- | :--- |
| **24V Power (PMU to MCU)** | Silicone Insulated, Stranded | 14 AWG | XT30/XT60 (Quick Disconnect) | High flexibility, high current capacity. |
| **CAN Bus (Daisy Chain)** | Shielded Twisted Pair | 24 AWG | JST-GH (Locking) | Shielding is mandatory to prevent motor noise interference. |
| **Motor Phases (MCU to BLDC)** | Silicone Insulated, Stranded | 16 AWG | MR30/MR60 | High flexibility, rated for motor current. |
| **Encoder (MCU to Encoder)** | Ribbon Cable or FFC | 28 AWG | JST-SH | Low-profile, high-density for SPI/ABI signals. |

### 3.2. Wiring Harness Routing

*   **Trunk:** The main power and CAN Bus lines run through the central torso/spine.
*   **Limb Segments:** All cables must be routed through the dedicated internal channels specified in the mechanical design (`mechanical_fabrication_guidelines.md`).
*   **Strain Relief:** All connectors must have strain relief (e.g., cable ties, potting) to prevent damage from repeated joint movement.
*   **Labeling:** Every connector and cable end must be labeled with its source and destination (e.g., `PMU_OUT_HIP_L` to `MCU_IN_HIP_L`).

## 4. Data Logging and Diagnostic Interfaces

Bench testing requires robust access to the system's internal state.

| Interface | Location | Purpose | Protocol |
| :--- | :--- | :--- | :--- |
| **CAN Bus Analyzer** | PMU/SBC | Monitoring all real-time command and telemetry traffic. | CAN 2.0B |
| **SWD/JTAG** | MCU/PMU PCBs | Low-level firmware debugging and flashing. | SWD (Serial Wire Debug) |
| **UART (Serial)** | MCU/SBC | High-speed, non-critical data logging (e.g., print statements, error dumps). | 115200 Baud |
| **Test Points** | MCU PCB | Access to critical signals (e.g., current sense, PWM output) for oscilloscope probing. | Gold-plated test pads. |

## 5. Next Steps

With the electrical design complete, the next step is to create the reference firmware and the high-level integration framework to bring the mechanical and electrical components to life.
