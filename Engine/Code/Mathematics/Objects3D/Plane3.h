/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/12 10:25)

#ifndef MATHEMATICS_OBJECTS_3D_PLANE3_H
#define MATHEMATICS_OBJECTS_3D_PLANE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector3.h"
#include "Mathematics/Algebra/Vector3Tools.h"
#include "Mathematics/Base/Flags/NumericalValueSymbol.h"
#include "Mathematics/Base/MathDetail.h"
#include "Mathematics/Objects3D/Triangle3.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Plane3 final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Plane3<Real>;

        using Vector3 = Vector3<Real>;
        using MathType = Math<Real>;
        using Vector3Tools = Vector3Tools<Real>;
        using Triangle3 = Triangle3<Real>;

    public:
        // ƽ���ʾΪDot(N,X) = c��
        // ����N��һ����λ���ȵķ���������
        // c��ƽ�泣������X����ƽ���ϵ�����㡣
        // �û����뱣֤���ߵ������ǵ�λ����

        Plane3() noexcept;

        // ֱ��ָ��N��C��
        Plane3(const Vector3& normal, Real constant, Real epsilon = MathType::GetZeroTolerance()) noexcept;

        // ָ��N��c = Dot(N,P)������P��ƽ���ǵ�һ�㡣
        Plane3(const Vector3& normal, const Vector3& point, Real epsilon = MathType::GetZeroTolerance()) noexcept;

        // N = Cross(P1 - P0,P2 - P0)/Length(Cross(P1 - P0,P2 - P0))��
        // c = Dot(N,P0)������P0��P1��P2����ƽ���ϵĵ㡣
        Plane3(const Vector3& point0, const Vector3& point1, const Vector3& point2, Real epsilon = MathType::GetZeroTolerance());

        explicit Plane3(const Triangle3& triangle, Real epsilon = MathType::GetZeroTolerance());

        CLASS_INVARIANT_DECLARE;

        NODISCARD Vector3 GetNormal() const noexcept;
        NODISCARD Real GetConstant() const noexcept;

        // ����d = Dot(N,P)-c ����N��ƽ�淨�ߺ�c��ƽ�泣����
        // ����һ�����ž��롣
        // �������ֵ�ķ��������ģ���õ�����ƽ���ϵ�������
        // ����Ǹ��ģ�����ƽ�渺����
        // ���Ϊ�㣬�����ƽ���ϡ�
        NODISCARD Real DistanceTo(const Vector3& point) const noexcept;

        // ƽ��������Ƿ��ߵ����ڵİ�ռ䣬��������һ��ռ䡣
        // �������ص���ƽ�����һ�ࡣ
        NODISCARD NumericalValueSymbol WhichSide(const Vector3& point) const noexcept;

        void SetPlane(const Vector3& newNormal, const Vector3& point) noexcept;

        NODISCARD Plane3 GetMove(Real t, const Vector3& velocity) const noexcept;

    private:
        Vector3 normal;
        Real constant;

        Real epsilon;
    };

    using Plane3F = Plane3<float>;
    using Plane3D = Plane3<double>;
}

#endif  // MATHEMATICS_OBJECTS_3D_PLANE3_H
