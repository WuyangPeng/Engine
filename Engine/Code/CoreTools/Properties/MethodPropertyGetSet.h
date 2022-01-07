///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/23 11:48)

#ifndef CORE_TOOLS_PROPERTIES_METHOD_PROPERTY_GET_SET_H
#define CORE_TOOLS_PROPERTIES_METHOD_PROPERTY_GET_SET_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/PropertiesMacro.h"

// 使用宏TCRE_METHOD_PROPERTY_GETSET定义属性
namespace CoreTools
{
    // 此类提供基于方法的读/写属性访问

    // 容器类定义get和set方法。 它还定义了一个静态方法，它包含给定属性在容器内的偏移量。
    // 然后使用值类型，设置引用类型，获取引用类型，容器类型，成员函数和偏移函数对模板进行参数化。

    template <typename Value,  // 实际属性值类型
              typename GetReference,  // 获取引用类型
              typename SetReference,  // 设置引用类型
              typename Container,  // 封闭类
              ptrdiff_t (*FO)(),  // 指针函数提供容器内偏移属性
              GetReference (Container::*FG)() const,  // 指向返回R的const成员函数的指针
              void (Container::*FS)(SetReference)>  // 指向R的成员函数的指针
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