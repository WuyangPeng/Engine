//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.7.1.1 (2020/10/23 15:23)

#ifndef CORE_TOOLS_TEMPLATE_TOOLS_LITERAL_CAST_H
#define CORE_TOOLS_TEMPLATE_TOOLS_LITERAL_CAST_H

#include "CoreTools/CoreToolsDll.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26432)
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
        ~LiteralCast();

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] operator T() const noexcept;
    };

    template <int64_t V>
    class LiteralCast<uint64_t, V>
    {
    public:
        using ClassType = LiteralCast<uint64_t, V>;

    private:
        CLASS_INVARIANT_DECLARE;

    public:
        [[nodiscard]] operator uint64_t() const;
    };

    template <int64_t V>
    class LiteralCast<int64_t, V>
    {
    public:
        using ClassType = LiteralCast<int64_t, V>;

    private:
        CLASS_INVARIANT_DECLARE;

    public:
        [[nodiscard]] operator int64_t() const;
    };
}
#include STSTEM_WARNING_POP
#endif  //  CORE_TOOLS_TEMPLATE_TOOLS_LITERAL_CAST_H
