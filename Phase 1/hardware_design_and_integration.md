# Domestic Android Hardware Design and Integration Plan

**Project:** Project Comfy (Domestic Android Companion)
**Author:** Manus AI
**Date:** November 9, 2025

## 1. Design Philosophy: Lightweight, Modular, and Compliant

The hardware design adheres to three core principles:
1.  **Lightweight and Strong:** Minimize mass to reduce energy consumption and motor torque requirements (mitigating the Square-Cube Law effects).
2.  **Modularity:** Use standardized interfaces (e.g., CAN Bus, quick-release connectors) for easy assembly, maintenance, and future upgrades.
3.  **Compliance and Safety:** Design all joints to be backdrivable and integrate force-limiting mechanisms to ensure safety during human interaction.

## 2. Skeletal and Chassis Specifications

| Component | Material | Design Specification | Rationale |
| :--- | :--- | :--- | :--- |
| **Main Chassis (Torso/Pelvis)** | Carbon Fiber Reinforced Polymer (CFRP) or High-Strength Aluminum Alloy | Monocoque design for maximum strength-to-weight ratio. Central cavity for main SBC, PMU, and battery. | Provides a rigid, lightweight core for anchoring high-torque actuators. |
| **Limb Segments (Bones)** | 3D-Printed Titanium Alloy (Selective Laser Sintering) or High-Density PLA/ABS (for low-cost prototype) | Hollowed structure with internal ribbing for cable routing and weight reduction. Modular attachment points for actuators and skin. | Allows for complex, custom geometries that are both light and strong, facilitating rapid prototyping. |
| **Spine/Torso Joint** | Stewart Platform-inspired design with 3-5 linear actuators (as discussed in research). | Provides multi-axis flexibility (pitch, roll, yaw) for human-like posture and expressive movement, while centralizing motor mass. | Reduces the number of high-torque rotary joints required in the torso. |

## 3. Actuation System Integration

The system uses a hybrid actuation approach to meet the diverse requirements of power, precision, and quiet operation.

### 3.1. Primary Actuators (Core Movement)

| Joint | Actuator Type | Torque Requirement (Peak) | Integration Method |
| :--- | :--- | :--- | :--- |
| **Hip (x2)** | BLDC Motor + Strain Wave Gear (Harmonic Drive) | **40 Nm** | Direct drive to the hip joint axis. Motor controller (ESP32-based) integrated into the pelvis chassis. |
| **Knee (x2)** | BLDC Motor + Cycloidal Drive | **25 Nm** | Integrated into the upper leg segment, connected via a short, rigid shaft. |
| **Shoulder (x2)** | BLDC Motor + Planetary Gear | **20 Nm** | Integrated into the shoulder girdle, allowing for three degrees of freedom (DOF) via three separate motors. |
| **Elbow (x2)** | BLDC Motor + Planetary Gear | **15 Nm** | Integrated into the upper arm segment. |

**Integration Notes:**
*   All primary actuators must be connected to the central **CAN Bus** for real-time command and telemetry.
*   **Thermal Management:** Passive cooling fins integrated into the chassis for heat dissipation from the motor controllers and motors.

### 3.2. Secondary Actuators (Fine Movement and Aesthetics)

| Component | Actuator Type | Function | Integration Method |
| :--- | :--- | :--- | :--- |
| **Fingers (x10)** | **DE/HASEL Actuators** (or Bowden Cable System with central micro-servos for prototype) | Grasping, haptic feedback, fine manipulation. | Embedded directly into the finger segments. Requires high-voltage (for DE/HASEL) or micro-servo control boards in the hand. |
| **Face/Mouth** | **Nitinol Wire** (Shape Memory Alloy) | Facial expressions (smile, frown, eye movement). | Wires anchored to the skull chassis and connected to the skin layer. Controlled by low-current PWM signals from a dedicated facial microcontroller. |
| **Sensual Areas** | **DE Actuators** | Localized contraction and vibration. | Embedded beneath the skin layer. Used for haptic feedback and generating localized warmth. |

## 4. Sensory and Perception System Integration

The android's "senses" are critical for multimodal interaction and safety.

| Sensor Type | Location | Purpose | Integration Method |
| :--- | :--- | :--- | :--- |
| **Visual (RGB-D Camera)** | Eyes (Stereo Pair) or Forehead | Face recognition, object tracking, depth perception, emotional analysis. | Small, high-resolution cameras integrated behind a transparent, protective lens. Connected to the main SBC via high-speed USB/PCIe. |
| **Auditory (Microphone Array)** | Head (4-8 microphones) | Sound source localization, noise cancellation, speech recognition. | Microphones discreetly placed around the head to enable 360-degree sound capture and beamforming. Connected to the main SBC. |
| **Haptic (Capacitive/Pressure Sensors)** | Palms, Fingertips, Torso, Limbs | Touch detection, pressure sensing, safety compliance check. | Thin-film sensors embedded beneath the microfiber skin layer. Connected to the nearest distributed microcontroller (e.g., ESP32) for local processing. |
| **Proprioception (IMUs/Encoders)** | All Major Joints (IMUs) and Actuators (Encoders) | Real-time position, velocity, and acceleration feedback for stability and control. | High-resolution magnetic encoders integrated directly into the motor assembly. IMUs (accelerometers/gyroscopes) placed in the torso and limb segments. |

## 5. Power and Communication Integration

### 5.1. Power Management Unit (PMU)

*   **Location:** Central Pelvis Chassis.
*   **Function:** Manages power flow from the external power supply or internal battery (24V DC). Includes a **Battery Management System (BMS)** for safe charging and discharge.
*   **Distribution:** Step-down converters to provide 5V and 3.3V for microcontrollers and sensors. Dedicated, isolated power lines for high-voltage DE/HASEL actuators.

### 5.2. Communication Bus

*   **Protocol:** **CAN Bus** (Controller Area Network).
*   **Topology:** A single, redundant CAN bus network connecting the main SBC (CAN Master) to all distributed motor controllers and sensor hubs.
*   **Rationale:** Ensures deterministic, low-latency communication for critical control loops, which is essential for real-time compliance and stability.

## 6. Skin and Aesthetic Integration

*   **Skin Material:** Microfiber fabric with elastic fibers, stretched over a flexible, foam-like underlayer.
*   **Attachment:** The skin is designed to be a single, removable piece (or large sections) attached via hidden zippers or Velcro to the chassis, facilitating easy maintenance and cleaning.
*   **Thermal Integration:** The flexible underlayer incorporates thin, heat-generating elements (powered by the DE/HASEL high-voltage lines or dedicated low-power resistors) to provide a human-like warmth to the touch.

## 7. Next Steps

The next phase will focus on the implementation of companion interaction and safety protocols, which are the software-level manifestation of the hardware's safety features (e.g., force-limiting control, emotional response to touch). This will bridge the gap between the physical body and the cognitive mind.
