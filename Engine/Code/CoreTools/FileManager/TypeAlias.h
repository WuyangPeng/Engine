/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/03/30 22:57)

#ifndef CORE_TOOLS_FILE_MANAGER_TYPE_ALIAS_H
#define CORE_TOOLS_FILE_MANAGER_TYPE_ALIAS_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

namespace CoreTools
{
    template <typename From, typename To>
    requires(sizeof(From) == sizeof(To))
    class TypeAlias final
    {
    public:
        using ClassType = TypeAlias<From, To>;

    public:
        explicit TypeAlias(From inFromValue) noexcept
            : asFromType{ inFromValue }
        {
            CORE_TOOLS_SELF_CLASS_IS_VALID_9;
        }

#ifdef OPEN_CLASS_INVARIANT

        NODISCARD bool IsValid() const noexcept
        {
            return true;
        }

#endif  // OPEN_CLASS_INVARIANT

        NODISCARD const To& Get() const noexcept
        {
            CORE_TOOLS_CLASS_IS_VALID_CONST_9;

            return asToType;
        }

        union
        {
            From asFromType;
            To asToType;
        };
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_TYPE_ALIAS_H
