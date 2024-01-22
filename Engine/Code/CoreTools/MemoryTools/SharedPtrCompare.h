/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 09:45)

#ifndef CORE_TOOLS_MEMORY_TOOLS_SHARED_PTR_COMPARE_H
#define CORE_TOOLS_MEMORY_TOOLS_SHARED_PTR_COMPARE_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/PragmaWarning/TypeTraits.h"
#include "System/Helper/Tools.h"

#include <memory>

namespace CoreTools
{
    template <typename T>
    struct SharedPtrEqual final
    {
        bool operator()(const std::shared_ptr<T>& lhs, const std::shared_ptr<T>& rhs) const noexcept
        {
            System::UnusedFunction(lhs, rhs);

            if constexpr (boost::has_less<T, T, bool>::value)
            {
                return (lhs ? (rhs ? *lhs == *rhs : false) : !rhs);
            }
            else
            {
                return lhs == rhs;
            }
        }
    };

    template <typename T>
    struct SharedPtrUnequal final
    {
        bool operator()(const std::shared_ptr<T>& lhs, const std::shared_ptr<T>& rhs) const noexcept
        {
            return !SharedPtrEqual<T>()(lhs, rhs);
        }
    };

    template <typename T>
    struct SharedPtrLess final
    {
        bool operator()(const std::shared_ptr<T>& lhs, const std::shared_ptr<T>& rhs) const noexcept
        {
            System::UnusedFunction(lhs, rhs);

            if constexpr (boost::has_less<T, T, bool>::value)
            {
                return (rhs ? (!lhs || *lhs < *rhs) : false);
            }
            else
            {
                return lhs < rhs;
            }
        }
    };

    template <typename T>
    struct SharedPtrLessEqual final
    {
        bool operator()(const std::shared_ptr<T>& lhs, const std::shared_ptr<T>& rhs) const noexcept
        {
            return !SharedPtrLess<T>()(rhs, lhs);
        }
    };

    template <typename T>
    struct SharedPtrGreater final
    {
        bool operator()(const std::shared_ptr<T>& lhs, const std::shared_ptr<T>& rhs) const noexcept
        {
            return SharedPtrLess<T>()(rhs, lhs);
        }
    };

    template <typename T>
    struct SharedPtrGreaterEqual final
    {
        bool operator()(const std::shared_ptr<T>& lhs, const std::shared_ptr<T>& rhs) const noexcept
        {
            return !SharedPtrLess<T>()(lhs, rhs);
        }
    };
}

#endif  // CORE_TOOLS_MEMORY_TOOLS_SHARED_PTR_COMPARE_H