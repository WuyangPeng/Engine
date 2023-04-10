///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/03/31 16:20)

#ifndef CORE_TOOLS_TEMPLATE_TOOLS_REFERENCE_CAST_H
#define CORE_TOOLS_TEMPLATE_TOOLS_REFERENCE_CAST_H

#include "CoreTools/CoreToolsDll.h"

namespace CoreTools
{
    template <typename T>
    class ReferenceCast
    {
    public:
        using ClassType = ReferenceCast<T>;

    public:
        explicit ReferenceCast(T& value) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD operator T&() noexcept;

        ~ReferenceCast() noexcept = default;
        ReferenceCast(const ReferenceCast& rhs) noexcept;
        ReferenceCast& operator=(const ReferenceCast&) noexcept = delete;
        ReferenceCast(ReferenceCast&& rhs) noexcept;
        ReferenceCast& operator=(ReferenceCast&&) noexcept = delete;

    private:
        T& value;
    };

    template <>
    class ReferenceCast<int>
    {
    public:
        using ClassType = ReferenceCast<int>;

    public:
        explicit ReferenceCast(int value) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD operator int() const noexcept;

    private:
        int value;
    };
}

#endif  //  CORE_TOOLS_TEMPLATE_TOOLS_REFERENCE_CAST_H
