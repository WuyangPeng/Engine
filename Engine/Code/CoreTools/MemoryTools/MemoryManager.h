// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.1 (2020/01/20 16:41)

#ifndef CORE_TOOLS_MEMORY_TOOLS_MEMORY_MANAGER_H
#define CORE_TOOLS_MEMORY_TOOLS_MEMORY_MANAGER_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/Helper/SingletonMacro.h"
#include "CoreTools/Base/SingletonDetail.h"
#include "CoreTools/Threading/ThreadingFwd.h"

#include <string>

CORE_TOOLS_EXPORT_SHARED_PTR(MemoryManagerImpl);
EXPORT_NONCOPYABLE_CLASS(CORE_TOOLS);

namespace CoreTools
{
	class CORE_TOOLS_DEFAULT_DECLARE MemoryManager : public CoreTools::Singleton<MemoryManager>
	{
	public:
		SINGLETON_GET_PTR_DECLARE(MemoryManager);
		NON_COPY_CLASSES_TYPE_DECLARE(MemoryManager);
		using ParentType = Singleton<MemoryManager>;

		// 让用户提供他们自己的分配函数和释放函数。
		using Allocator = void* (*)(size_t bytesNumber, const FunctionDescribed& functionDescribed);
		using Deallocator = void(*)(const void* memBlock, const FunctionDescribed& functionDescribed);

	public:
		// 初始化和终止函数在main函数中调用。要指定自己的分配函数和释放函数，修改Memory::Create调用在main。
		static void Create(Allocator allocator = &DefaultAllocator, Deallocator deallocator = &DefaultDeallocator);
		static void Destroy();

	private:
		static void DoCreate(Allocator allocator, Deallocator deallocator);
		MemoryManager(Allocator allocator, Deallocator deallocator);
		virtual ~MemoryManager();

	public:
		CLASS_INVARIANT_DECLARE;

		void PrintMemoryLeakInformation() const;
		int GetMemBlockDimensions(const void* memBlock) const;
		size_t GetBytesNumber(const void* memBlock) const;

		void* CreateBlock(size_t bytesNumber, int dimensionsNumber, const FunctionDescribed& functionDescribed);
		void Delete(const void* memBlock);

	private:
		static void* DefaultAllocator(size_t bytesNumber, const FunctionDescribed& functionDescribed) noexcept;
		static void DefaultDeallocator(const void* memBlock, const FunctionDescribed& functionDescribed) noexcept;

		SINGLETON_MEMBER_DECLARE(MemoryManager);
	};
}

#define MEMORY_MANAGER_SINGLETON CoreTools::MemoryManager::GetSingleton()

#endif // CORE_TOOLS_MEMORY_TOOLS_MEMORY_MANAGER_H
