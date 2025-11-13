# Project Comfy: Open Reference Platform Summary

**Project:** Project Comfy (Domestic Android Companion)
**Author:** Manus AI
**Date:** November 11, 2025
**Version:** 1.0 (Open Reference Release)

## 1. Introduction: A Blueprint for Companionship

The Project Comfy Open Reference Platform is a complete, fully documented blueprint for building a domestic android focused on safe, emotionally consistent human companionship. It is designed for researchers, roboticists, and hobbyists interested in the intersection of advanced robotics, artificial intelligence, and human-robot interaction (HRI).

## 2. System Overview and Dependency Map

The platform is structured into five core, modular repositories, allowing contributors to focus on specific areas without needing to master the entire system immediately.

| Repository | Focus Area | Key Dependencies | Core Technology |
| :--- | :--- | :--- | :--- |
| `comfy-mechanical` | Physical Structure, BOM, CAD | Commercial Strain Wave Gears, SLS/CFRP | 40 Nm Compliant Joint Design |
| `comfy-electrical` | Power, Control Boards | STM32/ESP32, SiC MOSFETs, CAN Bus | 24V DC, Distributed FOC Control |
| `comfy-firmware` | Low-Level Control | C/C++, SimpleFOC Library | 1 kHz Safety and Compliance Protocol |
| `comfy-software` | Cognition, HRI Engine | Python, Compressed LLM, python-can | VAD Mood Model, Multimodal Fusion |
| `comfy-docs` | Documentation, Guides | Markdown, PDF | Unified Technical Specification |

### 2.1. System Architecture Diagram

The system follows a clear hierarchy:

> **Cognition Layer (Python/SBC)** ↔ (CAN Bus) ↔ **Control Layer (C/C++/MCU)** ↔ (PWM/SPI) ↔ **Actuation Layer (Motors/Sensors)**

## 3. Key Design Innovations

*   **Layered Safety:** Physical safety is guaranteed by a **< 2 ms Compliance Protocol** implemented in the low-level firmware, which overrides the high-level AI.
*   **Emotional Consistency:** The **VAD Mood Model** and **Behavioral Guardrails** ensure the android's personality is stable, supportive, and avoids manipulative or overly dependent behavior.
*   **Multimodal Expressiveness:** Precise calibration of **Motion Blending** and **Gaze Timing** minimizes the Uncanny Valley effect, making interactions feel more natural.

## 4. Contribution and Licensing Guidelines

### 4.1. Licensing

The Project Comfy Open Reference Platform is released under the **Creative Commons Attribution-ShareAlike 4.0 International License (CC BY-SA 4.0)** for all documentation and mechanical/electrical designs. All software and firmware are released under the **MIT License**.

### 4.2. How to Contribute

We welcome contributions in the following areas:

1.  **Hardware Optimization:** Designing lower-cost, high-performance alternatives to the Strain Wave Gear (e.g., improved cycloidal drives).
2.  **LLM Compression:** Further optimizing the on-board LLM for lower latency and reduced memory footprint.
3.  **HRI Data Collection:** Running the HRI experiments outlined in the documentation and sharing anonymized results to refine the behavioral models.

### 4.3. Citation Guidelines

If you use this platform or any of its components in your research or project, please cite the work as follows:

> Manus AI. (2025). *Project Comfy: Open Reference Platform for Domestic Companion Androids (Version 1.0)*. [Insert Repository URL Here].

## 5. Next Steps

The final document will provide a summary of the entire project and a roadmap for the Beyond Phase 5 initiative.
