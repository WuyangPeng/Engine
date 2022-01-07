///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/23 11:48)

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
              ptrdiff_t (*FO)(),  // ָ�뺯���ṩ������ƫ������
              GetReference (Container::*FG)() const,  // ָ�򷵻�R��const��Ա������ָ��
              void (Container::*FS)(SetReference)>  // ָ��R�ĳ�Ա������ָ��
    class MethodPropertyGetSet final
    {
    public:
        using ValueType = Value;
        using GetReferenceType = GetReference;
        using SetReferenceType = SetReference;
        using ContainerType = Container;
        using ClassType = MethodPropertyGetSet<ValueType, GetReferenceType, SetReferenceType, ContainerType, FO, FG, FS>;

        CLASS_INVARIANT_DECLARE;

    private:
        MethodPropertyGetSet() noexcept;
        explicit MethodPropertyGetSet(SetReferenceType value);

        ~MethodPropertyGetSet() noexcept = default;
        MethodPropertyGetSet(const MethodPropertyGetSet& rhs) noexcept = delete;
        MethodPropertyGetSet& operator=(const MethodPropertyGetSet& rhs) noexcept = delete;
        MethodPropertyGetSet(MethodPropertyGetSet&& rhs) noexcept = delete;
        MethodPropertyGetSet& operator=(MethodPropertyGetSet&& rhs) noexcept = delete;

        TCRE_DECLARE_TEMPLATE_PARAM_AS_FRIEND(ContainerType);

    public:
        NODISCARD operator GetReferenceType() const noexcept;
        MethodPropertyGetSet& operator=(SetReferenceType value) noexcept;

    private:
        ValueType m_Value;
    };
}

#endif  // CORE_TOOLS_PROPERTIES_METHOD_PROPERTY_GET_SET_H