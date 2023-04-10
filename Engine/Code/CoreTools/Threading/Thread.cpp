///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/03/31 16:40)

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

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, Thread, Resume, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, Thread, Suspend, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, Thread, Wait, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(CoreTools, Thread, SetThreadPriority, int, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, Thread, GetThreadPriority, int)
