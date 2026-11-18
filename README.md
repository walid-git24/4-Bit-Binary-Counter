# 4-Bit-Binary-Counter

## Project Overview

This project implements a 4-bit binary click counter using an Arduino Uno and direct AVR port manipulation.

A pushbutton increments the counter from 0 to 15. The current value is displayed in binary using four LEDs connected to digital pins D8–D11.

The implementation uses the `DDRB`, `PORTB`, and `PINB` registers instead of standard Arduino GPIO functions.

## Circuit Overview

**Simulation:** [Open Wokwy Project]https://wokwi.com/projects/481013384534681601)

## Hardware Configuration

- Arduino Uno (ATmega328P)
- 4 LEDs
- 1 Pushbutton
- Current-limiting resistors for LEDs

## Pin Configuration

| Arduino Pin | AVR Port | Component | Function |
|---|---|---|---|
| D8 | PB0 | LED 1 | Bit 0 (LSB) |
| D9 | PB1 | LED 2 | Bit 1 |
| D10 | PB2 | LED 3 | Bit 2 |
| D11 | PB3 | LED 4 | Bit 3 (MSB) |
| D12 | PB4 | Pushbutton | Counter input |

The pushbutton is connected between D12 and GND. The internal pull-up resistor is enabled through `PORTB`.

## Working Principle

1. The counter starts at 0 (`0000`).
2. Each button press increments the counter by one.
3. The counter value is displayed on the four LEDs.
4. The counter wraps back to 0 after reaching 15 (`1111`).
5. The Serial Monitor displays both decimal and binary values.

## AVR Register Implementation

| Register | Purpose |
|---|---|
| `DDRB` | Configures PB0–PB3 as outputs and PB4 as input. |
| `PORTB` | Enables the internal pull-up and updates the four LED outputs with a single register write. |
| `PINB` | Reads the pushbutton state on PB4. |

A 50 ms delay is used for button debouncing.

## Simulation

**Wokwi Project:**  
https://wokwi.com/projects/481013384534681601

## Simulation Evidence

Screenshots are available in `evidence/simulation/`.

- `circuit-overview.png` — Complete circuit configuration.
- `binary-counter.png` — LED binary output.
- `serial-monitor.png` — Decimal and binary Serial Monitor output.

## Project Files

```text
MSTI_Arena-ASL-03/
├── sketch.ino
├── README.md
├── diagram.json
├── wokwi.toml
```

## Competition Information

- **Competition:** Alpha Science Lab — National Arena
- **Challenge:** #03
- **Title:** 4-Bit Binary Counter: AVR Port Manipulation
- **Maximum Score:** 100 Points
- **Accepted Submission Format:** GitHub
