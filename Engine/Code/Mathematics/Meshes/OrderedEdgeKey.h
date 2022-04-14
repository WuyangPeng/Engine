///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.4 (2022/03/07 22:00)

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
