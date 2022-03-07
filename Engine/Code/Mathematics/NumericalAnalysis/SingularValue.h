///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.2 (2022/02/17 11:38)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_SINGULAR_VALUE_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_SINGULAR_VALUE_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Matrix3.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE SingularValue final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = SingularValue<Real>;
        using Matrix3 = Matrix3<Real>;

    public:
        explicit SingularValue(const Matrix3& matrix);

        CLASS_INVARIANT_DECLARE;

    public:
        NODISCARD Matrix3 GetLeftMatrix() const noexcept;
        NODISCARD Matrix3 GetDiagonalMatrix() const noexcept;
        NODISCARD Matrix3 GetRightTransposeMatrix() const noexcept;

    private:
        void Calculate(const Matrix3& matrix);

    private:
        Matrix3 left;
        Matrix3 diagonal;
        Matrix3 rightTranspose;
    };

    using SingularValueF = SingularValue<float>;
    using SingularValueD = SingularValue<double>;
}

#endif  // MATHEMATICS_ALGEBRA_MATRIX3_TOOLS_H
