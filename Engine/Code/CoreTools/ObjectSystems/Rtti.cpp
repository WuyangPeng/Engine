///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/20 15:53)

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
