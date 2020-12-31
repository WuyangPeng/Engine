//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/26 13:10)

#ifndef CORE_TOOLS_PROPERTIES_METHOD_PROPERTY_GET_H
#define CORE_TOOLS_PROPERTIES_METHOD_PROPERTY_GET_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/PropertiesMacro.h"

#include <boost/noncopyable.hpp>

// 使用宏TCRE_METHOD_PROPERTY_GET定义属性
namespace CoreTools
{
    template <typename Value,  // 实际属性值类型
              typename ConstReference,  // 引用类型
              typename Container,  // 封闭类
              ptrdiff_t (*FO)(),  // 指针函数提供容器内偏移属性
              ConstReference (Container::*FG)() const>  // 指向返回R的const成员函数的指针
    class MethodPropertyGet final : private boost::noncopyable
    {
    public:
        using ValueType = Value;
        using ConstReferenceType = ConstReference;
        using ContainerType = Container;
        using ClassType = MethodPropertyGet<ValueType, ConstReferenceType, ContainerType, FO, FG>;

        CLASS_INVARIANT_DECLARE;

    private:
        MethodPropertyGet();
        explicit MethodPropertyGet(ConstReferenceType value);

        TCRE_DECLARE_TEMPLATE_PARAM_AS_FRIEND(ContainerType);

    public:
        [[nodiscard]] operator ConstReferenceType() const;

    private:
        ValueType m_Value;
    };
}

#endif  // CORE_TOOLS_PROPERTIES_METHOD_PROPERTY_GET_H