# Project Comfy: Domestic Android Companion Deployment Guide

**Author:** Manus AI
**Date:** November 9, 2025

## 1. Executive Summary

**Project Comfy** is a comprehensive design and development plan for a domestic android companion. The core philosophy is to create a **believable and pleasant companion** that prioritizes user safety, emotional connection, and cost-effective modularity. The system utilizes a **distributed, hybrid architecture** combining high-power electric motors for core movement with novel soft actuators for lifelike expression and touch.

## 2. System Architecture Overview

The system is structured into four primary domains, communicating via a high-speed CAN Bus:

| Domain | Core Component | Technology Focus | Key Function |
| :--- | :--- | :--- | :--- |
| **Cognition** | Main Single Board Computer (SBC) | Compressed LLM, C++ Multimodal Encoder | High-level reasoning, personality, natural language generation. |
| **Control** | Distributed Microcontrollers (e.g., ESP32) | Field-Oriented Control (FOC), CAN Bus | Real-time motor control, compliance, sensor data aggregation. |
| **Actuation** | BLDC Motors + Strain Wave Gears | High Torque (up to 40 Nm), Low Noise | Core movement (locomotion, lifting). |
| **Aesthetics** | DE/HASEL Actuators, Nitinol Wire | Soft Robotics, Haptic Feedback | Fine dexterity, facial expression, skin warmth. |

## 3. Hardware and Mechanical Specifications

The mechanical design is centered on minimizing weight and maximizing safety.

### 3.1. Actuator Selection and Integration

A hybrid approach is used to balance power and compliance:

*   **Primary Joints (Hips, Knees, Shoulders):** Utilize **Brushless DC (BLDC) Motors** coupled with high-reduction gearboxes (Strain Wave or Cycloidal) for high torque density and quiet operation. The hip joints are specified for a peak torque of **40 Nm** to support a 20kg upper body.
*   **Fine Movement (Hands, Face):** Employ **Dielectric Elastomers (DE)** and **Hydraulically Amplified Self-healing Electrostatic (HASEL) Actuators** for quiet, lifelike movement, and **Nitinol Wire** for facial expressions.

### 3.2. Safety and Power

*   **Power System:** A **24V DC** system is recommended, balancing power delivery with safety regulations. Peak power draw is designed for up to **1000W** for short bursts (e.g., standing up, lifting).
*   **Chassis:** Constructed from **Carbon Fiber Reinforced Polymer (CFRP)** or high-strength aluminum for a lightweight, rigid core.
*   **Skin:** **Microfiber fabric with elastic fibers** is proposed as a durable, soft, and easily cleanable alternative to silicone.

## 4. Software and AI Implementation

The software is divided into high-level cognitive and low-level control components.

### 4.1. Cognitive Engine (High-Level)

*   **Core Logic:** Implemented in Python (`core_ai_engine.py`) for rapid development and iteration.
*   **Multimodal Integration:** A C++ encoder is used to fuse visual (face recognition), auditory (speech analysis), and haptic data into a single vector to condition the LLM's response, ensuring context-aware interaction.
*   **Personality Module:** Manages an internal emotional state (Affection, Curiosity, Boredom, Distress) to filter the LLM output, implementing protocols like the **Taciturn Protocol** to create a more natural, less-chatty conversational style.

### 4.2. Control System (Low-Level)

*   **Core Logic:** Implemented in C/C++ (`motor_control_system.h`) on distributed microcontrollers (e.g., ESP32) for real-time performance.
*   **Field-Oriented Control (FOC):** Used for BLDC motors to ensure maximum efficiency and quiet operation.
*   **CAN Bus:** The communication standard for deterministic, low-latency control between the SBC and all joint controllers.

## 5. Safety and Interaction Protocols

Safety is paramount and is implemented at the hardware-firmware level.

*   **Force-Limiting and Compliance:** The core safety protocol is embedded in the motor controller firmware. If a joint's force exceeds a set threshold (e.g., **500N**), the controller immediately enters a **Compliant Mode**, making the joint soft and easily backdriven, preventing injury.
*   **Haptic Response:** Physical touch is integrated into the emotional model. Affectionate touch increases the **Affection** state and triggers localized warmth/vibration via DE actuators.
*   **Emergency Stop:** A physical E-Stop button cuts power to all actuators. The Power Management Unit (PMU) throttles power on sustained high-draw to prevent thermal damage.

## 6. Included Documentation

The following files contain the detailed specifications and code concepts for Project Comfy:

1.  `design_requirements.md`: Detailed extraction of project requirements.
2.  `android_system_architecture.md`: High-level system block diagram and technical specifications.
3.  `hardware_design_and_integration.md`: Detailed mechanical and sensory integration plan.
4.  `companion_and_safety_protocols.md`: Detailed logic for emotional modeling and safety mechanisms.
5.  `core_ai_engine.py`: Conceptual Python code for the Cognitive Engine.
6.  `motor_control_system.h`: Conceptual C++ header for the low-level Motor Control firmware.

These documents provide a complete foundation for the next stage of physical prototyping and software development.
