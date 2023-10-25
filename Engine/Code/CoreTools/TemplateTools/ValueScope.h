///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/20 14:49)

#ifndef CORE_TOOLS_TEMPLATE_TOOLS_VALUE_SCOPE_H
#define CORE_TOOLS_TEMPLATE_TOOLS_VALUE_SCOPE_H

#include "CoreTools/CoreToolsDll.h"

namespace CoreTools
{
    template <typename T>
    class ValueScope final
    {
    public:
        using ValueType = T;
        using ClassType = ValueScope<T>;
        using Reference = ValueType&;

    public:
        template <typename V>
        ValueScope(Reference value, V const& set) noexcept(std::is_arithmetic_v<T>);

        template <typename V1, typename V2>
        ValueScope(Reference value, V1 const& set, V2 const& revert) noexcept(std::is_arithmetic_v<T>);

        ~ValueScope() noexcept;

        ValueScope(const ValueScope&) noexcept = delete;
        ValueScope& operator=(const ValueScope&) noexcept = delete;
        ValueScope(ValueScope&&) noexcept = delete;
        ValueScope& operator=(ValueScope&&) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

    private:
        Reference value;
        ValueType revert;
    };
}

#endif  //  CORE_TOOLS_TEMPLATE_TOOLS_VALUE_SCOPE_H
