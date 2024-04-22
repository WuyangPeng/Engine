/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/11 15:51)

#ifndef CORE_TOOLS_MEMORY_TOOLS_WEAK_PTR_COMPARE_H
#define CORE_TOOLS_MEMORY_TOOLS_WEAK_PTR_COMPARE_H

#include "CoreTools/CoreToolsDll.h"

#include "SharedPtrCompare.h"

#include <memory>

/// std::weak_ptr����ıȽ��������
/// ����T����ʵ�ֱȽ��������
/// ����С���ڹ������std::weak_ptr�Ƚ������������
/// ����������ܻᷢ�����ģ��Ӷ�ʹ����������Ч��
/// ���������������������ʱû�и��ģ�����԰�ȫʹ����Щ����
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