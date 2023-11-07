///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/27 11:36)

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

        // ���һ���������û���������ݡ�
        using Function = Real (*)(Real, const UserDataType*) noexcept;

    public:
        GaussianQuadrature(Real begin, Real end, Function function, const UserDataType* userData) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD Real GetResult() const noexcept;

    private:
        void Calculate() noexcept;

    private:
        Real radius;
        Real center;
        Function function;
        const UserDataType* userData;
        Real result;
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_GAUSSIAN_QUADRATURE_H
