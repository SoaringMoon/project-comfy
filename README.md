# Project Comfy

**Project Comfy** is an open research and design initiative focused on the **development of a domestic android for human companionship**.  
The project’s goal is to create a complete, transparent blueprint for an affordable, safe, and emotionally intelligent humanoid system — including its **mechanical design, electronics, control software, and behavioral architecture**. Based on the posts of the /robowaifu/ imageboard at alogs.space.

---

## Overview

Project Comfy is being developed through a structured, multi-phase design and engineering process led by an autonomous agent (Manus) and human collaborators.  
Each phase refines the previous one — from abstract requirements to tangible, buildable systems.  
Following the completion of Phase 5, the project entered the **Beyond Phase 5** initiative — a living, iterative research process aimed at continual refinement, optimization, and open collaboration.

**Core Design Principles**
- Safety-first motion and actuation  
- Modular and serviceable construction  
- Realistic human interaction without deception  
- Localized AI architecture emphasizing privacy and transparency  
- Open documentation for replicability and educational use  

---

## Project Structure

(Files are constantly renamed by Manus, so they might not match the list below. The titles should however remain the same.)

| Folder / File | Description |
|----------------|-------------|
| Phase 1 Files | Description |
| `deployment_guide.md` | Full system summary and overarching design document. |
| `design_requirements.md` | Extracted functional and non-functional requirements. |
| `android_system_architecture.md` | Hybrid distributed system architecture and subsystem overview. |
| `hardware_design_and_integration.md` | Specifications for actuators, chassis, sensors, and integration. |
| `companion_and_safety_protocols.md` | Ethical, emotional, and physical safety guidelines. |
| `core_ai_engine.py` | Conceptual high-level cognitive engine code. |
| `motor_control_system.h` | Low-level firmware interface for motion control. |
| Phase 2 Files | Description |
| `mechanical_subsystems.md` | Mechanical engineering specifications (actuators, joints, chassis). |
| `electrical_subsystems.md` | Schematics and interface details for PMU, MCUs, and CAN bus. |
| `software_architecture_expanded.md` | Expanded AI and control software documentation. |
| `testing_and_validation_plan.md` | Test plans for performance, safety, and personality modeling. |
| `phase2_summary_and_recommendations.md` | Summary of Phase 2 results and next steps. |
| Phase 3 Files | Description |
| `phase3_prototyping_plan.md` | The strategic plan for the parallel Hardware and Software tracks. |
| `mechanical_fabrication_guidelines.md` | Detailed instructions for fabricating the mechanical assemblies. |
| `electrical_wiring_and_pcbs.md` | Comprehensive design packages for the PMU, MCUs, and components. |
| `firmware_reference_implementation.cpp` | Conceptual C++ code for the low-level MCU. |
| `integration_framework.py` | Python pseudocode for the high-level Cognitive Layer. |
| `testing_and_verification_results.md` | Quantitative benchmarks and pass/fail criteria for all subsystems. |
| `phase3_summary_and_readiness.md` | Summary of milestones achieved and confirmation that the project is ready to proceed to Phase 4. |
| Phase 4 Files | Description |
| `phase4_hri_plan.md` | Experimental methodology for controlled HRI evaluation and ethical review. |
| `behavior_model_and_personality_engine.md` | Defines the Mood Model (VAD parameters), adaptive dialogue rules, and emotional feedback routines. |
| `motion_and_expression_calibration.md` | Procedures for motion blending, gaze synchronization, and comfort distance calibration. |
| `long_term_learning_and_safety.md` | Safeguards including Behavioral Guardrails, dependency limits, and ethical compliance monitoring. |
| `interaction_evaluation_results.md` | Template for recording and analyzing quantitative and qualitative HRI results. |
| `phase4_summary_and_readiness.md` | Summary of achievements and readiness for Phase 5. |
| Phase 5 Files | Description |
| `phase5_production_plan.md` | Overall integration and release strategy, including modular repository structure. |
| `complete_system_reference.md` | Unified technical specification covering all mechanical, electrical, software, and HRI subsystems. |
| `manufacturing_and_assembly_guide.md` | Detailed fabrication, assembly, and calibration guide with partial BOM. |
| `software_and_firmware_release_notes.md` | Finalized documentation for control software and firmware with CAN Bus standards. |
| `quality_and_safety_compliance.md` | Verification of safeguards, ethical guardrails, and acceptance testing. |
| `open_reference_summary.md` | Public-facing summary of the platform and community contribution guidelines. |
| `phase5_summary_and_continuation.md` | End-of-project report and transition to Beyond Phase 5. |
| Beyond Phase 5 Files | Description |
| `beyond_phase5_iteration_plan.md` | Defines Iteration 1, focusing on Cost and Accessibility Engineering. |
| `digital_twin_development_plan.md` | Plan for a physics-accurate digital twin using Onshape and Gazebo/ROS. |
| `optimization_study_01.md` | Documentation of the cycloidal drive substitution study (94% cost reduction). |
| `research_log/2025_11_iteration1.md` | Structured research record for the first iteration. |
| `community_and_contribution_guidelines.md` | Standards for research submissions and traceability. |
| `beyond_phase5_summary_and_next_steps.md` | Summary of Iteration 1 and proposal for Iteration 2: Digital Twin Integration. |

