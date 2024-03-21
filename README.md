# Ard_ros_robot

<div align="center">
  <img src="images/Robot.png"  width="400" height="500" /> 
</div>



The objective of this experimental thesis work was to study and develop a mobile robot on the Arduino platform, leveraging the potential of ROS (Robot Operating System). The main goal was to bring robotics enthusiasts closer to computing platforms increasingly akin to the industrial world while remaining within economic constraints. Indeed, this robot closely resembles the classic industrial AGVs (Automated Guided Vehicles) commonly used in warehouse management and beyond.

## Features

Three types of control are presented:

<div align="center">

|  Object Avoid |  Line Follow | ROS control  | 
|:-:|:-:|:-:|
|  <img src="Doc/Object_avoid.gif" width="130" height="70" /> |   <img src="Doc/line_follow.gif" width="130" height="70" />  | <img src="Doc/ROS_control.gif" width="130" height="70" />  | 

</div>

## Object Avoid 

This control allows the robot to detect if there is an object along its path using an ultrasonic sensor. If an object is detected, the robot simply stops and moves backward using a servo motor installed at the base of the ultrasonic sensor. The environment is then examined within approximately 180°, looking both to the right and left, and finally, the robot decides in which direction to proceed.
The ultrasonic sensor used is the HC-SR04. It consists of two ultrasonic transducers, a transmitter, and a receiver. The transmitter emits an ultrasonic sound pulse that will be reflected by any solid object in front of it. The receiver listens to the reflected pulse and, if detected, measures the delay between transmission and reception. This delay can be used to calculate the distance from the solid object. The servo motor that positions the ultrasonic sensor is the SG90. 


## Line Follow

Line following is a very common robotic application and can be executed in various ways. The most common method is to have a dark line on a light background and use optical sensors to determine its position. A dark surface will reflect very little light, while a light surface will reflect light quite efficiently.

## ROS Control 
The objective was to create a robot that is easily accessible, yet also possesses a non-trivial level of intelligence. However, beyond that, as a secondary goal, we set out to expand the capabilities of Arduino, making it more closely aligned with the realm of robotics. This involved leveraging more advanced platforms for control.
