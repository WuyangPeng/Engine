///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 10:17)

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
