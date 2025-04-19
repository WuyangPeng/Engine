/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/02 09:20)

#ifndef MATHEMATICS_APPROXIMATION_APPROXIMATION_HEIGHT_LINE2_H
#define MATHEMATICS_APPROXIMATION_APPROXIMATION_HEIGHT_LINE2_H

#include "Mathematics/MathematicsDll.h"

#include "ApproximationQuery.h"
#include "Mathematics/Algebra/Vector/Vector2.h"

/// 直线与高度数据(x,f(x))的最小二乘拟合。
/// 该线的形式为：(y - yAvr) = a*(x - xAvr)，其中(xAvr,yAvr)是采样点的平均值。
/// 当且仅当拟合成功（输入点不会退化为单个点）时，“拟合”的返回值为“true”。
/// 成功时mParameters值为((xAvr,yAvr),(a,-1)) ，失败时为 ((0,0),(0,0))。
/// (x0,y0)的错误[a*(x0-xAvr)-(y0-yAvr)]^2。
namespace Mathematics
{
    template <typename Real>
    requires(std::is_arithmetic_v<Real>)
    class ApproximationHeightLine2 : public ApproximationQuery<Real, Algebra::Vector2<Real>>
    {
    public:
        using ClassType = ApproximationHeightLine2<Real>;
        using ParentType = ApproximationQuery<Real, Algebra::Vector2<Real>>;

        using Vector2 = Algebra::Vector2<Real>;
        using ObservationTypeContainer = typename ParentType::ObservationTypeContainer;
        using IndicesContainer = typename ParentType::IndicesContainer;
        using ParametersType = std::pair<Vector2, Vector2>;
        using MathType = Math<Real>;

    public:
        ApproximationHeightLine2() noexcept;

        CLASS_INVARIANT_DECLARE;

        /// 基本拟合算法。有关可以调用的各种Fit(...)函数，请参见ApproximationQuery.h。
        NODISCARD bool FitIndexed(const ObservationTypeContainer& observations, const IndicesContainer& indices) override;

        /// 获取最适合的参数。
        NODISCARD ParametersType GetParameters() const noexcept;

        NODISCARD int GetMinimumRequired() const noexcept override;

        NODISCARD Real Error(const Vector2& point) const override;

        void CopyParameters(const ParentType& input) override;

    private:
        ParametersType parameters;
    };
}

#endif  // MATHEMATICS_APPROXIMATION_APPROXIMATION_HEIGHT_LINE2_H
