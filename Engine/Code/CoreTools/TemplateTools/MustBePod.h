/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/12 14:16)

/// 约束：必须是POD
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
            MAYBE_UNUSED void (*ptr)() = Constraint;
        }

        MustBePod() noexcept = default;
        MustBePod(const MustBePod& rhs) noexcept = default;
        MustBePod& operator=(const MustBePod& rhs) noexcept = default;
        MustBePod(MustBePod&& rhs) noexcept = default;
        MustBePod& operator=(MustBePod&& rhs) noexcept = default;

    private:
        constexpr static void Constraint() noexcept
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
            MAYBE_UNUSED void (*ptr)() = Constraint;
        }

        MustBePodOrVoid() noexcept = default;
        MustBePodOrVoid(const MustBePodOrVoid& rhs) noexcept = default;
        MustBePodOrVoid& operator=(const MustBePodOrVoid& rhs) noexcept = default;
        MustBePodOrVoid(MustBePodOrVoid&& rhs) noexcept = default;
        MustBePodOrVoid& operator=(MustBePodOrVoid&& rhs) noexcept = default;

    private:
        constexpr static void Constraint() noexcept
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
