///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/20 14:36)

#include "CoreTools/CoreToolsExport.h"

#include "Thread.h"
#include "Detail/ThreadImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

CoreTools::Thread::Thread(void* function, void* userData, int processorNumber, ThreadSize stackSize)
    : impl{ function, userData, processorNumber, stackSize }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, Thread)

void CoreTools::Thread::Resume()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return impl->Resume();
}

void CoreTools::Thread::Suspend()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return impl->Suspend();
}

void CoreTools::Thread::Wait()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return impl->Wait();
}

void CoreTools::Thread::SetThreadPriority(int priority)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return impl->SetThreadPriority(priority);
}

int CoreTools::Thread::GetThreadPriority() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->GetThreadPriority();
}
