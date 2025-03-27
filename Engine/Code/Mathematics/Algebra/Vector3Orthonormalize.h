///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/26 15:17)

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

        using MathType = Math<Real>;
        using Vector3Type = Vector3<Real>;
        using Vector3ToolsType = Vector3Tools<Real>;
        using ContainerType = std::vector<Vector3Type>;

    public:
        // Gram-Schmidt������.
        // �������޹ص�����U��V��W��������һ�������飨��λ���ȣ��໥��ֱ����
        Vector3Orthonormalize(const Vector3Type& uVector, const Vector3Type& vVector, const Vector3Type& wVector, const Real epsilon = MathType::GetZeroTolerance());

        explicit Vector3Orthonormalize(const ContainerType& vectors, const Real epsilon = MathType::GetZeroTolerance());

        CLASS_INVARIANT_DECLARE;

        NODISCARD Vector3Type GetUVector() const noexcept;
        NODISCARD Vector3Type GetVVector() const noexcept;
        NODISCARD Vector3Type GetWVector() const noexcept;

    private:
        void Generate();

    private:
        Vector3Type uVector;
        Vector3Type vVector;
        Vector3Type wVector;
        Real epsilon;
    };

    using Vector3OrthonormalizeF = Vector3Orthonormalize<float>;
    using Vector3OrthonormalizeD = Vector3Orthonormalize<double>;
}

#endif  // MATHEMATICS_ALGEBRA_VECTOR3_ORTHONORMALIZE_H
