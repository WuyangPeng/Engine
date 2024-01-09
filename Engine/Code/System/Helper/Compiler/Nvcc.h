/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/21 18:14)

#ifndef SYSTEM_HELPER_NVCC_H
#define SYSTEM_HELPER_NVCC_H

#if defined(__CUDACC__)

    #define TCRE_USE_NVCC

    // NVIDIA CUDA C++ 编译器设置：

    #if defined(__CUDACC_VER_MAJOR__) && defined(__CUDACC_VER_MINOR__) && defined(__CUDACC_VER_BUILD__)

        #define TCRE_CUDA_VERSION (__CUDACC_VER_MAJOR__ * 1000000 + __CUDACC_VER_MINOR__ * 10000 + __CUDACC_VER_BUILD__)

    #else  // !(defined(__CUDACC_VER_MAJOR__) && defined(__CUDACC_VER_MINOR__) && defined(__CUDACC_VER_BUILD__))

        // 我们不知道CUDA版本是什么，但是肯定是在7.5之前的版本：
        #define TCRE_CUDA_VERSION 7000000

    #endif  // defined(__CUDACC_VER_MAJOR__) && defined(__CUDACC_VER_MINOR__) && defined(__CUDACC_VER_BUILD__)

    #define TCRE_COMPILER_VERSION TCRE_CUDA_VERSION

    #ifndef TCRE_SYSTEM_COMPILER

        #define TCRE_SYSTEM_COMPILER "NVIDIA CUDA C++ 编译器"

    #endif  // TCRE_SYSTEM_COMPILER

    // NVIDIA特定支持（TCRE_GPU_ENABLED）：将一个函数或方法标记为在主机和设备上启用
    #define TCRE_GPU_ENABLED __host__ __device__

#endif  // defined(__CUDACC__)

#endif  // SYSTEM_HELPER_NVCC_H
