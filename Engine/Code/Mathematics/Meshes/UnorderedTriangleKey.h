///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/09 10:17)

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
