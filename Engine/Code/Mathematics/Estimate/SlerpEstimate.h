///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/20 10:14)

#ifndef MATHEMATICS_ESTIMATE_SLERP_ESTIMATE_H
#define MATHEMATICS_ESTIMATE_SLERP_ESTIMATE_H

#include "Mathematics/MathematicsDll.h"

/// 该文件中实现的前两个slerp估计需要[0,pi/2]中的角度，因为这些估计基于具有相同角度要求的Chebyshev比率估计。使用qh输入的第三个函数估计允许[0,pi)中的角度。
namespace Mathematics
{

    // q0和q1之间的角度为[0,pi/2]。
    template <typename T, int N, int D>
    requires((N >= 2) && (1 <= D && D <= 16))
    NODISCARD std::array<T, N> SlerpEstimate(T t, const std::array<T, N>& q0, const std::array<T, N>& q1);

    /// q0和q1之间的角度必须在[0,pi/2] 中，并且cosA = Dot(q0,q1)。
    template <typename T, int N, int D>
    requires((N >= 2) && (1 <= D && D <= 16))
    NODISCARD std::array<T, N> SlerpEstimate(T t, const std::array<T, N>& q0, const std::array<T, N>& q1, T cosA);

    /// q0和q1之间的角度为[0,pi)。输入qh位于沿着超球面弧的q0和q1之间的中间。如果 cosA = Dot(q0,q1)，则 cosAH = sqrt((1+cosA)/2) ，qh = (q0+q1)/(2*cosAH)。
    template <typename T, int N, int D>
    requires((N >= 2) && (1 <= D && D <= 16))
    NODISCARD std::array<T, N> SlerpEstimate(T t, std::array<T, N> const& q0, const std::array<T, N>& q1, const std::array<T, N>& qh, T cosAH);
}

#endif  // MATHEMATICS_ESTIMATE_SLERP_ESTIMATE_H
