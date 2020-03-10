// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.0 (2020/01/02 16:13)

#ifndef SYSTEM_THREADING_INTERLOCKED_H
#define SYSTEM_THREADING_INTERLOCKED_H

#include "System/SystemDll.h" 

namespace System
{
	// ԭ�Ӳ���

	template<typename T>
	T SystemInterlockedIncrement(T* addend) noexcept;

	template<typename T>
	T SystemInterlockedDecrement(T* addend) noexcept;

	// ���ص���ԭ����ֵ��
	template<typename T>
	T SystemInterlockedExchangeAdd(T* addend, T value) noexcept;

	template<typename T>
	T SystemInterlockedExchange(T* target, T value) noexcept;

	template<typename T>
	T SystemInterlockedExchangeSubtract(T* addend, T value) noexcept;

	template<typename T>
	T SystemInterlockedCompareExchange(T* destination, T exchange, T comperand) noexcept;

	template<typename T>
	T SystemInterlockedAnd(T* destination, T value) noexcept;

	template<typename T>
	T SystemInterlockedOr(T* destination, T value) noexcept;

	template<typename T>
	T SystemInterlockedXor(T* destination, T value) noexcept;
}

#endif // SYSTEM_THREADING_INTERLOCKED_H