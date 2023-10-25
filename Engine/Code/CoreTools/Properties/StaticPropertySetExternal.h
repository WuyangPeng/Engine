///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/20 15:05)

#ifndef CORE_TOOLS_PROPERTIES_STATIC_PROPERTY_SET_EXTERNAL_H
#define CORE_TOOLS_PROPERTIES_STATIC_PROPERTY_SET_EXTERNAL_H

#include "CoreTools/CoreToolsDll.h"

#include <type_traits>

namespace CoreTools
{
    template <typename Reference, void (*PropertyFunction)(Reference)>
    class StaticPropertySetExternal final
    {
    public:
        static_assert(std::is_reference_v<Reference>, "Reference is not reference.");

        using ReferenceType = Reference;
        using ClassType = StaticPropertySetExternal<ReferenceType, PropertyFunction>;

    public:
        CLASS_INVARIANT_DECLARE;

        StaticPropertySetExternal& operator=(ReferenceType value);
    };
}

#endif  // CORE_TOOLS_PROPERTIES_STATIC_PROPERTY_SET_EXTERNAL_H