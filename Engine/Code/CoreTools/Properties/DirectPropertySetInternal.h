///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/22 18:19)

#ifndef CORE_TOOLS_PROPERTIES_DIRECT_PROPERTY_SET_INTERNAL_H
#define CORE_TOOLS_PROPERTIES_DIRECT_PROPERTY_SET_INTERNAL_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/PropertiesMacro.h"

namespace CoreTools
{
    template <typename Value,  // ʵ������ֵ����
              typename Reference,  // ��������
              typename Container>  // �����
    class DirectPropertySetInternal final
    {
    public:
        using ValueType = Value;
        using ReferenceType = Reference;
        using ContainerType = Container;
        using ClassType = DirectPropertySetInternal<ValueType, ReferenceType, ContainerType>;

        CLASS_INVARIANT_DECLARE;

    private:
        explicit DirectPropertySetInternal(ReferenceType value);

        ~DirectPropertySetInternal() noexcept = default;
        DirectPropertySetInternal(const DirectPropertySetInternal& rhs) noexcept = delete;
        DirectPropertySetInternal& operator=(const DirectPropertySetInternal& rhs) noexcept = delete;
        DirectPropertySetInternal(DirectPropertySetInternal&& rhs) noexcept = delete;
        DirectPropertySetInternal& operator=(DirectPropertySetInternal&& rhs) noexcept = delete;

        NODISCARD operator ReferenceType() const;

        TCRE_DECLARE_TEMPLATE_PARAM_AS_FRIEND(ContainerType);

    public:
        DirectPropertySetInternal& operator=(ReferenceType value);

    private:
        ValueType m_Value;
    };
}

#endif  // CORE_TOOLS_PROPERTIES_DIRECT_PROPERTY_SET_INTERNAL_H