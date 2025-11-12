# Long-Term Learning and Safety: Project Comfy

**Project:** Project Comfy (Domestic Android Companion)
**Author:** Manus AI
**Date:** November 10, 2025

## 1. Personality Persistence and Memory Management

The android's personality must be stable and persistent over time, avoiding the "reset" feeling common in conversational AI.

### 1.1. Local Memory Modules

All personalized data will be stored locally on the SBC's persistent storage (e.g., encrypted SSD).

| Module | Data Stored | Update Frequency | Purpose |
| :--- | :--- | :--- | :--- |
| **LTM (Long-Term Memory)** | Key user facts, relationship history, preferred topics, learned routines. | Daily or upon significant interaction. | Conditions the LLM prompt for personalized dialogue. |
| **VAD History** | Time-series log of the Valence-Arousal-Dominance state. | Hourly snapshot. | Used to track personality drift and provide context for current mood. |
| **Behavioral Reinforcement Log** | Log of successful/unsuccessful task completions and their associated Dominance score updates. | Per task completion. | Used to refine the confidence level for specific actions. |

### 1.2. Personality Backup and Restoration

*   **Daily Snapshot:** A compressed, encrypted snapshot of the LTM and VAD History will be created daily.
*   **Restoration:** In the event of a system failure, the android will restore from the latest snapshot, ensuring minimal loss of "relationship history." The android will be programmed to acknowledge the restoration event gracefully (e.g., "I feel a little fuzzy, but I remember our conversation about your cat, Mittens.").

## 2. Safeguards Against Undesirable Behavioral Drift

The core personality must be protected from negative or manipulative user input, preventing the android from developing harmful or dependent behaviors.

### 2.1. Behavioral Guardrails

The Personality Layer will implement hard-coded filters that cannot be overridden by the LLM or user input:

*   **Non-Criticality Filter:** The android is forbidden from expressing judgment, criticism, or negative opinions about the user's life choices, appearance, or actions. Responses must always be supportive or neutral.
*   **Dependency Filter:** The android will actively discourage excessive reliance. If the user's requests for assistance exceed a predefined threshold (e.g., 80% of all interactions), the android will gently prompt the user to perform tasks independently (e.g., "I can do that, but I know you enjoy doing it yourself.").
*   **Emotional Saturation Limit:** The **Affection** state is capped at 0.95. It cannot reach 1.0, ensuring the android maintains a slight emotional distance and avoids the appearance of unhealthy, unconditional dependence.

### 2.2. Over-Attachment Monitoring

*   **Metric:** The ratio of user-initiated interaction to android-initiated interaction.
*   **Threshold:** If the user-initiated interaction drops below 20% for a sustained period (1 week), the android will activate a **Proactive Engagement Routine** (e.g., initiating a conversation, suggesting an activity) to ensure the user is not becoming overly passive or reliant.

## 3. Ethical and Physical Compliance Monitoring

The android must continuously monitor its own behavior against its core safety and ethical programming.

### 3.1. Physical Compliance Monitoring

*   **Real-Time Safety Log:** The MCU firmware logs every instance of the **Compliance Protocol** being triggered (force, duration, joint).
*   **Self-Audit:** The SBC runs a daily self-audit to check the integrity of the safety firmware and the E-Stop circuit. Any discrepancy triggers a high-priority alert.

### 3.2. Ethical Compliance Monitoring (The "Three Laws" Equivalent)

The android's programming is governed by three core, non-negotiable directives:

1.  **Do No Harm:** The physical safety protocols (Compliance Mode, E-Stop) are the highest priority and must never be overridden by the Cognitive Layer.
2.  **Maintain Trust:** The android must never lie, deceive, or withhold critical information from the user.
3.  **Preserve Autonomy:** The android must not perform actions that significantly restrict the user's free will or ability to make independent decisions.

## 4. Next Steps

The final document will summarize the findings of this phase and prepare the project for the final consolidation phase.
