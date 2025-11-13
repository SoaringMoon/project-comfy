# Software and Firmware Release Notes

**Project:** Project Comfy (Domestic Android Companion)
**Author:** Manus AI
**Date:** November 11, 2025
**Version:** 1.0 (Open Reference Release)

## 1. Software Repository: `comfy-software` (Cognition Layer)

This repository contains the high-level Python code for the Cognitive Engine, Personality Layer, and HRI Engine.

### 1.1. Dependencies and Environment Setup

| Component | Version | Purpose | Installation Command |
| :--- | :--- | :--- | :--- |
| **Operating System** | Ubuntu 22.04 LTS | Recommended SBC OS | N/A |
| **Python** | 3.10+ | Core language | `sudo apt install python3.10` |
| **LLM Runtime** | ONNX Runtime / TensorRT | Compressed LLM inference | `pip install onnxruntime` |
| **CAN Interface** | python-can | Communication with MCUs | `pip install python-can` |
| **Database** | SQLite3 | Local memory persistence (LTM, VAD History) | Built-in with Python |

### 1.2. Build and Run Instructions

1.  **Clone Repository:** `git clone https://github.com/ProjectComfy/comfy-software.git`
2.  **Install Dependencies:** `pip install -r requirements.txt`
3.  **Configuration:** Edit `config/hardware_map.json` to match the CAN IDs of your assembled MCUs.
4.  **Run:** `python3 main.py --mode=production`

### 1.3. Versioning and Configuration

*   **Versioning:** Follows Semantic Versioning (MAJOR.MINOR.PATCH). Current version is **1.0.0**.
*   **Configuration:** All hardware-specific parameters (e.g., joint limits, CAN IDs, sensor offsets) are stored in external JSON files, allowing for easy adaptation to different hardware variants without recompiling the core code.

## 2. Firmware Repository: `comfy-firmware` (Control Layer)

This repository contains the C/C++ code for the distributed Motor Controller Units (MCUs).

### 2.1. Development Environment

| Component | Version | Purpose | Installation Command |
| :--- | :--- | :--- | :--- |
| **IDE/Toolchain** | PlatformIO / VSCode | Recommended build environment | PlatformIO CLI or VSCode Extension |
| **Compiler** | GCC ARM Embedded | For STM32 target | Installed via PlatformIO |
| **Library** | SimpleFOC (Modified) | Core FOC and control library | Included as a submodule |

### 2.2. Build and Flash Instructions

1.  **Clone Repository:** `git clone --recursive https://github.com/ProjectComfy/comfy-firmware.git`
2.  **Configure:** Edit `platformio.ini` to select the correct board (e.g., `env:stm32f405`).
3.  **Build:** `platformio run`
4.  **Flash:** Connect the MCU via SWD/JTAG and run `platformio run --target upload`

### 2.3. Safety and Compliance Logic

The safety logic is implemented in the highest-priority interrupt handler to ensure deterministic response.

*   **File:** `src/safety_protocol.cpp`
*   **Function:** `void check_force_limit_and_override()`
*   **Interlock:** This function is protected from modification by a checksum verification at boot. Any change to the safety logic requires a full re-verification of the physical safety benchmarks.

## 3. Communication Protocol (CAN Bus)

All communication uses a standardized CAN message format.

| Message Type | CAN ID Range | Sender | Receiver | Purpose |
| :--- | :--- | :--- | :--- | :--- |
| **Joint Command** | 0x100 - 0x1FF | SBC (Python) | MCU (C/C++) | Set target torque, velocity, or position. |
| **Joint Telemetry** | 0x200 - 0x2FF | MCU (C/C++) | SBC (Python) | Report actual position, torque, temperature, and error flags. |
| **Safety Alert** | 0x001 - 0x00F | MCU/PMU | All | High-priority alert (e.g., E-Stop, Over-Current). |

## 4. Next Steps

The next phase will focus on the final safety and compliance review, ensuring all systems meet the established benchmarks.
