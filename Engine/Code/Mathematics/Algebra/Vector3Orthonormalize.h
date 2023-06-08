///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.11 (2023/06/01 10:28)

#ifndef MATHEMATICS_ALGEBRA_VECTOR3_ORTHONORMALIZE_H
#define MATHEMATICS_ALGEBRA_VECTOR3_ORTHONORMALIZE_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"
#include "Vector3.h"
#include "Mathematics/Base/MathDetail.h"

#include <type_traits>
#include <vector>

namespace Mathematics
{
    template <typename Real, bool Robust = false>
    requires std::is_arithmetic_v<Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Vector3Orthonormalize final
    {
    public:
        using ClassType = Vector3Orthonormalize<Real, Robust>;
        using Math = Math<Real>;
        using Vector3 = Vector3<Real>;
        using Vector3Tools = Vector3Tools<Real>;
        using ContainerType = std::vector<Vector3>;

    public:
        // Gram-Schmidt������.
        // �������޹ص�����U��V��W��������һ�������飨��λ���ȣ��໥��ֱ����
        Vector3Orthonormalize(const Vector3& uVector, const Vector3& vVector, const Vector3& wVector, const Real epsilon = Math::GetZeroTolerance());

        explicit Vector3Orthonormalize(const ContainerType& vectors, const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_DECLARE;

        NODISCARD const Vector3 GetUVector() const noexcept;
        NODISCARD const Vector3 GetVVector() const noexcept;
        NODISCARD const Vector3 GetWVector() const noexcept;

    private:
        void Generate();

    private:
        Vector3 uVector;
        Vector3 vVector;
        Vector3 wVector;
        Real epsilon;
    };

    using Vector3OrthonormalizeF = Vector3Orthonormalize<float>;
    using Vector3OrthonormalizeD = Vector3Orthonormalize<double>;
}

#endif  // MATHEMATICS_ALGEBRA_VECTOR3_ORTHONORMALIZE_H
