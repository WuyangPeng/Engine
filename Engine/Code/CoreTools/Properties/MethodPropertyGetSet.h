///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/09/20 15:07)

#ifndef CORE_TOOLS_PROPERTIES_METHOD_PROPERTY_GET_SET_H
#define CORE_TOOLS_PROPERTIES_METHOD_PROPERTY_GET_SET_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/PropertiesMacro.h"

// ʹ�ú�TCRE_METHOD_PROPERTY_GETSET��������
namespace CoreTools
{
    // �����ṩ���ڷ����Ķ�/д���Է���

    // �����ඨ��get��set������ ����������һ����̬���������������������������ڵ�ƫ������
    // Ȼ��ʹ��ֵ���ͣ������������ͣ���ȡ�������ͣ��������ͣ���Ա������ƫ�ƺ�����ģ����в�������

    template <typename Value,  // ʵ������ֵ����
              typename GetReference,  // ��ȡ��������
              typename SetReference,  // ������������
              typename Container,  // �����
              ptrdiff_t (*FunctionOffset)(),  // ָ�뺯���ṩ������ƫ������
              GetReference (Container::*FunctionGet)() const,  // ָ�򷵻�R��const��Ա������ָ��
              void (Container::*FunctionSet)(SetReference)>  // ָ��R�ĳ�Ա������ָ��
    class MethodPropertyGetSet final
    {
    public:
        using ValueType = Value;
        using GetReferenceType = GetReference;
        using SetReferenceType = SetReference;
        using ContainerType = Container;
        using ClassType = MethodPropertyGetSet<ValueType, GetReferenceType, SetReferenceType, ContainerType, FunctionOffset, FunctionGet, FunctionSet>;

        CLASS_INVARIANT_DECLARE;

    private:
        MethodPropertyGetSet() noexcept;
        explicit MethodPropertyGetSet(SetReferenceType value);

    public:
        ~MethodPropertyGetSet() noexcept = default;
        MethodPropertyGetSet(const MethodPropertyGetSet& rhs) noexcept = delete;
        MethodPropertyGetSet& operator=(const MethodPropertyGetSet& rhs) noexcept = delete;
        MethodPropertyGetSet(MethodPropertyGetSet&& rhs) noexcept = delete;
        MethodPropertyGetSet& operator=(MethodPropertyGetSet&& rhs) noexcept = delete;

    private:
        TCRE_DECLARE_TEMPLATE_PARAM_AS_FRIEND(ContainerType);

    public:
        NODISCARD operator GetReferenceType() const noexcept;
        MethodPropertyGetSet& operator=(SetReferenceType aValue) noexcept;

    private:
        ValueType value;
    };
}

#endif  // CORE_TOOLS_PROPERTIES_METHOD_PROPERTY_GET_SET_H