/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 10:14)

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
              ptrdiff_t (*FunctionOffset)(),  // ָ�뺯���ṩ������ƫ������
              void (Container::*FunctionSet)(Reference)>  // ָ�򷵻�R�ĳ�Ա������ָ��
    class MethodPropertySet final
    {
    public:
        using ValueType = Value;
        using ReferenceType = Reference;
        using ContainerType = Container;
        using ClassType = MethodPropertySet<ValueType, ReferenceType, ContainerType, FunctionOffset, FunctionSet>;

        CLASS_INVARIANT_DECLARE;

    private:
        MethodPropertySet() noexcept;
        explicit MethodPropertySet(ReferenceType value);

    public:
        ~MethodPropertySet() noexcept = default;
        MethodPropertySet(const MethodPropertySet& rhs) noexcept = delete;
        MethodPropertySet& operator=(const MethodPropertySet& rhs) noexcept = delete;
        MethodPropertySet(MethodPropertySet&& rhs) noexcept = delete;
        MethodPropertySet& operator=(MethodPropertySet&& rhs) noexcept = delete;

    private:
        TCRE_DECLARE_TEMPLATE_PARAM_AS_FRIEND(ContainerType);

    public:
        MethodPropertySet& operator=(ReferenceType aValue) noexcept;

    private:
        ValueType value;
    };
}

#endif  // CORE_TOOLS_PROPERTIES_METHOD_PROPERTY_SET_H