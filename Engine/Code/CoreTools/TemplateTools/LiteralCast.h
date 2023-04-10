///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/03/31 16:07)

#ifndef CORE_TOOLS_TEMPLATE_TOOLS_LITERAL_CAST_H
#define CORE_TOOLS_TEMPLATE_TOOLS_LITERAL_CAST_H

#include "CoreTools/CoreToolsDll.h"

namespace CoreTools
{
    template <typename T, int64_t V>
    class LiteralCast
    {
    public:
        using ClassType = LiteralCast<T, V>;

    private:
        static void Constranints() noexcept;

    public:
        LiteralCast() noexcept = default;
        ~LiteralCast();
        LiteralCast(const LiteralCast& rhs) noexcept = default;
        LiteralCast& operator=(const LiteralCast& rhs) noexcept = default;
        LiteralCast(LiteralCast&& rhs) noexcept = default;
        LiteralCast& operator=(LiteralCast&& rhs) noexcept = default;

        CLASS_INVARIANT_DECLARE;

        NODISCARD operator T() const noexcept;
    };

    template <int64_t V>
    class LiteralCast<uint64_t, V>
    {
    public:
        using ClassType = LiteralCast<uint64_t, V>;

    private:
        CLASS_INVARIANT_DECLARE;

    public:
        NODISCARD operator uint64_t() const;
    };

    template <int64_t V>
    class LiteralCast<int64_t, V>
    {
    public:
        using ClassType = LiteralCast<int64_t, V>;

    private:
        CLASS_INVARIANT_DECLARE;

    public:
        NODISCARD operator int64_t() const;
    };
}

#endif  //  CORE_TOOLS_TEMPLATE_TOOLS_LITERAL_CAST_H
