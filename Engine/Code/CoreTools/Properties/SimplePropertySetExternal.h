///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/03/31 14:54)

#ifndef CORE_TOOLS_PROPERTIES_SIMPLE_PROPERTY_SET_EXTERNAL_H
#define CORE_TOOLS_PROPERTIES_SIMPLE_PROPERTY_SET_EXTERNAL_H

#include "CoreTools/CoreToolsDll.h"

namespace CoreTools
{
    template <typename Value, typename Reference>
    class SimplePropertySetExternal final
    {
    public:
        static_assert(std::is_reference_v<Reference>, "Reference is not reference.");

        using ValueType = Value;
        using ReferenceType = Reference;
        using ClassType = SimplePropertySetExternal<ValueType, ReferenceType>;

    public:
        explicit SimplePropertySetExternal(ValueType& value) noexcept;

        ~SimplePropertySetExternal() noexcept = default;
        SimplePropertySetExternal(const SimplePropertySetExternal& rhs) noexcept = delete;
        SimplePropertySetExternal& operator=(const SimplePropertySetExternal& rhs) noexcept = delete;
        SimplePropertySetExternal(SimplePropertySetExternal&& rhs) noexcept = delete;
        SimplePropertySetExternal& operator=(SimplePropertySetExternal&& rhs) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

        SimplePropertySetExternal& operator=(ReferenceType aValue);

    private:
        ValueType& value;
    };
}

#endif  // CORE_TOOLS_PROPERTIES_SIMPLE_PROPERTY_SET_EXTERNAL_H