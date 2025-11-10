# Electrical Subsystems Specification: Project Comfy

**Project:** Project Comfy (Domestic Android Companion)
**Author:** Manus AI
**Date:** November 10, 2025

## 1. Power Management Subsystem (PMU)

The PMU is the central hub for power distribution, safety, and monitoring.

### 1.1. PMU Specification

| Specification | Value | Rationale |
| :--- | :--- | :--- |
| **Input Voltage** | 24V DC (External or Battery) | Standard for high-power robotics; balances power delivery and safety. |
| **Peak Current Capacity** | 45A (for 1000W burst) | Required for simultaneous high-force movements (e.g., standing). |
| **Battery** | LiFePO4 (Lithium Iron Phosphate) 8S | Safer chemistry than LiPo; 25.6V nominal voltage; high cycle life. |
| **Safety** | Dedicated Battery Management System (BMS) with Over-Current Protection (OCP) and Thermal Shutdown. | Non-negotiable for safety and battery longevity. |

### 1.2. PMU Block Diagram and PCB Plan

*   **Topology:** Centralized PMU in the pelvis chassis.
*   **Key Components:**
    *   **BMS Chip:** BQ769x0 series (Texas Instruments) for cell monitoring.
    *   **Main Switch:** High-current MOSFET (e.g., IRF3205 or SiC equivalent) controlled by the E-Stop and BMS.
    *   **DC-DC Converters:** Isolated buck converters to step down 24V to 5V (for SBC, sensors) and 3.3V (for microcontrollers).
*   **PCB Plan:** 4-layer PCB required for high-current traces (24V lines) and noise isolation for low-voltage logic. High-current traces must be wide and utilize copper pours for heat dissipation.

## 2. Distributed Motor Control Subsystem

This subsystem consists of multiple identical motor controller boards distributed throughout the limbs, each managing one or two joints.

### 2.1. Motor Controller Unit (MCU) Specification

| Specification | Value | Rationale |
| :--- | :--- | :--- |
| **Microcontroller** | ESP32-S3 or STM32F4 series | High-speed processing for FOC; integrated peripherals (PWM, ADC). |
| **Motor Driver** | 3-Phase Bridge (6 MOSFETs) | Utilizes high-efficiency, low-Rds(on) MOSFETs (e.g., SiC-based) for 24V/45A operation. |
| **Communication** | **CAN Bus Transceiver** (e.g., MCP2551) | Robust, real-time communication with the main SBC. |
| **Feedback** | Encoder Interface (SPI/ABI) | Connects to the absolute magnetic encoder on the motor shaft. |

### 2.2. Electronics Schematics (Conceptual)

The core of the MCU is the FOC loop:

1.  **Sensing:** Three low-side current sense resistors feed into the MCU's ADC.
2.  **Processing:** The MCU runs the FOC algorithm to calculate the required PWM duty cycles.
3.  **Driving:** The MCU's PWM outputs drive the MOSFET gate drivers, which switch the 24V power to the BLDC motor windings.
4.  **Communication:** The CAN transceiver handles all data exchange with the central SBC.

## 3. Sensor and Actuator Interface Details

| Component | Interface Type | Voltage | Bandwidth/Frequency | Notes |
| :--- | :--- | :--- | :--- | :--- |
| **Primary Actuators (BLDC)** | CAN Bus (Command/Telemetry) | 24V (Power) | 1 kHz (Control Loop) | Deterministic, low-latency control is essential. |
| **Absolute Encoders** | SPI or ABI | 3.3V | High-speed data transfer for position feedback. |
| **RGB-D Camera** | USB 3.0 or PCIe | 5V | High bandwidth for real-time video and depth map streaming to the SBC. |
| **Haptic Sensors (Capacitive)** | GPIO/ADC (via ESP32) | 3.3V | Low frequency (Touch detection). | Localized processing on the nearest distributed MCU. |
| **Nitinol Actuators** | PWM (MOSFET Array) | 5V/12V (Heating) | Low frequency (Subtle, slow movements). | Requires a dedicated, low-power driver board. |

## 4. Risk and Cost Analysis (Electrical)

| Risk Factor | Description | Mitigation Strategy | Cost Impact |
| :--- | :--- | :--- | :--- |
| **Electrical Noise** | High-current motor switching can interfere with low-voltage logic (SBC, sensors). | Use isolated DC-DC converters; implement a dedicated ground plane on all PCBs; use shielded cables for CAN Bus and sensor lines. | **Medium** (PCB complexity) |
| **Thermal Runaway** | High-power MOSFETs can overheat and fail catastrophically. | Use SiC MOSFETs (higher efficiency); integrate thermal sensors on the PCB; utilize chassis as a heatsink. | **Medium** (Component cost) |
| **CAN Bus Latency** | High data traffic could delay critical control commands. | Prioritize critical messages (e.g., E-Stop, Compliance) with lower CAN IDs; optimize the control loop frequency. | **Low** (Software optimization) |
| **High-Voltage DE** | High voltage (kV range) for DE actuators poses a safety risk. | Isolate the high-voltage circuit entirely; use low-current, high-voltage power supplies with current limiting; only activate when the safety system confirms no direct human contact. | **High** (Safety isolation) |

## 5. Next Steps

The electrical specifications provide the necessary power and control infrastructure. The next step is to detail the **Software Architecture** that will orchestrate these electrical and mechanical components.
