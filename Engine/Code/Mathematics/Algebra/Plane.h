// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ����汾��0.0.2.5 (2020/03/19 10:13)

#ifndef MATHEMATICS_ALGEBRA_PLANE_H
#define MATHEMATICS_ALGEBRA_PLANE_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"
#include "HomogeneousPoint.h"
#include "Mathematics/Base/Flags/NumericalValueSymbol.h"
#include "Mathematics/Base/Math.h"

#include "System/Helper/PragmaWarning/Operators.h"
#include <type_traits>

namespace Mathematics
{
    template <typename T>
    class Plane : boost::totally_ordered<Plane<T>>
    {
    public:
        static_assert(std::is_arithmetic_v<T>, "T must be arithmetic.");

        using ClassType = Plane<T>;
        using Math = Math<T>;
        using AlgebraTraits = AlgebraTraits<T>;
        using AVector = AVector<T>;
        using APoint = APoint<T>;
        using HomogeneousPoint = HomogeneousPoint<T>;

    public:
        // ƽ���ʾΪDot(N,X) - c = 0��
        // ����N = (n0,n1,n2,0)��һ����λ���ȵķ���������
        // c��ƽ�泣������X = (x0,x1,x2,1) ����ƽ���ϵ�����㡣
        // �û����뱣֤���ߵ������ǵ�λ����
        // �洢��Ϊһ��4Ԫ����(n0,n1,n2,-c)��
        explicit Plane(const T epsilon = Math::sm_ZeroTolerance) noexcept;

        // ʹ��AVector����ƽ����뱣֤����ķ���Ϊ��λ������
        // ʹ��HomogeneousPoint������T����ƽ�棬ֻ�豣֤����ķ��������Ƿ���������

        // ֱ��ָ��N��c
        Plane(T normalX, T normalY, T normalZ, T constant, const T epsilon = Math::sm_ZeroTolerance);
        Plane(const AVector& normal, T constant, const T epsilon = Math::sm_ZeroTolerance);

        // N��ָ����c = Dot(N,P)������ P = (p0,p1,p2,1)����ƽ���ϵĵ㡣
        Plane(const AVector& normal, const APoint& point, const T epsilon = Math::sm_ZeroTolerance);

        // N = Cross(P1 - P0,P2 - P0) / Length(Cross(P1 - P0,P2 - P0))��
        // c = Dot(N,P0) ��
        // ����P0��P1��P2����ƽ���ϵĵ㡣
        Plane(const APoint& lhs, const APoint& mhs, const APoint& rhs, const T epsilon = Math::sm_ZeroTolerance);

        // ָ������(n0,n1,n2,-c) Ԫ�顣
        Plane(const HomogeneousPoint& tuple, const T epsilon = Math::sm_ZeroTolerance);

        CLASS_INVARIANT_DECLARE;

        const HomogeneousPoint GetHomogeneousPoint() const;

        // �������
        const T* GetElements() const noexcept;
        T* GetElements() noexcept;
        const T& operator[](int index) const;
        T& operator[](int index);

        // ���ʵ��������
        void SetNormal(const AVector& normal);
        void SetConstant(T constant);
        void SetEpsilon(T epsilon) noexcept;
        const AVector GetNormal() const;
        T GetConstant() const;
        T GetEpsilon() const noexcept;

        // ����d = Dot(N,P)-c ����N��ƽ�淨�ߺ�c��ƽ�泣����
        // ����һ�����ž��롣
        // �������ֵ�ķ��������ģ���õ�����ƽ���ϵ�������
        // ����Ǹ��ģ�����ƽ�渺����
        // ���Ϊ�㣬�����ƽ���ϡ�
        T DistanceTo(const APoint& point) const;

        // ƽ��������Ƿ��ߵ����ڵİ�ռ䣬��������һ��ռ䡣
        // �������ص���ƽ�����һ�ࡣ
        NumericalValueSymbol WhichSide(const APoint& point) const;

    private:
        // ���㣺L = Length(n0,n1,n2)��������ƽ��Ϊ(n0,n1,n2,-c)/L��
        // ��ƽ��ͨ���������������ת���������ܱ�֤��λ���ȷ���ʱ��
        // ���Ǻ����õġ�
        void Normalize();

    private:
        // �洢(n0,n1,n2,-c).
        HomogeneousPoint m_Tuple;
        T m_Epsilon;
    };

    template <typename T>
    bool Approximate(const Plane<T>& lhs, const Plane<T>& rhs, const T epsilon);

    template <typename T>
    bool Approximate(const Plane<T>& lhs, const Plane<T>& rhs);

    // �Ƚϣ�����STL����ʹ�ã���
    template <typename T>
    bool operator==(const Plane<T>& lhs, const Plane<T>& rhs);

    template <typename T>
    bool operator<(const Plane<T>& lhs, const Plane<T>& rhs);

    using Planef = Plane<float>;
    using Planed = Plane<double>;
}

#endif  // MATHEMATICS_ALGEBRA_PLANE_H
