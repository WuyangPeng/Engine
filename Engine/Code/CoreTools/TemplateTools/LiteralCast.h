///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/21 14:42)

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
