//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/26 13:05)

#ifndef CORE_TOOLS_PROPERTIES_DIRECT_PROPERTY_GET_INTERNAL_H
#define CORE_TOOLS_PROPERTIES_DIRECT_PROPERTY_GET_INTERNAL_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/PropertiesMacro.h"

#include <boost/noncopyable.hpp>

// 使用方式：
// 类通过友元实现对属性的只读访问。
// 如一个类，定义如下：
// class PropTester {
// public: CoreTools::DirectPropertyGetInternal<int, int, PropTester> Prop;
// 如果需要提供修改值的接口：
// public: void SetPropValue(int i)	{ Prop.m_Value = i;	}
// };

// 使用方式如下：
// PropTester tester;
// 只读访问：
// int i = tester.Prop;
// 设置值：
// tester.SetPropValue(100);

namespace CoreTools
{
    template <typename Value,  // 实际属性值类型
              typename Reference,  // 引用类型
              typename Container>  // 封闭类
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
        // 提供对该属性的只读访问
        [[nodiscard]] operator ReferenceType() const;

    private:
        ValueType m_Value;
    };
}

#endif  // CORE_TOOLS_PROPERTIES_DIRECT_PROPERTY_GET_INTERNAL_H