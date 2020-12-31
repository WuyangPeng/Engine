///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.3 (2020/11/16 12:50)

#ifndef MATHEMATICS_OBJECTS2D_ELLIPSE2_H
#define MATHEMATICS_OBJECTS2D_ELLIPSE2_H

#include "Mathematics/MathematicsDll.h"

#include "Ellipse2Coefficients.h"
#include "Mathematics/Algebra/Matrix2.h"
#include "Mathematics/Algebra/Vector2D.h"
#include "Mathematics/Algebra/Vector2DTools.h"
#include "Mathematics/Base/MathDetail.h"

#include <type_traits>
#include <vector>

namespace Mathematics
{
    template <typename Real>
    class Ellipse2Impl;

    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<Ellipse2Impl<float>>;
    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<Ellipse2Impl<double>>;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<Ellipse2Impl<Real>>;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Ellipse2 final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using Ellipse2Impl = Ellipse2Impl<Real>;
        DELAY_COPY_UNSHARE_CLASSES_TYPE_DECLARE(Ellipse2);
       
        using Math = Math<Real>;
        using Vector2D = Vector2D<Real>;
        using Matrix2 = Matrix2<Real>;
        using Ellipse2Coefficients = Ellipse2Coefficients<Real>;
        using Vector2DTools = Vector2DTools<Real>;

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

        Ellipse2(const Vector2D& center, const Vector2D& axis0, const Vector2D& axis1,
                 const Real extent0, const Real extent1, const Real epsilon = Math::GetZeroTolerance());

        explicit Ellipse2(const Ellipse2Coefficients& coefficients, const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] const Vector2D GetCenter() const noexcept;
        [[nodiscard]] const Vector2D GetAxis0() const noexcept;
        [[nodiscard]] const Vector2D GetAxis1() const noexcept;
        [[nodiscard]] Real GetExtent0() const noexcept;
        [[nodiscard]] Real GetExtent1() const noexcept;

        // ���� M = sum_{i=0}^1 U[i]*U[i]^T/e[i]^2.
        [[nodiscard]] const Matrix2 GetMatrix() const;

        // ���� M^{-1} = sum_{i=0}^1 U[i]*U[i]^T*e[i]^2.
        [[nodiscard]] const Matrix2 GetMatrixInverse() const;

        // �������η���ʽ����ʾ��Բ��ϵ����
        [[nodiscard]] const Ellipse2Coefficients ToCoefficients() const;

        // ����m_Center��m_Axis��m_Extent�Ӷ��η��̡�
        // �������ϵ�����ܱ�ʾһ����Բ�����׳��쳣��
        void FromCoefficients(const Ellipse2Coefficients& coefficients, const Real epsilon = Math::GetZeroTolerance());

        // ����Ķ��κ��� Q(X) = (X-K)^T * M * (X-K) - 1.
        [[nodiscard]] Real Evaluate(const Vector2D& point) const;

        // ����������Ƿ�����Բ���ڲ�����ϡ�
        // �õ㱻������Q(X) <= 0������Q(X)����Evaluate()��
        [[nodiscard]] bool Contains(const Vector2D& point) const;

        [[nodiscard]] const Ellipse2 GetMove(Real t, const Vector2D& velocity) const;

    private:
        IMPL_TYPE_DECLARE(Ellipse2);
    };

    template <typename Real>
    [[nodiscard]] bool Approximate(const Ellipse2<Real>& lhs, const Ellipse2<Real>& rhs, const Real epsilon);

    // �������
    template <typename Real>
    std::ostream& operator<<(std::ostream& outFile, const Ellipse2<Real>& line);

    using FloatEllipse2 = Ellipse2<float>;
    using DoubleEllipse2 = Ellipse2<double>;
}

#endif  // MATHEMATICS_OBJECTS2D_ELLIPSE2_H
