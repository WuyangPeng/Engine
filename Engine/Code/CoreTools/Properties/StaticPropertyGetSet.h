///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/23 18:06)

#ifndef CORE_TOOLS_PROPERTIES_STATIC_PROPERTY_GET_SET_H
#define CORE_TOOLS_PROPERTIES_STATIC_PROPERTY_GET_SET_H

#include "CoreTools/CoreToolsDll.h"

namespace CoreTools
{
    template <typename Value,
              typename GetReference,
              typename SetReference,
              typename Container,
              GetReference (*FG)(void),
              void (*FS)(SetReference)>
    class StaticPropertyGetSet final
    {
    public:
        using ValueType = Value;
        using GetReferenceType = GetReference;
        using SetReferenceType = SetReference;
        using ContainerType = Container;
        using ClassType = StaticPropertyGetSet<ValueType, GetReferenceType, SetReferenceType, ContainerType, FG, FS>;

    public:
        StaticPropertyGetSet() noexcept;
        explicit StaticPropertyGetSet(SetReferenceType value);

        ~StaticPropertyGetSet() noexcept = default;
        StaticPropertyGetSet(const StaticPropertyGetSet& rhs) noexcept = delete;
        StaticPropertyGetSet& operator=(const StaticPropertyGetSet& rhs) noexcept = delete;
        StaticPropertyGetSet(StaticPropertyGetSet&& rhs) noexcept = delete;
        StaticPropertyGetSet& operator=(StaticPropertyGetSet&& rhs) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

    public:
        NODISCARD operator GetReferenceType() const noexcept;
        StaticPropertyGetSet& operator=(SetReferenceType value);

    private:
        ValueType m_Value;
    };
}

#endif  // CORE_TOOLS_PROPERTIES_STATIC_PROPERTY_GET_SET_H