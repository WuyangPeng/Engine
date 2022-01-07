// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 18:41)

#include "DirectPropertyInternal.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::string;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26455)
CoreTools::DirectPropertyInternal ::DirectPropertyInternal()
    : m_GetType{ "Init" }, m_SetType{ "SetType" }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}
#include STSTEM_WARNING_POP

CLASS_INVARIANT_STUB_DEFINE(CoreTools, DirectPropertyInternal)

void CoreTools::DirectPropertyInternal ::SetValue(const std::string& value)
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;

    m_GetType.m_Value = value;
}

std::string CoreTools::DirectPropertyInternal ::GetValue() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return m_SetType.m_Value;
}
