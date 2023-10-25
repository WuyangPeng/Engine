///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/21 09:30)

#ifndef CORE_TOOLS_MEMORY_TOOLS_RAW_PTR_COMPARE_H
#define CORE_TOOLS_MEMORY_TOOLS_RAW_PTR_COMPARE_H

#include "CoreTools/CoreToolsDll.h"

#include <memory>

namespace CoreTools
{
    template <typename T>
    struct RawPtrEqual final
    {
        bool operator()(const RawConstIterator<T>& lhs, const RawConstIterator<T>& rhs) const noexcept
        {
            return *lhs == *rhs;
        }
    };

    template <typename T>
    struct RawPtrUnequal final
    {
        bool operator()(const RawConstIterator<T>& lhs, const RawConstIterator<T>& rhs) const noexcept
        {
            return !RawPtrEqual<T>()(lhs, rhs);
        }
    };

    template <typename T>
    struct RawPtrLess final
    {
        bool operator()(const RawConstIterator<T>& lhs, const RawConstIterator<T>& rhs) const noexcept
        {
            return *lhs < *rhs;
        }
    };

    template <typename T>
    struct RawPtrLessEqual final
    {
        bool operator()(const RawConstIterator<T>& lhs, const RawConstIterator<T>& rhs) const noexcept
        {
            return !RawPtrLess<T>()(rhs, lhs);
        }
    };

    template <typename T>
    struct RawPtrGreater final
    {
        bool operator()(const RawConstIterator<T>& lhs, const RawConstIterator<T>& rhs) const noexcept
        {
            return RawPtrLess<T>()(rhs, lhs);
        }
    };

    template <typename T>
    struct RawPtrGreaterEqual final
    {
        bool operator()(const RawConstIterator<T>& lhs, const RawConstIterator<T>& rhs) const noexcept
        {
            return !RawPtrLess<T>()(lhs, rhs);
        }
    };
}

#endif  // CORE_TOOLS_MEMORY_TOOLS_RAW_PTR_COMPARE_H