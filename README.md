## Minesweeper

#### Description
This is an implementation of Minesweeper using the SFML library in C++.

#### Creators
- Aabhwan Adhikary - Lab Section 9 - ID: 011915647
- Abby Wu - Lab Section 13 - ID: 011912550
- Addelyn Navarro - Lab Section 7 - ID: 011733012

#### Demonstration
Video Link: https://drive.google.com/file/d/1vujUk4yeb1h-PRjienmckRgY4idBAdrC/view?usp=sharing

#### Running the Application
In Visual Studio:
1. Create an empty Visual Studio project
2. Clone the repository into the project folder. Once cloned, it is best to move the Images and Fonts folder in the cloned repository folder outside of that folder (in the same folder as the project)
3. Open the Properties window of the project by right-clicking on the project in the Solution Explorer. We will start with the "Debug" configuration, which is shown on the top of the Properties window.
4. In the General tab, set C++ Language Standard to "ISO C++20 Standard (/std:c++20)"
5. Click on the arrow next to the "C/C++" folder in Properties, and then click on the General tab. In "Additional Include Directories," paste the complete file path of the "include" folder in the SFML folder.
6. Click on the arrow next to the "Linker" folder in Properties, and then click on the General tab. In "Additional Library Directories," paste the complete file path of the "lib" folder in the SFML folder.
7. In the "Input" tab in Linker, in the "Additional Dependencies" section, paste the following in:
```
sfml-window-d.lib
sfml-graphics-d.lib
sfml-system-d.lib
sfml-audio-d.lib
```
8. Repeat steps 4-6 for the "Release" configuration. When you get to the "Additional Dependencies" section, paste the following in:
```
sfml-window.lib
sfml-graphics.lib
sfml-system.lib
sfml-audio.lib
```
10. Compile the program with both the "Debug" and "Release" configurations. This is shown in the top of the Visual Studio interface. Note that the program won't work yet, as there are a few extra steps.
11. In the "bin" folder in the SFML folder, copy the files shown below:
```
sfml-audio-d-3.dll
sfml-graphics-d-3.dll
sfml-system-d-3.dll
sfml-window-d-3.dll
```
12. Then, go to the x64 folder in the project folder, open the "Debug" folder, then paste the above files in.
13. In the "bin" folder, copy the files shown below:
```
sfml-audio-3.dll
sfml-graphics-3.dll
sfml-system-3.dll
sfml-window-3.dll
```
14. Then, go to the x64 folder, open the "Release" folder, then paste the above files in.
15. The application should now work when run!

#### Game Instructions
- Click on play button to start the game
- Left click on a tile to mine it
- Right click on a tile to flag it
- If you mine all tiles that aren't bombs, you win
- If you mine a bomb, you lose
