# Week 3: Robot Motion

## Notes

---

### Coordinate Frames and Transformations
- Frames of Reference:
  - Robots use multiple coordinate frames:
    - World frame (map origin).
    - Robot frame (base_link).
    - Sensor frames and joint frames.
- Transformations:
  - Essential for motion planning and control.
  - Use libraries like ROS tf2 to handle coordinate transforms dynamically.
### Degrees of Freedom (DoF)
- Definition:
  - The number of independent motions a robot can perform.
  - Example: A 6-DoF robot manipulator has:
    - Linear motions: x,y,z.
    - Rotational motions: Roll (around x), Pitch (around y), Yaw (around z).
- Examples:
  - 2-DoF Wheel: Rotation around the axle and contact point with the ground.
  - TurtleBot Waffle: Linear x and angular z DoF.
### Robot Motion and Velocities
- Linear Velocity (v):
  - v=dt​, measured in m/s.
- Angular Velocity (ω):
  - ω=θt​, measured in rad/s.
  - Relationship: v=r⋅ω, where r is the radius of the circular path.
- Conversion between Degrees and Radians:
  - π rad=180∘.
  - Formulae: degrees=radians⋅180∘/π​, radians=degrees⋅π/180∘​.
### Goal-Based Motion
- Moving to a Goal Position:
  - Calculate Euclidean distance:
  - D(p,g)=sqrt[(xg−xp)^2+(yg−yp)^2]
- Calculate angle to goal:
  - θ=atan2(yg−yp,xg−xp)
### Execution Steps:
- Rotate to face the goal (θ).
- Move forward to the goal (D(p,g)).
- Adjust orientation to final goal angle (θg).
### Challenges:
- Dynamic obstacles: Require sensors and real-time path planning.
- Pose estimation errors: Use control loops and tolerances.

