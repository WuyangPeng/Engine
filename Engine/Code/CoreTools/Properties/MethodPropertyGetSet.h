//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.0 (2020/10/26 13:11)

#ifndef CORE_TOOLS_PROPERTIES_METHOD_PROPERTY_GET_SET_H
#define CORE_TOOLS_PROPERTIES_METHOD_PROPERTY_GET_SET_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/PropertiesMacro.h"

#include <boost/noncopyable.hpp>

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
    class MethodPropertyGetSet final : private boost::noncopyable
    {
    public:
        using ValueType = Value;
        using GetReferenceType = GetReference;
        using SetReferenceType = SetReference;
        using ContainerType = Container;
        using ClassType = MethodPropertyGetSet<ValueType, GetReferenceType, SetReferenceType, ContainerType, FO, FG, FS>;

        CLASS_INVARIANT_DECLARE;

    private:
        MethodPropertyGetSet();
        explicit MethodPropertyGetSet(SetReferenceType value);

        TCRE_DECLARE_TEMPLATE_PARAM_AS_FRIEND(ContainerType);

    public:
        [[nodiscard]] operator GetReferenceType() const;
        MethodPropertyGetSet& operator=(SetReferenceType value);

    private:
        ValueType m_Value;
    };
}

#endif  // CORE_TOOLS_PROPERTIES_METHOD_PROPERTY_GET_SET_H