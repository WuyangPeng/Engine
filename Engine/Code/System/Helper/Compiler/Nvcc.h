// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.2.0.0 (2020/05/07 15:33)

#ifndef SYSTEM_HELPER_NVCC_H
#define SYSTEM_HELPER_NVCC_H

#if defined(__CUDACC__)

	#define TCRE_USE_NVCC

	// NVIDIA CUDA C++ ���������ã�

	#ifndef TCRE_SYSTEM_COMPILER
		#define TCRE_SYSTEM_COMPILER "NVIDIA CUDA C++ ������"
	#endif // TCRE_SYSTEM_COMPILER

	// NVIDIA�ض�֧�֣�TCRE_GPU_ENABLED������һ�������򷽷����Ϊ���������豸������
	#define TCRE_GPU_ENABLED __host__ __device__ 

#endif // defined(__CUDACC__)

#endif // SYSTEM_HELPER_NVCC_H
