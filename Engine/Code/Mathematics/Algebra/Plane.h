///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.2 (2022/02/07 14:06)

#ifndef MATHEMATICS_ALGEBRA_PLANE_H
#define MATHEMATICS_ALGEBRA_PLANE_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"
#include "HomogeneousPoint.h"
#include "System/Helper/PragmaWarning/Operators.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "Mathematics/Base/BaseFwd.h"
#include "Mathematics/Base/MathDetail.h"

#include <type_traits>

namespace Mathematics
{
    template <typename T>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Plane final : boost::totally_ordered<Plane<T>>
    {
    public:
        static_assert(std::is_arithmetic_v<T>, "T must be arithmetic.");

        using ClassType = Plane<T>;
        using ElementType = T;
        using Math = Math<T>;
        using APoint = APoint<T>;
        using AVector = AVector<T>;
        using HomogeneousPoint = HomogeneousPoint<T>;

        static constexpr auto planeSize = HomogeneousPoint::pointSize;

    public:
        // ƽ���ʾΪDot(N,X) - c = 0������N = (n0,n1,n2,0)��һ����λ���ȵķ���������
        // c��ƽ�泣������X = (x0,x1,x2,1) ����ƽ���ϵ�����㡣
        // �û����뱣֤���ߵ������ǵ�λ���ȣ��洢��Ϊһ��4Ԫ����(n0,n1,n2,-c)��
        Plane() noexcept;
        explicit Plane(const T epsilon) noexcept;

        // ʹ��AVector����ƽ����뱣֤����ķ���Ϊ��λ������
        // ʹ��HomogeneousPoint������T����ƽ�棬ֻ�豣֤����ķ��������Ƿ���������

        // ֱ��ָ��N��c
        Plane(T normalX, T normalY, T normalZ, T constant, const T epsilon = Math::GetZeroTolerance());
        Plane(const AVector& normal, T constant, const T epsilon = Math::GetZeroTolerance()) noexcept;

        // N��ָ����c = Dot(N,P)������ P = (p0,p1,p2,1)����ƽ���ϵĵ㡣
        Plane(const AVector& normal, const APoint& point, const T epsilon = Math::GetZeroTolerance()) noexcept;

        // N = Cross(P1 - P0,P2 - P0) / Length(Cross(P1 - P0,P2 - P0))��c = Dot(N,P0)������P0��P1��P2����ƽ���ϵĵ㡣
        Plane(const APoint& lhs, const APoint& mhs, const APoint& rhs, const T epsilon = Math::GetZeroTolerance());

        // ָ������(n0,n1,n2,-c) Ԫ�顣
        Plane(const HomogeneousPoint& homogeneousPoint, const T epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_DECLARE;

        NODISCARD HomogeneousPoint GetHomogeneousPoint() const noexcept;

        // �������
        NODISCARD const T& operator[](int index) const;
        NODISCARD T& operator[](int index);

        // ���ʵ��������
        void SetConstant(T constant) noexcept;
        void SetEpsilon(T newEpsilon) noexcept;
        void SetNormal(const AVector& normal) noexcept(gAssert < 2 || gMathematicsAssert < 2);
        NODISCARD T GetConstant() const noexcept;
        NODISCARD T GetEpsilon() const noexcept;
        NODISCARD AVector GetNormal() const noexcept;

        // ����d = Dot(N,P)-c ����N��ƽ�淨�ߺ�c��ƽ�泣��������һ�����ž��롣
        // �������ֵ�ķ��������ģ���õ�����ƽ���ϵ�������
        // ����Ǹ��ģ�����ƽ�渺����
        // ���Ϊ�㣬�����ƽ���ϡ�
        NODISCARD T DistanceTo(const APoint& point) const noexcept;

        // ƽ��������Ƿ��ߵ����ڵİ�ռ䣬��������һ��ռ䡣�������ص���ƽ�����һ�ࡣ
        NODISCARD NumericalValueSymbol WhichSide(const APoint& point) const noexcept;

    private:
        // ���㣺L = Length(n0,n1,n2)��������ƽ��Ϊ(n0,n1,n2,-c)/L��
        // ��ƽ��ͨ���������������ת���������ܱ�֤��λ���ȷ���ʱ�����Ǻ����õġ�
        void Normalize();

    private:
        // �洢(n0,n1,n2,-c).
        HomogeneousPoint homogeneousPoint;
        T epsilon;
    };

    template <typename T>
    NODISCARD bool Approximate(const Plane<T>& lhs, const Plane<T>& rhs, const T epsilon = Math<T>::GetZeroTolerance());

    // �Ƚϣ�����STL����ʹ�ã���
    template <typename T>
    NODISCARD bool operator==(const Plane<T>& lhs, const Plane<T>& rhs);

    template <typename T>
    NODISCARD bool operator<(const Plane<T>& lhs, const Plane<T>& rhs);

    using PlaneF = Plane<float>;
    using PlaneD = Plane<double>;
}

#endif  // MATHEMATICS_ALGEBRA_PLANE_H
