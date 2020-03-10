// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/21 13:35)

#include "CoreTools/CoreToolsExport.h"

#include "MemoryManager.h"
#include "Detail/MemoryManagerImpl.h"
#include "System/Helper/UnusedMacro.h"
#include "System/MemoryTools/MemoryHelper.h"
#include "CoreTools/Threading/Mutex.h"
#include "CoreTools/Threading/ScopedMutex.h"
#include "CoreTools/Helper/MainFunctionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::string;
using std::make_shared;
using std::make_unique;

SINGLETON_MUTEX_DEFINE(CoreTools, MemoryManager);

#define MUTEX_ENTER_GLOBAL CoreTools::ScopedMutex holder{ g_CoreToolsMutex }

#define MUTEX_ENTER_MEMBER CoreTools::ScopedMutex holder{ *sm_MemoryManagerMutex }

SINGLETON_GET_PTR_DEFINE(CoreTools, MemoryManager)

void CoreTools::MemoryManager
	::Create(Allocator allocator, Deallocator deallocator)
{
	MUTEX_ENTER_GLOBAL;

	try
	{
		DoCreate(allocator, deallocator);
	}
	catch (...)
	{
		Destroy();
		throw;
	}
}

void CoreTools::MemoryManager
	::DoCreate(Allocator allocator, Deallocator deallocator)
{
	MUTEX_ENTER_GLOBAL;

	if (!sm_MemoryManagerMutex)
	{
		sm_MemoryManagerMutex = make_unique<Mutex>().release();
	}

	if (!sm_MemoryManager)
	{
		sm_MemoryManager = new MemoryManager{ allocator,deallocator };
	}
}

void CoreTools::MemoryManager
	::Destroy()
{
	MUTEX_ENTER_GLOBAL;

	delete sm_MemoryManager;
	sm_MemoryManager = nullptr;

	delete sm_MemoryManagerMutex;
	sm_MemoryManagerMutex = nullptr;
}

CoreTools::MemoryManager
	::MemoryManager(Allocator allocator, Deallocator deallocator)
	:m_Impl{ make_shared<ImplType>(allocator,deallocator) }
{
	MUTEX_ENTER_MEMBER;

	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::MemoryManager
	::~MemoryManager()
{
	MUTEX_ENTER_MEMBER;

	PrintMemoryLeakInformation();

	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::MemoryManager
	::IsValid() const noexcept
{
	MUTEX_ENTER_MEMBER;

	if (m_Impl != nullptr)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

// static
void* CoreTools::MemoryManager
	::DefaultAllocator(size_t bytesNumber, const FunctionDescribed& functionDescribed) noexcept
{
	MUTEX_ENTER_GLOBAL;

	SYSTEM_UNUSED_ARG(functionDescribed);

	return System::MallocMemory(bytesNumber);
}

// static
void CoreTools::MemoryManager
	::DefaultDeallocator(const void* memBlock, const FunctionDescribed& functionDescribed) noexcept
{
	MUTEX_ENTER_GLOBAL;

	System::FreeMemory(const_cast<void*>(memBlock));

	SYSTEM_UNUSED_ARG(functionDescribed);
}

void CoreTools::MemoryManager
	::PrintMemoryLeakInformation() const
{
	MUTEX_ENTER_MEMBER;

	CLASS_IS_VALID_CONST_1;

	return m_Impl->PrintMemoryLeakInformation();
}

int CoreTools::MemoryManager
	::GetMemBlockDimensions(const void* memBlock) const
{
	MUTEX_ENTER_MEMBER;

	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_Impl->GetMemBlockDimensions(memBlock);
}

size_t CoreTools::MemoryManager
	::GetBytesNumber(const void* memBlock) const
{
	MUTEX_ENTER_MEMBER;

	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_Impl->GetBytesNumber(memBlock);
}

void* CoreTools::MemoryManager
	::CreateBlock(size_t bytesNumber, int dimensionsNumber, const FunctionDescribed& functionDescribed)
{
	MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->CreateBlock(bytesNumber, dimensionsNumber, functionDescribed);
}

void CoreTools::MemoryManager
	::Delete(const void* memBlock)
{
	MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->Delete(memBlock);
}





