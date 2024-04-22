/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/12 15:05)

#ifndef CORE_TOOLS_PROPERTIES_METHOD_PROPERTY_GET_EXTERNAL_H
#define CORE_TOOLS_PROPERTIES_METHOD_PROPERTY_GET_EXTERNAL_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/PropertiesMacro.h"

namespace CoreTools
{
    /// 该类提供了基于方法的只读属性访问

    /// 容器类定义了一个get方法。
    /// 它还定义了一个静态方法，它包含给定属性在容器内的偏移量。
    /// 然后使用引用类型，容器类型，成员函数和偏移函数对模板进行参数化。
    template <typename ConstReference,  /// 引用类型
              typename Container,  /// 封闭类
              ptrdiff_t (*FunctionOffset)(),  /// 指针函数提供容器内偏移属性
              ConstReference (Container::*FunctionGet)() const>  /// 指针指向一个const成员函数返回CR
    class MethodPropertyGetExternal final
    {
    public:
        using ConstReferenceType = ConstReference;
        using ContainerType = Container;
        using ClassType = MethodPropertyGetExternal<ConstReferenceType, ContainerType, FunctionOffset, FunctionGet>;

        MethodPropertyGetExternal() noexcept = default;
        ~MethodPropertyGetExternal() noexcept = default;
        MethodPropertyGetExternal(const MethodPropertyGetExternal& rhs) noexcept = delete;
        MethodPropertyGetExternal& operator=(const MethodPropertyGetExternal& rhs) noexcept = delete;
        MethodPropertyGetExternal(MethodPropertyGetExternal&& rhs) noexcept = delete;
        MethodPropertyGetExternal& operator=(MethodPropertyGetExternal&& rhs) noexcept = delete;

    public:
        CLASS_INVARIANT_DECLARE;

        /// 提供对该属性的只读访问
        NODISCARD operator ConstReferenceType() const noexcept;

        /// 这种方法是隐藏的，以防止熟悉这个类的用户在包含的类中对属性实例使用operator=，
        /// 因为使用MethodPropertyGetSet<>会导致无限循环。
        MethodPropertyGetExternal& operator=(ConstReferenceType value) = delete;
    };
}

#endif  // CORE_TOOLS_PROPERTIES_METHOD_PROPERTY_GET_EXTERNAL_H