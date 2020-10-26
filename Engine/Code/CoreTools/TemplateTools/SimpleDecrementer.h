//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/23 15:29)

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
        void operator()(T& value);
    };
}

#endif  //  CORE_TOOLS_TEMPLATE_TOOLS_SIMPLE_DECREMENTER_H
