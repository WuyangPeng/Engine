///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.2 (2020/11/12 14:26)

#ifndef MATHEMATICS_ALGEBRA_VECTOR_2D_ORTHONORMALIZE_H
#define MATHEMATICS_ALGEBRA_VECTOR_2D_ORTHONORMALIZE_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"
#include "Vector2D.h"
#include "Mathematics/Base/MathDetail.h"

#include <type_traits>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Vector2DOrthonormalize final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Vector2DOrthonormalize<Real>;
        using Math = Math<Real>;
        using Vector2D = Vector2D<Real>;
        using Vector2DTools = Vector2DTools<Real>;

    public:
        // Gram-Schmidt������.
        // �������޹ص�����U��V��������һ�������飨��λ���ȣ��໥��ֱ����
        Vector2DOrthonormalize(const Vector2D& lhs, const Vector2D& rhs, const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] const Vector2D GetUVector() const noexcept;
        [[nodiscard]] const Vector2D GetVVector() const noexcept;

    private:
        void Generate();

    private:
        Vector2D m_UVector;
        Vector2D m_VVector;
        Real m_Epsilon;
    };

    using FloatVector2DOrthonormalize = Vector2DOrthonormalize<float>;
    using DoubleVector2DOrthonormalize = Vector2DOrthonormalize<double>;
}

#endif  // MATHEMATICS_ALGEBRA_VECTOR_2D_ORTHONORMALIZE_H
