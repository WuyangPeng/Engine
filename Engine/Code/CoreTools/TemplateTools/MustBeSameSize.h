///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/21 14:48)

// Լ�����������С������ȣ�����������Ӳ���ܹ����������
#ifndef CORE_TOOLS_TEMPLATE_TOOLS_MUST_BE_SAME_SIZE_H
#define CORE_TOOLS_TEMPLATE_TOOLS_MUST_BE_SAME_SIZE_H

#include "CoreTools/CoreToolsDll.h"

namespace CoreTools
{
    template <typename T>
    struct SizeOf
    {
        enum
        {
            Value = sizeof(T)
        };
    };

    template <>
    struct SizeOf<void>
    {
        enum
        {
            Value = 0
        };
    };

    template <typename T1, typename T2>
    struct MustBeSameSize
    {
        ~MustBeSameSize()
        {
            MAYBE_UNUSED void (*ptr)() = Constranints;
        }

        MustBeSameSize() noexcept = default;
        MustBeSameSize(const MustBeSameSize& rhs) noexcept = default;
        MustBeSameSize& operator=(const MustBeSameSize& rhs) noexcept = default;
        MustBeSameSize(MustBeSameSize&& rhs) noexcept = default;
        MustBeSameSize& operator=(MustBeSameSize&& rhs) noexcept = default;

    private:
        constexpr static void Constranints() noexcept
        {
            constexpr auto T1NotSameSizeAsT2 = static_cast<uint32_t>(static_cast<int>(SizeOf<T1>::Value) == static_cast<int>(SizeOf<T2>::Value));

            MAYBE_UNUSED const int i[T1NotSameSizeAsT2]{};
        }
    };
}

#endif  // CORE_TOOLS_TEMPLATE_TOOLS_MUST_BE_SAME_SIZE_H
