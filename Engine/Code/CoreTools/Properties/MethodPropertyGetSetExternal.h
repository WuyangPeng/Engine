/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 10:14)

#ifndef CORE_TOOLS_PROPERTIES_METHOD_PROPERTY_GET_SET_EXTERNAL_H
#define CORE_TOOLS_PROPERTIES_METHOD_PROPERTY_GET_SET_EXTERNAL_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/PropertiesMacro.h"

namespace CoreTools
{
    // 此类提供间接方法的读/写属性访问

    // 容器类定义get和set方法。 它还定义了一个静态方法，其中包含给定属性在容器内的偏移量。
    // 然后使用设置引用类型，获取引用类型，容器类型，成员函数和偏移函数对模板进行参数化。

    template <typename GetReference,
              typename SetReference,
              typename Container,
              ptrdiff_t (*FunctionOffset)(),
              GetReference (Container::*FunctionGet)() const,
              void (Container::*FunctionSet)(SetReference)>
    class MethodPropertyGetSetExternal final
    {
    public:
        using GetReferenceType = GetReference;
        using SetReferenceType = SetReference;
        using ContainerType = Container;
        using ClassType = MethodPropertyGetSetExternal<GetReferenceType, SetReferenceType, ContainerType, FunctionOffset, FunctionGet, FunctionSet>;

        MethodPropertyGetSetExternal() noexcept = default;
        ~MethodPropertyGetSetExternal() noexcept = default;
        MethodPropertyGetSetExternal(const MethodPropertyGetSetExternal& rhs) noexcept = delete;
        MethodPropertyGetSetExternal& operator=(const MethodPropertyGetSetExternal& rhs) noexcept = delete;
        MethodPropertyGetSetExternal(MethodPropertyGetSetExternal&& rhs) noexcept = delete;
        MethodPropertyGetSetExternal& operator=(MethodPropertyGetSetExternal&& rhs) noexcept = delete;

    public:
        CLASS_INVARIANT_DECLARE;

        // 提供对该属性的只读访问
        NODISCARD operator GetReferenceType() const noexcept;

        // 提供对该属性的只写访问
        MethodPropertyGetSetExternal& operator=(SetReferenceType value) noexcept;
    };
}

#endif  // CORE_TOOLS_PROPERTIES_METHOD_PROPERTY_GET_SET_EXTERNAL_H