///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.4 (2022/03/23 14:50)

#ifndef MATHEMATICS_MESHES_TETRAHEDRON_KEY_H
#define MATHEMATICS_MESHES_TETRAHEDRON_KEY_H

#include "Mathematics/MathematicsDll.h"

#include <array>

namespace Mathematics
{
    class TetrahedronKey
    {
    public:
        using ClassType = TetrahedronKey;

    public:
        TetrahedronKey(int v0 = -1, int v1 = -1, int v2 = -1, int v3 = -1) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD bool operator<(const TetrahedronKey& key) const noexcept;

        static const std::array<std::array<int, 3>, 4> oppositeFace;

    private:
        void Permute(int u0, int u1, int u2) noexcept;

    private:
        std::array<int, 4> v;
    };
}

#endif  // MATHEMATICS_MESHES_TETRAHEDRON_KEY_H
