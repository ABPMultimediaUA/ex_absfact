# Abstract Factory Example

This code is an application example of the _Abstract Factory Pattern_[1]. It shows a simple maze game with different types of enemies and walls. These different types are created using an Abstract Factory. 

![Screenshot of the two Game Modes in the Abstract Factory textmode example game](/media/gamescr00.png?raw=true "Two Game Modes controlled by an Abstract Factory in a simple textmode example game")

## Explanation

This example was used during Computer Games lessons of the [Multimedia Degree](https://cvnet.cpd.ua.es/webcvnet/planestudio/planEstudioND.aspx?plan=C205&lengua=E&caca=2016-17) at the [University of Alicante](http://www.ua.es). You may want to check out the [associated C++ lesson video (in Spanish)](https://youtu.be/FFM9cQ2bwA0):

[![Francisco Gallego's Computer Games Lesson at the University of Alicante](https://img.youtube.com/vi/FFM9cQ2bwA0/hqdefault.jpg "Watch Francisco Gallego's lesson on Computer Games at the University of Alicante (in Spanish)")](https://youtu.be/FFM9cQ2bwA0) 

## Compilation requisites

In order to compile this code you require:
- A Linux/*Nix operative system (Win10 bash may do the job)
- CMake 3.2 or greater
- A compiler supporting C++11 or greater (GNU GCC is recommended)
- NCurses library and its development headers

## Compilation instructions

1. Enter project folder
2. Create a build subfolder (`mkdir bin/`)
3. Enter build subfolder (`cd bin/`)
4. Launch CMake (`cmake ../src/`)
5. If CMake succeeded, run make (`make`)
6. If build succeeded, run minimaze game (`./minimaze`)

## Copyright and License

(c) 2017 Francisco Gallego 

This code is distributed under GNU-GPL v3 License.

[1]: "[Design patterns: elements of reusable object-oriented software.](https://www.amazon.es/Design-patterns-object-oriented-professional-computing/dp/0201633612)" Addison-Wesley Longman Publishing Co., Inc. Boston, MA, USA ©1995. ISBN:0-201-63361-2 
