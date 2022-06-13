///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/18 13:43)

#include "PropertiesBase.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

#include <string>

using std::string;

CoreTools::PropertiesBase::PropertiesBase() noexcept
    : fifthValue{ 0 }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, PropertiesBase)

int CoreTools::PropertiesBase::GetFifthValue() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return fifthValue;
}

void CoreTools::PropertiesBase::SetFifthValue(int value) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    fifthValue = value;
}

namespace CoreTools
{
    const ptrdiff_t CoreTools::PropertyBase<PropertiesBase::PropFifthValue, PropertiesBase>::offset = offsetof(PropertiesBase, FifthValue);
}
