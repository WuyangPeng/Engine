///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.2 (2022/02/10 14:06)

#ifndef MATHEMATICS_OBJECTS3D_RAY3_H
#define MATHEMATICS_OBJECTS3D_RAY3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector3.h"
#include "Mathematics/Base/MathDetail.h"

#include <type_traits>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Ray3 final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Ray3<Real>;
        using Vector3 = Vector3<Real>;
        using Math = Math<Real>;

    public:
        // ���߱�ʾΪP+t*D������P����ԭ�㣬D�ǵ�λ���ȵķ���������t >= 0��
        // �û�����ȷ��D�ǵ�λ���ȡ�
        Ray3(const Vector3& origin, const Vector3& direction, const Real epsilon = Math::GetZeroTolerance()) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD Vector3 GetOrigin() const noexcept;
        NODISCARD Vector3 GetDirection() const noexcept;

        NODISCARD Ray3 GetMove(Real t, const Vector3& velocity) const;

    private:
        Vector3 origin;
        Vector3 direction;
        Real epsilon;
    };

    using Ray3F = Ray3<float>;
    using Ray3D = Ray3<double>;

    template <typename Real>
    NODISCARD bool Approximate(const Ray3<Real>& lhs, const Ray3<Real>& rhs, const Real epsilon) noexcept(g_Assert < 1 || g_MathematicsAssert < 1);

    // �������
    template <typename Real>
    std::ostream& operator<<(std::ostream& outFile, const Ray3<Real>& ray);
}

#endif  // MATHEMATICS_OBJECTS3D_RAY3_H
