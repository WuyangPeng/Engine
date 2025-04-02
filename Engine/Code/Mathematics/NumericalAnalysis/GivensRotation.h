///	Copyright (c) 2010-2024
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.6 (2024/02/29 15:35)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_GIVENS_ROTATION_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_GIVENS_ROTATION_H

#include "Mathematics/MathematicsDll.h"

#include <type_traits>

namespace Mathematics
{
    /// Givens旋转用于将初始三对角矩阵简化为对角矩阵。
    /// 旋转与以下替换项相同：R(index,index) = cs、R(index,index+1) = sn, R(index+1,index) = -sn和R(index+1,index+1) = cs。
    /// 如果N是矩阵大小，K是最大迭代次数，则Givens旋转的最大次数为K*(N-1)。
    /// 分配的最大内存量用于存储这些内容。
    template <typename Real>
    requires(std::is_arithmetic_v<Real>)
    class GivensRotation
    {
    public:
        using ClassType = GivensRotation<Real>;

    public:
        GivensRotation() noexcept;
        GivensRotation(int index, Real cs, Real sn) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetIndex() const noexcept;
        void SetIndex(int aIndex) noexcept;
        NODISCARD Real GetCs() const noexcept;
        void SetCs(Real aCs) noexcept;
        NODISCARD Real GetSn() const noexcept;
        void SetSn(Real aSn) noexcept;

    private:
        int index;
        Real cs;
        Real sn;
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_GIVENS_ROTATION_H
