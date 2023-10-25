///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/09/20 14:47)

#ifndef CORE_TOOLS_TEMPLATE_TOOLS_MUST_BE_BASE_H
#define CORE_TOOLS_TEMPLATE_TOOLS_MUST_BE_BASE_H

#include "CoreTools/CoreToolsDll.h"

// Լ������D����B�����������ͬ����
namespace CoreTools
{
    template <typename Derive, typename Base>
    struct MustHaveBase
    {
        MustHaveBase() noexcept = default;
        MustHaveBase(const MustHaveBase& rhs) noexcept = default;
        MustHaveBase& operator=(const MustHaveBase& rhs) noexcept = default;
        MustHaveBase(MustHaveBase&& rhs) noexcept = default;
        MustHaveBase& operator=(MustHaveBase&& rhs) noexcept = default;

        ~MustHaveBase()
        {
            MAYBE_UNUSED void (*ptr)(Derive*, Base*) = Constranints;
        }

    private:
        static void Constranints(Derive* derivePtr, Base* basePtr) noexcept
        {
            basePtr = derivePtr;
        }
    };
}

#endif  // CORE_TOOLS_TEMPLATE_TOOLS_MUST_BE_BASE_H
