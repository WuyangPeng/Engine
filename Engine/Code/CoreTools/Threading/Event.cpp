// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/19 11:29)

#include "CoreTools/CoreToolsExport.h"

#include "Event.h"
#include "Detail/EventImpl.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::make_shared;

CoreTools::Event
	::Event(bool manualReset, bool initialState)
	:m_Impl{ make_shared<ImplType>(manualReset, initialState) }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(CoreTools, Event)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, Event, SetEvent, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, Event, ResetEvent, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, Event, Wait, void)