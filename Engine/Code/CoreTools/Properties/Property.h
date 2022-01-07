///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/23 17:26)

#ifndef CORE_TOOLS_PROPERTIES_PROPERTY_H
#define CORE_TOOLS_PROPERTIES_PROPERTY_H

#include "CoreTools/CoreToolsDll.h"

#include "PropertyBase.h"

namespace CoreTools
{
    // 需要通过宏TCRE_DECLARE_PROPERTY来声明属性
    template <typename ID, typename T, typename V, typename R, void (T::*FS)(R), R (T::*FG)() const>
    class Property : PropertyBase<ID, T>
    {
    public:
        using ParentType = PropertyBase<ID, T>;
        using ClassType = Property<ID, T, V, R, FS, FG>;

    public:
        Property() noexcept;
        explicit Property(V value);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        Property& operator=(R value) noexcept;
        NODISCARD operator R() const noexcept;

    public:
        V m_Value;
    };
}

#endif  // CORE_TOOLS_PROPERTIES_PROPERTY_H