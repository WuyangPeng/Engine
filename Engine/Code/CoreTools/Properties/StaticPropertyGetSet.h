/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 10:16)

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