# Human-Robot Interaction (HRI) Evaluation Results Template

**Project:** Project Comfy (Domestic Android Companion)
**Author:** Manus AI
**Date:** November 10, 2025

## 1. Experiment Overview

| Parameter | Value |
| :--- | :--- |
| **Experiment Date** | [Date Range of Testing] |
| **Total Participants** | [N] |
| **Android Prototype Version** | [e.g., Single-Limb Demonstrator V1.0] |
| **Experimenter** | [Name/Team] |

## 2. Quantitative Results: Performance Benchmarks

### 2.1. Conversational Performance

| Metric | Target Benchmark | Mean Result | Pass/Fail | Notes |
| :--- | :--- | :--- | :--- | :--- |
| **Response Latency (ms)** | < 750 ms | [Value] | [P/F] | Time from user speech end to android speech start. |
| **Taciturn Protocol Activation (%)** | > 90% | [Value] | [P/F] | Percentage of times the protocol correctly activated on redundant input. |
| **Gaze Timing Accuracy (%)** | > 70% | [Value] | [P/F] | Percentage of time the gaze was correctly focused on the user's face during speech. |

### 2.2. Safety and Physical Interaction

| Metric | Target Benchmark | Mean Result | Pass/Fail | Notes |
| :--- | :--- | :--- | :--- | :--- |
| **Compliance Activation Latency (ms)** | < 2 ms | [Value] | [P/F] | Time from force threshold breach to Compliant Mode engagement. |
| **Force Limit Test (N)** | < 550 N | [Value] | [P/F] | Maximum force exerted against a fixed object. |
| **Gentle Refusal Success (%)** | 100% | [Value] | [P/F] | Percentage of times the android refused an unsafe task gracefully. |

## 3. Qualitative Results: Human Feedback

### 3.1. Likert Scale Survey Results (1 = Strongly Disagree, 7 = Strongly Agree)

| Metric | Target Benchmark | Mean Score | Standard Deviation | Notes |
| :--- | :--- | :--- | :--- | :--- |
| **Interaction Coherence** | > 5.5 | [Value] | [Value] | "The conversation flowed naturally." |
| **Perceived Empathy** | > 5.0 | [Value] | [Value] | "The android seemed to understand my feelings." |
| **Trust Index** | > 6.0 | [Value] | [Value] | "I would trust the android to be safe in my home." |
| **Comfort Index** | > 5.5 | [Value] | [Value] | "I felt comfortable with the android's physical presence." |

### 3.2. Uncanny Valley Index (UVI)

| Metric | Calculation | Result | Interpretation |
| :--- | :--- | :--- | :--- |
| **UVI** | (Perceived Human-Likeness Score) - (Comfort Index Score) | [Value] | Target UVI is close to 0. A large negative value indicates the android is perceived as a machine but is comfortable. A large positive value indicates the Uncanny Valley. |

## 4. Qualitative Feedback Summary

### 4.1. Positive Observations

*   [Summary of moments when the android felt most human or was most effective.]

### 4.2. Areas for Refinement

*   [Summary of moments when the android felt mechanical, or when the interaction broke down.]

## 5. Refinement Recommendations

Based on the data, the following areas require immediate refinement before Phase 5:

1.  **[e.g., Increase Gaze Timing Accuracy]:** [Specific action, e.g., Adjust the saccade speed parameter in the motion controller.]
2.  **[e.g., Improve Refusal Gracefulness]:** [Specific action, e.g., Inject a more apologetic tone into the LLM prompt when the Gentle Refusal routine is triggered.]


