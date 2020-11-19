///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.3 (2020/11/16 17:45)

#ifndef MATHEMATICS_OBJECTS3D_SPHERE3_H
#define MATHEMATICS_OBJECTS3D_SPHERE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector3D.h"

#include <type_traits>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Sphere3 final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Sphere3<Real>;
        using Math = Math<Real>;
        using Vector3D = Vector3D<Real>;

    public:
        // ���屻��ʾΪ|X-C| = Real������CΪ���ģ�RealΪ�뾶��
        Sphere3(const Vector3D& center, Real radius) noexcept;
        Sphere3() noexcept;

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] const Vector3D GetCenter() const noexcept;
        [[nodiscard]] Real GetRadius() const noexcept;

        void SetSphere(const Vector3D& center, Real radius) noexcept;

    private:
        Vector3D m_Center;
        Real m_Radius;
    };

    using FloatSphere3 = Sphere3<float>;
    using DoubleSphere3 = Sphere3<double>;
}

#endif  // MATHEMATICS_OBJECTS3D_SPHERE3_H
