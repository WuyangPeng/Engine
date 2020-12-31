//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/10/12 19:21)

#include "CoreTools/CoreToolsExport.h"

#include "Semaphore.h"
#include "Detail/SemaphoreImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::make_shared;

CoreTools::Semaphore::Semaphore(int initialCount, int maximumCount)
    : m_Impl{ make_shared<ImplType>(initialCount, maximumCount) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(CoreTools, Semaphore)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(CoreTools, Semaphore, Release, int, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, Semaphore, Wait, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, Semaphore, GetCurrentCount, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, Semaphore, GetMaximumCount, int)