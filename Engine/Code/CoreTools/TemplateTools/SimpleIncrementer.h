///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/21 15:28)

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
