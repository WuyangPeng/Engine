///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.3 (2020/11/16 18:53)

#ifndef MATHEMATICS_OBJECTS3D_PLANE3_H
#define MATHEMATICS_OBJECTS3D_PLANE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector3D.h"
#include "Mathematics/Algebra/Vector3DTools.h"
#include "Mathematics/Base/Flags/NumericalValueSymbol.h"
#include "Mathematics/Base/MathDetail.h"
#include "Mathematics/Objects3D/Triangle3.h"

#include <type_traits>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Plane3 final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Plane3<Real>;
        using Vector3D = Vector3D<Real>;
        using Math = Math<Real>;
        using Vector3DTools = Vector3DTools<Real>;
        using Triangle3 = Triangle3<Real>;

    public:
        // ƽ���ʾΪDot(N,X) = c��
        // ����N��һ����λ���ȵķ���������
        // c��ƽ�泣������X����ƽ���ϵ�����㡣
        // �û����뱣֤���ߵ������ǵ�λ����

        Plane3() noexcept;

        // ֱ��ָ��N��C��
        Plane3(const Vector3D& normal, Real constant, const Real epsilon = Math::GetZeroTolerance()) noexcept;

        // ָ��N��c = Dot(N,P)������P��ƽ���ǵ�һ�㡣
        Plane3(const Vector3D& normal, const Vector3D& point, const Real epsilon = Math::GetZeroTolerance()) noexcept;

        // N = Cross(P1 - P0,P2 - P0)/Length(Cross(P1 - P0,P2 - P0))��
        // c = Dot(N,P0)������P0��P1��P2����ƽ���ϵĵ㡣
        Plane3(const Vector3D& point0, const Vector3D& point1, const Vector3D& point2, const Real epsilon = Math::GetZeroTolerance());

        explicit Plane3(const Triangle3& triangle, const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] const Vector3D GetNormal() const noexcept;
        [[nodiscard]] Real GetConstant() const noexcept;

        // ����d = Dot(N,P)-c ����N��ƽ�淨�ߺ�c��ƽ�泣����
        // ����һ�����ž��롣
        // �������ֵ�ķ��������ģ���õ�����ƽ���ϵ�������
        // ����Ǹ��ģ�����ƽ�渺����
        // ���Ϊ�㣬�����ƽ���ϡ�
        [[nodiscard]] Real DistanceTo(const Vector3D& point) const noexcept;

        // ƽ��������Ƿ��ߵ����ڵİ�ռ䣬��������һ��ռ䡣
        // �������ص���ƽ�����һ�ࡣ
        [[nodiscard]] NumericalValueSymbol WhichSide(const Vector3D& point) const noexcept;

        void SetPlane(const Vector3D& normal, const Vector3D& point) noexcept;

    private:
        Vector3D m_Normal;
        Real m_Constant;

        Real m_Epsilon;
    };

    using FloatPlane3 = Plane3<float>;
    using DoublePlane3 = Plane3<double>;
}

#endif  // MATHEMATICS_OBJECTS3D_PLANE3_H
