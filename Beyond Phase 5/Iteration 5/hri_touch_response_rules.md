# HRI Touch Response Rules and Safety Logic

**Project:** Project Comfy (Domestic Android Companion)
**Author:** Manus AI
**Iteration Focus:** HRI Sensor Fusion and Tactile Integration

## 1. Safety Hierarchy

Physical interaction safety is governed by a three-tiered hierarchy, ensuring that low-latency, hard safety overrides take precedence over nuanced behavioral responses.

| Tier | Trigger Location | Response Latency | Action |
| :--- | :--- | :--- | :--- |
| **Tier 1: Hard Safety** | MCU (Local) | < 10 ms | Immediate compliance mode, motor power reduction, and E-Stop signal to all joints. |
| **Tier 2: Soft Safety** | SBC (Cognitive Layer) | 50 – 100 ms | Posture adjustment, verbal disengagement cue, and joint compliance request. |
| **Tier 3: Behavioral** | SBC (Cognitive Layer) | > 200 ms | Emotional state update, conversational response, and long-term memory logging. |

## 2. Touch Response Rules (Tier 2 & 3)

The following rules are triggered by the **Contact Intent Model (CIM)** output (from `sensor_fusion_architecture.md`).

| CIM Inferred Intent | Tier | Behavioral Response | Control Action |
| :--- | :--- | :--- | :--- |
| **Affectionate Touch** (Pat, Gentle Press) | Tier 3 | **Emotional Update:** Positive valence. **Verbal:** "That feels nice, thank you." | Request `Compliance Mode = Adaptive` for the touched joint. |
| **Supportive Contact** (Hand-Holding, Leaning) | Tier 3 | **Emotional Update:** Calm/Trust. **Verbal:** "I'm here for you." | Request `Compliance Mode = Stiff` for the supporting joints to maintain stability. |
| **Accidental Bump/Obstacle** | Tier 2 | **Emotional Update:** Neutral/Surprise. **Verbal:** "Excuse me, I'll move out of the way." | **Posture Adjustment:** Gentle, slow movement away from the contact point. |
| **Sustained High Pressure** (Grip > 15N) | Tier 2 | **Emotional Update:** Anxiety/Discomfort. **Verbal:** "That's a little too tight, please let go." | Request `Compliance Mode = Low-Force` for the affected joint. |
| **Unsafe Grip/Push** (High Pressure > 40N) | Tier 1 | **Immediate E-Stop** (Hard Safety Override). | **Full Motor Power Cut** and broadcast of E-Stop CAN message. |

## 3. Force-Limited Compliance Routine

The low-level compliance routine is refined to use the RFS data for localized force limiting.

*   **Routine:** `ForceLimitedCompliance(JointID, MaxForceN)`
*   **Trigger:** Tier 2 or Tier 3 event (e.g., Affectionate Touch).
*   **Action:** The MCU monitors the RFS data for the specified joint. If the RFS Max Pressure exceeds `MaxForceN` (e.g., 5N for a gentle touch), the MCU overrides the commanded torque to zero, allowing the joint to yield slightly. This creates a soft, yielding sensation without triggering a full safety shutdown.

## 4. Proximity Sensor Rules

The CPS data is used primarily for pre-contact warning and HRI context.

| CPS Trigger | Action | Rationale |
| :--- | :--- | :--- |
| **Approach (50mm)** | **Slow Down:** Reduce joint velocity by 50%. | Prevents accidental collision during movement. |
| **Close Proximity (5mm)** | **Gaze Shift:** Shift gaze to the approaching object/person. | Acknowledges the impending interaction (HRI comfort). |
| **Face Proximity (0mm)** | **Stillness Mode:** Lock neck/head joints in a compliant, still position. | Prevents accidental movement during intimate HRI. |

## 5. Conclusion

These rules establish a comprehensive framework for safe and emotionally intelligent physical interaction. The integration of tactile data allows the robot to move beyond simple force thresholds to infer the **intent** of the human touch, which is paramount for a companion android.
