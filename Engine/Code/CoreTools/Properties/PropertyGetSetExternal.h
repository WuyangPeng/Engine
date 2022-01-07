///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/23 18:02)

#ifndef CORE_TOOLS_PROPERTIES_PROPERTY_GET_SET_EXTERNAL_H
#define CORE_TOOLS_PROPERTIES_PROPERTY_GET_SET_EXTERNAL_H

#include "CoreTools/CoreToolsDll.h"

#include <type_traits>

namespace CoreTools
{
    template <typename T,
              typename GetReference,
              GetReference (T::*FG)(void) const,
              typename SetReference,
              void (T::*FS)(SetReference)>
    class PropertyGetSetExternal final
    {
    public:
        static_assert(std::is_const_v<std::remove_reference_t<GetReference>>, "GetReference is not const.");
        static_assert(std::is_reference_v<GetReference>, "GetReference is not reference.");
        static_assert(std::is_reference_v<SetReference>, "Reference is not reference.");

        using GetReferenceType = GetReference;
        using SetReferenceType = SetReference;
        using ClassType = PropertyGetSetExternal<T, GetReferenceType, FG, SetReferenceType, FS>;

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
        T& m_Object;
    };
}

#endif  // CORE_TOOLS_PROPERTIES_PROPERTY_GET_SET_EXTERNAL_H