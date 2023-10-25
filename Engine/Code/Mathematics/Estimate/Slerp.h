///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/09 17:05)

#ifndef MATHEMATICS_ESTIMATE_SLERP_H
#define MATHEMATICS_ESTIMATE_SLERP_H

#include "Mathematics/MathematicsDll.h"

/// 对于[0,1] 中的t和(0,pi)中的theta，
/// 单位长度矢量q0和q1的球面线性插值(slerp)为slerp(t,q0,q1) = [sin((1-t)*theta)*q0 + sin(theta)*q1]/sin(theta)。
/// 这个函数是单位超球面上q0和q1之间的大球面弧的参数化。
/// 此外，参数化具有这样的特性，即粒子沿着弧以恒定速度移动，其中t是时间。
//

/// 当将slerp应用于表示旋转的单位长度四元数 (N = 4)时，q和-q表示相同的旋转。四元数序列通常由
///  std::array<T, N> q[numElements];  // 假定已初始化
///  for (i0 = 0, i1 = 1; i1 < numElements; i0 = i1++)
///  {
///       cosA = Dot(q[i0], q[i1]);
///       if (cosA < 0)
///       {
///           q[i1] = -q[i1];  // now Dot(q[i0], q[i]1) >= 0
///       }
///   }
/// 使得连续四元数之间的角度为[0,pi/2]。

/// 余弦也可以被预先计算，
///   std::array<T, N> q[numElements];  // 假定已初始化
///   T cosA[numElements-1];  // 待预计算
///   for (i0 = 0, i1 = 1; i1 < numElements; i0 = i1++)
///   {
///       cosA[i0] = Dot(q[i0], q[i1]);
///       if (cosA[i0] < 0)
///       {
///           q[i1] = -q[i1];
///           cosA[i0] = -cosA[i0];
///       }
///   }

/// 为了提高slerp的数值鲁棒性，可以对四元数进行预处理，
/// 以便在每对原始四元数之间插入一个四元数。给定q0和q1，连接它们的弧的中点是qh，使得
/// A = Dot(q0,q1) 和 A/2 = Dot(q0,qh) = Dot(qh,q1).中点为
/// qh = Slerp(1/2,q0,q1) = (q0 + q1)/|q0 + q1|. 预处理是
///   std::array<T, N> q[numElements];  // 假定已初始化
///   std::array<T, N> qh[numElements-1];  // 待预计算
///   T cosAH[numElements-1];  // 待预计算
///   for (i0 = 0, i1 = 1; i1 < numElements; i0 = i1++)
///   {
///       cosA = Dot(q[i0], q[i1]);
///       if (cosA < 0)
///       {
///           q[i1] = -q[i1];
///           cosA = -cosA;
///       }
///       cosAH[i0] = sqrt((1 + cosA) / 2);
///       qh[i0] = (q0 + q1) / (2 * cosAH[i0]);
///   }

namespace Mathematics
{
    // q0和q1之间的角度为 [0,pi)。
    template <typename T, int N>
    requires(N >= 2)
    NODISCARD std::array<T, N> Slerp(T t, const std::array<T, N>& q0, const std::array<T, N>& q1);

    // q0和q1之间的角度必须在[0,pi)中，并且cosA = Dot(q0,q1)。
    template <typename T, int N>
    requires(N >= 2)
    NODISCARD std::array<T, N> Slerp(T t, const std::array<T, N>& q0, const std::array<T, N>& q1, T cosA);

    /// q0和q1之间的角度为[0,pi)。输入qh位于沿着超球面弧的q0和qc1之间的中间。
    /// 如果cosA = Dot(q0,q1)，则 cosAH = sqrt((1+cosA)/2)，qh = (q0+q1)/(2*cosAH)。
    template <typename T, int N>
    requires(N >= 2)
    NODISCARD std::array<T, N> Slerp(T t, const std::array<T, N>& q0, const std::array<T, N>& q1, const std::array<T, N>& qh, T cosAH);
}

#endif  // MATHEMATICS_ESTIMATE_SLERP_H
