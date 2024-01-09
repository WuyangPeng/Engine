/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2023/12/21 18:14)

#ifndef SYSTEM_HELPER_NVCC_H
#define SYSTEM_HELPER_NVCC_H

#if defined(__CUDACC__)

    #define TCRE_USE_NVCC

    // NVIDIA CUDA C++ ���������ã�

    #if defined(__CUDACC_VER_MAJOR__) && defined(__CUDACC_VER_MINOR__) && defined(__CUDACC_VER_BUILD__)

        #define TCRE_CUDA_VERSION (__CUDACC_VER_MAJOR__ * 1000000 + __CUDACC_VER_MINOR__ * 10000 + __CUDACC_VER_BUILD__)

    #else  // !(defined(__CUDACC_VER_MAJOR__) && defined(__CUDACC_VER_MINOR__) && defined(__CUDACC_VER_BUILD__))

        // ���ǲ�֪��CUDA�汾��ʲô�����ǿ϶�����7.5֮ǰ�İ汾��
        #define TCRE_CUDA_VERSION 7000000

    #endif  // defined(__CUDACC_VER_MAJOR__) && defined(__CUDACC_VER_MINOR__) && defined(__CUDACC_VER_BUILD__)

    #define TCRE_COMPILER_VERSION TCRE_CUDA_VERSION

    #ifndef TCRE_SYSTEM_COMPILER

        #define TCRE_SYSTEM_COMPILER "NVIDIA CUDA C++ ������"

    #endif  // TCRE_SYSTEM_COMPILER

    // NVIDIA�ض�֧�֣�TCRE_GPU_ENABLED������һ�������򷽷����Ϊ���������豸������
    #define TCRE_GPU_ENABLED __host__ __device__

#endif  // defined(__CUDACC__)

#endif  // SYSTEM_HELPER_NVCC_H
