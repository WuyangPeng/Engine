// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 19:00)

#include "Entity.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemoryMacro.h"

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26455)
CoreTools::Entity ::Entity()
    : ParentType{}, m_Value{ 0 }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}
#include STSTEM_WARNING_POP

CoreTools::Entity ::Entity(int value)
    : ParentType{}, m_Value{ value }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, Entity)

bool CoreTools::Entity ::EventFunction(const Telegram& telegram)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    m_Value += telegram.GetCallbackParameters().GetInt32Value(0);

    return true;
}

int CoreTools::Entity ::GetValue() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return m_Value;
}
