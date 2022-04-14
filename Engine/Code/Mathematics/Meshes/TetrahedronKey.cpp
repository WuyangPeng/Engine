///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.4 (2022/03/23 14:52)

#include "Mathematics/MathematicsExport.h"

#include "TetrahedronKey.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

const std::array<std::array<int, 3>, 4> Mathematics::TetrahedronKey::oppositeFace{ std::array<int, 3>{ 1, 2, 3 }, std::array<int, 3>{ 0, 3, 2 }, std::array<int, 3>{ 0, 1, 3 }, std::array<int, 3>{ 0, 2, 1 } };

Mathematics::TetrahedronKey::TetrahedronKey(int v0, int v1, int v2, int v3) noexcept
    : v{}
{
    auto imin = 0;
    v.at(0) = v0;
    if (v1 < v.at(0))
    {
        v.at(0) = v1;
        imin = 1;
    }
    if (v2 < v.at(0))
    {
        v.at(0) = v2;
        imin = 2;
    }
    if (v3 < v.at(0))
    {
        v.at(0) = v3;
        imin = 3;
    }

    if (imin == 0)
    {
        Permute(v1, v2, v3);
    }
    else if (imin == 1)
    {
        Permute(v0, v3, v2);
    }
    else if (imin == 2)
    {
        Permute(v0, v1, v3);
    }
    else
    {
        Permute(v0, v2, v1);
    }

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Mathematics, TetrahedronKey)

bool Mathematics::TetrahedronKey::operator<(const TetrahedronKey& key) const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (v.at(3) < key.v.at(3))
    {
        return true;
    }

    if (v.at(3) > key.v.at(3))
    {
        return false;
    }

    if (v.at(2) < key.v.at(2))
    {
        return true;
    }

    if (v.at(2) > key.v.at(2))
    {
        return false;
    }

    if (v.at(1) < key.v.at(1))
    {
        return true;
    }

    if (v.at(1) > key.v.at(1))
    {
        return false;
    }

    return v.at(0) < key.v.at(0);
}

void Mathematics::TetrahedronKey::Permute(int u0, int u1, int u2) noexcept
{
    if (u0 < u1)
    {
        if (u0 < u2)
        {
            v.at(1) = u0;
            v.at(2) = u1;
            v.at(3) = u2;
        }
        else
        {
            v.at(1) = u2;
            v.at(2) = u0;
            v.at(3) = u1;
        }
    }
    else
    {
        if (u1 < u2)
        {
            v.at(1) = u1;
            v.at(2) = u2;
            v.at(3) = u0;
        }
        else
        {
            v.at(1) = u2;
            v.at(2) = u0;
            v.at(3) = u1;
        }
    }
}
