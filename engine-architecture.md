# Haven Engine Architecture Guideline

## Build System
**Implemented Using:**
- **Premake5**
### Build Types
- **Debug**
Complete debugging info (-g3), No optimization, assertions, full logging.
- **Release**
Some debugging info (-g), Optimized build (-O3), assertions, full logging.
- **Distribution**
No debugging info, Full optimization (-Ofast), only critical logging.

## Core
### Assertions
**Implemented Using:**
- **Catch2**
### Unit Testing
**Implemented Using:**
- **Catch2**
### Math Library
**Implemented Using:**
- **GLM**
Using GLM due to feature set and compatibility with OpenGL.
### Logging
**Implemented Using:**
- **spdlog**
Engine logger should only be accessable from engine.
Client logger should only be accessable from client.
### Configuration / Scripting
**Implemented Using:**
- &#9744; **inih**
- &#9744; **libconfig**
- &#9745; **OpenDDL** *(Custom Parser)*
Use to write out internal state?
- &#9744; **Lua**
- &#9745; **ChaiScript**
Using libconfig because it looks JSONish.
ChaiScript seems like it would interface well with C++
#### Model Parsers
- **[Wavefront OBJ](https://en.wikipedia.org/wiki/Wavefront_.obj_file) to Internal Format**
- **[OpenGEX](http://opengex.org/) to Internal Format**
- **[Quake2/Valve BSP](https://developer.valvesoftware.com/wiki/BSP) to Internal Format**
## Renderer
**Implemented Renderers:**
- &#9744; **renderer_gl** *(OpenGL 3.3 core - Windows, Linux)*
glfw / glad
- &#9744; **renderer_sw** *(Software Renderer - Windows, MacOS, Linux)*
- &#9744; **renderer_dx** *(DirectX 11 - Windows)*
- &#9744; **renderer_vk** *(Vulkan - Windows, MacOS (via MoltenVK), Linux)*

Starting with OpenGL renderer.
## Resource Manager

## UI
### Debug UI
**Implemented Using:**
- &#9745; **ImGui**