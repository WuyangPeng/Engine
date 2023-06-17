///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 10:17)

#ifndef MATHEMATICS_MESHES_ORDERED_EDGE_KEY_H
#define MATHEMATICS_MESHES_ORDERED_EDGE_KEY_H

#include "Mathematics/MathematicsDll.h"

namespace Mathematics
{
    class MATHEMATICS_DEFAULT_DECLARE OrderedEdgeKey
    {
    public:
        using ClassType = OrderedEdgeKey;

    public:
        OrderedEdgeKey(int first, int second) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetKey(int index) const;

    private:
        int first;
        int second;
    };

    NODISCARD bool MATHEMATICS_DEFAULT_DECLARE operator<(const OrderedEdgeKey& lhs, const OrderedEdgeKey& rhs);
}

#endif  // MATHEMATICS_MESHES_ORDERED_EDGE_KEY_H
