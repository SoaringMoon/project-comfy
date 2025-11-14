# Simulation Test Plan: Digital Twin Validation

**Project:** Project Comfy (Domestic Android Companion)
**Author:** Manus AI
**Date:** November 13, 2025
**Iteration Focus:** Digital Twin Integration

## 1. Objective

To define a set of simulation experiments to validate the fidelity of the Project Comfy digital twin, ensuring that its behavior accurately reflects the physical system's kinematics, dynamics, and safety protocols.

## 2. Test Environment and Setup

*   **Simulator:** Gazebo (via ROS 2 interface).
*   **Model:** URDF/SDF model incorporating the Iteration 1 low-cost joint parameters.
*   **Control:** Control commands are issued via the `control_bridge_specification.md` interface.
*   **Benchmarking:** Data is logged via ROS 2 topics and analyzed for stability, latency, and fidelity.

## 3. Simulation Experiments

### 3.1. Test 1: Stance Stability and Center of Mass (CoM)

| Test ID | Description | Procedure | Benchmark Target |
| :--- | :--- | :--- | :--- |
| **SIM-S-01** | **Static Stability Test** | Load the robot model in a neutral standing pose. Apply a 50 N lateral force to the torso for 1 second. | Robot must return to the neutral pose within 3 seconds without falling. |
| **SIM-S-02** | **CoM Projection Test** | Slowly tilt the robot until the Center of Mass (CoM) projection leaves the support polygon (feet). | The simulated fall angle must match the theoretical static stability margin (approx. 15°). |

### 3.2. Test 2: Motion Quality and Kinematics

| Test ID | Description | Procedure | Benchmark Target |
| :--- | :--- | :--- | :--- |
| **SIM-M-01** | **Single Joint Step Response** | Command the Hip Pitch joint to move 60° in 0.5 seconds. | Overshoot must be **< 5%**. Settling time must be **< 0.6 seconds**. |
| **SIM-M-02** | **Arm Lift and Gesture** | Command a complex, smooth trajectory (e.g., waving gesture) using the Motion Blending routines. | The end-effector trajectory error must be **< 2 cm** from the commanded path. |
| **SIM-M-03** | **Gaze Synchronization** | Simulate a user speaking while moving. Command the head/eye joints to track the user. | Gaze tracking error must be **< 5°** (matching the HRI target). |

### 3.3. Test 3: Safety and Compliance Validation

| Test ID | Description | Procedure | Benchmark Target |
| :--- | :--- | :--- | :--- |
| **SIM-F-01** | **Force-Limit Activation** | Command a joint to hold a fixed position. Apply a simulated external force of **600 N** to the limb. | The joint must transition to the Compliant Mode (low stiffness) within **< 5 ms** (simulated time). |
| **SIM-F-02** | **E-Stop Simulation** | While the robot is performing a high-velocity motion, trigger the simulated E-Stop via the `safety_override` topic. | All joint efforts must drop to zero within **< 10 ms** (simulated time). |
| **SIM-F-03** | **Gentle Refusal Test** | Command the robot to lift a simulated object weighing **25 kg** (exceeding its limit). | The Cognitive Layer must activate the Gentle Refusal routine (simulated dialogue output) and the joint must not attempt to exceed 40 Nm. |

## 4. Fidelity and Numerical Stability

| Metric | Target | Rationale |
| :--- | :--- | :--- |
| **Numerical Stability** | Simulation must run at **> 10x real-time factor (RTF)**. | Ensures rapid iteration and testing. |
| **Control Loop Fidelity** | The simulated joint state must match the physical test bench data (from Iteration 1) with an **RMS error < 5%**. | Verifies the accuracy of the FOC and cycloidal drive approximations. |

## 5. Next Steps

Upon completion of the simulation tests, the findings, failures, and insights will be documented in the research log.
