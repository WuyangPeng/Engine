///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.5 (2023/03/31 16:22)

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
