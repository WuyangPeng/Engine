///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.4 (2020/11/24 18:27)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_GAUSSIAN_QUADRATURE_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_GAUSSIAN_QUADRATURE_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Base/MathDetail.h"

#include <type_traits>

namespace Mathematics
{
    template <typename Real, typename UserDataType>
    class GaussianQuadrature final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = GaussianQuadrature<Real, UserDataType>;
        using Math = Math<Real>;

        // 最后一个参数是用户定义的数据。
        using Function = Real (*)(Real, const UserDataType*);

    public:
        GaussianQuadrature(Real begin, Real end, Function function, const UserDataType* userData) noexcept;

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] Real GetResult() const noexcept;

    private:
        void Calculate() noexcept;

    private:
        Real m_Radius;
        Real m_Center;
        Function m_Function;
        const UserDataType* m_UserData;
        Real m_Result;
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_GAUSSIAN_QUADRATURE_H
