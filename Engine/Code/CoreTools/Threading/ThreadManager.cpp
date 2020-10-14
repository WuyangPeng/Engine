//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.1 (2020/10/12 19:21)

#include "CoreTools/CoreToolsExport.h"

#include "ThreadManager.h"
#include "Detail/ThreadManagerImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::make_shared;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26455)
CoreTools::ThreadManager::ThreadManager()
    : m_Impl{ make_shared<ImplType>() }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}
#include STSTEM_WARNING_POP
CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(CoreTools, ThreadManager)

void CoreTools::ThreadManager::AddThread(void* function, void* userData, int processorNumber, ThreadSize stackSize)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    return m_Impl->AddThread(function, userData, processorNumber, stackSize);
}

void CoreTools::ThreadManager::AddThreadUsePriority(void* function, void* userData, int priority, int processorNumber, ThreadSize stackSize)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    return m_Impl->AddThreadUsePriority(function, userData, priority, processorNumber, stackSize);
}

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, ThreadManager, Resume, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, ThreadManager, Suspend, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, ThreadManager, Wait, void)