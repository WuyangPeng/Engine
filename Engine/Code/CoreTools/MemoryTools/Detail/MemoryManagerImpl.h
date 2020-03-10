// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.1 (2020/01/20 16:40)

#ifndef CORE_TOOLS_MEMORY_TOOLS_MEMORY_MANAGER_IMPL_H
#define CORE_TOOLS_MEMORY_TOOLS_MEMORY_MANAGER_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "MemoryInformation.h"

#include <map>
#include <string>

namespace CoreTools
{
	class CORE_TOOLS_HIDDEN_DECLARE MemoryManagerImpl
	{
	public:
		using ClassType = MemoryManagerImpl;

		// 让用户提供他们自己的分配函数和释放函数。
		using Allocator = void*(*)(size_t bytesNumber, const FunctionDescribed& functionDescribed);
		using Deallocator = void(*)(const void* memBlock, const FunctionDescribed& functionDescribed);

	public:
		MemoryManagerImpl(Allocator allocator, Deallocator deallocator);

		CLASS_INVARIANT_DECLARE;

		void PrintMemoryLeakInformation() const;
		int GetMemBlockDimensions(const void* memBlock) const;
		size_t GetBytesNumber(const void* memBlock) const;

		void* CreateBlock(size_t bytesNumber, int dimensionsNumber, const FunctionDescribed& functionDescribed);
		void Delete(const void* memBlock);

	private:
		using MemoryContainer = std::map<const void*, MemoryInformation>;
		using SortedContainer = std::map<uint64_t, MemoryContainer::value_type>;

	private:
		MemoryContainer m_MemoryContainer;
		Allocator m_Allocator;
		Deallocator m_Deallocator;
	};
}

#endif // CORE_TOOLS_MEMORY_TOOLS_MEMORY_MANAGER_IMPL_H
