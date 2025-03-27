/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/03/30 17:02)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_NI_SYMMETRIC_EIGENSOLVER_3X3_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_NI_SYMMETRIC_EIGENSOLVER_3X3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Base/Math.h"

#include <array>

namespace Mathematics
{
    template <typename Real>
    requires(std::is_arithmetic_v<Real>)
    class NISymmetricEigensolver3x3
    {
    public:
        using ClassType = NISymmetricEigensolver3x3<Real>;

        using MathType = Math<Real>;

    public:
        NISymmetricEigensolver3x3() noexcept;

        CLASS_INVARIANT_DECLARE;

        /// 输入矩阵必须对称，因此只能指定唯一元素：a00、a01、a02、a11、a12和a22。
        /// 特征值按升序排序：eval0 <= eval1 <= eval2。

        void operator()(Real a00,
                        Real a01,
                        Real a02,
                        Real a11,
                        Real a12,
                        Real a22,
                        int sortType,
                        std::array<Real, 3>& eval,
                        std::array<std::array<Real, 3>, 3>& evec) const;

    private:
        static std::array<Real, 3> Multiply(Real s, const std::array<Real, 3>& u);

        static std::array<Real, 3> Subtract(const std::array<Real, 3>& u, const std::array<Real, 3>& v);

        static std::array<Real, 3> Divide(const std::array<Real, 3>& u, Real s);

        NODISCARD static Real Dot(const std::array<Real, 3>& u, const std::array<Real, 3>& v);

        NODISCARD static std::array<Real, 3> Cross(const std::array<Real, 3>& u, const std::array<Real, 3>& v);

        void ComputeOrthogonalComplement(const std::array<Real, 3>& w,
                                         std::array<Real, 3>& u,
                                         std::array<Real, 3>& v) const;

        void ComputeEigenvector0(Real a00,
                                 Real a01,
                                 Real a02,
                                 Real a11,
                                 Real a12,
                                 Real a22,
                                 Real eval0,
                                 std::array<Real, 3>& evec0) const;

        void ComputeEigenvector1(Real a00,
                                 Real a01,
                                 Real a02,
                                 Real a11,
                                 Real a12,
                                 Real a22,
                                 const std::array<Real, 3>& evec0,
                                 Real eval1,
                                 std::array<Real, 3>& evec1) const;
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_NI_SYMMETRIC_EIGENSOLVER_3X3_H
