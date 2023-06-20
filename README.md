# metroidvania-prototype
C++ / SDL2 metroidvania-style platformer inspired by Hollow Knight. VERY VERY Very early developement, like REALLY early. You can barely call it a game at this point. 

## Compiling/running
#### Installing SDL2, SDL2_Image and SDL_ttf (arch): 
`sudo pacman -S sdl2 sdl2_image sdl2_ttf`
#### Installing SDL2, SDL_Image and SDL_ttf (debian):
`sudo apt-get install libsdl2-dev libsdl2-ttf-dev`

#### Compiling:
First pull the repo (duh) `git clone https://github.com/MightySpaceman/metroidvania-prototype`

cd into it and make 

`cd metroidvania-prototype && make`

Then just `./program`

## Todo
- [ ] Fix movement system by limiting height of jumps
- [ ] Add config file for quick settings editing
- [ ] Code refactor/use inheritance with entity class like a normal human being
- [ ] Animations with spritesheets
- [ ] Level props/elements
- [ ] Enemies
- [ ] Level loading system 😬
