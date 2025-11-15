# Sensor Fusion Architecture: Contact Intent Model

**Project:** Project Comfy (Domestic Android Companion)
**Author:** Manus AI
**Iteration Focus:** HRI Sensor Fusion and Tactile Integration

## 1. Multimodal Sensor Fusion Rationale

Physical interaction with a companion android requires a robust understanding of **Contact Intent**. This cannot be achieved by tactile sensors alone; it requires fusing tactile data with existing proprioceptive data (joint encoders, force/torque estimates) and exteroceptive data (proximity sensors).

## 2. Fusion Architecture Overview

The fusion process occurs in two stages:
1.  **Low-Level Fusion (MCU):** Tactile data is fused with local joint data for immediate safety and compliance response.
2.  **High-Level Fusion (SBC/Cognitive Layer):** Fused data is combined with HRI context and historical data to infer **Contact Intent**.

## 3. Low-Level Fusion (MCU)

The MCU fuses RFS data with the estimated joint torque to refine the compliance response.

| Input Sensor | Fused Sensor | Output | Purpose |
| :--- | :--- | :--- | :--- |
| **RFS (Pressure)** | **Joint Torque (Estimated)** | **Refined Compliance Torque** | If RFS pressure is high, but Joint Torque is low, the robot is being gently pressed. If both are high, the robot is being gripped or pushed hard. |
| **CPS (Proximity)** | **Joint Velocity** | **Pre-Contact Warning** | If CPS detects an object approaching a moving joint, the joint velocity is immediately reduced (local speed limit). |

## 4. High-Level Fusion (SBC/Cognitive Layer)

The Cognitive Layer uses a **Bayesian Network** or a simple **Decision Tree** to classify the Contact Intent based on five key features.

### 4.1. Contact Intent Model (CIM) Features

| Feature | Source | Classification Logic |
| :--- | :--- | :--- |
| **F1: Pressure Magnitude** | RFS Max Pressure (from `TLM_TACTILE_DATA`) | Low (0-5N), Medium (5-20N), High (>20N). |
| **F2: Pressure Duration** | Internal Timer (SBC) | Transient (< 0.5s), Sustained (0.5s - 5s), Prolonged (> 5s). |
| **F3: Contact Area** | RFS Avg Pressure / RFS Count | Small (Fingertip), Large (Palm/Forearm). |
| **F4: Robot Motion** | Joint Encoders (from `TLM_JOINT_STATUS`) | Moving, Still, Moving Away from Contact. |
| **F5: External Force** | Joint Torque (Estimated) | Supportive (Torque opposes gravity), Opposing (Torque matches contact). |

### 4.2. Contact Intent Classification

The CIM uses the fused features to classify the intent, which then triggers the appropriate HRI response (detailed in `hri_touch_response_rules.md`).

| Fused Feature Combination (Example) | Inferred Contact Intent |
| :--- | :--- |
| **F1: Low, F2: Transient, F3: Small, F4: Still, F5: Supportive** | **Affectionate Touch** (e.g., a pat) |
| **F1: Medium, F2: Sustained, F3: Large, F4: Still, F5: Supportive** | **Hand-Holding** (Requires compliance and stillness) |
| **F1: High, F2: Transient, F3: Small, F4: Moving, F5: Opposing** | **Accidental Bump/Obstacle** (Requires immediate compliance) |
| **F1: High, F2: Prolonged, F3: Large, F4: Moving, F5: Opposing** | **Unsafe Grip/Push** (Triggers full safety shutdown) |

## 5. Conclusion

This two-stage fusion architecture ensures both **low-latency safety** (MCU-side) and **high-level behavioral nuance** (SBC-side). The resulting Contact Intent Model provides the necessary input for the Cognitive Layer to react to physical touch in an emotionally appropriate and safe manner.
