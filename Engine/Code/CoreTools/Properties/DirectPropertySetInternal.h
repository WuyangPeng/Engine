/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/12 15:06)

#ifndef CORE_TOOLS_PROPERTIES_DIRECT_PROPERTY_SET_INTERNAL_H
#define CORE_TOOLS_PROPERTIES_DIRECT_PROPERTY_SET_INTERNAL_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/PropertiesMacro.h"

namespace CoreTools
{
    template <typename Value,  /// 实际属性值类型
              typename Reference,  /// 引用类型
              typename Container>  /// 封闭类
    class DirectPropertySetInternal final
    {
    public:
        using ValueType = Value;
        using ReferenceType = Reference;
        using ContainerType = Container;
        using ClassType = DirectPropertySetInternal<ValueType, ReferenceType, ContainerType>;

        CLASS_INVARIANT_DECLARE;

    private:
        explicit DirectPropertySetInternal(ReferenceType value);

    public:
        ~DirectPropertySetInternal() noexcept = default;
        DirectPropertySetInternal(const DirectPropertySetInternal& rhs) noexcept = delete;
        DirectPropertySetInternal& operator=(const DirectPropertySetInternal& rhs) noexcept = delete;
        DirectPropertySetInternal(DirectPropertySetInternal&& rhs) noexcept = delete;
        DirectPropertySetInternal& operator=(DirectPropertySetInternal&& rhs) noexcept = delete;

    private:
        NODISCARD operator ReferenceType() const;

        TCRE_DECLARE_TEMPLATE_PARAM_AS_FRIEND(ContainerType);

    public:
        DirectPropertySetInternal& operator=(ReferenceType aValue);

    private:
        ValueType value;
    };
}

#endif  // CORE_TOOLS_PROPERTIES_DIRECT_PROPERTY_SET_INTERNAL_H