---

## Current Phase

**Beyond Phase 5 — Iterative Optimization and Research Continuation** *In Progress*  
**Iteration 1:** *Cost and Accessibility Engineering* — *Completed*

Project Comfy has successfully transitioned into an active, open research platform.  
The first iteration replaced the costly Strain Wave Gear with a 3D-printed cycloidal drive, achieving a **94% cost reduction** in the core joint module while maintaining performance and safety targets.  
The next iteration, **Iteration 2: Digital Twin Integration and Full-System Simulation**, will focus on creating a physics-accurate simulation model for validation and testing.

**Ongoing Goals**
1. Develop a full digital twin for motion and behavioral testing  
2. Optimize structural and electrical systems for cost, weight, and reliability  
3. Improve documentation and research logging standards  
4. Support community-based research through open contribution  

---

## Technology Focus

- **Control Systems:** Field-Oriented Control (FOC) and compliance modeling  
- **Computation:** Distributed microcontrollers with centralized high-level cognition  
- **AI Architecture:** Layered design (Reflex → Behavior → Personality)  
- **Interaction:** Speech, gesture, and emotional state simulation  
- **Power:** 24V modular PMU with hot-swappable cells  
- **Networking:** Real-time CAN bus and Ethernet-based supervision  
- **Simulation:** Parametric digital twin development with ROS/Gazebo integration  

---

## Project Roadmap

| Phase | Description | Status |
|-------|--------------|--------|
| **Phase 1** | Conceptual Design & System Architecture | Complete |
| **Phase 2** | Subsystem Specification & Validation | Complete |
| **Phase 3** | Prototyping & Integration | Complete |
| **Phase 4** | Human-Robot Interaction & Refinement | Complete |
| **Phase 5** | Production-Ready Blueprint & Open Reference Platform | Complete |
| **Beyond Phase 5** | Iterative Optimization & Advanced Research | In Progress |
| **Iteration 1** | Cost and Accessibility Engineering | Complete |
| **Iteration 2** | Digital Twin Integration and Full-System Simulation | Planned |

---

## Continuing Development

Project Comfy will continue as a **living, community-driven research platform**.  
Future work will focus on refinement, simplification, and advanced modeling across mechanical, electrical, and behavioral domains.

**Long-Term Research Goals**
- **Design Consolidation:** Minimize part count and mechanical complexity.  
- **Digital Twin Development:** Complete parametric modeling and real-time simulation integration.  
- **Cost Reduction:** Continue material and component substitutions for accessibility.  
- **Performance Enhancement:** Improve motion precision, thermal efficiency, and control latency.  
- **Community Collaboration:** Establish standards for peer-reviewed research integration.  

---

## Contribution

This repository is a continuously evolving research project.  
Contributions are welcome in the following areas:
- Mechanical and electrical CAD validation  
- Firmware and embedded systems development  
- AI and behavioral modeling  
- Simulation and digital twin integration  
- Ethics, safety, and compliance documentation  

If you wish to collaborate, please open an issue or discussion thread outlining your area of expertise.

---

## Disclaimer

Project Comfy is a **research and educational initiative**.  
It is not a commercial or consumer-ready product.  
All documentation and designs are provided **“as-is”** with no warranty of safety or fitness for purpose.

---

## License

All documentation and conceptual code are released under the **Creative Commons Attribution-ShareAlike 4.0 (CC BY-SA 4.0)** license unless otherwise specified.

---

### Contact
**Maintainer:** [SoaringMoon](https://github.com/SoaringMoon)  
**Project Alias:** *Comfy Team / Manus Initiative*  

---