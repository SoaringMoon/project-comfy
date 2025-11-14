# Digital Twin and Simulation Environment Development Plan

**Project:** Project Comfy (Domestic Android Companion)
**Author:** Manus AI
**Date:** November 11, 2025
**Iteration Focus:** Digital Twin and Simulation Development (Track 7)

## 1. Objective

To create a physics-accurate, parametric digital twin of the Project Comfy platform, enabling rapid, cost-effective testing of mechanical, control, and behavioral modifications prior to physical prototyping.

## 2. Toolchain Selection

| Component | Tool | Rationale |
| :--- | :--- | :--- |
| **Parametric CAD** | **Onshape** (Cloud-based) | Accessibility, collaborative features, and robust parametric modeling. |
| **Physics Simulation** | **Gazebo/ROS** | Industry standard for robotics simulation, excellent integration with control software, and open-source community support. |
| **Model Format** | **URDF/SDF** | Standard format for describing robot kinematics, dynamics, and visual properties in ROS/Gazebo. |
| **Control Interface** | **ROS Control** | Provides a standardized interface for connecting the physical control layer (MCU) to the simulated environment. |

## 3. Development Stages

### 3.1. Stage 1: Kinematic and Visual Model (CAD)

1.  **Model Creation:** Replicate the mechanical design (chassis, limb segments, joint housings) in Onshape, ensuring all dimensions are driven by a central set of parameters (e.g., `Limb_Length_M`, `Joint_Torque_Max`).
2.  **Joint Definition:** Define all joints (revolute and prismatic) and their limits based on the `complete_system_reference.md`.
3.  **Export:** Export the model as a Collada (`.dae`) or STL file for visual representation and generate the initial **URDF** (Unified Robot Description Format) file.

### 3.2. Stage 2: Dynamic and Sensor Model (Gazebo)

1.  **Inertia Calculation:** Calculate the mass and inertia tensors for all links (limb segments) based on the material properties and geometry defined in the CAD model.
2.  **Actuator Modeling:** Implement the motor dynamics (torque limits, velocity limits, friction) using Gazebo's joint controllers, mirroring the FOC performance parameters.
3.  **Sensor Integration:** Model the primary sensors:
    *   **Absolute Encoders:** Joint position feedback.
    *   **Force/Torque Sensors:** Model the compliant behavior and force feedback.
    *   **Vision:** Integrate a simulated camera for visual input to the Cognitive Layer.

### 3.3. Stage 3: Control and HRI Integration

1.  **ROS Control Interface:** Implement the `hardware_interface` to connect the simulated robot to the `comfy-software` (Python) and `comfy-firmware` (C/C++) control logic.
2.  **Data Interface:** Define the **CAN Bus Data Interface** within the simulation, allowing the Python Cognitive Layer to send commands and receive telemetry as if it were communicating with the physical MCUs.
3.  **HRI Validation:** Use the simulation to run the **Gaze Timing Test (ATP-H-02)** and **Gentle Refusal Test (ATP-H-01)** from the `quality_and_safety_compliance.md` to validate behavioral changes in a controlled environment.

## 4. Next Steps

The next phase will be to conduct the first optimization study, focusing on the cost-reduction hypothesis defined in Iteration 1. The digital twin will be used in subsequent iterations to validate the new mechanical design.
