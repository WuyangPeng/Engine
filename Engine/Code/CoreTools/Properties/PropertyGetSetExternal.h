///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/20 15:05)

#ifndef CORE_TOOLS_PROPERTIES_PROPERTY_GET_SET_EXTERNAL_H
#define CORE_TOOLS_PROPERTIES_PROPERTY_GET_SET_EXTERNAL_H

#include "CoreTools/CoreToolsDll.h"

#include <type_traits>

namespace CoreTools
{
    template <typename T,
              typename GetReference,
              GetReference (T::*PropertyGet)() const,
              typename SetReference,
              void (T::*PropertySet)(SetReference)>
    class PropertyGetSetExternal final
    {
    public:
        static_assert(std::is_const_v<std::remove_reference_t<GetReference>>, "GetReference is not const.");
        static_assert(std::is_reference_v<GetReference>, "GetReference is not reference.");
        static_assert(std::is_reference_v<SetReference>, "Reference is not reference.");

        using GetReferenceType = GetReference;
        using SetReferenceType = SetReference;
        using ClassType = PropertyGetSetExternal<T, GetReferenceType, PropertyGet, SetReferenceType, PropertySet>;

    public:
        explicit PropertyGetSetExternal(T& object) noexcept;

        ~PropertyGetSetExternal() noexcept = default;
        PropertyGetSetExternal(const PropertyGetSetExternal& rhs) noexcept = delete;
        PropertyGetSetExternal& operator=(const PropertyGetSetExternal& rhs) noexcept = delete;
        PropertyGetSetExternal(PropertyGetSetExternal&& rhs) noexcept = delete;
        PropertyGetSetExternal& operator=(PropertyGetSetExternal&& rhs) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

        NODISCARD operator GetReferenceType() const noexcept;
        PropertyGetSetExternal& operator=(SetReferenceType value) noexcept;

    private:
        T& object;
    };
}

#endif  // CORE_TOOLS_PROPERTIES_PROPERTY_GET_SET_EXTERNAL_H