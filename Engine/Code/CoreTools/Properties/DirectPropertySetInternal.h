//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.0 (2020/10/26 13:10)

#ifndef CORE_TOOLS_PROPERTIES_DIRECT_PROPERTY_SET_INTERNAL_H
#define CORE_TOOLS_PROPERTIES_DIRECT_PROPERTY_SET_INTERNAL_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/PropertiesMacro.h"

#include <boost/noncopyable.hpp>

namespace CoreTools
{
    template <typename Value,  // ʵ������ֵ����
              typename Reference,  // ��������
              typename Container>  // �����
    class DirectPropertySetInternal final : private boost::noncopyable
    {
    public:
        using ValueType = Value;
        using ReferenceType = Reference;
        using ContainerType = Container;
        using ClassType = DirectPropertySetInternal<ValueType, ReferenceType, ContainerType>;

        CLASS_INVARIANT_DECLARE;

    private:
        explicit DirectPropertySetInternal(ReferenceType value);
        [[nodiscard]] operator ReferenceType() const;

        TCRE_DECLARE_TEMPLATE_PARAM_AS_FRIEND(ContainerType);

    public:
        DirectPropertySetInternal& operator=(ReferenceType value);

    private:
        ValueType m_Value;
    };
}

#endif  // CORE_TOOLS_PROPERTIES_DIRECT_PROPERTY_SET_INTERNAL_H