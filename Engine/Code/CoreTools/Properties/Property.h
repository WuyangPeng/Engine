///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/20 15:06)

#ifndef CORE_TOOLS_PROPERTIES_PROPERTY_H
#define CORE_TOOLS_PROPERTIES_PROPERTY_H

#include "CoreTools/CoreToolsDll.h"

#include "PropertyBase.h"

namespace CoreTools
{
    // 需要通过宏TCRE_DECLARE_PROPERTY来声明属性
    template <typename Id, typename T, typename V, typename R, void (T::*FunctionSet)(R), R (T::*FunctionGet)() const>
    class Property final : PropertyBase<Id, T>
    {
    public:
        using ParentType = PropertyBase<Id, T>;
        using ClassType = Property<Id, T, V, R, FunctionSet, FunctionGet>;

    public:
        Property() noexcept;
        explicit Property(V value);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        Property& operator=(R aValue) noexcept;
        NODISCARD operator R() const noexcept;

    public:
        V value;
    };
}

#endif  // CORE_TOOLS_PROPERTIES_PROPERTY_H