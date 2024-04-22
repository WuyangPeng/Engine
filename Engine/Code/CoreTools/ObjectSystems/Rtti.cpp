/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/11 22:19)

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
    return name != nullptr;
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
