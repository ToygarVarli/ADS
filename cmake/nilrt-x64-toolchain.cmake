# CMake toolchain file for NI Linux Real-Time (x64)
# Evan Pezent (epezent@rice.edu)

set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR x64)

# set flag for MEL CMakeLists.txt
set(NI_LRT ON)

# root to cross compiler
set(toolchainpath C:/build/17/x64/sysroots)
# add compiler program path
LIST(APPEND CMAKE_PROGRAM_PATH ${toolchainpath}/i686-nilrtsdk-mingw32/usr/bin/x86_64-nilrt-linux)

# set compiler




set(CMAKE_C_COMPILER ${toolchainpath}/i686-nilrtsdk-mingw32/usr/bin/x86_64-nilrt-linux/x86_64-nilrt-linux-gcc.exe)
set(CMAKE_CXX_COMPILER ${toolchainpath}/i686-nilrtsdk-mingw32/usr/bin/x86_64-nilrt-linux/x86_64-nilrt-linux-g++.exe)

# set to cross compile
set(CMAKE_CROSSCOMPILING 1)

# setup sysroot (for NI RT cross compiler)
set(CMAKE_SYSROOT ${toolchainpath}/core2-64-nilrt-linux CACHE FILEPATH "Path to NI x64 Cross Compiler Sysroot")

set(CMAKE_C_FLAGS_INIT   "-pthread")
set(CMAKE_CXX_FLAGS_INIT "-pthread")