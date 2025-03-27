/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/12 11:17)

#ifndef MATHEMATICS_OBJECTS_2D_ELLIPSE2_H
#define MATHEMATICS_OBJECTS_2D_ELLIPSE2_H

#include "Mathematics/MathematicsDll.h"

#include "Ellipse2Coefficients.h"
#include "CoreTools/Helper/Export/DelayCopyUnsharedMacro.h"
#include "Mathematics/Algebra/Matrix2.h"
#include "Mathematics/Algebra/Vector2.h"
#include "Mathematics/Algebra/Vector2Tools.h"
#include "Mathematics/Base/MathDetail.h"

namespace Mathematics
{
    template <typename Real>
    class Ellipse2 final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Ellipse2<Real>;

        using MathType = Math<Real>;
        using Vector2Type = Vector2<Real>;
        using Matrix2Type = Matrix2<Real>;
        using Ellipse2CoefficientsType = Ellipse2Coefficients<Real>;
        using Vector2ToolsType = Vector2Tools<Real>;

    public:
        // ��Բ��������K���᷽��U[0]��U[1]���������ǵ�λ������������
        // ����չe[0] �� e[1]���������Ǿ�Ϊ��������
        // ��X = K + y[0] * U[0] + y[1] * U[1]����Բʱ��
        // ��(y[0] / e[0])^2 + (y[1] / e[1])^2 = 1��
        // ��������Բ�ڲ��ĵ�ʹ�á�<=�����桰=����
        // ��Բ�Ĵ�����ʾ��
        //   1 = (X-K)^T * (U[0] * U[0]^T / e[0]^2 + U[1 ]* U[1]^T / e[1]^2) * (X-K)
        //     = (X-K)^T * M * (X-K)
        // ���У��ϱ�T��ʾת�á��۲쵽U[i] * U[i]^T��һ�����󣬶����Ǳ�������
        // ����M�ǶԳƵġ���ԲҲ��һԪ���η��̱�ʾ
        //   0 = a0 + a1 * x[0] + a2 * x[1] + a3 * x[0]^2 + a4 * x[0]*x[1] + a5 * x[1]^2
        //     = a0 + [a1 a2] * X + X^T * [a3   a4 / 2] * X
        //                                [a4 / 2 a5  ]
        //     = C + B^T * X + X^T * A * X
        // ����X = (x[0],x[1])�������ʽ���Ա��ֽ⵽(X - K)^T * M * (X - K) = 1��
        // ����K = -A^{-1} * B / 2, M = A / (B^T * A^{-1} * B / 4 - C)��
        // Ϊ��Բ��ʱ��M���������������ֵΪ����

        Ellipse2(const Vector2Type& center,
                 const Vector2Type& axis0,
                 const Vector2Type& axis1,
                 const Real extent0,
                 const Real extent1,
                 const Real epsilon = MathType::GetZeroTolerance()) noexcept;

        explicit Ellipse2(const Ellipse2CoefficientsType& coefficients, const Real epsilon = MathType::GetZeroTolerance());

        CLASS_INVARIANT_DECLARE;

        NODISCARD Vector2Type GetCenter() const noexcept;
        NODISCARD Vector2Type GetAxis0() const noexcept;
        NODISCARD Vector2Type GetAxis1() const noexcept;
        NODISCARD Real GetExtent0() const noexcept;
        NODISCARD Real GetExtent1() const noexcept;

        // ���� M = sum_{i=0}^1 U[i]*U[i]^T/e[i]^2.
        NODISCARD Matrix2Type GetMatrix() const;

        // ���� M^{-1} = sum_{i=0}^1 U[i]*U[i]^T*e[i]^2.
        NODISCARD Matrix2Type GetMatrixInverse() const;

        // �������η���ʽ����ʾ��Բ��ϵ����
        NODISCARD Ellipse2CoefficientsType ToCoefficients() const;

        // ����m_Center��m_Axis��m_Extent�Ӷ��η��̡�
        // �������ϵ�����ܱ�ʾһ����Բ�����׳��쳣��
        void FromCoefficients(const Ellipse2CoefficientsType& coefficients, const Real newEpsilon = MathType::GetZeroTolerance());

        // ����Ķ��κ��� Q(X) = (X-K)^T * M * (X-K) - 1.
        NODISCARD Real Evaluate(const Vector2Type& point) const;

        // ����������Ƿ�����Բ���ڲ�����ϡ�
        // �õ㱻������Q(X) <= 0������Q(X)����Evaluate()��
        NODISCARD bool Contains(const Vector2Type& point) const;

        NODISCARD Ellipse2 GetMove(Real t, const Vector2Type& velocity) const;

    private:
        static constexpr auto axisSize = 2;
        using AxisType = std::array<Vector2Type, axisSize>;
        using ExtentType = std::array<Real, axisSize>;

    private:
        Vector2Type center;
        AxisType axis;
        ExtentType extent;
        Real epsilon;
    };

    template <typename Real>
    NODISCARD bool Approximate(const Ellipse2<Real>& lhs, const Ellipse2<Real>& rhs, Real epsilon);

    // �������
    template <typename Real>
    std::ostream& operator<<(std::ostream& outFile, const Ellipse2<Real>& line);

    using Ellipse2F = Ellipse2<float>;
    using Ellipse2D = Ellipse2<double>;
}

#endif  // MATHEMATICS_OBJECTS_2D_ELLIPSE2_H
