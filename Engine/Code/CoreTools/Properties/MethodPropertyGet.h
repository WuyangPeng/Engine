///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/22 18:38)

#ifndef CORE_TOOLS_PROPERTIES_METHOD_PROPERTY_GET_H
#define CORE_TOOLS_PROPERTIES_METHOD_PROPERTY_GET_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/PropertiesMacro.h"

// ʹ�ú�TCRE_METHOD_PROPERTY_GET��������
namespace CoreTools
{
    template <typename Value,  // ʵ������ֵ����
              typename ConstReference,  // ��������
              typename Container,  // �����
              ptrdiff_t (*FO)(),  // ָ�뺯���ṩ������ƫ������
              ConstReference (Container::*FG)() const>  // ָ�򷵻�R��const��Ա������ָ��
    class MethodPropertyGet final
    {
    public:
        using ValueType = Value;
        using ConstReferenceType = ConstReference;
        using ContainerType = Container;
        using ClassType = MethodPropertyGet<ValueType, ConstReferenceType, ContainerType, FO, FG>;

        CLASS_INVARIANT_DECLARE;

    private:
        MethodPropertyGet() noexcept;
        explicit MethodPropertyGet(ConstReferenceType value);

        ~MethodPropertyGet() noexcept = default;
        MethodPropertyGet(const MethodPropertyGet& rhs) noexcept = delete;
        MethodPropertyGet& operator=(const MethodPropertyGet& rhs) noexcept = delete;
        MethodPropertyGet(MethodPropertyGet&& rhs) noexcept = delete;
        MethodPropertyGet& operator=(MethodPropertyGet&& rhs) noexcept = delete;

        TCRE_DECLARE_TEMPLATE_PARAM_AS_FRIEND(ContainerType);

    public:
        NODISCARD operator ConstReferenceType() const noexcept;

    private:
        ValueType m_Value;
    };
}

#endif  // CORE_TOOLS_PROPERTIES_METHOD_PROPERTY_GET_H