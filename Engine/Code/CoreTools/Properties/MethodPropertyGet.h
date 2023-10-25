///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/09/20 15:07)

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
              ptrdiff_t (*FunctionOffset)(),  // ָ�뺯���ṩ������ƫ������
              ConstReference (Container::*FunctionGet)() const>  // ָ�򷵻�R��const��Ա������ָ��
    class MethodPropertyGet final
    {
    public:
        using ValueType = Value;
        using ConstReferenceType = ConstReference;
        using ContainerType = Container;
        using ClassType = MethodPropertyGet<ValueType, ConstReferenceType, ContainerType, FunctionOffset, FunctionGet>;

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
        ValueType value;
    };
}

#endif  // CORE_TOOLS_PROPERTIES_METHOD_PROPERTY_GET_H