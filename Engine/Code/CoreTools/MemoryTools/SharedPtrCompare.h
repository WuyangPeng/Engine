///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/29 10:38)

#ifndef CORE_TOOLS_MEMORY_TOOLS_SHARED_PTR_COMPARE_H
#define CORE_TOOLS_MEMORY_TOOLS_SHARED_PTR_COMPARE_H

#include "CoreTools/CoreToolsDll.h"

#include <memory>

namespace CoreTools
{
    template <typename T>
    struct SharedPtrEqual final
    {
        bool operator()(const std::shared_ptr<T>& lhs, const std::shared_ptr<T>& rhs) const
        {
            return (lhs ? (rhs ? *lhs == *rhs : false) : !rhs);
        }
    };

    template <typename T>
    struct SharedPtrUnequal final
    {
        bool operator()(const std::shared_ptr<T>& lhs, const std::shared_ptr<T>& rhs) const
        {
            return !SharedPtrEqual<T>()(lhs, rhs);
        }
    };

    template <typename T>
    struct SharedPtrLess final
    {
        bool operator()(const std::shared_ptr<T>& lhs, const std::shared_ptr<T>& rhs) const
        {
            return (rhs ? (!lhs || *lhs < *rhs) : false);
        }
    };

    template <typename T>
    struct SharedPtrLessEqual final
    {
        bool operator()(const std::shared_ptr<T>& lhs, const std::shared_ptr<T>& rhs) const
        {
            return !SharedPtrLess<T>()(rhs, lhs);
        }
    };

    template <typename T>
    struct SharedPtrGreater final
    {
        bool operator()(const std::shared_ptr<T>& lhs, const std::shared_ptr<T>& rhs) const
        {
            return SharedPtrLess<T>()(rhs, lhs);
        }
    };

    template <typename T>
    struct SharedPtrGreaterEqual final
    {
        bool operator()(const std::shared_ptr<T>& lhs, const std::shared_ptr<T>& rhs) const
        {
            return !SharedPtrLess<T>()(lhs, rhs);
        }
    };
}

#endif  // CORE_TOOLS_MEMORY_TOOLS_SHARED_PTR_COMPARE_H