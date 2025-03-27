///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/26 15:15)

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
    requires std::is_arithmetic_v<Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Vector2Orthonormalize final
    {
    public:
        using ClassType = Vector2Orthonormalize<Real, Robust>;

        using MathType = Math<Real>;
        using Vector2Type = Vector2<Real>;
        using Vector2ToolsType = Vector2Tools<Real>;

    public:
        // Gram-Schmidt������.
        // �������޹ص�����U��V��������һ�������飨��λ���ȣ��໥��ֱ����
        Vector2Orthonormalize(const Vector2Type& lhs, const Vector2Type& rhs, const Real epsilon = MathType::GetZeroTolerance());

        CLASS_INVARIANT_DECLARE;

        NODISCARD const Vector2Type GetUVector() const noexcept;
        NODISCARD const Vector2Type GetVVector() const noexcept;

    private:
        void Generate();

    private:
        Vector2Type uVector;
        Vector2Type vVector;
        Real epsilon;
    };

    using Vector2OrthonormalizeF = Vector2Orthonormalize<float>;
    using Vector2OrthonormalizeD = Vector2Orthonormalize<double>;
}

#endif  // MATHEMATICS_ALGEBRA_VECTOR2_ORTHONORMALIZE_H
