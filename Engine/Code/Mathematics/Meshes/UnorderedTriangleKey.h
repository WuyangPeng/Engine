///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.4 (2022/03/23 16:35)

#ifndef MATHEMATICS_MESHES_UNORDERED_TRIANGLE_KEY_H
#define MATHEMATICS_MESHES_UNORDERED_TRIANGLE_KEY_H

#include "Mathematics/MathematicsDll.h"

#include <array>

namespace Mathematics
{
    class MATHEMATICS_DEFAULT_DECLARE UnorderedTriangleKey
    {
    public:
        using ClassType = UnorderedTriangleKey;

    public:
        UnorderedTriangleKey(int first, int second, int third) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetKey(int index) const;

    private:
        std::array<int, 3> vertex;
    };

    NODISCARD bool MATHEMATICS_DEFAULT_DECLARE operator<(const UnorderedTriangleKey& lhs, const UnorderedTriangleKey& rhs);
}

#endif  // MATHEMATICS_MESHES_UNORDERED_TRIANGLE_KEY_H
