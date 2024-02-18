///	Copyright (c) 2010-2024
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.5 (2024/01/24 16:36)

#ifndef MATHEMATICS_RATIONAL_CIRCLE_SORT_OBJECT_H
#define MATHEMATICS_RATIONAL_CIRCLE_SORT_OBJECT_H

#include "Mathematics/MathematicsDll.h"

#include <array>

namespace Mathematics
{
    template <typename T>
    class CircleSortObject final
    {
    public:
        using ClassType = CircleSortObject<T>;

        using Vector2 = std::array<T, 2>;

    public:
        CircleSortObject() noexcept;
        CircleSortObject(const Vector2& w, int index) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD Vector2 GetW() const noexcept;
        NODISCARD T GetW(int i) const;
        NODISCARD int GetIndex() const noexcept;

    private:
        Vector2 w;
        int index;
    };

}

#endif  // MATHEMATICS_RATIONAL_CIRCLE_SORT_OBJECT_H
