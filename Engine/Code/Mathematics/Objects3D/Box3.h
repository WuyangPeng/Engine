///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.3 (2020/11/16 14:03)

#ifndef MATHEMATICS_OBJECTS3D_BOX3_H
#define MATHEMATICS_OBJECTS3D_BOX3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector3D.h"
#include "Mathematics/Base/MathDetail.h"

#include <type_traits>
#include <vector>

namespace Mathematics
{
    template <typename Real>
    class Box3Impl;

    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<Box3Impl<float>>;
    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<Box3Impl<double>>;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<Box3Impl<Real>>;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Box3 final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using Box3Impl = Box3Impl<Real>;
        DELAY_COPY_UNSHARE_CLASSES_TYPE_DECLARE(Box3);

        using Math = Math<Real>;
        using Vector3D = Vector3D<Real>;
        using VerticesType = std::vector<Vector3D>;

    public:
        // һ�����������ĵ�C���᷽��U[0]��U[1]��U[2]����ֱ�͵�λ���ȵ���������
        // �ͷ�Χe[0]��e[1]��e[2]���Ǹ�������
        // A point X = C + y[0] * U[0] + y[1] * U[1] + y[2] * U[2]�����ڲ����ں����ϣ�
        // ÿ��|y[i]| <= e[i]�������е�i
        Box3();
        Box3(const Vector3D& center, const Vector3D& axis0, const Vector3D& axis1, const Vector3D& axis2,
             const Real extent0, const Real extent1, const Real extent2, const Real epsilon = Math::GetZeroTolerance());

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

        [[nodiscard]] const Box3 GetMove(Real t, const Vector3D& velocity) const;

        void Set(const Vector3D& center, const Vector3D& axis0, const Vector3D& axis1, const Vector3D& axis2,
                 const Real extent0, const Real extent1, const Real extent2);

    private:
        IMPL_TYPE_DECLARE(Box3);
    };

    using FloatBox3 = Box3<float>;
    using DoubleBox3 = Box3<double>;

    template <typename Real>
    [[nodiscard]] bool Approximate(const Box3<Real>& lhs, const Box3<Real>& rhs, const Real epsilon);

    // �������
    template <typename Real>
    std::ostream& operator<<(std::ostream& outFile, const Box3<Real>& box);
}

#endif  // MATHEMATICS_OBJECTS3D_BOX3_H
