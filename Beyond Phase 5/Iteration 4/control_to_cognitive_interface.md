# Control-to-Cognitive Interface Specification Update

**Project:** Project Comfy (Domestic Android Companion)
**Author:** Manus AI
**Iteration Focus:** Control and Firmware Refinement

## 1. Objective

To update the communication protocol between the low-level Motor Controller Units (MCUs) and the high-level Cognitive Layer (running on the Single Board Computer - SBC) to support the new adaptive control features and enhanced safety monitoring.

## 2. Communication Protocol Overview

The system continues to use **CAN Bus** for low-latency, high-reliability communication between the SBC and the distributed MCUs. The protocol remains message-based, but the data payload is updated.

## 3. Updated Message Payloads

### 3.1. Cognitive Layer (SBC) to Control Layer (MCU)

The high-level command message (`CMD_JOINT_CONTROL`) is updated to include a **Compliance Mode** flag, allowing the Cognitive Layer to dynamically request different levels of joint compliance based on the HRI context (e.g., "handshake" vs. "carrying a tray").

| Field | Type | Size (Bytes) | Description | Iteration 4 Change |
| :--- | :--- | :--- | :--- | :--- |
| **Joint ID** | UINT8 | 1 | Target joint (0-18). | None |
| **Command Type** | UINT8 | 1 | Position, Velocity, or Torque. | None |
| **Target Value** | FLOAT32 | 4 | Desired position (rad), velocity (rad/s), or torque (Nm). | None |
| **Compliance Mode** | UINT8 | 1 | **NEW:** 0: Stiff (Default), 1: Compliant (Low-Force), 2: Adaptive (HRI). | **NEW FIELD** |
| **Total Payload** | | **7 Bytes** | | |

### 3.2. Control Layer (MCU) to Cognitive Layer (SBC)

The telemetry message (`TLM_JOINT_STATUS`) is updated to include the status of the new MCU-side safety checks, providing the Cognitive Layer with critical, real-time diagnostic information.

| Field | Type | Size (Bytes) | Description | Iteration 4 Change |
| :--- | :--- | :--- | :--- | :--- |
| **Joint ID** | UINT8 | 1 | Source joint. | None |
| **Actual Position** | FLOAT32 | 4 | Current joint position (rad). | None |
| **Actual Torque** | FLOAT32 | 4 | Estimated output torque (Nm). | None |
| **MCU Temp** | UINT8 | 1 | **NEW:** Internal MCU temperature (°C). | **NEW FIELD** |
| **Safety Status** | UINT8 | 1 | **NEW:** Bitmask for: Thermal Watchdog, Over-Current, Backlash Zone. | **NEW FIELD** |
| **Total Payload** | | **11 Bytes** | | |

## 4. Behavioral Integration

The new `Compliance Mode` field enables the Cognitive Layer to implement more nuanced HRI rules:

*   **Handshake/Touch:** Cognitive Layer sets `Compliance Mode = 1` (Compliant) for the arm joints, ensuring a soft, safe interaction.
*   **Carrying/Load:** Cognitive Layer sets `Compliance Mode = 0` (Stiff) for the arm joints, ensuring maximum holding strength.
*   **Adaptive HRI:** Cognitive Layer uses the new `Safety Status` (Backlash Zone bit) to adjust its conversational flow. If the robot is physically struggling (high backlash/torque), the Cognitive Layer can respond with an appropriate verbal cue ("One moment, I'm adjusting my grip") to maintain interaction coherence.

## 5. Conclusion

The updated interface ensures that the high-level behavioral rules can dynamically influence the low-level control, while the enhanced telemetry provides the necessary feedback for the Cognitive Layer to maintain safety and conversational context. This integration is crucial for the overall HRI quality.
