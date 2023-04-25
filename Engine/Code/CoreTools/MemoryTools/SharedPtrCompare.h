///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.4 (2023/03/29 10:38)

#ifndef CORE_TOOLS_MEMORY_TOOLS_SHARED_PTR_COMPARE_H
#define CORE_TOOLS_MEMORY_TOOLS_SHARED_PTR_COMPARE_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/PragmaWarning.h"

#include <memory>

namespace CoreTools
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26415)
#include SYSTEM_WARNING_DISABLE(26418)

    template <typename T>
    struct SharedPtrEqual final
    {
        bool operator()(const std::shared_ptr<T>& lhs, const std::shared_ptr<T>& rhs) const noexcept
        {
            return (lhs ? (rhs ? *lhs == *rhs : false) : !rhs);
        }
    };
#include STSTEM_WARNING_POP

    template <typename T>
    struct SharedPtrUnequal final
    {
        bool operator()(const std::shared_ptr<T>& lhs, const std::shared_ptr<T>& rhs) const noexcept
        {
            return !SharedPtrEqual<T>()(lhs, rhs);
        }
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26415)
#include SYSTEM_WARNING_DISABLE(26418)

    template <typename T>
    struct SharedPtrLess final
    {
        bool operator()(const std::shared_ptr<T>& lhs, const std::shared_ptr<T>& rhs) const noexcept
        {
            return (rhs ? (!lhs || *lhs < *rhs) : false);
        }
    };

#include STSTEM_WARNING_POP

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