# Hourglass
Electronic Hourglass

:clapper: Youtube shorts link: https://www.youtube.com/shorts/0R3GjrOCUNI


<img src = "/Images/Hourglass on.jpg" height = "500px">

# Algorithm
The main idea behind the algorithm is to check the spots on the matrix in the direction of potential movement. If the spot is empty, the particle moves there.
The circle in which the hourglass can rotate gets divided in 16 segments and every segment has its own order of the neighbouring spots each particle will check as shown in the figure. At 45 degree angle, the second checked spot is chosen randomly to make the simulation look more realistic without overcomplicating the algorithm.

The algorithm doesn't require any floating point numbers or nested loops. All the possible directions are conveniently stored in FLASH and do not take any RAM space. This allows this algorithm to run on basically any microcontroller and show incredible performance even with higher resolution displays.

<img src="/Images/Algorithm Image.PNG">

# Schematic

<img src="/Schematic/Hourglass schematic.png">
