if not exist build mkdir build

cd build 
cmake ..
CMake --build d:/VSCODE/OOP/Tubes1_OOP/src/build --config Debug --target ALL_BUILD -j 10 --
cd ..
cls
"./build/Debug/Tubes1_OOP.exe"