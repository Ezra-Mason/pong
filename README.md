# pong
Pong clone, made using OpenGL and C++

## Building
To build a Visual Studio solution, run the following from within the root directory:
```
 cmake -S . -B build -G "Visual Studio 17 2022"
```
This builds the project in `build\` and create a `Pong.sln` file.

## Running
To run from Visual Studio:
1. Build the application using `Ctrl+Shift+B` 
2. Right-click on the `App` module in the Solution Explorer 
3. Select `Set as Startup project`
