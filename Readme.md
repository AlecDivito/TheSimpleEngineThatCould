# The Simple Engine That Could 

This is a simple opengl project that will hopefully teach me about making a game, creating data structures, using muiltiple design patterns in unison, and much more like networking, file prasing, program preformance.  

## Getting Started

You need to have g++, make, cmake, GLFW, GLM, and GLEW installed. You also will need openGL installed. This currently is only for linux computers. I have not tested or tried to set this system on windows. 

### Prerequisites

Use a Debian based linux distribution. (This could work on other operating systems but this is what I am using)

Install OpenGL, GLFW, GLM, GLEW, freeGlut, and cmake

### Installing

Install OpenGL, GLM, GLEW, freeGlut, and cmake
```
# update your system packages
sudo apt-get update && sudo apt-get upgrade
sudo apt-get install build-essential
# grab all of the needed packages (you may not need all of them, but this worked for me)
sudo apt install libgl1-mesa-dev mesa-common-dev freeglut3 freeglut3-dev libglew-dev libglew2.0 libglm-dev libsoil-dev cmake
```
You will also need to install GLFW from there website. They provide very helpful  documentation on there website at http://www.glfw.org. You will need to install GLFW into the lib directoy in the project. After download glfw, move it to the lib direcotry in this projects directory and use the following commands:
```
cd <glfw-root-dir>
cmake .
```

At this point you should be able to go into the root project directory and make the project with:
```
make
```

## Tests

Tests have not been implemented yet but i'm planning to implment them in the future.