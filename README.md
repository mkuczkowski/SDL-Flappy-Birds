# SDL-Flappy-Birds
[Flappy Birds](https://en.wikipedia.org/wiki/Flappy_Bird) clone recreated using SDL library for C++

 ### Features  
 * Dynamic collision detection system
 * Interactive obstacles (pipes move up and down)
 * Randomly generated obstacle positions
 * Perspective of 3D graphics
 
 ### Technologies and tools used
* [Code::Blocks](http://www.codeblocks.org/) - Cross-platform integrated development environment
* [SDL version 1.2.15](http://www.libsdl.org/download-1.2.php) - Development library designed to provide low level access to audio, keyboard, mouse, joystick, and graphics hardware via OpenGL and Direct3D

### Example SDL installation for Windows & CodeBlocks users
Enter [this website](http://www.libsdl.org/download-1.2.php) and download SDL-devel-1.2.15-mingw32.tar.gz (Mingw32) file and extract it.  
Copy the libSDL.dll.a, libSDL.la and libSDLmain.a files from the "lib" directory to the "lib" directory of the CodeBlocks compiler.
Copy the "SDL" directory from the "include" directory to the "include" directory of the CodeBlocks compiler.  
Copy the SDL.dll file from the "bin" directory to the "C:/Windows/System32" directory (32-bit system) or to the "C:/Windows/SysWOW64" directory (64-bit system).  
In the "linker settings" of the CodeBlocks project, add the following line:  

```sh
 -lmingw32 -lSDLMain -lSDL -lopengl32 -lglu32
```  
Make sure that in Settings->Compiler and debugger->Toolchain Executables the path to compiler is as follows:  
```sh
  C:\Program Files\CodeBlocks\MinGW  
```  
If everything has been done correctly, you will be able to run any SDL 1.2.15 app via CodeBlocks.
