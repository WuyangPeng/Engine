///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/12 18:33)

#ifndef CORE_TOOLS_MEMORY_TOOLS_WEAK_PTR_COMPARE_H
#define CORE_TOOLS_MEMORY_TOOLS_WEAK_PTR_COMPARE_H

#include "CoreTools/CoreToolsDll.h"

#include <memory>

namespace CoreTools
{
    template <typename T>
    struct WeakPtrEqual final
    {
        bool operator()(const std::weak_ptr<T>& lhs, const std::weak_ptr<T>& rhs) const
        {
            return (lhs ? (rhs ? *lhs == *rhs : false) : !rhs);
        }
    };

    template <typename T>
    struct WeakPtrUnequal final
    {
        bool operator()(const std::weak_ptr<T>& lhs, const std::weak_ptr<T>& rhs) const
        {
            return !WeakPtrEqual<T>()(lhs, rhs);
        }
    };

    template <typename T>
    struct WeakPtrLess final
    {
        bool operator()(const std::weak_ptr<T>& lhs, const std::weak_ptr<T>& rhs) const
        {
            return (rhs ? (!lhs || *lhs < *rhs) : false);
        }
    };

    template <typename T>
    struct WeakPtrLessEqual final
    {
        bool operator()(const std::weak_ptr<T>& lhs, const std::weak_ptr<T>& rhs) const
        {
            return !WeakPtrLess<T>()(rhs, lhs);
        }
    };

    template <typename T>
    struct WeakPtrGreater final
    {
        bool operator()(const std::weak_ptr<T>& lhs, const std::weak_ptr<T>& rhs) const
        {
            return WeakPtrLess<T>()(rhs, lhs);
        }
    };

    template <typename T>
    struct WeakPtrGreaterEqual final
    {
        bool operator()(const std::weak_ptr<T>& lhs, const std::weak_ptr<T>& rhs) const
        {
            return !WeakPtrLess<T>()(lhs, rhs);
        }
    };
}

#endif  // CORE_TOOLS_MEMORY_TOOLS_WEAK_PTR_COMPARE_H