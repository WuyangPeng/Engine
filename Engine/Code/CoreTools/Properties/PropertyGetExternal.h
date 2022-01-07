///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/23 17:59)

#ifndef CORE_TOOLS_PROPERTIES_PROPERTY_GET_EXTERNAL_H
#define CORE_TOOLS_PROPERTIES_PROPERTY_GET_EXTERNAL_H

#include "CoreTools/CoreToolsDll.h"

#include <type_traits>

namespace CoreTools
{
    template <typename T, typename ConstReference, ConstReference (T::*PF)() const>
    class PropertyGetExternal final
    {
    public:
        static_assert(std::is_const_v<std::remove_reference_t<ConstReference>>, "ConstReference is not const.");
        static_assert(std::is_reference_v<ConstReference>, "ConstReference is not reference.");

        using ConstReferenceType = ConstReference;
        using ClassType = PropertyGetExternal<T, ConstReferenceType, PF>;

    public:
        explicit PropertyGetExternal(const T& object) noexcept;

        ~PropertyGetExternal() noexcept = default;
        PropertyGetExternal(const PropertyGetExternal& rhs) = delete;
        PropertyGetExternal& operator=(const PropertyGetExternal& rhs) = delete;
        PropertyGetExternal(PropertyGetExternal&& rhs) noexcept = delete;
        PropertyGetExternal& operator=(PropertyGetExternal&& rhs) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

        NODISCARD operator ConstReferenceType() const noexcept;

    private:
        const T& m_Object;
    };
}

#endif  // CORE_TOOLS_PROPERTIES_PROPERTY_GET_EXTERNAL_H