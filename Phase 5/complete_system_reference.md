# Complete System Reference: Project Comfy Open Platform

**Project:** Project Comfy (Domestic Android Companion)
**Author:** Manus AI
**Date:** November 11, 2025
**Version:** 1.0 (Open Reference Release)

## 1. Executive Summary and Core Philosophy

Project Comfy is a domestic android designed for human companionship, prioritizing **safety, emotional connection, and open-source modularity**. The system employs a hybrid architecture combining high-torque, compliant electromechanical joints with soft, expressive actuators. The core philosophy is to be "just smart enough to love my dumb ass," achieved through a filtered, emotionally consistent AI personality.

## 2. System Architecture Overview

The system is based on a three-layered, distributed architecture communicating via a high-speed CAN Bus.

| Layer | Component | Primary Function | Communication | Language |
| :--- | :--- | :--- | :--- | :--- |
| **Cognition** | Single Board Computer (SBC) | AI, Personality, Multimodal Fusion, HRI Engine | CAN Bus (Commands) | Python |
| **Control** | Distributed Microcontrollers (MCU) | Real-time FOC, Safety/Compliance Protocol | CAN Bus (Telemetry/Commands) | C/C++ |
| **Actuation** | BLDC Motors, Strain Wave Gears, Nitinol | Physical movement and expression | PWM/SPI (Local) | Firmware |

## 3. Mechanical Subsystem Specification

### 3.1. Primary Actuation (Core Joints)

*   **Joint Type:** BLDC Motor + Strain Wave Gear (e.g., Harmonic Drive CSF-8-100-2UJ).
*   **Key Specification:** Hip Joint Peak Torque: **40 Nm**.
*   **Safety Feature:** Backdrivable design is mandatory for compliance.
*   **Material:** Chassis constructed from **CFRP** or high-density SLS Nylon for the demonstrator.

### 3.2. Fine Actuation (Expression)

*   **Facial Actuators:** **Nitinol (Shape Memory Alloy) Wire** controlled by PWM.
*   **Haptic Feedback:** Localized **DE Actuators** (Dielectric Elastomers) for generating warmth and subtle vibration upon affectionate touch.

## 4. Electrical Subsystem Specification

### 4.1. Power Management Unit (PMU)

*   **Voltage:** **24V DC** (LiFePO4 8S battery).
*   **Peak Current:** **45A** (1000W burst).
*   **Safety:** Dedicated BMS, high-current SiC MOSFET main switch, and a physical E-Stop button.

### 4.2. Motor Controller Unit (MCU)

*   **Microcontroller:** STM32F4 or equivalent (for 1 kHz FOC loop).
*   **Control Algorithm:** **Field-Oriented Control (FOC)** for efficiency and quiet operation.
*   **Communication:** **MCP2551 CAN Transceiver** for robust, low-latency communication.

## 5. Software and Firmware Specification

### 5.1. Control Layer Firmware (C/C++)

*   **Control Loop Frequency:** **1 kHz**.
*   **Safety Protocol:** **Compliance Mode** is triggered within **< 2 ms** if the estimated joint force exceeds **500 N**, overriding all high-level commands.
*   **Initialization:** Zeroing of all joints using absolute magnetic encoders.

### 5.2. Cognition Layer Software (Python)

*   **Multimodal Fusion:** Fuses visual (pose, emotion), auditory (STT, prosody), and proprioceptive (telemetry) data into a **Context Vector** to condition the LLM.
*   **Personality Engine:** Implements the **Mood Model** (Valence-Arousal-Dominance) and applies filtering protocols (e.g., **Taciturn Protocol**) to the LLM output.
*   **HRI Engine:** Manages **Motion Blending** (Cubic Spline Interpolation) and **Multimodal Synchronization** (gaze, speech, gesture timing).

## 6. Safety, Compliance, and Ethical Guardrails

### 6.1. Physical Safety Benchmarks

| Metric | Target Value | Verification |
| :--- | :--- | :--- |
| **E-Stop Latency** | < 10 ms | Oscilloscope Measurement |
| **Force Limit** | < 550 N | Calibrated Load Cell Test |
| **Compliance Latency** | < 2 ms | MCU Log/CAN Bus Status |

### 6.2. Behavioral and Ethical Safeguards

*   **Behavioral Guardrails:** Non-Criticality Filter (prevents judgment), Dependency Filter (discourages over-reliance).
*   **Safe Emotional Feedback:** **Gentle Refusal** routine for unsafe tasks, **De-escalation** routine for conflict.
*   **Ethical Directives:** Hard-coded principles equivalent to "Do No Harm," "Maintain Trust," and "Preserve Autonomy."

## 7. Next Steps (Beyond Phase 5)

The platform is complete. Future work should focus on:
1.  **Full-Scale Prototyping:** Moving beyond the Single-Limb Demonstrator.
2.  **LLM Optimization:** Further compression and fine-tuning of the on-board LLM for lower latency and more nuanced personality.
3.  **HRI Refinement:** Long-term HRI studies to refine the Uncanny Valley Index (UVI) and improve the naturalness of the android's motion and gaze.
