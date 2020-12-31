//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/21 11:09)

#ifndef SYSTEM_HELPER_NVCC_H
#define SYSTEM_HELPER_NVCC_H

#if defined(__CUDACC__)

    #define TCRE_USE_NVCC

    // NVIDIA CUDA C++ 编译器设置：

    #ifndef TCRE_SYSTEM_COMPILER
        #define TCRE_SYSTEM_COMPILER "NVIDIA CUDA C++ 编译器"
    #endif  // TCRE_SYSTEM_COMPILER

    // NVIDIA特定支持（TCRE_GPU_ENABLED）：将一个函数或方法标记为在主机和设备上启用
    #define TCRE_GPU_ENABLED __host__ __device__

#endif  // defined(__CUDACC__)

#endif  // SYSTEM_HELPER_NVCC_H
