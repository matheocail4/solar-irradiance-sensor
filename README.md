# MINUTO: measuring solar irradiance with a low-cost sensor

Design and construction of a simple, low-cost solar sensor to measure solar irradiance (in W/m²) in Brest under different weather conditions.

**Result:** 4 measurements over 3 days, between **279 ± 10 and 507 ± 18 W/m²**, with a full uncertainty analysis.

First-year team project at IMT Atlantique (Brest), group B24, delivered on 15 January 2025.
Team: Aymane Ounzar, Alix Barraque (project lead), Nada Aleian, Mathéo Cail, Rémi Leluan, Hugo Bentata.

## Principle

A brass block is exposed to the sun and its temperature rise is measured. The irradiance is the power received per unit area:

```
F = (m × C_T × ΔT) / (S × Δt)
```

where `m` (622 g) and `S` (25 cm²) are the mass and exposed area of the brass block, `C_T` its specific heat capacity, and `ΔT/Δt` its heating rate. The temperature is read through a thermistor, so the measurement has three steps:

1. **Thermistor calibration**: a Wheatstone bridge read by an Arduino, next to a TMP117 reference temperature sensor, in an insulated box whose temperature is varied. This gives the relation between the bridge voltage and the temperature.
2. **Heat capacity of the block**: the block is heated with a NiCr resistance wire (Joule heating) while the thermistor voltage is recorded. Result: C_T = 389 ± 10 J·kg⁻¹·K⁻¹.
3. **Irradiance**: the block is exposed to the sun, the voltage is recorded over time (about 15 min, 30 min for the second measurement), then converted into irradiance using the two previous steps.

## Results

| Measurement | Date | Time | Irradiance (W/m²) |
|---:|---|---|---:|
| 1 | 12 Dec 2024 | 16:10 | 507 ± 18 |
| 2 | 10 Jan 2025 | 11:02 | 308 ± 12 |
| 3 | 12 Jan 2025 | 15:06 | 439 ± 15 |
| 4 | 12 Jan 2025 | 15:28 | 279 ± 10 |

Possible improvements identified in the report: account for albedo and reflections (sea, buildings, clouds), track the sun's position to correct the angle of incidence, and use better thermal insulation than polystyrene for the heat capacity measurement.

## Contents

- [`docs/Rapport_MINUTO.pdf`](docs/Rapport_MINUTO.pdf): full report in French (method, set-ups, uncertainty calculations, results)
- [`arduino/etalonnage_thermistance.ino`](arduino/etalonnage_thermistance.ino): reads the bridge voltage and the TMP117 temperature, used for the thermistor calibration
- [`arduino/mesure_dV_temps.ino`](arduino/mesure_dV_temps.ino): records the thermistor voltage over time (pins A0/A1, 12-bit ADC), used for the heat capacity and irradiance measurements

## Tech

Arduino (C++), Wheatstone bridge, TMP117 sensor, uncertainty propagation.
