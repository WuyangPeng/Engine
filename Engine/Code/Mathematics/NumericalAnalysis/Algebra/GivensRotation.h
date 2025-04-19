///	Copyright (c) 2010-2024
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.6 (2024/02/27 11:12)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_ALGEBRA_GIVENS_ROTATION_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_ALGEBRA_GIVENS_ROTATION_H

#include "Mathematics/MathematicsDll.h"

#include <type_traits>

namespace Mathematics::Algebra
{
    /// Givens旋转用于将初始双对角矩阵简化为对角矩阵。
    /// 旋转与以下替换项相同： R(index0,index0) = cs, R(index0,index1) = sn，R(index1,index0) = -sn 和 R(index1,index1) = cs。
    /// 如果N是矩阵列的数量，K是最大迭代次数，则Givens右旋转或左旋转的最大次数为K*(N-1)。
    /// 分配的最大内存量用于存储这些内容。
    /// 然而，当对角项为零时，我们也可能需要左旋转来解耦矩阵。
    /// 最坏的情况是N的二次矩阵，所以现在我们只使用std::vector<GivensRotation>，其初始容量为K*(N-1)。
    template <typename Real>
    requires(std::is_arithmetic_v<Real>)
    class GivensRotation
    {
    public:
        using ClassType = GivensRotation<Real>;

    public:
        GivensRotation() noexcept;
        GivensRotation(int index0, int index1, Real cs, Real sn) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetIndex0() const noexcept;

        void SetIndex0(int aIndex0) noexcept;
        NODISCARD int GetIndex1() const noexcept;
        void SetIndex1(int aIndex1) noexcept;
        NODISCARD Real GetCs() const noexcept;
        void SetCs(Real aCs) noexcept;
        NODISCARD Real GetSn() const noexcept;
        void SetSn(Real aSn) noexcept;

    private:
        int index0;
        int index1;
        Real cs;
        Real sn;
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_ALGEBRA_GIVENS_ROTATION_H
