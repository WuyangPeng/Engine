///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/21 15:23)

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
        NODISCARD bool operator()(T left, T right) noexcept
        {
            return ((*left) < (*right));
        }
    };

    template <class T>
    class PtrGreater
    {
    public:
        NODISCARD bool operator()(T left, T right) noexcept
        {
            return ((*right) < (*left));
        }
    };
}

#endif  // CORE_TOOLS_TEMPLATE_TOOLS_PTR_COMPARE_H
