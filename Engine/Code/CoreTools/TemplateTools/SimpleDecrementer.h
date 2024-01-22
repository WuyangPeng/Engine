/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 10:24)

#ifndef CORE_TOOLS_TEMPLATE_TOOLS_SIMPLE_DECREMENTER_H
#define CORE_TOOLS_TEMPLATE_TOOLS_SIMPLE_DECREMENTER_H

#include "CoreTools/CoreToolsDll.h"

namespace CoreTools
{
    template <typename T>
    class SimpleDecrementer final
    {
    public:
        using ClassType = SimpleDecrementer<T>;

        CLASS_INVARIANT_DECLARE;

    public:
        void operator()(T& value) noexcept;
    };
}

#endif  //  CORE_TOOLS_TEMPLATE_TOOLS_SIMPLE_DECREMENTER_H
