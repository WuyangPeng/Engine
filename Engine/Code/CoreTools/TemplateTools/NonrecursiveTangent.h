//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.0 (2020/10/23 15:27)

#ifndef CORE_TOOLS_TEMPLATE_TOOLS_NONRECURSIVE_TANGENT_H
#define CORE_TOOLS_TEMPLATE_TOOLS_NONRECURSIVE_TANGENT_H

#include "CoreTools/CoreToolsDll.h"

#include "NonrecursiveCosine.h"
#include "NonrecursiveSine.h"

namespace CoreTools
{
    template <double& Radian>
    struct NonrecursiveTangent
    {
        static double Tan()
        {
            return NonrecursiveSine<Radian>::Sin() / NonrecursiveCosine<Radian>::Cos();
        }
    };
}

#define NONRECURSIVE_TANGENT(r) CoreTools::NonrecursiveTangent<r>::Tan()

#endif  // CORE_TOOLS_TEMPLATE_TOOLS_NONRECURSIVE_TANGENT_H
