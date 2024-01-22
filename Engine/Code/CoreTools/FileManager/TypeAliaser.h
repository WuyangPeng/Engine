/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/10 21:45)

#ifndef CORE_TOOLS_FILE_MANAGER_TYPE_ALIASER_H
#define CORE_TOOLS_FILE_MANAGER_TYPE_ALIASER_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

namespace CoreTools
{
    template <typename From, typename To>
    class TypeAliaser final
    {
    public:
        static_assert(sizeof(From) == sizeof(To));

        using ClassType = TypeAliaser<From, To>;

    public:
        explicit TypeAliaser(From inFromValue) noexcept
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

#endif  // CORE_TOOLS_FILE_MANAGER_TYPE_ALIASER_H
