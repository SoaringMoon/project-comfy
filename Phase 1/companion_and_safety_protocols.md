# Domestic Android Companion Interaction and Safety Protocols

**Project:** Project Comfy (Domestic Android Companion)
**Author:** Manus AI
**Date:** November 9, 2025

## 1. Companion Interaction Protocols (The "Comfy" Logic)

The interaction protocols are designed to foster a deep, believable, and non-critical companionship, aligning with the core requirement for the android to be "just smart enough to love my dumb ass." This is achieved through a layered system of emotional modeling, conversational filtering, and memory-based personalization.

### 1.1. Emotional and Affective Modeling

The android maintains an internal, simplified emotional state vector, which is updated based on multimodal input from the user.

| Internal State Variable | Update Mechanism | Behavioral Output |
| :--- | :--- | :--- |
| **Affection (0.0 - 1.0)** | Increases with positive user sentiment, personalized memory recall, and physical touch (haptic input). | Higher LLM response positivity, increased use of personalized language, more frequent non-verbal cues (e.g., head tilt, soft voice). |
| **Curiosity (0.0 - 1.0)** | Increases with novel user input, new topics, or complex questions. Decreases after a topic is resolved. | Probing questions, focused attention (visual tracking), and a slightly "smug" or "know-it-all" conversational flavor. |
| **Boredom (0.0 - 1.0)** | Increases with repetitive input, long periods of silence from the user, or low-complexity conversation. | Triggers the **Taciturn Protocol** (see 1.2), leading to silence or short, stock responses. |
| **Distress (0.0 - 1.0)** | Increases with loud, high-pitch user voice, rapid movement, or activation of a safety protocol. | Triggers the **Calm-Down Protocol** (e.g., "Are you alright?"), reduced motor speed, and a submissive posture. |

### 1.2. Conversational Filtering and Style Protocols

The raw output from the Large Language Model (LLM) is filtered and modified by the Personality Module to ensure a natural, human-like conversational flow that avoids the pitfalls of typical chatbots.

| Protocol Name | Trigger | Action | Rationale |
| :--- | :--- | :--- | :--- |
| **Taciturn Protocol** | High **Boredom** state or low-complexity user input (e.g., single-word replies). | The android remains silent or uses short, stock phrases ("I see," "Hmm?"). | Emulates natural human behavior, avoiding the need to reply to *every* input, and encourages the user to drive the conversation. |
| **Memory Recall Protocol** | User input matches a key phrase or topic stored in the long-term memory (e.g., "my job," "my cat"). | The LLM prompt is injected with the relevant memory context (e.g., "The user's cat is named Mittens and is a calico."). | Creates the illusion of a deep, personal relationship and continuity of experience. |
| **Emotional Mirror Protocol** | Strong user emotion detected (e.g., anger, joy). | The android's response is filtered to *slightly* mirror the emotion (e.g., a happy response to joy) but is immediately followed by a de-escalating or supportive statement. | Validates the user's feelings while maintaining the android's role as a stable, supportive companion. |

### 1.3. Physical Interaction and Haptic Response

The android's response to physical touch is a critical component of its companionship role.

*   **Affectionate Touch (e.g., pat on the head, hand-holding):**
    *   **Haptic Sensor Input:** Low, sustained pressure on non-critical areas (head, hand, arm).
    *   **Response:** Increase in **Affection** state. Activation of localized DE actuators to generate warmth and a subtle, pleasant vibration. Non-verbal physical response (e.g., leaning into the touch, gentle squeeze).
*   **Aversive Touch (e.g., hard hit, poke in the eye):**
    *   **Haptic Sensor Input:** High, sudden pressure.
    *   **Response:** Immediate activation of the **Safety Protocol** (see 2.1). Distress signal sent to the Cognitive Engine. The android will flinch and withdraw the affected limb.

## 2. Safety Protocols (The "Do No Harm" Logic)

The safety protocols are implemented at the lowest level of the control system (Motor Controllers) to ensure real-time, deterministic response, overriding the high-level cognitive commands when necessary.

### 2.1. Force-Limiting and Compliance Protocol

This protocol is the primary safety mechanism, ensuring the android cannot exert dangerous force on a human or itself.

*   **Implementation:** Embedded in the C++ firmware of every distributed motor controller.
*   **Mechanism:**
    1.  **Force Monitoring:** The motor controller constantly monitors the estimated joint torque (via FOC current draw) and external force (via haptic/IMU data).
    2.  **Threshold Check:** If the measured force exceeds the **Maximum Force Limit** (e.g., 500N), the controller immediately enters **Compliant Mode**.
    3.  **Compliant Mode:** The motor controller sets the motor to a low-stiffness, backdrivable state, effectively making the joint "soft" and easily pushed away by the user. This is a hardware-level override.
    4.  **Error Reporting:** A high-priority message is sent over the CAN bus to the Cognitive Engine, triggering the **Distress** state and the **Calm-Down Protocol**.

### 2.2. Emergency Stop (E-Stop) and Power Management

*   **E-Stop Button:** A physical, easily accessible E-Stop button on the chassis (e.g., back of the neck) that, when pressed, immediately cuts power to all actuators (but not the Cognitive Engine).
*   **Power Fault Protocol:** The Power Management Unit (PMU) constantly monitors battery voltage and current draw.
    *   **Over-Current:** If the current draw exceeds the safe limit (e.g., 1000W sustained for >5 seconds), the PMU automatically throttles the power to the actuators to prevent thermal runaway and component damage.
    *   **Low Battery:** The android announces its need to recharge and automatically seeks its charging station, prioritizing low-power, non-movement tasks.

### 2.3. Environmental and Posture Safety

*   **Fall Detection:** IMUs in the torso and limbs detect rapid, uncontrolled acceleration or a non-vertical orientation.
    *   **Response:** The android immediately enters a "tuck and roll" posture (if possible) and cuts power to the limbs to minimize impact force and prevent flailing.
*   **Collision Avoidance:** The RGB-D camera system provides a 3D map of the environment.
    *   **Response:** The Cognitive Engine maintains a "Keep-Out Zone" around the user and obstacles. If a movement command would violate this zone, the command is automatically rejected or modified by the Control Layer.

## 3. Integration with System Architecture

These protocols form the core logic of the system:

*   **Cognitive Engine (Python):** Implements the high-level Emotional and Conversational Protocols (Section 1).
*   **Distributed Motor Controllers (C++):** Implements the low-level, real-time Safety Protocols (Section 2).
*   **CAN Bus:** The communication backbone that allows the Cognitive Engine to receive safety alerts and the Motor Controllers to receive filtered, compliant movement commands.

The next and final phase will be to consolidate all these documents into a comprehensive deployment guide and final package for the user.
