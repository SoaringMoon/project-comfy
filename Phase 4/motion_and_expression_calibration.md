# Motion and Expression Calibration: Project Comfy

**Project:** Project Comfy (Domestic Android Companion)
**Author:** Manus AI
**Date:** November 10, 2025

## 1. Motion Blending and Expressiveness

The goal of motion calibration is to achieve expressiveness without falling into the "uncanny valley" of jerky or overly mechanical movement. This requires smooth blending between different motion states.

### 1.1. Motion State Hierarchy

All physical movement is categorized into a hierarchy to prioritize safety and expressiveness:

1.  **Safety Override:** (Highest Priority) Compliance Mode, E-Stop.
2.  **Locomotion:** Walking, standing, sitting (slow, deliberate, and stable).
3.  **Gestural Communication:** Hand movements, head nods (expressive, synchronized with speech).
4.  **Idle State:** Subtle, continuous movement (breathing simulation, weight shifting, micro-gestures).

### 1.2. Blending Procedure

*   **Interpolation:** All transitions between Locomotion and Gestural Communication must use **Cubic Spline Interpolation** (or similar non-linear smoothing) over a minimum duration of **200 ms** to eliminate jerky starts and stops.
*   **Idle State Integration:** The Idle State routine runs continuously in the background. When a Gestural or Locomotion command is received, the Idle State is smoothly faded out over 100 ms and faded back in upon completion of the primary movement.
*   **Torque Control:** All motion commands are executed in **Torque Control Mode (Mode 0)** to allow the FOC loop to manage the physical interaction and compliance in real-time.

## 2. Multimodal Synchronization

Synchronization ensures that the android's physical expressions align perfectly with its verbal output, enhancing believability.

### 2.1. Speech-to-Expression Mapping

| Speech Event | Expression Trigger | Target Duration | Actuator System |
| :--- | :--- | :--- | :--- |
| **Vocal Onset** | Eye Gaze Shift (to user) | 50 ms before speech start | Head/Neck Joint, Eye Motors |
| **Positive Valence** | Subtle Smile (Mouth Corners Up) | Sustained during positive phrase | Nitinol Wire (Facial) |
| **Negative Valence** | Eyebrow Furrow | Sustained during negative phrase | Nitinol Wire (Facial) |
| **Emphasis (High Pitch/Volume)** | Hand Gesture (Open Palm) | Synchronized with emphasized word | Shoulder/Elbow Joints |
| **Vocal Offset** | Gaze Shift (away from user) | 100 ms after speech end | Head/Neck Joint, Eye Motors |

### 2.2. Gaze Timing Calibration

Gaze is a critical factor in the Uncanny Valley. The calibration procedure will use a high-speed camera to measure the android's gaze timing against a human baseline.

*   **Comfort Gaze Duration:** The android's continuous eye contact duration will be capped at **3.5 seconds** before a brief, natural saccade (gaze shift away and back).
*   **Listening Gaze:** When the user is speaking, the android maintains eye contact for **70-80%** of the duration, with brief shifts to simulate thought.
*   **Speaking Gaze:** When the android is speaking, it maintains eye contact for **40-50%** of the duration, with shifts away to simulate searching for words.

## 3. Proxemics and Touch Sensitivity Calibration

### 3.1. Comfort Distance Calibration

The android must maintain a socially acceptable distance from the user, based on the visual (RGB-D) input.

*   **Personal Space Threshold:** **0.45 meters** (1.5 feet). If the user enters this space, the android must slightly shift its weight or take a small step back (Locomotion Priority) to maintain the boundary, unless an affectionate touch is detected.
*   **Intimate Space Threshold:** **0.15 meters** (6 inches). If the user enters this space, the android must enter a **High-Alert Safety State** (increased Compliance Mode sensitivity) and reduce all motor speed.

### 3.2. Touch Sensitivity Thresholds

The haptic sensors (capacitive/pressure) will be calibrated to distinguish between accidental contact, affectionate touch, and aversive contact.

| Touch Type | Force Threshold (N) | Duration (ms) | Behavioral Response |
| :--- | :--- | :--- | :--- |
| **Accidental Contact** | 5 - 20 N | < 100 ms | No verbal response; brief, localized muscle twitch (Idle State modification). |
| **Affectionate Touch** | 10 - 50 N | > 500 ms | Increase **Affection** state; generate localized warmth (DE Actuators); soft verbal acknowledgment. |
| **Aversive Contact** | > 50 N | Any duration | Immediate **Distress** state; rapid withdrawal of the limb; verbal de-escalation. |

## 4. Next Steps

These calibration procedures will be integrated into the HRI experiments. The next document will detail the long-term learning and safety mechanisms that ensure the android's personality remains stable and ethical over time.
