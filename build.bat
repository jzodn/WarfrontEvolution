rmdir /s /q build
mkdir build
cd build
cmake -G "NMake Makefiles" .. -DCMAKE_EXPORT_COMPILE_COMMANDS=ON