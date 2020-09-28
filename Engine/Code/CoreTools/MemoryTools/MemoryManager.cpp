// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/21 13:35)

#include "CoreTools/CoreToolsExport.h"

#include "MemoryManager.h"
#include "Detail/MemoryManagerImpl.h"

#include "System/MemoryTools/MemoryHelper.h"
#include "CoreTools/Threading/Mutex.h"
#include "CoreTools/Threading/ScopedMutex.h"
#include "CoreTools/Helper/MainFunctionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::string;
using std::make_shared;
using std::make_unique;

#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26487)
#include SYSTEM_WARNING_DISABLE(26492)

SINGLETON_GET_PTR_DEFINE(CoreTools, MemoryManager);

CoreTools::MemoryManager::MemoryManagerUniquePtr CoreTools::MemoryManager
::sm_MemoryManager{ };

 
 

void CoreTools::MemoryManager
	::Create(Allocator allocator, Deallocator deallocator)
{
	sm_MemoryManager = make_unique<CoreTools::MemoryManager>(allocator, deallocator,MemoryManagerCreate::Init);
}
 

void CoreTools::MemoryManager
::Destroy()noexcept
{
	sm_MemoryManager.reset();
}

CoreTools::MemoryManager ::MemoryManager(Allocator allocator, Deallocator deallocator, [[maybe_unused]] MemoryManagerCreate memoryManagerCreate)
    : m_Impl{ make_shared<ImplType>(allocator, deallocator) }
{
	 

	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::MemoryManager
	::~MemoryManager() noexcept
{
	PrintMemoryLeakInformation();

	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(CoreTools, MemoryManager)

// static
void* CoreTools::MemoryManager ::DefaultAllocator([[maybe_unused]] size_t bytesNumber, [[maybe_unused]] const FunctionDescribed& functionDescribed) noexcept
{
 

	 

	return System::MallocMemory(bytesNumber);
}

// static
void CoreTools::MemoryManager ::DefaultDeallocator(const void* memBlock, [[maybe_unused]] const FunctionDescribed& functionDescribed) noexcept
{
 

	System::FreeMemory(const_cast<void*>(memBlock));

 
}

void CoreTools::MemoryManager
	::PrintMemoryLeakInformation() const noexcept
{
	try
	{
	
#include STSTEM_WARNING_PUSH
		#include SYSTEM_WARNING_DISABLE(26447)
		SINGLETON_MUTEX_ENTER_MEMBER;

		CLASS_IS_VALID_CONST_1;

		return m_Impl->PrintMemoryLeakInformation();
		#include STSTEM_WARNING_POP
	}
	catch (...)
	{
		
	}	
}

int CoreTools::MemoryManager
	::GetMemBlockDimensions(const void* memBlock) const
{
	SINGLETON_MUTEX_ENTER_MEMBER;

	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_Impl->GetMemBlockDimensions(memBlock);
}

size_t CoreTools::MemoryManager
	::GetBytesNumber(const void* memBlock) const
{
	SINGLETON_MUTEX_ENTER_MEMBER;

	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_Impl->GetBytesNumber(memBlock);
}

void* CoreTools::MemoryManager
	::CreateBlock(size_t bytesNumber, int dimensionsNumber, const FunctionDescribed& functionDescribed)
{
	SINGLETON_MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->CreateBlock(bytesNumber, dimensionsNumber, functionDescribed);
}

void CoreTools::MemoryManager
	::Delete(const void* memBlock)
{
	SINGLETON_MUTEX_ENTER_MEMBER;

	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->Delete(memBlock);
}





#include STSTEM_WARNING_POP