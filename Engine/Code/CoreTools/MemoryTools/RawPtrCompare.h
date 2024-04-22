/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/11 15:50)

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