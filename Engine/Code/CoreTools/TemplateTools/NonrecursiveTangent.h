///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.5 (2023/03/31 16:18)

#ifndef CORE_TOOLS_TEMPLATE_TOOLS_NON_RECURSIVE_TANGENT_H
#define CORE_TOOLS_TEMPLATE_TOOLS_NON_RECURSIVE_TANGENT_H

#include "CoreTools/CoreToolsDll.h"

#include "NonRecursiveCosine.h"
#include "NonRecursiveSine.h"

namespace CoreTools
{
    struct NonRecursiveTangent
    {
        static constexpr double Tan(const double radian) noexcept
        {
            return NonRecursiveSine::Sin(radian) / NonRecursiveCosine::Cos(radian);
        }
    };
}

#define NON_RECURSIVE_TANGENT(r) CoreTools::NonRecursiveTangent::Tan(r)

#endif  // CORE_TOOLS_TEMPLATE_TOOLS_NON_RECURSIVE_TANGENT_H
