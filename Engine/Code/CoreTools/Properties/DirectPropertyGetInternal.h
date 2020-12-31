//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.0 (2020/10/26 13:05)

#ifndef CORE_TOOLS_PROPERTIES_DIRECT_PROPERTY_GET_INTERNAL_H
#define CORE_TOOLS_PROPERTIES_DIRECT_PROPERTY_GET_INTERNAL_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/PropertiesMacro.h"

#include <boost/noncopyable.hpp>

// ʹ�÷�ʽ��
// ��ͨ����Ԫʵ�ֶ����Ե�ֻ�����ʡ�
// ��һ���࣬�������£�
// class PropTester {
// public: CoreTools::DirectPropertyGetInternal<int, int, PropTester> Prop;
// �����Ҫ�ṩ�޸�ֵ�Ľӿڣ�
// public: void SetPropValue(int i)	{ Prop.m_Value = i;	}
// };

// ʹ�÷�ʽ���£�
// PropTester tester;
// ֻ�����ʣ�
// int i = tester.Prop;
// ����ֵ��
// tester.SetPropValue(100);

namespace CoreTools
{
    template <typename Value,  // ʵ������ֵ����
              typename Reference,  // ��������
              typename Container>  // �����
    class DirectPropertyGetInternal final : private boost::noncopyable
    {
    public:
        using ValueType = Value;
        using ReferenceType = Reference;
        using ContainerType = Container;
        using ClassType = DirectPropertyGetInternal<ValueType, ReferenceType, ContainerType>;

        CLASS_INVARIANT_DECLARE;

#if defined(TCRE_USE_DIGITAL_MARS)
    public:
#else  // TCRE_USE_DIGITAL_MARS
    private:
#endif  // TCRE_USE_DIGITAL_MARS
        DirectPropertyGetInternal();

    private:
        explicit DirectPropertyGetInternal(ReferenceType value);
        ClassType& operator=(ReferenceType value);

        TCRE_DECLARE_TEMPLATE_PARAM_AS_FRIEND(ContainerType);

    public:
        // �ṩ�Ը����Ե�ֻ������
        [[nodiscard]] operator ReferenceType() const;

    private:
        ValueType m_Value;
    };
}

#endif  // CORE_TOOLS_PROPERTIES_DIRECT_PROPERTY_GET_INTERNAL_H