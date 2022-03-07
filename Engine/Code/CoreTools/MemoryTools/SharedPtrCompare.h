///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/12 18:33)

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