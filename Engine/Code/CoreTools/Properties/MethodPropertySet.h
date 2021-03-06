//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/26 13:12)

#ifndef CORE_TOOLS_PROPERTIES_METHOD_PROPERTY_SET_H
#define CORE_TOOLS_PROPERTIES_METHOD_PROPERTY_SET_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/PropertiesMacro.h"

#include <boost/noncopyable.hpp>

// 使用宏TCRE_METHOD_PROPERTY_SET定义属性
namespace CoreTools
{
    // 此类提供基于方法的只写属性访问

    // contains类定义了一个set方法。 它还定义了一个静态方法，它包含给定属性在容器内的偏移量。
    // 然后，使用值类型，引用类型，容器类型，成员函数和偏移函数对模板进行参数化。
    template <typename Value,  // 实际属性值类型
              typename Reference,  // 引用类型
              typename Container,  // 封闭类
              ptrdiff_t (*FO)(),  // 指针函数提供容器内偏移属性
              void (Container::*FS)(Reference)>  // 指向返回R的成员函数的指针
    class MethodPropertySet final : private boost::noncopyable
    {
    public:
        using ValueType = Value;
        using ReferenceType = Reference;
        using ContainerType = Container;
        using ClassType = MethodPropertySet<ValueType, ReferenceType, ContainerType, FO, FS>;

        CLASS_INVARIANT_DECLARE;

    private:
        MethodPropertySet();
        explicit MethodPropertySet(ReferenceType value);

        TCRE_DECLARE_TEMPLATE_PARAM_AS_FRIEND(ContainerType);

    public:
        MethodPropertySet& operator=(ReferenceType value);

    private:
        ValueType m_Value;
    };
}

#endif  // CORE_TOOLS_PROPERTIES_METHOD_PROPERTY_SET_H