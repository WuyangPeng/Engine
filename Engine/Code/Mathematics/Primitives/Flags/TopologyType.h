///	Copyright (c) 2010-2024
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.6 (2024/03/01 16:30)

#ifndef MATHEMATICS_PRIMITIVES_TOPOLOGY_TYPE_H
#define MATHEMATICS_PRIMITIVES_TOPOLOGY_TYPE_H

#include "Mathematics/Helper/UserMacro.h"

namespace Mathematics
{
    /// 拓扑的注释基于具有 L >= 2个元素的输入顶点，
    /// 这些元素排序为 { V[0], V[1], ..., V[L-1] }。
    enum class TopologyType
    {
        /// 默认构造函数没有关于网格拓扑的信息。
        Unknown,

        /// L必须是偶数。L/2段为
        /// <V[0],V[1]>, <V[2],V[3]>, ..., <V[L-2],V[L-1]>.
        Disjoint,

        /// 顶点形成一条开放的多段线。L-1段为
        /// <V[0],V[1]>, <V[1],V[2]>, ..., <V[L-2],V[L-1]>.
        ContiguousOpen,

        // 顶点形成一条闭合的多段线。L段为
        // <V[0],V[1]>, ..., <V[L-2],V[L-1]>, <V[L-1],V[0]>.
        ContiguousClosed,

        /// 线段是通过索引到顶点阵列中生成的。
        /// 网格具有M个分段，每个分段由索引对S[i]生成，用于0 <= i <= M-1。分段为
        /// <V[S[0][0],S[0][1]>, <V[S[1][0],S[1][1]>, ...,
        /// <V[S[M-1][0],S[M-1][1]>。
        /// 其他拓扑可以使用索引方法来表示，
        /// DISJOINT: S[i] = {2*i, 2*i+1} for 0 <= i <= (L-2)/2
        //  CONTIGUOUS_OPEN: S[i] = {i, i + 1} for 0 <= i <= L-2
        //  CONTIGUOUS_CLOSED: S[i] = {i, (i + 1) % L} for 0 <= i <= L-1
        Indexed
    };
}

#endif  // MATHEMATICS_PRIMITIVES_TOPOLOGY_TYPE_H
