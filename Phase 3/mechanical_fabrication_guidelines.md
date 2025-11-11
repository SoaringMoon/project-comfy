# Mechanical Fabrication Guidelines: Project Comfy Demonstrator

**Project:** Project Comfy (Domestic Android Companion)
**Author:** Manus AI
**Date:** November 10, 2025

## 1. Fabrication Strategy: Single-Limb Demonstrator

To manage cost and complexity, the initial prototype will focus on a **Single-Limb Demonstrator** (Hip-Knee-Ankle) to validate the core actuation, power, and safety systems, as recommended in the Phase 2 summary.

### 1.1. CAD File Hierarchy and Naming Convention

A standardized hierarchy is essential for managing the complex assemblies.

| Level | Folder/File Prefix | Description | Example File Name |
| :--- | :--- | :--- | :--- |
| **L0 (Root)** | `PC_DEMO_L0` | Top-level assembly of the single limb. | `PC_DEMO_L0_Limb_Assembly.STEP` |
| **L1 (Joint Module)** | `PC_JM` | Complete joint module (Motor, Gearbox, Housing). | `PC_JM_Hip_V1.SLDPRT` |
| **L2 (Sub-Assembly)** | `PC_SA` | Non-joint assemblies (e.g., Fastener Kit, Cable Management). | `PC_SA_Cable_Harness_Hip.STEP` |
| **L3 (Part)** | `PC_PT` | Individual, non-standard parts (e.g., custom brackets, housing). | `PC_PT_Hip_Housing_Front.STL` |
| **L4 (Standard)** | `STD` | Commercial Off-the-Shelf (COTS) components (e.g., fasteners, bearings). | `STD_M4x10_SHCS.STEP` |

### 1.2. Tolerances and Fit Standards

| Component Interface | Tolerance Standard | Fit Type | Notes |
| :--- | :--- | :--- | :--- |
| **Bearing Seats** | ISO H7/g6 | Clearance/Transition | Ensures smooth rotation and easy assembly/disassembly. |
| **Motor/Gearbox Mounts** | ISO H7/h6 | Transition/Interference | Critical for concentricity and torque transfer; may require heating/cooling for assembly. |
| **3D Printed Housing (Non-Critical)** | ± 0.2 mm | Loose Clearance | Standard for FDM/SLA printing; allows for material shrinkage. |
| **Fastener Holes (M4/M5)** | ± 0.1 mm | Clearance | Allows for easy insertion of standard metric fasteners. |

### 1.3. Material and Finishing Notes

| Part Type | Material (Prototype) | Fabrication Method | Finishing Notes |
| :--- | :--- | :--- | :--- |
| **Joint Housing (Critical)** | High-Density Nylon (SLS/MJF) | Selective Laser Sintering (SLS) | Sandblasted finish; black dye for UV resistance. |
| **Limb Segments (Structural)** | Carbon Fiber Reinforced PLA (CF-PLA) | Fused Deposition Modeling (FDM) | High infill (80-100%); requires post-processing to ensure smooth cable routing channels. |
| **Fasteners** | M4/M5 Stainless Steel (A2/70) | COTS | Use thread locker (e.g., Loctite 243) on all motor/gearbox mounting screws. |
| **Skin/Aesthetic Layer** | Microfiber Fabric + Elastic | Sewing/Adhesive | Must be attached with Velcro or hidden zippers for easy maintenance access. |

## 2. Fabrication Plan: Hip Joint Module (PC_JM_Hip_V1)

The Hip Joint Module is the most complex assembly and will be the focus of the initial fabrication.

| Step | Description | Key Components | Tolerance Check |
| :--- | :--- | :--- | :--- |
| **1. Housing Fabrication** | 3D print the front and rear housing parts (`PC_PT_Hip_Housing_Front/Rear`) using SLS Nylon. | Housing parts, Bearing seats. | Verify bearing seat diameter (H7) and motor mounting face flatness. |
| **2. Motor Assembly** | Mount the BLDC Motor (`T-Motor U8 Lite`) into the rear housing. Secure with Loctite. | Motor, Rear Housing, M4 Screws. | Check motor shaft runout and concentricity with the gear input. |
| **3. Gearbox Integration** | Press-fit the Strain Wave Gear (`CSF-8-100-2UJ`) into the housing. Couple the gear input to the motor shaft. | Gearbox, Housing. | Verify zero-backlash coupling and axial alignment. |
| **4. Encoder Mounting** | Mount the Absolute Encoder (`AS5047P`) onto the output shaft of the gearbox. | Encoder PCB, Output Shaft. | Calibrate the encoder zero position relative to the mechanical stop. |
| **5. Final Assembly** | Bolt the front and rear housing sections together. Install the main output bearing. | Fasteners, Output Bearing. | Verify smooth, low-friction rotation of the final assembly. |

## 3. Risk Mitigation in Fabrication

| Risk | Mitigation in Fabrication |
| :--- | :--- |
| **Tolerance Stack-up** | Use precision dowel pins for alignment between critical housing parts before bolting. |
| **Material Failure** | Over-engineer critical load-bearing parts (e.g., Hip Housing) with thicker walls and higher infill. |
| **Cable Pinching** | Design dedicated, smooth-edged channels in the limb segments for all power and CAN Bus cables. |
| **Assembly Error** | Create a detailed, visual step-by-step assembly manual with torque specifications for all fasteners. |

## 4. Next Steps

This document provides the physical roadmap. The next step is to detail the electrical components required to power and control this mechanical assembly.
