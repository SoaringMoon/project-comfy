# Digital Twin: URDF/SDF Model and Simulation Configuration

**Project:** Project Comfy (Domestic Android Companion)
**Author:** Manus AI
**Date:** November 13, 2025
**Iteration Focus:** Digital Twin Integration

## 1. Model Format Selection

The primary model format will be **URDF (Unified Robot Description Format)**, as it is the standard for ROS and provides a clean, hierarchical structure for defining the robot's kinematics. The URDF will be converted to **SDF (Simulation Description Format)** for use in Gazebo, as SDF offers more robust support for physics simulation features like complex joints, environmental interactions, and non-fixed sensors.

## 2. URDF Structure and Link/Joint Definitions

The URDF will define the robot as a chain of **links** (rigid bodies) connected by **joints** (degrees of freedom).

### 2.1. Root Link and Base Frame

*   **Root Link:** `torso_link` (Defined as the center of the main body).
*   **Base Frame:** The world frame will be attached to the `torso_link` via a fixed joint for initial stability testing, and later converted to a floating joint for locomotion.

### 2.2. Joint Definition Example (Hip Pitch Joint)

| Parameter | Value/Description | Rationale |
| :--- | :--- | :--- |
| **Joint Name** | `hip_pitch_L` | Standardized naming. |
| **Type** | `revolute` | Rotational joint. |
| **Parent Link** | `torso_link` | Attached to the main body. |
| **Child Link** | `thigh_link_L` | The upper leg segment. |
| **Axis** | `0 1 0` | Rotation around the Y-axis (pitch). |
| **Limit (Effort)** | 40.0 | Corresponds to the 40 Nm peak torque. |
| **Limit (Velocity)** | 5.0 | 5 rad/s (approx. 47 RPM) maximum speed. |
| **Limit (Lower/Upper)** | -2.0 / 0.5 | -120° (flexion) to 30° (extension). |

## 3. Dynamic Properties and Inertia Tensors

Accurate simulation requires precise definition of the mass and inertia of each link. These values are derived from the parametric CAD model (`iteration2_cad_structure.md`).

### 3.1. Inertia Tensor Calculation

The inertia tensor for each link will be calculated using the CAD software's mass properties tool, based on the material density (e.g., `Material_Density_CFPLA` = 1.45 g/cm³).

*   **Example (Thigh Link):**
    *   `mass`: 1.5 kg
    *   `ixx`: 0.015, `iyy`: 0.015, `izz`: 0.001
    *   `ixy`, `ixz`, `iyz`: 0.0 (Assumed symmetric for initial model)

### 3.2. Collision and Visual Meshes

*   **Visual Mesh:** High-resolution `.dae` or `.stl` files for realistic rendering.
*   **Collision Mesh:** Simplified, convex hull meshes to reduce computational load and ensure stable physics interactions.

## 4. Simulation Configuration (Gazebo)

### 4.1. Actuator Modeling

The Gazebo simulation will use the **`gazebo_ros_control`** plugin to model the actuators.

*   **Joint Type:** Position-controlled joints with force limits.
*   **Friction:** Friction parameters (`mu1`, `mu2`) will be added to the joints to simulate the mechanical losses and friction inherent in the cycloidal drive (Iteration 1 finding).

### 4.2. Sensor Stubs

Simulated sensors will be added to the model to provide input to the Cognitive Layer.

| Sensor | Gazebo Plugin | Output Topic (ROS 2) | Purpose |
| :--- | :--- | :--- | :--- |
| **IMU** | `libgazebo_ros_imu.so` | `/comfy/imu/data` | Torso stability and orientation. |
| **Camera** | `libgazebo_ros_camera.so` | `/comfy/camera/image_raw` | Visual input for HRI and object recognition. |
| **Force/Torque** | `libgazebo_ros_ft_sensor.so` | `/comfy/ft_sensor/L_foot` | Ground reaction forces for locomotion. |

## 5. Next Steps

The next phase will define the control bridge, which is the critical interface that allows the existing firmware and software to interact with this simulated environment.
