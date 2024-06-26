/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/12 14:56)

#ifndef CORE_TOOLS_PROPERTIES_STATIC_PROPERTY_GET_EXTERNAL_H
#define CORE_TOOLS_PROPERTIES_STATIC_PROPERTY_GET_EXTERNAL_H

#include "CoreTools/CoreToolsDll.h"

#include <type_traits>

namespace CoreTools
{
    template <typename ConstReference, ConstReference (*PropertyFunction)()>
    requires(std::is_const_v<std::remove_reference_t<ConstReference>> && std::is_reference_v<ConstReference>)
    class StaticPropertyGetExternal final
    {
    public:
        using ConstReferenceType = ConstReference;
        using ClassType = StaticPropertyGetExternal<ConstReferenceType, PropertyFunction>;

    public:
        StaticPropertyGetExternal() noexcept = default;
        ~StaticPropertyGetExternal() noexcept = default;
        StaticPropertyGetExternal(const StaticPropertyGetExternal& rhs) noexcept = delete;
        StaticPropertyGetExternal& operator=(const StaticPropertyGetExternal& rhs) noexcept = delete;
        StaticPropertyGetExternal(StaticPropertyGetExternal&& rhs) noexcept = delete;
        StaticPropertyGetExternal& operator=(StaticPropertyGetExternal&& rhs) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

        NODISCARD operator ConstReferenceType() const noexcept;
    };
}

#endif  // CORE_TOOLS_PROPERTIES_STATIC_PROPERTY_GET_EXTERNAL_H