//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/26 13:12)

#ifndef CORE_TOOLS_PROPERTIES_METHOD_PROPERTY_SET_EXTERNAL_H
#define CORE_TOOLS_PROPERTIES_METHOD_PROPERTY_SET_EXTERNAL_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/PropertiesMacro.h"

namespace CoreTools
{
    // 此类提供间接的基于方法的只写属性访问
    // 容器类定义了一个set方法。 它还定义了一个静态方法，它包含给定属性在容器内的偏移量。
    // 然后使用引用类型，容器类型，成员函数和偏移函数对模板进行参数化。

    template <typename Reference,  // 引用类型
              typename Container,  // 封闭类
              ptrdiff_t (*FO)(),  // 指针函数提供容器内偏移属性
              void (Container::*FS)(Reference)>  // 指针到一个成员函数设置R
    class MethodPropertySetExternal final
    {
    public:
        using ReferenceType = Reference;
        using ContainerType = Container;
        using ClassType = MethodPropertySetExternal<ReferenceType, ContainerType, FO, FS>;

    public:
        CLASS_INVARIANT_DECLARE;

        // 提供对该属性的只写访问
        MethodPropertySetExternal& operator=(ReferenceType value);
    };
}

#endif  // CORE_TOOLS_PROPERTIES_METHOD_PROPERTY_SET_EXTERNAL_H