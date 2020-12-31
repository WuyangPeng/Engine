///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.2 (2020/11/01 23:37)

#ifndef CORE_TOOLS_FILE_MANAGER_TYPE_ALIASER_H
#define CORE_TOOLS_FILE_MANAGER_TYPE_ALIASER_H

#include "CoreTools/CoreToolsDll.h"

namespace CoreTools
{
    template <typename From, typename To>
    class TypeAliaser final
    {
    public:
        static_assert(sizeof(From) == sizeof(To));

        using ClassType = TypeAliaser<From, To>;

    public:
        constexpr TypeAliaser(From inFromValue) noexcept
            : m_AsFromType(inFromValue)
        {
        }

        constexpr To& Get() noexcept
        {
            return m_AsToType;
        }

        union
        {
            From m_AsFromType;
            To m_AsToType;
        };
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_TYPE_ALIASER_H
