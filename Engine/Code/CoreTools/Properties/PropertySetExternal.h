///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/23 18:02)

#ifndef CORE_TOOLS_PROPERTIES_PROPERTY_SET_EXTERNAL_H
#define CORE_TOOLS_PROPERTIES_PROPERTY_SET_EXTERNAL_H

#include "CoreTools/CoreToolsDll.h"

#include <type_traits>

namespace CoreTools
{
    template <typename T, typename Reference, void (T::*PF)(Reference)>
    class PropertySetExternal final
    {
    public:
        static_assert(std::is_reference_v<Reference>, "Reference is not reference.");

        using ReferenceType = Reference;
        using ClassType = PropertySetExternal<T, ReferenceType, PF>;

    public:
        explicit PropertySetExternal(T& object) noexcept;

        ~PropertySetExternal() noexcept = default;
        PropertySetExternal(const PropertySetExternal& rhs) noexcept = delete;
        PropertySetExternal& operator=(const PropertySetExternal& rhs) noexcept = delete;
        PropertySetExternal(PropertySetExternal&& rhs) noexcept = delete;
        PropertySetExternal& operator=(PropertySetExternal&& rhs) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

        PropertySetExternal& operator=(ReferenceType value) noexcept;

    private:
        T& m_Object;
    };
}

#endif  // CORE_TOOLS_PROPERTIES_PROPERTY_SET_EXTERNAL_H