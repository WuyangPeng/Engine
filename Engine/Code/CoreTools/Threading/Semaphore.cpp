///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/20 14:35)

#include "CoreTools/CoreToolsExport.h"

#include "Semaphore.h"
#include "Detail/SemaphoreImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

CoreTools::Semaphore::Semaphore(int initialCount, int maximumCount)
    : impl{ initialCount, maximumCount }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, Semaphore)

void CoreTools::Semaphore::Release(int releaseCount)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return impl->Release(releaseCount);
}

void CoreTools::Semaphore::Wait()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return impl->Wait();
}

int CoreTools::Semaphore::GetCurrentCount() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->GetCurrentCount();
}

int CoreTools::Semaphore::GetMaximumCount() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->GetMaximumCount();
}
