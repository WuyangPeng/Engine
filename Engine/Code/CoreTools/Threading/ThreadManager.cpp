//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/10/12 19:21)

#include "CoreTools/CoreToolsExport.h"

#include "ThreadManager.h"
#include "Detail/ThreadManagerImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::make_shared;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26455)
CoreTools::ThreadManager::ThreadManager()
    : impl{ 0  }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}
#include STSTEM_WARNING_POP
CLASS_INVARIANT_STUB_DEFINE(CoreTools, ThreadManager)

void CoreTools::ThreadManager::AddThread(void* function, void* userData, int processorNumber, ThreadSize stackSize)
{
    

    return impl->AddThread(function, userData, processorNumber, stackSize);
}

void CoreTools::ThreadManager::AddThreadUsePriority(void* function, void* userData, int priority, int processorNumber, ThreadSize stackSize)
{
    

    return impl->AddThreadUsePriority(function, userData, priority, processorNumber, stackSize);
}

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, ThreadManager, Resume, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, ThreadManager, Suspend, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, ThreadManager, Wait, void)