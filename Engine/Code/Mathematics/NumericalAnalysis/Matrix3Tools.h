///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/27 11:38)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_MATRIX3_TOOLS_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_MATRIX3_TOOLS_H

#include "Mathematics/MathematicsDll.h"

#include "PolarDecompositionValue.h"
#include "QDUDecompositionValue.h"
#include "SingularValue.h"
#include "Mathematics/Algebra/Matrix3.h"
#include "Mathematics/MathematicsFwd.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Matrix3Tools final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Matrix3Tools<Real>;

        using Matrix3 = Matrix3<Real>;
        using QDUDecompositionValue = QDUDecompositionValue<Real>;
        using SingularValue = SingularValue<Real>;
        using PolarDecompositionValue = PolarDecompositionValue<Real>;

    public:
        explicit Matrix3Tools(const Matrix3& matrix) noexcept;

        CLASS_INVARIANT_DECLARE;

    public:
        // ����ֵ�ֽ⣬M = L * D * Transpose(Real)������L��Real�������ģ�
        // D�ǶԽǾ�����Խ�Ԫ���ǷǸ��ġ�
        // ����ֵ��һ����Ϊleft, �ڶ�����Ϊdiag,��������ΪrightTranspose
        NODISCARD SingularValue SingularValueDecomposition() const;

        // ���ֽ⣬M = Q * S������Q�������ģ�S�ǶԳƵġ�
        // ����ʹ������ֵ�ֽ⣺
        // M = L * D * Transpose(Real) = (L * Transpose(Real)) * (Real * D * Transpose(Real)) = Q * S
        // ����Q = L * Transpose(Real)��S = Real * D * Transpose(Real)��
        // ����ֵ��һ����ΪQ���ڶ�����ΪS
        NODISCARD PolarDecompositionValue PolarDecomposition() const;

        // ϵ��M = Q * D * Uʹ����������Q���ԽǾ���D�������Ǿ���U��
        // ����ֵ��һ����ΪQ���ڶ�����ΪD����������ΪU
        NODISCARD QDUDecompositionValue QDUDecomposition() const;

    private:
        Matrix3 matrix;
    };

    using Matrix3ToolsF = Matrix3Tools<float>;
    using Matrix3ToolsD = Matrix3Tools<double>;
}

#endif  // MATHEMATICS_ALGEBRA_MATRIX3_TOOLS_H
