// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.2.0.0 (2020/05/07 15:33)

#ifndef SYSTEM_HELPER_NVCC_H
#define SYSTEM_HELPER_NVCC_H

#if defined(__CUDACC__)

	#define TCRE_USE_NVCC

	// NVIDIA CUDA C++ 编译器设置：

	#ifndef TCRE_SYSTEM_COMPILER
		#define TCRE_SYSTEM_COMPILER "NVIDIA CUDA C++ 编译器"
	#endif // TCRE_SYSTEM_COMPILER

	// NVIDIA特定支持（TCRE_GPU_ENABLED）：将一个函数或方法标记为在主机和设备上启用
	#define TCRE_GPU_ENABLED __host__ __device__ 

#endif // defined(__CUDACC__)

#endif // SYSTEM_HELPER_NVCC_H
