//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/26 13:13)

#ifndef CORE_TOOLS_PROPERTIES_PROPERTY_GET_SET_EXTERNAL_H
#define CORE_TOOLS_PROPERTIES_PROPERTY_GET_SET_EXTERNAL_H

#include "CoreTools/CoreToolsDll.h"

#include <boost/noncopyable.hpp>
#include <type_traits>

namespace CoreTools
{
    template <typename T, typename GetReference, GetReference (T::*FG)(void) const,
              typename SetReference, void (T::*FS)(SetReference)>
    class PropertyGetSetExternal final : private boost::noncopyable
    {
    public:
        static_assert(std::is_const_v<std::remove_reference_t<GetReference>>, "GetReference is not const.");
        static_assert(std::is_reference_v<GetReference>, "GetReference is not reference.");
        static_assert(std::is_reference_v<SetReference>, "Reference is not reference.");

        using GetReferenceType = GetReference;
        using SetReferenceType = SetReference;
        using ClassType = PropertyGetSetExternal<T, GetReferenceType, FG, SetReferenceType, FS>;

    public:
        explicit PropertyGetSetExternal(T& object);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] operator GetReferenceType() const;
        PropertyGetSetExternal& operator=(SetReferenceType value);

    private:
        T& m_Object;
    };
}

#endif  // CORE_TOOLS_PROPERTIES_PROPERTY_GET_SET_EXTERNAL_H