///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.3 (2023/03/01 17:34)

#include "CoreTools/CoreToolsExport.h"

#include "ThreadManager.h"
#include "Detail/ThreadManagerImpl.h"
#include "System/Helper/Tools.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

CoreTools::ThreadManager::ThreadManager(DisableNotThrow disableNotThrow)
    : impl{ ImplCreateUseDefaultConstruction::Default }
{
    System::UnusedFunction(disableNotThrow);

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

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

CoreTools::ThreadManager CoreTools::ThreadManager::Create()
{
    return ThreadManager{ DisableNotThrow::Disable };
}
