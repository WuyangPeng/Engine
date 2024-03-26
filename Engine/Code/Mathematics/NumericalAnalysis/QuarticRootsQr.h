/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/20 13:46)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_QUARTIC_ROOTS_QR_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_QUARTIC_ROOTS_QR_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Base/Math.h"

#include <array>

/// G.H.Golub和C.F.Van Loan在“矩阵计算，第二版”中描述的QR算法的实现，
/// 约翰霍普金斯大学出版社，巴尔的摩医学博士，1993年第四次印刷。
/// 特别是，该实现基于第7章（非对称特征值问题）第7.5节（实用QR算法）。
/// 该算法专门用于与四次多项式相关的伴随矩阵。
namespace Mathematics
{
    template <typename Real>
    requires(std::is_arithmetic_v<Real>)
    class QuarticRootsQr
    {
    public:
        using ClassType = QuarticRootsQr<Real>;

        using Math = Math<Real>;
        using Matrix = std::array<std::array<Real, 4>, 4>;

    public:
        QuarticRootsQr() noexcept;

        CLASS_INVARIANT_DECLARE;

        /// 求解 p(x) = c0 + c1 * x + c2 * x^2 + c3 * x^3 + x^4 = 0.
        NODISCARD int operator()(int maxIterations, Real c0, Real c1, Real c2, Real c3, int& numRoots, std::array<Real, 4>& roots) const;

        /// 计算上Hessenberg矩阵A的实本征值。
        /// 矩阵是通过原位运算修改的，所以如果你需要记住A，
        /// 你必须在调用这个函数之前制作自己的副本。
        NODISCARD int operator()(int maxIterations, Matrix& a, int& numRoots, std::array<Real, 4>& roots) const;

    private:
        void DoIteration(const std::array<Real, 3>& v, Matrix& a) const;

        template <int N>
        NODISCARD std::array<Real, N> House(const std::array<Real, N>& x) const;

        template <int N>
        void RowHouse(int rMin, int rMax, int cMin, int cMax, const std::array<Real, N>& v, const std::array<Real, N>& mv, Matrix& a) const;

        template <int N>
        void ColHouse(int rMin, int rMax, int cMin, int cMax, const std::array<Real, N>& v, const std::array<Real, N>& mv, Matrix& a) const;

        void GetQuadraticRoots(int i0, int i1, const Matrix& a, int& numRoots, std::array<Real, 4>& roots) const;
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_QUARTIC_ROOTS_QR_H
