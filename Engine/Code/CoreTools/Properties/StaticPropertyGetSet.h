//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.0 (2020/10/26 13:15)

#ifndef CORE_TOOLS_PROPERTIES_STATIC_PROPERTY_GET_SET_H
#define CORE_TOOLS_PROPERTIES_STATIC_PROPERTY_GET_SET_H

#include "CoreTools/CoreToolsDll.h"

namespace CoreTools
{
    template <typename Value, typename GetReference, typename SetReference, typename Container,
              GetReference (*FG)(void), void (*FS)(SetReference)>
    class StaticPropertyGetSet final
    {
    public:
        using ValueType = Value;
        using GetReferenceType = GetReference;
        using SetReferenceType = SetReference;
        using ContainerType = Container;
        using ClassType = StaticPropertyGetSet<ValueType, GetReferenceType, SetReferenceType, ContainerType, FG, FS>;

    public:
        StaticPropertyGetSet();
        explicit StaticPropertyGetSet(SetReferenceType value);

        CLASS_INVARIANT_DECLARE;

    public:
        [[nodiscard]] operator GetReferenceType() const;
        StaticPropertyGetSet& operator=(SetReferenceType value);

    private:
        ValueType m_Value;
    };
}

#endif  // CORE_TOOLS_PROPERTIES_STATIC_PROPERTY_GET_SET_H