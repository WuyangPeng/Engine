///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.2 (2020/11/12 20:35)

#ifndef MATHEMATICS_ALGEBRA_VECTOR_3D_ORTHONORMA_BASIS_H
#define MATHEMATICS_ALGEBRA_VECTOR_3D_ORTHONORMA_BASIS_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"
#include "Vector3D.h"
#include "Mathematics/Base/MathDetail.h"

#include <type_traits>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Vector3DOrthonormalBasis final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Vector3DOrthonormalBasis<Real>;
        using Vector3D = Vector3D<Real>;
        using Vector3DTools = Vector3DTools<Real>;
        using Math = Math<Real>;

    public:
        explicit Vector3DOrthonormalBasis(const Vector3D& nonzeroVector, bool isUnit, const Real epsilon = Math::GetZeroTolerance()) noexcept(g_Assert < 1 || g_MathematicsAssert < 1);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] const Vector3D GetUVector() const noexcept;
        [[nodiscard]] const Vector3D GetVVector() const noexcept;
        [[nodiscard]] const Vector3D GetWVector() const noexcept;

    private:
        void Generate() noexcept(g_Assert < 1 || g_MathematicsAssert < 1);
        void GenerateOnXOrZIsMax() noexcept(g_Assert < 3 || g_MathematicsAssert < 3);
        void GenerateOnYOrZIsMax() noexcept(g_Assert < 3 || g_MathematicsAssert < 3);

    private:
        bool m_IsUnit;
        Vector3D m_UVector;
        Vector3D m_VVector;
        Vector3D m_WVector;
        Real m_Epsilon;
    };

    using FloatVector3DOrthonormalBasis = Vector3DOrthonormalBasis<float>;
    using DoubleVector3DOrthonormalBasis = Vector3DOrthonormalBasis<double>;
}

#endif  // MATHEMATICS_ALGEBRA_VECTOR_3D_ORTHONORMA_BASIS_H
