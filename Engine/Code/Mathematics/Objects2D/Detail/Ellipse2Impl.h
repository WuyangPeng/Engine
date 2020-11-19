///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.3 (2020/11/16 11:40)

#ifndef MATHEMATICS_OBJECTS2D_ELLIPSE2_IMPL_H
#define MATHEMATICS_OBJECTS2D_ELLIPSE2_IMPL_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Matrix2.h"
#include "Mathematics/Algebra/Vector2D.h"
#include "Mathematics/Algebra/Vector2DTools.h"
#include "Mathematics/Base/MathDetail.h"
#include "Mathematics/Objects2D/Ellipse2Coefficients.h"

#include <type_traits>
#include <vector>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_HIDDEN_DECLARE Ellipse2Impl final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Ellipse2Impl<Real>;
        using Math = Math<Real>;
        using Vector2D = Vector2D<Real>;
        using Matrix2 = Matrix2<Real>;
        using Vector2DTools = Vector2DTools<Real>;
        using Ellipse2Coefficients = Ellipse2Coefficients<Real>;

    public:
        Ellipse2Impl(const Vector2D& center, const Vector2D& axis0, const Vector2D& axis1,
                     const Real extent0, const Real extent1, const Real epsilon = Math::GetZeroTolerance()) noexcept;

        explicit Ellipse2Impl(const Ellipse2Coefficients& coefficients, const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] const Vector2D GetCenter() const noexcept;
        [[nodiscard]] const Vector2D GetAxis0() const noexcept;
        [[nodiscard]] const Vector2D GetAxis1() const noexcept;
        [[nodiscard]] Real GetExtent0() const noexcept;
        [[nodiscard]] Real GetExtent1() const noexcept;
        [[nodiscard]] Real GetEpsilon() const noexcept;

        // ���� M = sum_{i=0}^1 U[i]*U[i]^T/e[i]^2.
        [[nodiscard]] const Matrix2 GetMatrix() const;

        // ���� M^{-1} = sum_{i=0}^1 U[i]*U[i]^T*e[i]^2.
        [[nodiscard]] const Matrix2 GetMatrixInverse() const;

        // �������η���ʽ����ʾ��Բ��ϵ����
        [[nodiscard]] const Ellipse2Coefficients ToCoefficients() const;

        // ����m_Center��m_Axis��m_Extent�Ӷ��η��̡�
        // �������ϵ�����ܱ�ʾһ����Բ�����׳��쳣��
        [[nodiscard]] void FromCoefficients(const Ellipse2Coefficients& coefficients, const Real epsilon = Math::GetZeroTolerance());

        // ����Ķ��κ��� Q(X) = (X-K)^T * M * (X-K) - 1.
        [[nodiscard]] Real Evaluate(const Vector2D& point) const;

        // ����������Ƿ�����Բ���ڲ�����ϡ�
        // �õ㱻������Q(X) <= 0������Q(X)����Evaluate()��
        [[nodiscard]] bool Contains(const Vector2D& point) const;

    private:
        static constexpr auto sm_AxisSize = 2;
        using AxisType = std::array<Vector2D, sm_AxisSize>;
        using ExtentType = std::array<Real, sm_AxisSize>;

    private:
        Vector2D m_Center;
        AxisType m_Axis;
        ExtentType m_Extent;
        Real m_Epsilon;
    };
}

#endif  // MATHEMATICS_OBJECTS2D_ELLIPSE2_IMPL_H
