//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/26 13:14)

#ifndef CORE_TOOLS_PROPERTIES_PROPERTY_SET_EXTERNAL_H
#define CORE_TOOLS_PROPERTIES_PROPERTY_SET_EXTERNAL_H

#include "CoreTools/CoreToolsDll.h"

#include <boost/noncopyable.hpp>
#include <type_traits>

namespace CoreTools
{
    template <typename T, typename Reference, void (T::*PF)(Reference)>
    class PropertySetExternal final : private boost::noncopyable
    {
    public:
        static_assert(std::is_reference_v<Reference>, "Reference is not reference.");

        using ReferenceType = Reference;
        using ClassType = PropertySetExternal<T, ReferenceType, PF>;

    public:
        explicit PropertySetExternal(T& object);

        CLASS_INVARIANT_DECLARE;

        PropertySetExternal& operator=(ReferenceType value);

    private:
        T& m_Object;
    };
}

#endif  // CORE_TOOLS_PROPERTIES_PROPERTY_SET_EXTERNAL_H