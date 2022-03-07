///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.2 (2022/02/01 23:45)

#ifndef MATHEMATICS_ALGEBRA_VECTOR2_ORTHONORMALIZE_H
#define MATHEMATICS_ALGEBRA_VECTOR2_ORTHONORMALIZE_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"
#include "Vector2.h"
#include "Mathematics/Base/MathDetail.h"

#include <type_traits>

namespace Mathematics
{
    template <typename Real, bool Robust = false>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Vector2Orthonormalize final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Vector2Orthonormalize<Real, Robust>;
        using Math = Math<Real>;
        using Vector2 = Vector2<Real>;
        using Vector2Tools = Vector2Tools<Real>;

    public:
        // Gram-Schmidt������.
        // �������޹ص�����U��V��������һ�������飨��λ���ȣ��໥��ֱ����
        Vector2Orthonormalize(const Vector2& lhs, const Vector2& rhs, const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_DECLARE;

        NODISCARD const Vector2 GetUVector() const noexcept;
        NODISCARD const Vector2 GetVVector() const noexcept;

    private:
        void Generate();

    private:
        Vector2 uVector;
        Vector2 vVector;
        Real epsilon;
    };

    using Vector2OrthonormalizeF = Vector2Orthonormalize<float>;
    using Vector2OrthonormalizeD = Vector2Orthonormalize<double>;
}

#endif  // MATHEMATICS_ALGEBRA_VECTOR2_ORTHONORMALIZE_H
