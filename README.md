# newday
凡是过往,皆为序章！！！

每天都是新的一天！！！

# Cmake

## 基础命令

1. 查看版本

   ```shell
   cmake --version
   ```

2. 初始化项目构建

   ```shell
   cmake . -B build -G "Unix Makefiles"
   ```

3. 编译项目并显示编译信息

   ```shell
   cmake --build ./build -v
   ```

4. Cmake 中使用 vcpkg

   ```shell
   # cmake -B [build directory] -S . "-DCMAKE_TOOLCHAIN_FILE=[path to vcpkg]/scripts/buildsystems/vcpkg.cmake"
   cmake -B build -S . "-DCMAKE_TOOLCHAIN_FILE=/Users/muqing/Downloads/tools/vcpkg/scripts/buildsystems/vcpkg.cmake"
   ```

   

## CMakeLists.txt解析

```cmake
// 设置项目编译所使用的的 cmake 版本
cmake_minimum_required(VERSION 3.23.2)
// 设置项目名称和项目所使用的语言
project(sort C)

// 设置项目所使用的的C语言语法版本
set(CMAKE_C_STANDARD 99)

// 设置项目的可执行二进制文件名称以及编译所需源文件
add_executable(
    sort
    main.c
)
```

