# CS 100 Programming Project
## Fall 2019 <br>
**Jiahe Gellert Li** -- #862157315 <br>
**Steven Joseph**

# Introduction
This is a smart lighting system aiming to construct a modern, clean interface for smart homes. <br>
This project uses composite as well as module design patterns to implement all classes, structs and enums. <br>
The input data will either be entered by users or read from an external file, and the output will display the color and the brightness of each light in each individual room.<br>

# Diagram
![UML Diagram][uml_diagram]

# Classes
## Space: 
A generic base class for placing individual light
## Home, Room, Group, Light
All inherit from **Space** class,<br> 
each **Home** contains multiple **Room**, <br>
each **Room** contains multiple **Group**, <br>
each **Group** contains multiple **Light**. <br>

**Home** class has a static variable `mainSwitch` which controls the power of the house.<br>
And each Home, Room, Group can add Lights.

# Prototype/Research

# Development and Testing Roadmap





[uml_diagram]: ./images/Lighting_system.png