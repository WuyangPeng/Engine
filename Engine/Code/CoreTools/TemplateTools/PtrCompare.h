//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.0 (2020/10/23 15:28)

#ifndef CORE_TOOLS_TEMPLATE_TOOLS_PTR_COMPARE_H
#define CORE_TOOLS_TEMPLATE_TOOLS_PTR_COMPARE_H

#include "CoreTools/CoreToolsDll.h"

namespace CoreTools
{
    // ��������һ��STL������бȽ϶����ֵ��������ָ���ֵ��
    template <class T>
    class PtrLess
    {
    public:
        [[nodiscard]] bool operator()(T left, T right)
        {
            return ((*left) < (*right));
        }
    };

    template <class T>
    class PtrGreater
    {
    public:
        bool operator()(T left, T right)
        {
            return ((*right) < (*left));
        }
    };
}

#endif  // CORE_TOOLS_TEMPLATE_TOOLS_PTR_COMPARE_H
