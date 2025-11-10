// /home/ubuntu/motor_control_system.h
// Conceptual C++ Header for Low-Level Distributed Motor Control (e.g., on ESP32/STM32)

#ifndef MOTOR_CONTROL_SYSTEM_H
#define MOTOR_CONTROL_SYSTEM_H

#include <stdint.h>

// --- 1. Constants and Configuration ---

// Communication Protocol: CAN Bus ID for this specific joint controller
#define JOINT_CAN_ID 0x101 

// Motor Parameters (specific to the chosen BLDC motor)
#define POLE_PAIRS 7
#define KV_RATING 100 // RPM/Volt
#define MAX_TORQUE_NM 40.0f // Maximum safe torque for this joint (e.g., Hip)

// Safety and Compliance
#define MAX_FORCE_LIMIT_N 500.0f // Max force allowed before compliance activation
#define COMPLIANCE_STIFFNESS 0.1f // Softness factor for compliant mode

// --- 2. Data Structures ---

/**
 * @brief Structure for receiving high-level commands from the Cognition layer.
 */
typedef struct {
    uint8_t mode; // 0: Torque, 1: Velocity, 2: Position, 3: Compliant
    float target_value; // Target torque (Nm), velocity (rad/s), or position (rad)
    float feedforward_torque; // Optional: Torque to overcome gravity/inertia
} JointCommand_t;

/**
 * @brief Structure for sending telemetry data back to the Cognition layer.
 */
typedef struct {
    float actual_position; // Current joint angle (rad)
    float actual_velocity; // Current joint velocity (rad/s)
    float actual_torque;   // Estimated or measured torque (Nm)
    float temperature_c;   // Motor/Driver temperature
    uint8_t error_flags;   // Safety/Error status
} JointTelemetry_t;

// --- 3. Core Control Class ---

class MotorController {
public:
    /**
     * @brief Initializes the motor driver hardware and CAN communication.
     */
    void initialize();

    /**
     * @brief Main control loop function, called at a high frequency (e.g., 1kHz).
     */
    void run_control_loop();

    /**
     * @brief Sets a new command from the high-level AI.
     * @param command The new joint command.
     */
    void set_command(const JointCommand_t& command);

    /**
     * @brief Gets the current telemetry data.
     * @return The current joint telemetry.
     */
    JointTelemetry_t get_telemetry() const;

private:
    JointCommand_t current_command;
    JointTelemetry_t current_telemetry;

    /**
     * @brief Implements the Field-Oriented Control (FOC) algorithm.
     * This is the core of the quiet, efficient BLDC control.
     */
    void field_oriented_control();

    /**
     * @brief Implements the safety and compliance logic.
     * This function checks for over-force and switches to compliant mode if necessary.
     */
    void safety_and_compliance_check();

    /**
     * @brief Implements the logic for the Compliant Mode (Mode 3).
     * This mode allows the joint to be easily backdriven by external force.
     */
    void compliant_mode_logic();
};

// --- 4. Communication Interface (CAN Bus Stub) ---

namespace CAN_Interface {
    /**
     * @brief Simulates receiving a command from the CAN bus.
     * @param command The command to populate.
     * @return True if a new command was received.
     */
    bool receive_command(JointCommand_t& command);

    /**
     * @brief Simulates sending telemetry data over the CAN bus.
     * @param telemetry The data to send.
     */
    void send_telemetry(const JointTelemetry_t& telemetry);
}

#endif // MOTOR_CONTROL_SYSTEM_H
