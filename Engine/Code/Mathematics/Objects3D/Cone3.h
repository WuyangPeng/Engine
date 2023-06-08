///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.11 (2023/06/08 15:43)

#ifndef MATHEMATICS_OBJECTS_3D_CONE3_H
#define MATHEMATICS_OBJECTS_3D_CONE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector3.h"
#include "Mathematics/Base/MathDetail.h"

#include <type_traits>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Cone3 final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Cone3<Real>;
        using Math = Math<Real>;
        using Vector3 = Vector3<Real>;

    public:
        // ���׶����Dot(A,X-V) = |X-V| cos(t)
        // ����V�Ƕ��㣬AΪԲ׶����ĵ�λ���ȷ���
        // ����T��Բ׶����0 < t < pi/2��
        // Բ׶�ڲ��ĵ㶨��ΪDot(A,X-V) >= |X-V| cos(t)��
        // ����cos(t) > 0���ɱ������ƽ������
        // ����׶���ɲ���ʽ����Ϊ Dot(A,X-V)^2 >= Dot(X-V,X-V) cos(t)^2��
        // ����һ�����޵ģ�����׶��
        //
        // ׶�������ƽ��ضϴ�ֱ�����ڴӶ���ĸ߶�h����
        // ���Ӷ�����ƽ��Ľ�������ľ��룩��
        // ����׶��h = �����
        // ����׶����һ�������ϵ�ƽ�������׶��֮�佻�档
        // ���̵İ뾶rΪr = h*tan(t)��

        // axis�����ǵ�λ���ȺͽǶȱ�����(0,pi/2)��
        // ��������׶�����á�height��ΪMath<Real>::sm_MaxReal
        Cone3(const Vector3& vertex,
              const Vector3& axis,
              const Real angle,
              const Real height,
              const Real epsilon = Math::GetZeroTolerance()) noexcept(gAssert < 1 || gMathematicsAssert < 1);

        // axis�����ǵ�λ���ȡ�
        // һ��(cosAngle,sinAngle)�����ϸ���ƽ��ĵ�һ���ޣ��Ա�֤׶��Ϊ(0,pi/2)
        // ��������׶�����á�height��ΪMath<Real>::sm_MaxReal
        Cone3(const Real cosAngle,
              const Real sinAngle,
              const Real height,
              const Vector3& vertex,
              const Vector3& axis,
              const Real epsilon = Math::GetZeroTolerance()) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD Vector3 GetVertex() const noexcept;
        NODISCARD Vector3 GetAxis() const noexcept;
        NODISCARD Real GetCosAngle() const noexcept;
        NODISCARD Real GetSinAngle() const noexcept;
        NODISCARD Real GetHeight() const noexcept;

    private:
        Vector3 vertex;
        Vector3 axis;
        Real cosAngle;
        Real sinAngle;
        Real height;

        Real epsilon;
    };

    using Cone3F = Cone3<float>;
    using Cone3D = Cone3<double>;
}

#endif  // MATHEMATICS_OBJECTS_3D_CONE3_H
