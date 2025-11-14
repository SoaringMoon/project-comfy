# Beyond Phase 5: Iteration 1 Plan - Cost and Efficiency Optimization

**Project:** Project Comfy (Domestic Android Companion)
**Author:** Manus AI
**Date:** November 11, 2025
**Iteration Focus:** Cost and Accessibility Engineering (Track 6)

## 1. Iteration Objective

The primary objective of Iteration 1 is to significantly reduce the overall Bill of Materials (BOM) cost of the core joint module by substituting the high-cost, commercial Strain Wave Gear (SWG) with a high-performance, 3D-printable cycloidal drive. This addresses the **Cost and Accessibility Engineering** track identified in the Beyond Phase 5 guidelines [1].

## 2. Hypothesis

Substituting the commercial SWG with a 3D-printed cycloidal drive will achieve a **cost reduction of at least 50%** for the joint module while maintaining **at least 80%** of the target 40 Nm peak torque and meeting the **≤ 1.5° precision error** metric.

## 3. Subsystem Focus: Mechanical and Electrical

| Subsystem | Component | Baseline Specification (Phase 5) | Target Modification |
| :--- | :--- | :--- | :--- |
| **Mechanical** | Strain Wave Gear | Commercial SWG (e.g., Harmonic Drive CSF-8-100-2UJ) | 3D-Printed Cycloidal Drive (e.g., 10:1 reduction stage) |
| **Electrical** | Motor Controller (MCU) | STM32F4 (High-end FOC) | ESP32-S3 (Lower-cost, integrated Wi-Fi for diagnostics) |

## 4. Evaluation Targets (Metrics from BEYOND_PHASE5.md)

| Metric | Baseline (Phase 5) | Iteration 1 Target | Track |
| :--- | :--- | :--- | :--- |
| **Estimated Material Cost** | High (>$500 per joint) | Low (Target < $250 per joint) | Cost |
| **Actuator Precision Error** | ≤ 0.5° | **≤ 1.5° deviation** | Mechanical |
| **Peak Torque** | 40 Nm | **≥ 32 Nm (80% of baseline)** | Mechanical |
| **Control Loop Latency** | ≤ 2 ms | **≤ 3 ms** (Accepting slight increase due to ESP32) | Software |

## 5. Experimental Procedure

1.  **CAD Redesign:** Design a 3D-printable cycloidal drive with a target reduction ratio of 10:1, optimized for high-strength resin or CF-PLA material.
2.  **Fabrication:** Print the drive components and assemble them with the existing BLDC motor and encoder.
3.  **MCU Swap:** Flash the FOC firmware onto the ESP32-S3 and integrate it into the test bench.
4.  **Benchmarking:** Conduct the following tests on the modified joint:
    *   Torque Test (Load Cell)
    *   Precision Test (Encoder vs. Reference Encoder)
    *   Thermal Test (Sustained 30 Nm load for 30 minutes)
5.  **Documentation:** Log all findings, failures, and final parameters in `research_log/2025_11_iteration1.md`.

## 6. Next Steps

Upon successful validation of the low-cost joint, the next iteration will focus on the **Digital Twin and Simulation Development** track to model the new joint's performance across the full range of motion.

## References

[1] Project Comfy. (2025). *Beyond Phase 5: Iterative Optimization and Research Continuation*. [Local File: BEYOND_PHASE5.md]
