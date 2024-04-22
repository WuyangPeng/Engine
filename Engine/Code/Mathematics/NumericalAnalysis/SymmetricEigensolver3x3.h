/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/03/30 14:41)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_SYMMETRIC_EIGENSOLVER3_X_3_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_SYMMETRIC_EIGENSOLVER3_X_3_H

#include "Mathematics/Base/Math.h"
#include "Mathematics/MathematicsDll.h"

#include <array>

/// 描述了求解与3x3对称实值矩阵相关的本征系统的算法。
/// 迭代算法由SymmetricEigensolver3x3类实现。
/// 非迭代算法由类NISymmetricEigensolver3x3实现。
namespace Mathematics
{
    template <typename Real>
    requires(std::is_arithmetic_v<Real>)
    class SymmetricEigensolver3x3
    {
    public:
        using ClassType = SymmetricEigensolver3x3<Real>;

        using Math = Math<Real>;

    public:
        SymmetricEigensolver3x3() noexcept;

        CLASS_INVARIANT_DECLARE;

        /// 输入矩阵必须对称，因此只能指定唯一元素：a00, a01, a02, a11, a12,和 a22。
        ///
        /// 如果'aggressive'为'true'，则会进行迭代，直到超对角线条目恰好为零。
        /// 如果'aggressive'为'false'，则迭代发生，直到超对角线条目与其对角线邻居的幅度之和相比实际上为零。
        /// 一般来说，非攻击性收敛是可以接受的。
        ///
        /// 特征值的顺序由sortType指定：-1（递减）、0（无排序）或+1（递增）。
        /// 当排序时，特征向量被相应地排序，
        /// 并且{evec[0], evec[1], evec[2]}被保证为/是右手正交集。
        /// 返回值是算法使用的迭代次数。

        int operator()(const Real& a00,
                       const Real& a01,
                       const Real& a02,
                       const Real& a11,
                       const Real& a12,
                       const Real& a22,
                       bool aggressive,
                       int sortType,
                       std::array<Real, 3>& eval,
                       std::array<std::array<Real, 3>, 3>& evec) const;

    private:
        /// 当(u,v)不是 (0,0)时，用 c <= 0将(u,v)归一化为 (c,s)。
        /// 如果(u,v) = (0,0)，则函数返回(c,s) = (-1,0)。
        /// 当用于生成Householder反射时，返回(c,s)还是(-c,-s)并不重要。
        /// 当生成Givens反射时，c = cos(2*theta)，s = sin(theta)。
        /// 对于双角度项具有负余弦确保了单角度项c = cos(theta)和s = sin(theta)满足|c| < 1/sqrt(2) < |s|。
        static void GetCosSin(const Real& u, const Real& v, Real& c, Real& s) noexcept;

        NODISCARD static bool Converged(bool aggressive, const Real& diagonal0, const Real& diagonal1, const Real& superDiagonal) noexcept(gAssert < 3 || gMathematicsAssert < 3);
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_SYMMETRIC_EIGENSOLVER3_X_3_H
