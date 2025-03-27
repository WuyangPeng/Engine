/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/07 16:07)

#ifndef MATHEMATICS_APPROXIMATION_APPROXIMATION_ELLIPSE2_H
#define MATHEMATICS_APPROXIMATION_APPROXIMATION_ELLIPSE2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Matrix/Matrix2x2.h"
#include "Mathematics/Algebra/Vector/Vector2.h"
#include "Mathematics/Primitives/HyperEllipsoid.h"

#include <vector>

/// 椭圆隐含地定义为(X-C)^T * M * (X-C) = 1，其中C是中心，M是正定矩阵，X是椭圆上的任何点。
/// 该代码实现了误差函数的非线性最小二乘拟合算法
///   F(C,M) = sum_{i=0}^{n-1} ((X[i] - C)^T * M * (X[i] - C) - 1)^2
///   对于n个数据点X[0]到X[n-1]。
///   Ellipse2<Real>对象具有与C相对应的成员 'center'。
///   它还具有单位长度方向为'axis[]'的轴和相应的轴半长度为 'extent[]'的轴线。
///   矩阵是M = sum_{i=0}^1 axis[i] * axis[i]^T / extent[i]^2，
///   其中axis[i]是2x1矢量， axis[i]^T是1x2矢量。
///
/// 最小化器使用两步梯度下降算法。
///
/// 给定current (C,M),找出的最小值
///   G(t) = F(C - t * dF(C,M)/dC, M)
///   对于t > 0。函数G(t) >= 0是一个4次多项式，导数G'(t)是一个3次多项式。
///   G'(t)必须有一个正根，因为G(0) > 0和G'(0) < 0，并且t^4的G系数是正的。
///   T产生最小G值的正根用于更新中心C' = C - T * dF/dC(C,M)。
///
/// 给定current (C,M),找出的最小值
///   H(t) = F(C, M - t * dF(C,M)/dM)
///
/// 对于t > 0。函数H(t) >= 0是一个2次多项式，导数H'(t)是一个1次多项式。
/// H'(t)必须有一个正根，因为H(0) > 0 和H'(0) < 0，并且t^2的H系数是正的。
/// 产生最小G值的正根T用于更新矩阵M' = M - T * dF/dC(C,M)，只要M'是正定的。
/// 如果M'不是正定的，则根在有限的步数内减半，直到M'是正定的。
namespace Mathematics
{
    template <typename Real>
    requires(std::is_arithmetic_v<Real>)
    class ApproximationEllipse2
    {
    public:
        using ClassType = ApproximationEllipse2<Real>;

        using Vector2 = Algebra::Vector2<Real>;
        using Vector2Container = std::vector<Vector2>;
        using IndicesContainer = std::vector<int>;
        using Ellipse2 = Algebra::Ellipse2<Real>;
        using Matrix2x2 = Algebra::Matrix2x2<Real>;
        using MathType = Math<Real>;

    public:
        ApproximationEllipse2() noexcept;

        CLASS_INVARIANT_DECLARE;

        /// 如果希望此函数计算椭球体的初始猜测，请将 'useEllipseForInitialGuess'设置为true。
        /// 包含点的定向边界框用于启动最小化器。
        /// 如果希望初始猜测为输入椭圆，请将'useEllipseForInitialGuess'设置为true。
        /// 如果要重复查询，这将非常有用。返回的'Real'值是输出“椭圆”的错误函数值。
        NODISCARD Real operator()(const Vector2Container& points,
                                  int numIterations,
                                  bool useEllipseForInitialGuess,
                                  Ellipse2& ellipse);

    private:
        NODISCARD Real UpdateCenter(const Vector2Container& points,
                                    const Matrix2x2& m,
                                    Vector2& c);

        NODISCARD Real UpdateMatrix(const Vector2Container& points,
                                    const Vector2& c,
                                    Matrix2x2& m);

        NODISCARD Real ErrorFunction(const Vector2Container& points,
                                     const Vector2& c,
                                     const Matrix2x2& m) const;
    };
}

#endif  // MATHEMATICS_APPROXIMATION_APPROXIMATION_ELLIPSE2_H
