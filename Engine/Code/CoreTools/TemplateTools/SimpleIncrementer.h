///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/09/20 14:48)

#ifndef CORE_TOOLS_TEMPLATE_TOOLS_SIMPLE_INCREMENTER_H
#define CORE_TOOLS_TEMPLATE_TOOLS_SIMPLE_INCREMENTER_H

#include "CoreTools/CoreToolsDll.h"

namespace CoreTools
{
    template <typename T>
    class SimpleIncrementer final
    {
    public:
        using ClassType = SimpleIncrementer<T>;

        CLASS_INVARIANT_DECLARE;

    public:
        void operator()(T& value) noexcept;
    };
}

#endif  //  CORE_TOOLS_TEMPLATE_TOOLS_SIMPLE_INCREMENTER_H
