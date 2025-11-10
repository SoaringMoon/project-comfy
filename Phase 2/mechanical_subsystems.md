# Mechanical Subsystems Specification: Project Comfy

**Project:** Project Comfy (Domestic Android Companion)
**Author:** Manus AI
**Date:** November 10, 2025

## 1. Primary Actuation Subsystem (Core Joints)

The primary actuation system focuses on high-torque, low-noise, and compliant movement for the core joints (Hips, Knees, Shoulders). The design is based on Brushless DC (BLDC) motors paired with high-reduction gearboxes.

### 1.1. Hip Joint Module Specification

The Hip Joint is the most critical component, requiring a peak torque of **40 Nm** to support the upper body mass.

| Specification | Value | Rationale |
| :--- | :--- | :--- |
| **Required Peak Torque** | 40 Nm | Based on 20kg upper body mass and lever arm analysis. |
| **Motor Type** | High-Power BLDC Outrunner | High torque density, efficiency, and quiet operation. |
| **Gearbox Type** | Strain Wave Gear (Harmonic Drive) | Zero backlash, high reduction ratio (e.g., 100:1), and compact form factor. |
| **Sensor** | Absolute Magnetic Encoder (14-bit+) | High-resolution position feedback for FOC and compliance control. |
| **Compliance** | Backdrivable (via Strain Wave Gear design) | Essential for safety and implementing force-limiting protocols. |

### 1.2. Bill of Materials (BOM) - Hip Joint (Per Unit)

| Component | Part Number (Example) | Supplier | Cost Est. (USD) | Notes |
| :--- | :--- | :--- | :--- | :--- |
| **BLDC Motor** | T-Motor U8 Lite KV100 | T-Motor / HobbyKing | $150 | High-efficiency, low-KV for torque. |
| **Strain Wave Gear** | Harmonic Drive CSF-8-100-2UJ | Harmonic Drive | $800 | High-precision, zero-backlash. High cost is a major risk factor. |
| **Absolute Encoder** | AS5047P (Magnetic) | AMS / Digi-Key | $25 | High-resolution, robust against dust/vibration. |
| **Housing/Flange** | Custom 3D Print (Titanium/CFRP) | In-House / Service | $50 | Must integrate motor, gear, and encoder. |
| **Total (Est.)** | | | **$1,025** | |

### 1.3. CAD Guidance

*   **Design Focus:** Minimize the axial length of the joint module to maintain a human-like profile.
*   **Integration:** The motor stator must be rigidly mounted to the housing, and the rotor must be coupled to the gear input. The encoder must be placed on the output shaft for absolute position sensing.
*   **Source Suggestion:** Use **Fusion 360** or **SolidWorks** for parametric modeling. Focus on simulating stress on the output flange under the 40 Nm load.

## 2. Secondary Actuation Subsystem (Fine Movement)

This subsystem focuses on soft, quiet, and lifelike movement for hands and face.

### 2.1. Facial Expression Module Specification

| Specification | Value | Rationale |
| :--- | :--- | :--- |
| **Actuator Type** | Nitinol (Shape Memory Alloy) Wire | Quiet, compact, and provides a muscle-like contraction. |
| **Control** | Low-Voltage PWM (Pulse Width Modulation) | Controls the heating/cooling cycle for contraction/relaxation. |
| **Stroke Length** | 3-5% of wire length | Sufficient for subtle facial movements (e.g., eyebrow raise, smile). |
| **Integration** | Anchored to the skull chassis and connected to the microfiber skin layer. | Mimics the action of human facial muscles. |

### 2.2. Bill of Materials (BOM) - Facial Module (Per Unit)

| Component | Part Number (Example) | Supplier | Cost Est. (USD) | Notes |
| :--- | :--- | :--- | :--- | :--- |
| **Nitinol Wire** | 0.15mm Diameter, 10m Spool | Dynalloy (Flexinol) | $30 | Requires custom length cutting and anchoring. |
| **Driver Circuit** | MOSFET Array (Logic-Level) | Digi-Key | $10 | For PWM control of heating current. |
| **Microcontroller** | ESP32-S3 (Dedicated) | Espressif / Adafruit | $15 | Handles PWM generation and communication with the main SBC via CAN Bus. |
| **Total (Est.)** | | | **$55** | |

## 3. Chassis and Structure Subsystem

The structure must be modular to facilitate maintenance and upgrades.

### 3.1. Torso/Pelvis Chassis

*   **Design:** Monocoque structure with integrated mounting points for the Hip Joint Modules and the central Power Management Unit (PMU).
*   **Material:** **CFRP (Carbon Fiber Reinforced Polymer)** is the preferred material for the final design due to its superior strength-to-weight ratio.
*   **Modularity:** Quick-release panels for access to the SBC and PMU.

### 3.2. Limb Segments

*   **Design:** Hollow segments with internal channels for cable routing (CAN Bus, power lines) and a central cavity for the distributed motor controller PCB.
*   **Material:** High-Density PLA/ABS for initial prototyping; final version should use a stronger composite or lightweight metal.

## 4. Risk and Cost Analysis (Mechanical)

| Risk Factor | Description | Mitigation Strategy | Cost Impact |
| :--- | :--- | :--- | :--- |
| **Actuator Cost** | Strain Wave Gears are the single most expensive component. | Explore 3D-printed cycloidal drives (e.g., Open-Source designs) for a low-cost prototype, accepting reduced lifespan/precision. | **High** (Dominates BOM) |
| **Weight Creep** | Accumulation of component weight leads to increased torque requirements. | Strict weight budget for all components; use topology optimization in CAD design; prioritize CFRP for final build. | **Medium** (Material cost) |
| **Noise/Vibration** | Gearbox and motor noise can break the "comfy" illusion. | Use FOC control (software); incorporate vibration dampening mounts for all motors; use zero-backlash gearboxes. | **Medium** (Dampening materials) |
| **Thermal Management** | High-power motors generate heat, which can affect performance and skin temperature. | Integrate passive cooling fins into the joint housing; monitor motor temperature via the encoder/controller. | **Low** (Design complexity) |

## 5. Next Steps

The mechanical design provides the physical framework. The next step is to detail the **Electrical Subsystems** to power and control these mechanical components.
