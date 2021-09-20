// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 18:41)

#include "PropertyOffset.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::string;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26455)
CoreTools::PropertyOffset ::PropertyOffset()
    : m_Offset{}, m_Value{ "Value" }, m_InternalOffset{ "Offset" }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}
#include STSTEM_WARNING_POP

CLASS_INVARIANT_STUB_DEFINE(CoreTools, PropertyOffset)

ptrdiff_t CoreTools::PropertyOffset ::GetOffset() noexcept
{
    enum
    {
        offset = offsetof(ClassType, m_Offset)
    };

    return offset;
}

const string& CoreTools::PropertyOffset ::GetValue() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return m_Value;
}

const std::string& CoreTools::PropertyOffset ::GetInternalValue() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return m_InternalOffset.m_Value;
}
