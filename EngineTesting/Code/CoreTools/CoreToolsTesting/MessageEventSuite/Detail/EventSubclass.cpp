// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 19:00)

#include "EventSubclass.h"
#include "CoreTools/Helper/MemoryMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/MessageEvent/Telegram.h"
#include "CoreTools/MessageEvent/CallbackParameters.h"
 

CoreTools::EventSubclass ::EventSubclass(int value) noexcept
    : m_Value{ value }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, EventSubclass)

int CoreTools::EventSubclass ::GetValue() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return m_Value;
}

void CoreTools::EventSubclass ::SetValue(int Value) noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	m_Value = Value;
}

bool CoreTools::EventSubclass
	::EventFunction(const CallbackParameters& callbackParameters)
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	m_Value += callbackParameters.GetInt32Value(0);

	return true;
}

