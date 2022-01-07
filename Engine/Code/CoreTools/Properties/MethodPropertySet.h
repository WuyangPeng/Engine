///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/23 11:56)

#ifndef CORE_TOOLS_PROPERTIES_METHOD_PROPERTY_SET_H
#define CORE_TOOLS_PROPERTIES_METHOD_PROPERTY_SET_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/PropertiesMacro.h"

// ʹ�ú�TCRE_METHOD_PROPERTY_SET��������
namespace CoreTools
{
    // �����ṩ���ڷ�����ֻд���Է���

    // contains�ඨ����һ��set������ ����������һ����̬���������������������������ڵ�ƫ������
    // Ȼ��ʹ��ֵ���ͣ��������ͣ��������ͣ���Ա������ƫ�ƺ�����ģ����в�������
    template <typename Value,  // ʵ������ֵ����
              typename Reference,  // ��������
              typename Container,  // �����
              ptrdiff_t (*FO)(),  // ָ�뺯���ṩ������ƫ������
              void (Container::*FS)(Reference)>  // ָ�򷵻�R�ĳ�Ա������ָ��
    class MethodPropertySet final
    {
    public:
        using ValueType = Value;
        using ReferenceType = Reference;
        using ContainerType = Container;
        using ClassType = MethodPropertySet<ValueType, ReferenceType, ContainerType, FO, FS>;

        CLASS_INVARIANT_DECLARE;

    private:
        MethodPropertySet() noexcept;
        explicit MethodPropertySet(ReferenceType value);

        ~MethodPropertySet() noexcept = default;
        MethodPropertySet(const MethodPropertySet& rhs) noexcept = delete;
        MethodPropertySet& operator=(const MethodPropertySet& rhs) noexcept = delete;
        MethodPropertySet(MethodPropertySet&& rhs) noexcept = delete;
        MethodPropertySet& operator=(MethodPropertySet&& rhs) noexcept = delete;

        TCRE_DECLARE_TEMPLATE_PARAM_AS_FRIEND(ContainerType);

    public:
        MethodPropertySet& operator=(ReferenceType value) noexcept;

    private:
        ValueType m_Value;
    };
}

#endif  // CORE_TOOLS_PROPERTIES_METHOD_PROPERTY_SET_H