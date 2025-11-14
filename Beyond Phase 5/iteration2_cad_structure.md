# Iteration 2: Parametric CAD Structure and Modeling Standards

**Project:** Project Comfy (Domestic Android Companion)
**Author:** Manus AI
**Date:** November 13, 2025
**Iteration Focus:** Digital Twin Integration

## 1. Parametric Modeling Standards

The entire CAD model will be built using a **top-down, parametric approach** to facilitate rapid scaling and modification (e.g., for the Experimental Scaling Studies outlined in the Beyond Phase 5 framework). All critical dimensions will be controlled by a single **Global Parameter Table**.

### 1.1. Global Parameter Table (Excerpts)

| Parameter Name | Value (M-Variant) | Unit | Description |
| :--- | :--- | :--- | :--- |
| `Robot_Height_Total` | 1.50 | m | Total height of the android. |
| `Limb_Length_Upper` | 0.30 | m | Length of the upper arm/thigh link. |
| `Joint_Torque_Peak` | 40.0 | Nm | Maximum torque for core joints (Hip/Knee/Shoulder). |
| `Joint_Limit_Hip_Flex` | 120.0 | deg | Maximum forward flexion of the hip joint. |
| `Material_Density_CFPLA` | 1.45 | g/cm³ | Density used for inertia calculations. |

### 1.2. Naming Convention

All files, parts, and assemblies must adhere to the **UNC (Unified Naming Convention)** established in Phase 5:

*   **Format:** `PC_PT_AssemblyName_Subsystem_Variant`
*   **Example:** `PC_PT_Hip_Joint_L_V1` (Project Comfy, Part, Hip Joint, Left, Version 1)

## 2. Full Assembly Hierarchy (Skeleton)

The model is structured hierarchically, with the `Torso` as the root link.

| Level | Assembly/Part | Description | Critical Parameters |
| :--- | :--- | :--- | :--- |
| **Root** | `PC_ASM_Torso_Main` | Central structural element, houses SBC and PMU. | `Torso_Height`, `Torso_Width`, `Battery_Mass` |
| **Level 1** | `PC_ASM_Hip_L` / `PC_ASM_Hip_R` | Connects Torso to Thigh. Contains 3 DoF (Yaw, Roll, Pitch). | `Joint_Limit_Hip_Flex`, `Joint_Torque_Peak` |
| **Level 2** | `PC_ASM_Thigh_L` / `PC_ASM_Thigh_R` | Upper leg link. | `Limb_Length_Upper`, `Material_Density` |
| **Level 3** | `PC_ASM_Knee_L` / `PC_ASM_Knee_R` | Single DoF (Pitch). | `Joint_Limit_Knee_Flex` |
| **Level 4** | `PC_ASM_Foot_L` / `PC_ASM_Foot_R` | Terminal link for locomotion. | `Foot_Length`, `Foot_Width` |
| **Arms** | `PC_ASM_Shoulder_L` / `PC_ASM_Shoulder_R` | 3 DoF assembly. | `Limb_Length_Upper` |
| **Head** | `PC_ASM_Head_Main` | Houses cameras, microphones, and facial actuators. | `Head_Mass`, `Camera_Offset` |

## 3. Geometric Inconsistencies and Abstractions

During the detailed CAD construction, the following inconsistencies from the Phase 5 blueprint were identified and resolved:

*   **Cable Routing:** The internal volume required for the CAN Bus and 24V power lines was insufficient in the initial Thigh link design. The link geometry was adjusted to include a dedicated, shielded cable channel.
*   **Joint Center Alignment:** The initial design assumed a perfect intersection of the Hip joint axes. The CAD model revealed a **5 mm offset** between the Hip Yaw and Hip Roll axes, which must be accurately reflected in the URDF model.
*   **Actuator Geometry:** The actual dimensions of the T-Motor U8 Lite are slightly larger than the placeholder used in the initial design, requiring a minor increase in the joint housing diameter.

## 4. Next Steps

The next phase will use this structured CAD hierarchy to generate the URDF/SDF files and define the simulation configuration details.
