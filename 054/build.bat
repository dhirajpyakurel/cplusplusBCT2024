@echo off
setlocal enabledelayedexpansion

clang++ -std=c++17 -ladvapi32 -o fonograf.exe main.cpp fonograf.cpp ui.cpp
 
if %errorlevel% neq 0 (
    echo Failed to compile.
    exit /b 1
) else (
    echo Compiled successfully!
)
