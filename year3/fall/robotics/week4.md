# Week 4: Sensors

## Notes

---

### Purpose and Categories of Sensors
- Purpose of Sensors:
  - Enable robots to perceive the environment.
  - Key for localization, navigation, and interaction.
  - Factors to consider:
    - Weight, space, energy usage, and processing power.
- Taxonomy of Sensors:
  - Proprioceptive: Measure internal states (e.g., motor speed, wheel load).
  - Exteroceptive: Measure external environment (e.g., distance to objects, temperature).
  - Passive Sensors: Measure energy from the environment (e.g., cameras, thermometers).
  - Active Sensors: Emit energy and measure the reaction (e.g., sonar, LiDAR).

### Key Sensors and Applications
- Wheel Encoders:
  - Measure wheel position or speed.
  - Calculate position through odometry.
  - Types:
    - Optical Encoders: High resolution (64-2048 counts/revolution).
    - Quadrature Encoders: Detect direction and provide controlled high-resolution measurements.
- Heading Sensors:
  - Determine orientation.
  - Examples:
    - Gyroscopes: Detect angular velocity, subject to drift.
    - Accelerometers: Measure acceleration; gravity must be accounted for.
- Inertial Measurement Unit (IMU):
  - Combines gyroscopes, accelerometers, and magnetometers.
  - Provides position, velocity, and orientation.
  - Susceptible to drift, requiring external references like GPS.
- GPS:
  - Useful for outdoor localization via satellite trilateration.
  - Challenges: Signal interference, time synchronization.
- Active Range Sensors:
  - Ultrasonic Sensors: Use sound waves; inexpensive, handle transparent surfaces.
  - LiDAR: Uses laser beams for high-precision, high-resolution 3D mapping.

### Sensor Performance Metrics
- Dynamic Range: Ratio of max to min measurable input.
- Sensitivity: Degree of response to input changes; cross-sensitivity (response to non-target signals) is undesirable.
- Linearity: Desired proportional relationship between input and output.
- Accuracy vs. Precision:
  - Accuracy: Closeness to true value.
  - Precision: Consistency of repeated measurements.
