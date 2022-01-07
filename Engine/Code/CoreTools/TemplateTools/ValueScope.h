///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/21 15:35)

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
