# So_long

*"This project is a very small 2D game.
Its purpose is to make you work with textures, sprites,
and some other very basic gameplay elements."*

### Subject and goal of project:
*'It’s time for you to create a basic computer graphics project!
so long will help you improve your skills in the following areas: window management,
event handling, colors, textures, and so forth.
You are going to use the school graphical library: the MiniLibX! This library was
developed internally and includes basic necessary tools to open a window, create images
and deal with keyboard and mouse events.
The other goals are similar to every other goal for this first year: being rigorous, level
up in C programming, use basic algorithms, do some information research, and so forth.'*

### Skills that I've learned / improved
- Working with data structures
- Memory management
- Creating and using pointers
- Implementing and working with third party libraries
- Creating graphical output

### What could be done better next time
- Image managament could be more efficient. All images are now screen filling, but some of the images could have been made smaller (for example player, exit, enemy). These images are now filled with a transparent layer, but this is bulk unnecessary data that has to be processed. This results in my game using a lot (RAM) memory when maps get larger.
- Code could be cleaner. I use one giant data structure ('all') that contains almost all variables in this program. This data structure is passed as a parameter to amost all functions. Because of this, you can't exactly tell which variables are used in a functions by reading the function name and it's parameters.
