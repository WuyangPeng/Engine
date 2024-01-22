/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 10:16)

#ifndef CORE_TOOLS_PROPERTIES_STATIC_PROPERTY_GET_EXTERNAL_H
#define CORE_TOOLS_PROPERTIES_STATIC_PROPERTY_GET_EXTERNAL_H

#include "CoreTools/CoreToolsDll.h"

#include <type_traits>

namespace CoreTools
{
    template <typename ConstReference, ConstReference (*PropertyFunction)()>
    class StaticPropertyGetExternal final
    {
    public:
        static_assert(std::is_const_v<std::remove_reference_t<ConstReference>>, "ConstReference is not const.");
        static_assert(std::is_reference_v<ConstReference>, "ConstReference is not reference.");

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