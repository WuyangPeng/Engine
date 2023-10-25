///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/09/20 15:06)

#ifndef CORE_TOOLS_PROPERTIES_PROPERTY_GET_EXTERNAL_H
#define CORE_TOOLS_PROPERTIES_PROPERTY_GET_EXTERNAL_H

#include "CoreTools/CoreToolsDll.h"

#include <type_traits>

namespace CoreTools
{
    template <typename T, typename ConstReference, ConstReference (T::*PropertyFunction)() const>
    class PropertyGetExternal final
    {
    public:
        static_assert(std::is_const_v<std::remove_reference_t<ConstReference>>, "ConstReference is not const.");
        static_assert(std::is_reference_v<ConstReference>, "ConstReference is not reference.");

        using ConstReferenceType = ConstReference;
        using ClassType = PropertyGetExternal<T, ConstReferenceType, PropertyFunction>;

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
        const T& object;
    };
}

#endif  // CORE_TOOLS_PROPERTIES_PROPERTY_GET_EXTERNAL_H