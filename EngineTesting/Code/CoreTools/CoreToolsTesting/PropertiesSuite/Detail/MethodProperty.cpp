/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.10 (2024/05/27 19:39)

#include "MethodProperty.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Properties/MethodPropertyGetDetail.h"
#include "CoreTools/Properties/MethodPropertyGetExternalDetail.h"
#include "CoreTools/Properties/MethodPropertyGetSetDetail.h"
#include "CoreTools/Properties/MethodPropertyGetSetExternalDetail.h"
#include "CoreTools/Properties/MethodPropertySetDetail.h"
#include "CoreTools/Properties/MethodPropertySetExternalDetail.h"

CoreTools::MethodProperty::MethodProperty() noexcept
    : getType{}, setType{}, getSetType{}, getExternalType{}, setExternalType{}, getSetExternalType{}, value{ 0 }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, MethodProperty)

ptrdiff_t CoreTools::MethodProperty::FirstValueGetOffset() noexcept
{
    return offsetof(ClassType, getType);
}

ptrdiff_t CoreTools::MethodProperty::FirstValueSetOffset() noexcept
{
    return offsetof(ClassType, setType);
}

const int& CoreTools::MethodProperty::GetValue() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return value;
}

void CoreTools::MethodProperty::SetValue(const int& aValue) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    value = aValue;
}

ptrdiff_t CoreTools::MethodProperty::FirstValueGetSetOffset() noexcept
{
    return offsetof(ClassType, getSetType);
}

ptrdiff_t CoreTools::MethodProperty::FirstValueGetExternalOffset() noexcept
{
    return offsetof(ClassType, getExternalType);
}

ptrdiff_t CoreTools::MethodProperty::FirstValueSetExternalOffset() noexcept
{
    return offsetof(ClassType, setExternalType);
}

ptrdiff_t CoreTools::MethodProperty::FirstValueGetSetExternalOffset() noexcept
{
    return offsetof(ClassType, getSetExternalType);
}
