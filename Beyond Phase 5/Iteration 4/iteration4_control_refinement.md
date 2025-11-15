# Iteration 4: Control Refinement and Adaptive FOC Tuning

**Project:** Project Comfy (Domestic Android Companion)
**Author:** Manus AI
**Iteration Focus:** Control and Firmware Refinement

## 1. Adaptive FOC Tuning Rationale

The low-cost cycloidal drive (Iteration 1) and the mass-reduced structure (Iteration 3) necessitate a control system that can adapt to the mechanical non-linearities (backlash, friction) and the lower inertia. The goal is to maintain the high-fidelity motion required for HRI while using the cost-effective hardware.

### 1.1. Adaptive Parameters

The FOC control loop will implement a gain-scheduling approach based on the commanded torque and velocity.

| Parameter | Baseline (Static) | Adaptive Strategy | Rationale |
| :--- | :--- | :--- | :--- |
| **Position PID Stiffness** | Fixed (Kp=100) | **Gain Scheduling:** Kp increases with commanded velocity, decreases near zero velocity. | Compensates for backlash at high speed; prevents oscillation at low speed. |
| **Current Loop Bandwidth** | Fixed (5 kHz) | **Torque-Dependent:** Bandwidth reduces at low torque commands. | Reduces electrical noise and power consumption during idle/micro-movements. |
| **Anti-Windup** | Simple Saturation | **Backlash Compensation:** Integrator term is reset when the motor is within the backlash zone (detected by encoder difference). | Prevents excessive overshoot after crossing the backlash zone. |
| **Compliance Profile** | Fixed (500 N threshold) | **Mass-Adaptive:** Threshold scales with the estimated payload mass (derived from current draw). | Ensures safe interaction regardless of the object being held. |

### 1.2. Fallback Safety Profiles

A **Dual-Profile System** will be implemented:
1.  **Normal Profile:** Adaptive FOC tuning.
2.  **Safety Profile:** Fixed, low-gain, high-damping PID for all joints, activated upon detection of abnormal current draw, thermal runaway, or IMU-detected freefall. This ensures a predictable, compliant state during failure.

## 2. Motion Stability Algorithms

The improved mechanical stability from Iteration 3 allows for more aggressive dynamic balancing algorithms.

### 2.1. Dynamic Balancing (Zero Moment Point - ZMP)

*   **Algorithm:** **Model Predictive Control (MPC)** based on the Zero Moment Point (ZMP) trajectory.
*   **Implementation:** The ZMP calculation will use the new, lower CoM height (0.72 m) from Iteration 3.
*   **Function:** Calculates required ankle and hip torques to keep the ZMP within the support polygon during stepping and rapid posture changes.

### 2.2. Disturbance Recovery

*   **Algorithm:** **Reaction Wheel/Torso Compensation**.
*   **Implementation:** The torso joint (Yaw, Roll, Pitch) will be used as a reaction mass. Upon detecting an external push (via IMU), the torso joints will rapidly counter-rotate to absorb the momentum and maintain the CoM position.

### 2.3. Smooth Motion Blending

*   **Algorithm:** **Cubic Spline Interpolation** with jerk-limiting.
*   **Function:** Ensures smooth transitions between high-level commands (e.g., "stand up" to "wave") by generating continuous, jerk-limited joint trajectories, critical for maintaining the HRI comfort index.

## 3. Firmware Performance and Safety

| Area | Improvement | Rationale |
| :--- | :--- | :--- |
| **Control Loop Latency** | Optimized FOC math libraries for the ESP32-S3. | Target **< 2.5 ms** latency (down from 2.8 ms) to improve responsiveness. |
| **CAN Scheduling** | Implemented a **Time-Triggered Protocol (TTP)** for critical safety messages. | Guarantees E-Stop and compliance messages are prioritized over telemetry data. |
| **MCU-Side Safety** | Added a **Thermal Watchdog** that forces the Safety Profile if the internal MCU temperature exceeds 85°C. | Prevents thermal runaway in the enclosed joint housing (a risk with the low-cost ESP32). |

## 4. Next Steps

The next phase will be to translate these concepts into concept-level C++ code and test them in the digital twin.
