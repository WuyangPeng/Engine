/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/12 14:13)

#ifndef CORE_TOOLS_TEMPLATE_TOOLS_PTR_COMPARE_H
#define CORE_TOOLS_TEMPLATE_TOOLS_PTR_COMPARE_H

#include "CoreTools/CoreToolsDll.h"

namespace CoreTools
{
    /// 该类允许一个STL对象进行比较对象的值，而不是指针的值。
    template <class T>
    class PtrLess
    {
    public:
        NODISCARD bool operator()(T left, T right) const noexcept
        {
            return ((*left) < (*right));
        }
    };

    template <class T>
    class PtrGreater
    {
    public:
        NODISCARD bool operator()(T left, T right) const noexcept
        {
            return ((*right) < (*left));
        }
    };
}

#endif  // CORE_TOOLS_TEMPLATE_TOOLS_PTR_COMPARE_H
