///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/18 12:27)

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

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(CoreTools, Semaphore, Release, int, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, Semaphore, Wait, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, Semaphore, GetCurrentCount, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, Semaphore, GetMaximumCount, int)