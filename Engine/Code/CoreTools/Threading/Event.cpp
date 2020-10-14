//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/10/12 19:19)

#include "CoreTools/CoreToolsExport.h"

#include "Event.h"
#include "Detail/EventImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::make_shared;

CoreTools::Event::Event(bool manualReset, bool initialState)
    : m_Impl{ make_shared<ImplType>(manualReset, initialState) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(CoreTools, Event)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, Event, SetEvent, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, Event, ResetEvent, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, Event, Wait, void)