///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/21 15:23)

#ifndef CORE_TOOLS_TEMPLATE_TOOLS_POW3_H
#define CORE_TOOLS_TEMPLATE_TOOLS_POW3_H

#include "CoreTools/CoreToolsDll.h"

#include "IfThenElse.h"

namespace CoreTools
{
    // ��ģ�����3 �� Nth
    template <int N>
    class Pow3
    {
    public:
        enum
        {
            Result = 3 * Pow3<N - 1>::Result
        };
    };

    // �������ػ������ݹ�
    template <>
    class Pow3<0>
    {
    public:
        enum
        {
            Result = 1
        };
    };
}

#endif  //  CORE_TOOLS_TEMPLATE_TOOLS_POW3_H
