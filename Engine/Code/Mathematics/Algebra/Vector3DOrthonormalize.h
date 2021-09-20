///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.2 (2020/11/12 20:36)

#ifndef MATHEMATICS_ALGEBRA_VECTOR_3D_ORTHONORMALIZE_H
#define MATHEMATICS_ALGEBRA_VECTOR_3D_ORTHONORMALIZE_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"
#include "Vector3D.h"
#include "Mathematics/Base/MathDetail.h"

#include <type_traits>
#include <vector>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Vector3DOrthonormalize final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Vector3DOrthonormalize<Real>;
        using Math = Math<Real>;
        using Vector3D = Vector3D<Real>;
        using Vector3DTools = Vector3DTools<Real>;
        using ContainerType = std::vector<Vector3D>;

    public:
        // Gram-Schmidt������.
        // �������޹ص�����U��V��W��������һ�������飨��λ���ȣ��໥��ֱ����
        Vector3DOrthonormalize(const Vector3D& lhs, const Vector3D& mhs, const Vector3D& rhs, const Real epsilon = Math::GetZeroTolerance());

        explicit Vector3DOrthonormalize(const ContainerType& vectors, const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] const Vector3D GetUVector() const noexcept;
        [[nodiscard]] const Vector3D GetVVector() const noexcept;
        [[nodiscard]] const Vector3D GetWVector() const noexcept;

    private:
        void Generate();

    private:
        Vector3D m_UVector;
        Vector3D m_VVector;
        Vector3D m_WVector;
        Real m_Epsilon;
    };

    using FloatVector3DOrthonormalize = Vector3DOrthonormalize<float>;
    using DoubleVector3DOrthonormalize = Vector3DOrthonormalize<double>;
}

#endif  // MATHEMATICS_ALGEBRA_VECTOR_3D_ORTHONORMALIZE_H
