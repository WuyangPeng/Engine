//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.7.1.1 (2020/10/20 10:18)

#include "CoreTools/CoreToolsExport.h"

#include "MemoryManager.h"
#include "Detail/MemoryManagerImpl.h"
#include "System/MemoryTools/MemoryHelper.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MainFunctionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Threading/Mutex.h"
#include "CoreTools/Threading/ScopedMutex.h"

using std::make_shared;
using std::make_unique;
using std::string;

SINGLETON_GET_PTR_DEFINE(CoreTools, MemoryManager);

CoreTools::MemoryManager::MemoryManagerUniquePtr CoreTools::MemoryManager::sm_MemoryManager{};

void CoreTools::MemoryManager::Create(Allocator allocator, Deallocator deallocator)
{
    sm_MemoryManager = make_unique<CoreTools::MemoryManager>(allocator, deallocator, MemoryManagerCreate::Init);
}

void CoreTools::MemoryManager::Destroy() noexcept
{
    sm_MemoryManager.reset();
}

CoreTools::MemoryManager::MemoryManager(Allocator allocator, Deallocator deallocator, [[maybe_unused]] MemoryManagerCreate memoryManagerCreate)
    : impl{  allocator, deallocator  }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::MemoryManager::~MemoryManager() noexcept
{
    CoreTools::NoexceptNoReturn(*this, &ClassType::PrintMemoryLeakInformation);

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, MemoryManager)

// static
void* CoreTools::MemoryManager::DefaultAllocator([[maybe_unused]] size_t bytesNumber, [[maybe_unused]] const FunctionDescribed& functionDescribed) noexcept
{
    return System::MallocMemory(bytesNumber);
}

// static
void CoreTools::MemoryManager::DefaultDeallocator(const void* memBlock, [[maybe_unused]] const FunctionDescribed& functionDescribed) noexcept
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26492)
    System::FreeMemory(const_cast<void*>(memBlock));
#include STSTEM_WARNING_POP
}

void CoreTools::MemoryManager::PrintMemoryLeakInformation() const
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    CLASS_IS_VALID_CONST_1;

    return impl->PrintMemoryLeakInformation();
}

int CoreTools::MemoryManager::GetMemBlockDimensions(const void* memBlock) const
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->GetMemBlockDimensions(memBlock);
}

size_t CoreTools::MemoryManager::GetBytesNumber(const void* memBlock) const
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->GetBytesNumber(memBlock);
}

void* CoreTools::MemoryManager::CreateBlock(size_t bytesNumber, int dimensionsNumber, const FunctionDescribed& functionDescribed)
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    

    return impl->CreateBlock(bytesNumber, dimensionsNumber, functionDescribed);
}

void CoreTools::MemoryManager::Delete(const void* memBlock)
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    

    return impl->Delete(memBlock);
}
