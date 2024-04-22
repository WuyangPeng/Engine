/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/11 15:51)

#ifndef CORE_TOOLS_MEMORY_TOOLS_WEAK_PTR_COMPARE_H
#define CORE_TOOLS_MEMORY_TOOLS_WEAK_PTR_COMPARE_H

#include "CoreTools/CoreToolsDll.h"

#include "SharedPtrCompare.h"

#include <memory>

/// std::weak_ptr对象的比较运算符。
/// 类型T必须实现比较运算符。
/// 必须小心在管理基于std::weak_ptr比较排序的容器。
/// 基础对象可能会发生更改，从而使容器排序无效。
/// 如果对象在容器持续存在时没有更改，则可以安全使用这些对象。
namespace CoreTools
{
    template <typename T>
    struct WeakPtrEqual final
    {
        bool operator()(const std::weak_ptr<T>& lhs, const std::weak_ptr<T>& rhs) const noexcept
        {
            auto lhsSharedPtr = lhs.lock();
            auto rhsSharedPtr = rhs.lock();

            return SharedPtrEqual<T>()(lhsSharedPtr, rhsSharedPtr);
        }
    };

    template <typename T>
    struct WeakPtrUnequal final
    {
        bool operator()(const std::weak_ptr<T>& lhs, const std::weak_ptr<T>& rhs) const noexcept
        {
            return !WeakPtrEqual<T>()(lhs, rhs);
        }
    };

    template <typename T>
    struct WeakPtrLess final
    {
        bool operator()(const std::weak_ptr<T>& lhs, const std::weak_ptr<T>& rhs) const noexcept
        {
            auto lhsSharedPtr = lhs.lock();
            auto rhsSharedPtr = rhs.lock();

            return SharedPtrLess<T>()(lhsSharedPtr, rhsSharedPtr);
        }
    };

    template <typename T>
    struct WeakPtrLessEqual final
    {
        bool operator()(const std::weak_ptr<T>& lhs, const std::weak_ptr<T>& rhs) const noexcept
        {
            return !WeakPtrLess<T>()(rhs, lhs);
        }
    };

    template <typename T>
    struct WeakPtrGreater final
    {
        bool operator()(const std::weak_ptr<T>& lhs, const std::weak_ptr<T>& rhs) const noexcept
        {
            return WeakPtrLess<T>()(rhs, lhs);
        }
    };

    template <typename T>
    struct WeakPtrGreaterEqual final
    {
        bool operator()(const std::weak_ptr<T>& lhs, const std::weak_ptr<T>& rhs) const noexcept
        {
            return !WeakPtrLess<T>()(lhs, rhs);
        }
    };
}

#endif  // CORE_TOOLS_MEMORY_TOOLS_WEAK_PTR_COMPARE_H