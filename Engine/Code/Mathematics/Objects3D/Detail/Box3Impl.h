///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.3 (2020/11/16 13:43)

#ifndef MATHEMATICS_OBJECTS3D_BOX3_IMPL_H
#define MATHEMATICS_OBJECTS3D_BOX3_IMPL_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector3D.h"
#include "Mathematics/Base/MathDetail.h"

#include <type_traits>
#include <vector>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_HIDDEN_DECLARE Box3Impl final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Box3Impl<Real>;
        using Math = Math<Real>;
        using Vector3D = Vector3D<Real>;
        using VerticesType = std::vector<Vector3D>;

    public:
        // һ�����������ĵ�C���᷽��U[0]��U[1]��U[2]����ֱ�͵�λ���ȵ���������
        // �ͷ�Χe[0]��e[1]��e[2]���Ǹ�������
        // A point X = C + y[0] * U[0] + y[1] * U[1] + y[2] * U[2]�����ڲ����ں����ϣ�
        // ÿ��|y[i]| <= e[i]�������е�i
        Box3Impl() noexcept;
        Box3Impl(const Vector3D& center, const Vector3D& axis0, const Vector3D& axis1, const Vector3D& axis2,
                 const Real extent0, const Real extent1, const Real extent2, const Real epsilon = Math::GetZeroTolerance()) noexcept;

        CLASS_INVARIANT_DECLARE;

        // ���صĶ�����Ϊ8
        [[nodiscard]] const VerticesType ComputeVertices() const;
        [[nodiscard]] const Vector3D GetCenter() const noexcept;

        [[nodiscard]] const Vector3D GetAxis0() const noexcept;
        [[nodiscard]] const Vector3D GetAxis1() const noexcept;
        [[nodiscard]] const Vector3D GetAxis2() const noexcept;
        [[nodiscard]] const Vector3D GetAxis(int index) const;

        [[nodiscard]] Real GetExtent0() const noexcept;
        [[nodiscard]] Real GetExtent1() const noexcept;
        [[nodiscard]] Real GetExtent2() const noexcept;
        [[nodiscard]] Real GetExtent(int index) const;

        [[nodiscard]] Real GetEpsilon() const noexcept;

        void Set(const Vector3D& center, const Vector3D& axis0, const Vector3D& axis1, const Vector3D& axis2,
                 const Real extent0, const Real extent1, const Real extent2) noexcept;

    private:
        static constexpr auto sm_AxisSize = 3;

        using AxisType = std::array<Vector3D, sm_AxisSize>;
        using ExtentType = std::array<Real, sm_AxisSize>;

    private:
        Vector3D m_Center;
        AxisType m_Axis;
        ExtentType m_Extent;
        Real m_Epsilon;
    };
}

#endif  // MATHEMATICS_OBJECTS3D_BOX3_IMPL_H
