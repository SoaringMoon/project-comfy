# Iteration 5: Tactile System Design and Integration

**Project:** Project Comfy (Domestic Android Companion)
**Author:** Manus AI
**Iteration Focus:** HRI Sensor Fusion and Tactile Integration

## 1. Tactile Sensing System Proposal

To meet the low-cost and modularity constraints, the proposed system utilizes a hybrid approach combining two accessible sensor types: **Resistive Force Sensors (RFS)** and **Capacitive Proximity Sensors (CPS)**.

### 1.1. Sensor Types

| Sensor Type | Principle | Application | Polling Rate |
| :--- | :--- | :--- | :--- |
| **Resistive Force Sensor (RFS)** | Measures pressure/force via resistance change. | Direct contact, grip strength, sustained pressure. | 100 Hz |
| **Capacitive Proximity Sensor (CPS)** | Measures change in capacitance (distance). | Pre-contact warning, approach speed, non-contact touch. | 50 Hz |

### 1.2. Modular Design and Placement

The system is designed around modular **Sensor Patches** that can be integrated into the existing 3D-printed skin layer.

| Location | Sensor Type | Rationale |
| :--- | :--- | :--- |
| **Hands (Fingertips & Palm)** | RFS (High Density) | Critical for object manipulation, hand-holding, and grip safety. |
| **Forearms (Inner & Outer)** | RFS (Low Density) + CPS | Detects gentle touch, supportive contact, and pre-contact approach. |
| **Torso (Upper Back)** | RFS (Low Density) | Detects comforting gestures (e.g., pat on the back) and leaning. |
| **Face (Cheeks/Forehead)** | CPS (Very Low Density) | Detects close proximity for intimate HRI (e.g., a kiss or close inspection). |

## 2. Technical Specifications

### 2.1. Sensing Resolution and Thresholds

| Parameter | Value | Rationale |
| :--- | :--- | :--- |
| **RFS Pressure Range** | 0.1 N to 50 N | Covers gentle touch up to safe grip force limit. |
| **CPS Proximity Range** | 0 mm to 50 mm | Provides a buffer zone for safe approach. |
| **RFS Safety Threshold** | 40 N | Triggers immediate compliance mode (MCU-side). |
| **RFS HRI Threshold** | 1 N to 5 N | Triggers Cognitive Layer inference (e.g., "affectionate touch"). |

### 2.2. Wiring and MCU Integration

*   **RFS Integration:** Each RFS is connected to an **Analog-to-Digital Converter (ADC)** input on the nearest Motor Controller Unit (MCU).
*   **CPS Integration:** Each CPS is connected to a **Digital Input** or a dedicated I2C/SPI bus on the nearest MCU.
*   **Data Aggregation:** The MCU is responsible for polling the local sensors, applying debouncing/filtering, and packaging the raw data into a new CAN Bus message for the Cognitive Layer.

## 3. CAN Bus Message Format Update

A new low-priority CAN message, `TLM_TACTILE_DATA`, will be introduced to transmit the processed sensor data to the SBC.

| Field | Type | Size (Bytes) | Description |
| :--- | :--- | :--- |
| **Joint ID** | UINT8 | 1 | Source MCU (e.g., Right Arm MCU). |
| **RFS Avg Pressure** | FLOAT16 | 2 | Average pressure across all RFS in the module (N). |
| **RFS Max Pressure** | FLOAT16 | 2 | Peak pressure detected (N). |
| **CPS Proximity** | UINT8 | 1 | Closest proximity detected (mm). |
| **Total Payload** | | **6 Bytes** | |

## 4. Conclusion

This modular design ensures that the tactile system is cost-effective and scalable. The integration via the existing MCU/CAN infrastructure minimizes hardware complexity and allows for low-latency safety overrides, which will be detailed in the subsequent deliverables.
