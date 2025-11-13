# Community and Contribution Guidelines

**Project:** Project Comfy (Domestic Android Companion)
**Author:** Manus AI
**Date:** November 11, 2025
**Version:** 1.0 (Open Reference Release)

## 1. Philosophy: Open Science and Reproducibility

Project Comfy is a **living research platform**. Our goal is to foster a collaborative environment where improvements are systematically documented, validated, and reintegrated into the canonical design. All contributions must adhere to the core principles of **safety, ethical compliance, and reproducibility**.

## 2. Licensing

| Component | License | Rationale |
| :--- | :--- | :--- |
| **Documentation, Mechanical, Electrical Designs** | **CC BY-SA 4.0** | Encourages sharing and adaptation while ensuring derivative works maintain the open-source nature. |
| **Software and Firmware** | **MIT License** | Highly permissive, allowing maximum flexibility for integration into other projects. |

## 3. Contribution Workflow

All contributions follow a standard workflow to ensure quality and traceability:

1.  **Fork:** Fork the relevant repository (`comfy-mechanical`, `comfy-software`, etc.).
2.  **Develop:** Implement your proposed change.
3.  **Document:** Create a structured **Research Log** (`research_log/YYYY_MM_*.md`) detailing the objective, methodology, results, and a clear pass/fail against the established Acceptance Testing Protocol (ATP).
4.  **Pull Request (PR):** Submit a Pull Request to the main branch. The PR description **MUST** link to the Research Log.
5.  **Review:** The maintainers and community will review the PR for technical merit, adherence to safety standards, and reproducibility.

## 4. Contribution Standards

### 4.1. Research Logging (Mandatory)

Every proposed change, regardless of size, must be accompanied by a Research Log. This log must clearly state how the change affects the core metrics (Cost, Efficiency, Precision, Comfort Index).

### 4.2. Safety and Ethical Compliance

*   **No Compromise:** Any contribution that compromises the established safety interlocks (e.g., E-Stop latency, Force-Limiting) will be immediately rejected.
*   **Behavioral Guardrails:** Changes to the Cognitive Layer must be tested against the Behavioral Guardrails to ensure the android remains supportive and non-manipulative.

### 4.3. Version Control and Naming

*   **Branch Naming:** Use descriptive branch names (e.g., `feature/low-cost-cycloidal`, `bugfix/can-bus-timeout`).
*   **Code Style:** Adhere to the established style guides (e.g., PEP 8 for Python, Google C++ Style Guide for firmware).

## 5. Areas for Modular Research

We encourage contributions in the following high-impact areas:

| Research Track | Example Contribution |
| :--- | :--- |
| **Mechanical** | Optimized 3D-printable cycloidal drive geometry for higher torque density. |
| **Electrical** | Design for a modular, hot-swappable battery pack. |
| **Firmware** | Adaptive FOC tuning algorithms for self-calibration. |
| **HRI** | New emotional state models or refined gaze-timing parameters based on human studies. |
| **Cost Engineering** | Sourcing and validation of lower-cost sensor alternatives. |

## 6. Maintainer Contact

For governance questions, licensing inquiries, or to report a security vulnerability, please contact the maintainer team via the official repository.
