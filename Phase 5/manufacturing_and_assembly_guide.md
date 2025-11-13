# Manufacturing, Assembly, and Calibration Guide

**Project:** Project Comfy (Domestic Android Companion)
**Author:** Manus AI
**Date:** November 11, 2025
**Version:** 1.0 (Open Reference Release)

## 1. Manufacturing and Fabrication Flow

The manufacturing process is divided into three parallel tracks to optimize production time.

| Track | Focus | Key Deliverable | Fabrication Method |
| :--- | :--- | :--- | :--- |
| **Mechanical** | Chassis, Limb Segments, Joint Housings | CAD Files (STL/STEP) | SLS Nylon (High-Volume), FDM (Prototyping) |
| **Electrical** | PMU and MCU PCBs | Gerber Files, Component Placement | Professional PCB Fabrication (4-Layer) |
| **Harness** | Wiring, Cable Assemblies | Wiring Diagrams, BOM | Custom Harness Assembly |

### 1.1. Component Sourcing and Alternatives (Partial BOM)

| Component | Part Number (Example) | Sourcing Option 1 (High-End) | Sourcing Option 2 (Budget) |
| :--- | :--- | :--- | :--- |
| **BLDC Motor** | T-Motor U8 Lite KV100 | T-Motor | HobbyKing/Generic High-Torque Motor |
| **Strain Wave Gear** | Harmonic Drive CSF-8-100-2UJ | Harmonic Drive | 3D-Printed Cycloidal Drive (Open Source) |
| **Microcontroller** | STM32F405RGT6 | Digi-Key/Mouser | ESP32-S3 (for lower-power joints) |
| **Battery** | LiFePO4 8S Pack | Custom Battery Manufacturer | Off-the-shelf RC Battery Pack |

## 2. Assembly Procedure: Hip Joint Module (Critical Assembly)

The Hip Joint Module requires precision assembly to ensure the 40 Nm torque capacity and low backlash.

### 2.1. Exploded View and Alignment

1.  **Motor Mounting:** Secure the BLDC motor into the rear housing (`PC_PT_Hip_Housing_Rear`). **Torque Specification:** 1.5 Nm (use Loctite 243).
2.  **Gearbox Integration:** Press-fit the Strain Wave Gear into the housing. Ensure the gear input is perfectly concentric with the motor shaft. **Alignment Tolerance:** < 0.05 mm runout.
3.  **Encoder Installation:** Mount the absolute magnetic encoder PCB onto the output shaft. The magnet must be centered over the sensor chip.
4.  **Final Housing:** Bolt the front and rear housing sections together. Ensure no wires are pinched.

### 2.2. Wiring and Harness Integration

*   **CAN Bus:** Daisy-chain the CAN Bus (CAN_H, CAN_L, GND) between the PMU and all MCUs. Use shielded twisted pair cable.
*   **Power:** Route 24V power lines (14 AWG) through the dedicated channels. Use locking connectors (e.g., XT30) at the MCU interface.
*   **Strain Relief:** Apply cable ties at all entry/exit points of the limb segments to prevent movement from stressing the solder joints or connectors.

## 3. Calibration Procedures

### 3.1. Mechanical Calibration: Joint Zeroing

1.  **Procedure:** Manually move each joint to its mechanical end-stop (e.g., fully extended).
2.  **Firmware Action:** Read the absolute encoder value at this position.
3.  **Storage:** Store this value as the `MAX_POSITION_LIMIT` in the MCU's non-volatile memory. The zero position (0 radians) is defined as the mid-point of the joint's range of motion.

### 3.2. Electrical Calibration: FOC Tuning

1.  **Procedure:** Use a dedicated FOC tuning script (provided in the `comfy-firmware` repository) to determine the motor's electrical parameters (Phase Resistance, Inductance, Flux Linkage).
2.  **Bench Test:** Connect the MCU to a dynamometer. Run the motor at 10 Nm load.
3.  **Refinement:** Adjust the Proportional-Integral-Derivative (PID) gains for the FOC current and velocity loops until the motor response is stable, with **< 5% overshoot** and **< 0.1 degree steady-state error**.

### 3.3. Behavioral Calibration: Gaze Timing

1.  **Procedure:** Use the HRI test rig (high-speed camera) to record the android's gaze during a standardized dialogue script.
2.  **Adjustment:** Adjust the `Gaze_Saccade_Duration` and `Gaze_Contact_Ratio` parameters in the HRI Engine until the recorded gaze pattern matches the target human baseline (e.g., **3.5-second max continuous contact**).

## 4. Maintenance Notes

*   **Lubrication:** Strain Wave Gears require periodic re-lubrication (every 1,000 operating hours) with a specified grease (e.g., Harmonic Drive Grease).
*   **Battery Cycle:** The LiFePO4 battery should be cycled (full discharge/recharge) every 6 months to maintain cell balance.
*   **Firmware Update:** Use the SWD/JTAG interface for critical firmware updates. Over-the-air (OTA) updates are available for the Python Cognitive Layer.
