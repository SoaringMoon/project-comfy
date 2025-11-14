# Control Bridge Specification: Digital Twin Interface

**Project:** Project Comfy (Domestic Android Companion)
**Author:** Manus AI
**Date:** November 13, 2025
**Iteration Focus:** Digital Twin Integration

## 1. Objective

To define the interface that allows the existing `comfy-software` (Cognitive Layer) and `comfy-firmware` (Control Layer) logic to operate seamlessly with the Gazebo simulation, effectively replacing the physical CAN Bus with a virtual communication channel.

## 2. Bridging Architecture: ROS 2 / CAN Emulation

The bridge will utilize **ROS 2** as the middleware to connect the Python Cognitive Layer to the Gazebo simulation. This approach is superior to direct CAN emulation as it leverages ROS 2's built-in tools for data logging, visualization, and standardized control interfaces.

### 2.1. Data Flow Diagram (Pseudocode)

```mermaid
graph LR
    subgraph Cognitive Layer (Python)
        A[Personality Engine] --> B(High-Level Command Generator);
    end
    subgraph Control Bridge (ROS 2 Node)
        B --> C{ROS 2 Topic: /comfy/joint_command};
        C --> D[ROS 2 Control Interface];
        E[ROS 2 Topic: /comfy/joint_state] --> F(Telemetry Parser);
    end
    subgraph Simulation (Gazebo)
        D --> G[Gazebo Joint Controller];
        G --> H[Gazebo Physics Engine];
        H --> I[Gazebo Sensor Output];
        I --> E;
    end
    F --> A;
```

## 3. Interface Specifications

### 3.1. Command Interface (Cognitive Layer to Simulation)

The Cognitive Layer sends commands via a standardized ROS 2 topic, effectively replacing the physical CAN Bus Joint Command message.

| Parameter | ROS 2 Topic | ROS 2 Message Type | Purpose |
| :--- | :--- | :--- | :--- |
| **Joint Command** | `/comfy/joint_command` | `sensor_msgs/JointState` | Target position, velocity, or effort for all joints. |
| **Safety Override** | `/comfy/safety_override` | `std_msgs/Bool` | Simulates the E-Stop or Compliant Mode activation. |

### 3.2. Telemetry Interface (Simulation to Cognitive Layer)

The simulation publishes the joint state and sensor data, replacing the physical CAN Bus Joint Telemetry message.

| Parameter | ROS 2 Topic | ROS 2 Message Type | Purpose |
| :--- | :--- | :--- | :--- |
| **Joint State** | `/comfy/joint_state` | `sensor_msgs/JointState` | Current position, velocity, and effort (torque) of all joints. |
| **IMU Data** | `/comfy/imu/data` | `sensor_msgs/Imu` | Torso orientation and acceleration. |
| **Camera Feed** | `/comfy/camera/image_raw` | `sensor_msgs/Image` | Visual input for the Cognitive Layer's perception module. |

## 4. FOC and Compliance Simulation Approximations

Since the physical FOC firmware runs at 350 Hz (Iteration 1) on the ESP32, the simulation must approximate this behavior without running the actual C/C++ code.

| Physical Behavior | Simulation Approximation | Rationale |
| :--- | :--- | :--- |
| **FOC Loop (350 Hz)** | **PID Controller in Gazebo** | Uses Gazebo's built-in PID to simulate the motor's response to a target command, tuned to match the physical rise time and overshoot. |
| **Compliance Protocol** | **Joint Force Limit Plugin** | A custom Gazebo plugin that monitors the joint effort and, upon exceeding the 500 N threshold, switches the joint controller from position/torque mode to a passive, low-stiffness mode. |
| **Torque Limit** | **URDF Effort Limit** | The maximum effort is hard-coded in the URDF joint definition (40 Nm). |

## 5. Pseudocode for Firmware Validation

The physical firmware can be validated against the simulation by using a **Hardware-in-the-Loop (HIL)** setup.

```python
# Pseudocode for HIL Validation

def run_hil_test(firmware_instance):
    # 1. Initialize Simulation and Physical Firmware
    sim_node = ROS2Node('simulation_bridge')
    
    # Physical firmware is running on the ESP32 (firmware_instance)
    
    # 2. Send Command to BOTH
    target_position = 0.5  # radians
    sim_node.publish_command(target_position)
    firmware_instance.send_can_command(target_position)
    
    # 3. Monitor and Compare Telemetry
    sim_telemetry = sim_node.subscribe_telemetry()
    physical_telemetry = firmware_instance.subscribe_can_telemetry()
    
    # 4. Check for Safety Compliance
    # Simulate a sudden external force in Gazebo
    sim_node.apply_external_force(joint='hip_pitch_L', force=600)
    
    # Check if both systems activate Compliant Mode
    assert sim_telemetry.compliant_mode_active == True
    assert physical_telemetry.compliant_mode_active == True
    
    # 5. Log and Report
    # Log the difference between sim_telemetry and physical_telemetry for error analysis.
```
