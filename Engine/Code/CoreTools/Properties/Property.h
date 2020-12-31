//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/26 13:12)

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
        Property();
        explicit Property(V value);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        Property& operator=(R value);
        [[nodiscard]] operator R() const;

    public:
        V m_Value;
    };
}

#endif  // CORE_TOOLS_PROPERTIES_PROPERTY_H