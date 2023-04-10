///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.5 (2023/03/31 16:10)

// Լ����������POD
#ifndef CORE_TOOLS_TEMPLATE_TOOLS_MUST_BE_POD_H
#define CORE_TOOLS_TEMPLATE_TOOLS_MUST_BE_POD_H

#include "CoreTools/CoreToolsDll.h"

namespace CoreTools
{
    template <typename T>
    struct MustBePod
    {
        ~MustBePod()
        {
            MAYBE_UNUSED void (*ptr)() = Constranints;
        }

        MustBePod() noexcept = default;
        MustBePod(const MustBePod& rhs) noexcept = default;
        MustBePod& operator=(const MustBePod& rhs) noexcept = default;
        MustBePod(MustBePod&& rhs) noexcept = default;
        MustBePod& operator=(MustBePod&& rhs) noexcept = default;

    private:
        constexpr static void Constranints() noexcept
        {
            MAYBE_UNUSED const union
            {
                T tIsNotPodType;
            } unionType{};
        }
    };

    template <typename T>
    struct MustBePodOrVoid
    {
        ~MustBePodOrVoid()
        {
            MAYBE_UNUSED void (*ptr)() = Constranints;
        }

        MustBePodOrVoid() noexcept = default;
        MustBePodOrVoid(const MustBePodOrVoid& rhs) noexcept = default;
        MustBePodOrVoid& operator=(const MustBePodOrVoid& rhs) noexcept = default;
        MustBePodOrVoid(MustBePodOrVoid&& rhs) noexcept = default;
        MustBePodOrVoid& operator=(MustBePodOrVoid&& rhs) noexcept = default;

    private:
        constexpr static void Constranints() noexcept
        {
            MAYBE_UNUSED const union
            {
                T tIsNotPodTypeOrVoid;
            } unionType{};
        }
    };

    template <>
    struct MustBePodOrVoid<void>
    {
    };
}

#endif  // CORE_TOOLS_TEMPLATE_TOOLS_MUST_BE_POD_H
