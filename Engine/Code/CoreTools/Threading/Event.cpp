///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/09/20 14:34)

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

void CoreTools::Event::SetEvent()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return impl->SetEvent();
}

void CoreTools::Event::ResetEvent()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return impl->ResetEvent();
}

void CoreTools::Event::Wait()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return impl->Wait();
}
