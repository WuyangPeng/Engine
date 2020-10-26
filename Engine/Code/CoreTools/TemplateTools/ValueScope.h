//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.0 (2020/10/23 15:30)

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
        ValueScope(Reference value, V const& set);

        template <typename V1, typename V2>
        ValueScope(Reference value, V1 const& set, V2 const& revert);

        ~ValueScope();

        ValueScope(const ValueScope&) = delete;
        ValueScope& operator=(const ValueScope&) = delete;
        ValueScope(ValueScope&&) = delete;
        ValueScope& operator=(ValueScope&&) = delete;

        CLASS_INVARIANT_DECLARE;

    private:
        Reference m_Value;
        ValueType m_Revert;
    };
}

#endif  //  CORE_TOOLS_TEMPLATE_TOOLS_VALUE_SCOPE_H
