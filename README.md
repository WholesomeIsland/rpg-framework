# RPG Framework

A C++ SFML library for making turn based RPGs.
Currently in early development, the main/ folder contains a basic program for setting up a world and entering an encounter.
some test assets are included, but the backgrounds are not, there is more details in the building section.

## Building

something like 
```
mkdir build
cd build
cmake ..
```
should generate cmake files, which can be opened or built with your IDE or build system of choice.
test-assets/backgrounds/battle-bg.png and test-assets/backgrounds/test-map.png have to be provided, the assets im using on my end do not allow distribution in their license.
on my end im using images that are 900x540, which is the default size for a tiled map with 32x32 tiles.
the working directory is test-assets/ for the built in example.
