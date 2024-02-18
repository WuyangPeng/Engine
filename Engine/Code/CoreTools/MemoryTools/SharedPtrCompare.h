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

/// std::shared_ptr对象的比较运算符。
/// 类型T必须实现比较运算符。
/// 必须小心在管理基于std::shared_ptr比较排序的容器。
/// 基础对象可能会发生更改，从而使容器排序无效。
/// 如果对象在容器持续存在时没有更改，则可以安全使用这些对象。
///
/// 注意：std::shared_ptr<T>已经有比较运算符，但这些运算符比较指针值，而不是比较指针引用的对象。
/// 如果为程序的两个不同执行创建了使用std::shared_ptr<T>排序的容器，则指针排序可能不同。
/// 这对于执行之间结果的再现性来说可能是不希望的。

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