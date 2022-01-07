///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/24 23:12)

#include "CoreTools/CoreToolsExport.h"

#include "Rtti.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::Rtti::Rtti(const char* name, const Rtti* baseType) noexcept
    : name{ name }, baseType{ baseType }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool CoreTools::Rtti::IsValid() const noexcept
{
    if (name != nullptr)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

const char* CoreTools::Rtti::GetName() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return name;
}

bool CoreTools::Rtti::IsExactly(const Rtti& type) const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return (&type == this);
}

bool CoreTools::Rtti::IsDerived(const Rtti& type) const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    auto search = this;
    while (search != nullptr)
    {
        if (search == &type)
        {
            return true;
        }
        search = search->baseType;
    }

    return false;
}
