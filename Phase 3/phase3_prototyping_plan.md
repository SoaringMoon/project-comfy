# Phase 3 Prototyping and Integration Plan

**Project:** Project Comfy (Domestic Android Companion)
**Author:** Manus AI
**Date:** November 10, 2025

## 1. Phase Goal and Strategy

The goal of Phase 3 is to produce a **functional Single-Limb Demonstrator** and a **Cognitive Subsystem Emulation** to validate the core design principles of safety, performance, and companionship.

**Strategy:** A parallel, two-track approach:
1.  **Hardware Track:** Focus on the Single-Limb Prototype (Hip-Knee-Ankle) to validate the electromechanical and low-level control systems.
2.  **Software Track:** Focus on the Cognitive Subsystem Emulation to validate the AI pipeline and personality logic using simulated hardware data.

## 2. Hardware Track: Single-Limb Prototype Plan

### 2.1. Key Milestones

| Milestone ID | Description | Dependencies | Estimated Duration |
| :--- | :--- | :--- | :--- |
| **H3.1** | PCB Fabrication and Assembly (PMU & MCU) | `electrical_wiring_and_pcbs.md` | 2 Weeks |
| **H3.2** | Mechanical Fabrication (Housing, Limb Segments) | `mechanical_fabrication_guidelines.md` | 1 Week |
| **H3.3** | Firmware Flashing and Bench Test (FOC) | `firmware_reference_implementation.cpp` | 1 Week |
| **H3.4** | Final Limb Assembly and Integration | H3.1, H3.2, H3.3 | 1 Week |
| **H3.5** | **Safety and Performance Validation** | `testing_and_verification_results.md` | 1 Week |

### 2.2. Required Equipment (Bench Testing)

| Equipment | Purpose | Notes |
| :--- | :--- | :--- |
| **DC Power Supply** | 24V, 50A capacity | Must be current-limited for safety during initial testing. |
| **Digital Oscilloscope** | 4-channel, 100 MHz+ | Essential for FOC tuning (current sense, PWM signals). |
| **CAN Bus Analyzer** | USB Interface | Monitoring and injecting CAN messages. |
| **Torque Sensor/Load Cell** | 50 Nm capacity | Calibrated device for validating the 40 Nm hip joint requirement. |
| **Data Acquisition (DAQ) System** | Logging telemetry (position, temperature, current) at high frequency. |

## 3. Software Track: Cognitive Subsystem Emulation Plan

### 3.1. Key Milestones

| Milestone ID | Description | Dependencies | Estimated Duration |
| :--- | :--- | :--- | :--- |
| **S3.1** | SBC Setup and Environment Configuration | Main SBC (e.g., Jetson/NVIDIA) | 1 Day |
| **S3.2** | Integration Framework Implementation | `integration_framework.py` | 3 Days |
| **S3.3** | Multimodal Encoder Stub Development | `core_ai_engine.py` | 1 Week |
| **S3.4** | **Personality Consistency Test** | S3.2, S3.3 | 1 Week |

### 3.2. Simulation and Diagnostic Interfaces

*   **Hardware-in-the-Loop (HIL):** The high-level Python code will communicate with the physical MCU via the CAN Bus. The MCU acts as the HIL component, providing real-time motor and sensor data.
*   **Data Logging:** The `integration_framework.py` will log all incoming CAN telemetry and outgoing AI responses to a structured database (e.g., InfluxDB) for post-analysis.

## 4. Next Steps

Upon successful completion of the validation tests (H3.5 and S3.4), the project will be ready to proceed to Phase 4: Human-Robot Interaction (HRI) Evaluation and Refinement. The next document will detail the specific validation procedures.
