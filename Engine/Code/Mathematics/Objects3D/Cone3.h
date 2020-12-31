///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.3 (2020/11/16 15:58)

#ifndef MATHEMATICS_OBJECTS3D_CONE3_H
#define MATHEMATICS_OBJECTS3D_CONE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector3D.h"
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
        using Vector3D = Vector3D<Real>;

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
        Cone3(const Vector3D& vertex, const Vector3D& axis, const Real angle,
              const Real height, const Real epsilon = Math::GetZeroTolerance()) noexcept(g_Assert < 1 || g_MathematicsAssert < 1);

        // axis�����ǵ�λ���ȡ�
        // һ��(cosAngle,sinAngle)�����ϸ���ƽ��ĵ�һ���ޣ��Ա�֤׶��Ϊ(0,pi/2)
        // ��������׶�����á�height��ΪMath<Real>::sm_MaxReal
        Cone3(const Real cosAngle, const Real sinAngle, const Real height,
              const Vector3D& vertex, const Vector3D& axis, const Real epsilon = Math::GetZeroTolerance()) noexcept;

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] const Vector3D GetVertex() const noexcept; 
        [[nodiscard]] const Vector3D GetAxis() const noexcept;
        [[nodiscard]] Real GetCosAngle() const noexcept;
        [[nodiscard]] Real GetSinAngle() const noexcept;
        [[nodiscard]] Real GetHeight() const noexcept;

    private:
        Vector3D m_Vertex;
        Vector3D m_Axis;
        Real m_CosAngle;
        Real m_SinAngle;
        Real m_Height;

        Real m_Epsilon;
    };

    using FloatCone3 = Cone3<float>;
    using DoubleCone3 = Cone3<double>;
}

#endif  // MATHEMATICS_OBJECTS3D_CONE3_H
