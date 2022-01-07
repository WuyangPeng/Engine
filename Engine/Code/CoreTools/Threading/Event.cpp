///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/18 12:26)

#include "CoreTools/CoreToolsExport.h"

#include "Event.h"
#include "Detail/EventImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

CoreTools::Event::Event(bool manualReset, bool initialState)
    : impl{ manualReset, initialState }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, Event)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, Event, SetEvent, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, Event, ResetEvent, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, Event, Wait, void)