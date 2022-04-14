///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.4 (2022/03/22 13:19)

#ifndef MATHEMATICS_MESHES_TRIANGLE_KEY_H
#define MATHEMATICS_MESHES_TRIANGLE_KEY_H

#include "Mathematics/MathematicsDll.h"

#include <array>

namespace Mathematics
{
    class MATHEMATICS_DEFAULT_DECLARE TriangleKey
    {
    public:
        using ClassType = TriangleKey;

    public:
        TriangleKey() noexcept;
        TriangleKey(int first, int second, int third) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetKey(int index) const;
        NODISCARD int GetKeyIndex(int key) const;
        void SetKey(int index, int value);

        void Swap(int lhsIndex, int rhsIndex);

    private:
        const static int vertexSize = 3;

    private:
        NODISCARD std::array<int, vertexSize> Init(int first, int second, int third) noexcept;

    private:
        std::array<int, vertexSize> vertex;
    };

    NODISCARD bool MATHEMATICS_DEFAULT_DECLARE operator<(const TriangleKey& lhs, const TriangleKey& rhs);
}

#endif  // MATHEMATICS_MESHES_TRIANGLE_KEY_H
