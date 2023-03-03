///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.3 (2023/03/01 17:33) 

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