///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/03/31 14:55)

#ifndef CORE_TOOLS_PROPERTIES_STATIC_PROPERTY_GET_SET_H
#define CORE_TOOLS_PROPERTIES_STATIC_PROPERTY_GET_SET_H

#include "CoreTools/CoreToolsDll.h"

namespace CoreTools
{
    template <typename Value,
              typename GetReference,
              typename SetReference,
              typename Container,
              GetReference (*PropertyGet)(),
              void (*PropertySet)(SetReference)>
    class StaticPropertyGetSet final
    {
    public:
        using ValueType = Value;
        using GetReferenceType = GetReference;
        using SetReferenceType = SetReference;
        using ContainerType = Container;
        using ClassType = StaticPropertyGetSet<ValueType, GetReferenceType, SetReferenceType, ContainerType, PropertyGet, PropertySet>;

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
        StaticPropertyGetSet& operator=(SetReferenceType aValue);

    private:
        ValueType value;
    };
}

#endif  // CORE_TOOLS_PROPERTIES_STATIC_PROPERTY_GET_SET_H