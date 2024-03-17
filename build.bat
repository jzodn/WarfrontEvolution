rmdir /s /q build
mkdir build
cd build
cmake -G "NMake Makefiles"  .. -DCMAKE_BUILD_TYPE=debug -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
