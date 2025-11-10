# Software Architecture Expanded: Project Comfy

**Project:** Project Comfy (Domestic Android Companion)
**Author:** Manus AI
**Date:** November 10, 2025

## 1. Architectural Overview: The Layered Model

The software architecture is a three-layered model designed for performance, modularity, and safety:

1.  **Cognition Layer (High-Level):** Non-deterministic, complex processing (AI, NLP, Personality). Runs on the main SBC (Python/LLM).
2.  **Control Layer (Mid-Level):** Deterministic, real-time command translation and safety monitoring. Runs on distributed Microcontrollers (C/C++).
3.  **Actuation Layer (Low-Level):** Hardware-specific control (FOC, PWM). Embedded in the Microcontroller firmware.

## 2. Control Layer Firmware Logic (C/C++)

The firmware on each distributed motor controller is the heart of the android's physical safety and responsiveness.

### 2.1. Core Firmware Loop

The firmware executes a high-frequency (e.g., 1 kHz) control loop:

1.  **CAN Receive:** Check for new `JointCommand_t` messages from the Cognition Layer.
2.  **Sensor Read:** Read absolute encoder position, motor current (for FOC), and local haptic sensor data.
3.  **Safety Check:** Execute `safety_and_compliance_check()`:
    *   If **Force > Max Limit**, override command and switch to **Compliant Mode**.
    *   If **Temperature > Max Limit**, throttle power and send a warning.
4.  **Control Execution:** Execute the commanded mode (Torque, Velocity, or Position) using the **Field-Oriented Control (FOC)** algorithm.
5.  **CAN Transmit:** Send updated `JointTelemetry_t` (position, torque, status) back to the Cognition Layer.

### 2.2. Data Flow: FOC and Compliance

| Data Point | Source | Destination | Frequency | Purpose |
| :--- | :--- | :--- | :--- | :--- |
| **Target Torque (Tq)** | Cognition Layer (via CAN) | MCU Control Loop | 100 Hz | High-level movement goal. |
| **Actual Current (I_a, I_b, I_c)** | Current Sense Resistors (ADC) | MCU FOC Algorithm | 1 kHz | Real-time input for FOC calculation. |
| **Rotor Angle (θ)** | Absolute Encoder (SPI) | MCU FOC Algorithm | 1 kHz | Required for vector control. |
| **Actual Torque (Tq_est)** | MCU (Calculated) | Safety Check, CAN Telemetry | 1 kHz | Primary input for the Force-Limiting Protocol. |

## 3. Cognition Layer Software (Python/LLM)

The Cognition Layer handles the complex, non-deterministic tasks of perception and personality.

### 3.1. Multimodal Data Pipeline

The pipeline is designed to fuse diverse sensor data into a coherent context for the LLM.

1.  **Perception Modules (C++ / Optimized Libraries):**
    *   **Visual:** OpenCV/OakD for face recognition, pose estimation, and object tracking. Outputs a JSON object containing recognized entities and their emotional state.
    *   **Auditory:** Speech-to-Text (STT) and Prosody Analysis (pitch, speed, volume).
2.  **Multimodal Encoder (Python/C++ Bindings):**
    *   Takes the JSON/text outputs and converts them into a fixed-size **Context Vector**.
    *   **Vector Composition:** Concatenates embeddings for Text, Visual Context, and Auditory Prosody.
3.  **LLM Interface:** The Context Vector is prepended to the user's text input, conditioning the LLM to generate a context-aware response.

### 3.2. Personality and Memory Management

*   **Emotional State Vector:** A dictionary of floating-point values (Affection, Curiosity, Boredom, Distress) is maintained in a persistent database (e.g., SQLite).
*   **Memory System:** Stores key user facts and past interactions.
    *   **Short-Term Memory (STM):** Recent 10-20 turns of conversation.
    *   **Long-Term Memory (LTM):** Personalized facts (e.g., "Owner's name is Alex," "Likes coffee"). Uses a simple vector search (e.g., FAISS) to retrieve relevant facts based on the current conversation topic.
*   **Response Filter:** The **Personality Module** (as detailed in `companion_and_safety_protocols.md`) applies the **Taciturn Protocol** and emotional flavoring to the raw LLM output before it is sent to the Text-to-Speech (TTS) module.

## 4. Communication Architecture

The communication system is the backbone linking the two primary layers.

| Communication Link | Protocol | Purpose | Bandwidth/Latency |
| :--- | :--- | :--- | :--- |
| **SBC ↔ MCU** | **CAN Bus** | Real-time command and telemetry. | High Reliability, Low Latency (< 1ms) |
| **SBC ↔ Camera** | USB 3.0 / PCIe | High-bandwidth video/depth stream. | High Bandwidth (> 5 Gbps) |
| **SBC ↔ Internet** | Wi-Fi / Ethernet | LLM updates, external knowledge access. | Standard Network |

## 5. Risk and Cost Analysis (Software)

| Risk Factor | Description | Mitigation Strategy | Cost Impact |
| :--- | :--- | :--- | :--- |
| **LLM Latency** | Slow response time breaks the illusion of companionship. | Use highly compressed, quantized models (e.g., 4-bit) on dedicated SBC hardware (e.g., Jetson/Coral); implement the AIML Fallback for instant responses. | **Medium** (Hardware/Optimization time) |
| **FOC Implementation** | Incorrect FOC tuning leads to motor inefficiency, noise, and instability. | Use established open-source FOC libraries (e.g., SimpleFOC) as a starting point; dedicate significant testing time to tuning the PID controllers. | **High** (Development time) |
| **Multimodal Fusion** | Poor fusion leads to context-unaware or nonsensical responses. | Use a simple, proven concatenation method initially; focus on robust pre-processing of sensor data (e.g., high confidence scores for face recognition). | **Medium** (Algorithm complexity) |
| **Safety Override Failure** | Software bug prevents the safety check from engaging. | Implement the safety check at the highest priority interrupt level in the firmware; use hardware watchdogs; ensure the safety check is independent of the high-level command. | **Critical** (Testing/Verification time) |
