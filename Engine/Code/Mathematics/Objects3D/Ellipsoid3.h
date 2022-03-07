///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.2 (2022/02/10 15:31)

#ifndef MATHEMATICS_OBJECTS3D_ELLIPSOID3_H
#define MATHEMATICS_OBJECTS3D_ELLIPSOID3_H

#include "Mathematics/MathematicsDll.h"

#include "Ellipsoid3Coefficients.h"
#include "Mathematics/Algebra/Vector3.h"

#include <type_traits>

namespace Mathematics
{
    template <typename Real>
    class Ellipsoid3 final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Ellipsoid3<Real>;
        using Math = Math<Real>;
        using Vector3 = Vector3<Real>;
        using Matrix3 = Matrix3<Real>;
        using Ellipsoid3Coefficients = Ellipsoid3Coefficients<Real>;
        using Vector3Tools = Vector3Tools<Real>;

    public:
        // ��Բ��������K���᷽��U[0], U[1], �� U[2]�����е�λ������������
        // ����չe[0], e[1], �� e[2]��ȫ����������
        // ��X = K + y[0] * U[0] + y[1] * U[1] + y[2] * U[2]������Բ���ϣ�
        // ����Ϊ�������ڲ��ĵ��á�<=�������桰=������ǰ�ı��ʽ�С�
        // ������Ĵ�����ʾ��
        //   1 = (X-K)^T * (U[0] * U[0]^T / e[0]^2 + U[1] * U[1]^T / e[1]^2 +
        //                  U[2] * U[2]^T / e[2]^2) * (X - K)
        //     = (X-K)^T * M * (X - K)
        // ���У��ϱ�T��ʾת�á��۲쵽U[i] * U[i]^T��һ�����󣬶����Ǳ�������
        // ����M�ǶԳƵġ�������Ҳ��һԪ���η��̱�ʾ
        //   0 = a0 + a1 * x[0] + a2 * x[1] + a3 * x[2] + a4 * x[0]^2 + a5 * x[0] * x[1] +
        //       a6 * x[0] * x[2] + a7 * x[1]^2 + a8 * x[1] * x[2] + a9 * x[2]^2
        //     = a0 + [a1 a2 a3] * X + X^T * [a4     a5 / 2 a6 / 2] * X
        //                                   [a5 / 2 a7     a8 / 2]
        //                                   [a6 / 2 a8 / 2 a9  ]
        //     = C + B^T * X + X^T * A * X
        // ����X = (x[0],x[1],x[2])�������ʽ���Ա��ֽ⵽(X-K)^T * M * (X - K) = 1��
        // ����K = -A^{-1} * B / 2, M = A / (B^T * A^{-1} * B / 4 - C)��
        // Ϊ��Բ��ʱ��M���������������ֵΪ����
        Ellipsoid3(const Vector3& center,
                   const Vector3& axis0,
                   const Vector3& axis1,
                   const Vector3& axis2,
                   const Real extent0,
                   const Real extent1,
                   const Real extent2,
                   const Real epsilon = Math::GetZeroTolerance()) noexcept;

        explicit Ellipsoid3(const Ellipsoid3Coefficients& coefficients, const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_DECLARE;

        NODISCARD Vector3 GetCenter() const noexcept;
        NODISCARD Vector3 GetAxis0() const noexcept;
        NODISCARD Vector3 GetAxis1() const noexcept;
        NODISCARD Vector3 GetAxis2() const noexcept;
        NODISCARD Real GetExtent0() const noexcept;
        NODISCARD Real GetExtent1() const noexcept;
        NODISCARD Real GetExtent2() const noexcept;

        // ���� M = sum_{i = 0}^2 U[i] * U[i]^T/e[i]^2.
        NODISCARD Matrix3 GetMatrix() const;

        // ���� M^{-1} = sum_{i = 0}^2 U[i] * U[i]^T * e[i]^2.
        NODISCARD Matrix3 GetMatrixInverse() const;

        // �������η���ʽ����ʾ��Բ���ϵ����
        NODISCARD Ellipsoid3Coefficients ToCoefficients() const;

        // ����m_Center��m_Axis��m_Extent�Ӷ��η��̡�
        // �������ϵ�����ܱ�ʾһ����Բ�壬���׳��쳣��
        void FromCoefficients(const Ellipsoid3Coefficients& coefficients, const Real newEpsilon = Math::GetZeroTolerance());

        // ����Ķ��κ��� Q(X) = (X-K)^T * M * (X-K) - 1.
        NODISCARD Real Evaluate(const Vector3& point) const;

        // ����������Ƿ�����Բ���ڲ�����ϡ�
        // �õ㱻������Q(X) <= 0������Q(X)Ϊ����Evaluate()��
        NODISCARD bool Contains(const Vector3& point) const;

        NODISCARD Ellipsoid3 GetMove(Real t, const Vector3& velocity) const;

    private:
        static constexpr auto axisSize = 3;
        using AxisType = std::array<Vector3, axisSize>;
        using ExtentType = std::array<Real, axisSize>;

    private:
        Vector3 center;
        AxisType axis;
        ExtentType extent;

        Real epsilon;
    };

    template <typename Real>
    NODISCARD bool Approximate(const Ellipsoid3<Real>& lhs, const Ellipsoid3<Real>& rhs, const Real epsilon);

    // �������
    template <typename Real>
    std::ostream& operator<<(std::ostream& outFile, const Ellipsoid3<Real>& ellipsoid);

    using Ellipsoid3F = Ellipsoid3<float>;
    using Ellipsoid3D = Ellipsoid3<double>;
}

#endif  // MATHEMATICS_OBJECTS3D_ELLIPSOID3_H
