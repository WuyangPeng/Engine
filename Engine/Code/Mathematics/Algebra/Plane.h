// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎版本：0.0.2.5 (2020/03/19 10:13)

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
        // 平面表示为Dot(N,X) - c = 0，
        // 其中N = (n0,n1,n2,0)是一个单位长度的法线向量，
        // c是平面常数，且X = (x0,x1,x2,1) 是在平面上的任意点。
        // 用户必须保证法线的向量是单位长度
        // 存储作为一个4元组是(n0,n1,n2,-c)。
        explicit Plane(const T epsilon = Math::sm_ZeroTolerance) noexcept;

        // 使用AVector构造平面必须保证输入的法线为单位向量，
        // 使用HomogeneousPoint或三个T构造平面，只需保证输入的法线向量是非零向量。

        // 直接指定N和c
        Plane(T normalX, T normalY, T normalZ, T constant, const T epsilon = Math::sm_ZeroTolerance);
        Plane(const AVector& normal, T constant, const T epsilon = Math::sm_ZeroTolerance);

        // N被指定，c = Dot(N,P)，其中 P = (p0,p1,p2,1)是在平面上的点。
        Plane(const AVector& normal, const APoint& point, const T epsilon = Math::sm_ZeroTolerance);

        // N = Cross(P1 - P0,P2 - P0) / Length(Cross(P1 - P0,P2 - P0))，
        // c = Dot(N,P0) ，
        // 这里P0，P1，P2是在平面上的点。
        Plane(const APoint& lhs, const APoint& mhs, const APoint& rhs, const T epsilon = Math::sm_ZeroTolerance);

        // 指定整个(n0,n1,n2,-c) 元组。
        Plane(const HomogeneousPoint& tuple, const T epsilon = Math::sm_ZeroTolerance);

        CLASS_INVARIANT_DECLARE;

        const HomogeneousPoint GetHomogeneousPoint() const;

        // 坐标访问
        const T* GetElements() const noexcept;
        T* GetElements() noexcept;
        const T& operator[](int index) const;
        T& operator[](int index);

        // 访问单个组件。
        void SetNormal(const AVector& normal);
        void SetConstant(T constant);
        void SetEpsilon(T epsilon) noexcept;
        const AVector GetNormal() const;
        T GetConstant() const;
        T GetEpsilon() const noexcept;

        // 计算d = Dot(N,P)-c 其中N是平面法线和c是平面常量。
        // 这是一个符号距离。
        // 如果返回值的符号是正的，则该点是在平面上的正方向，
        // 如果是负的，则在平面负方向，
        // 如果为零，则点在平面上。
        T DistanceTo(const APoint& point) const;

        // 平面的正面是法线点所在的半空间，背面是另一半空间。
        // 函数返回点在平面的哪一侧。
        NumericalValueSymbol WhichSide(const APoint& point) const;

    private:
        // 计算：L = Length(n0,n1,n2)，并设置平面为(n0,n1,n2,-c)/L。
        // 当平面通过齐次坐标矩阵进行转换，当不能保证单位长度法线时，
        // 这是很有用的。
        void Normalize();

    private:
        // 存储(n0,n1,n2,-c).
        HomogeneousPoint m_Tuple;
        T m_Epsilon;
    };

    template <typename T>
    bool Approximate(const Plane<T>& lhs, const Plane<T>& rhs, const T epsilon);

    template <typename T>
    bool Approximate(const Plane<T>& lhs, const Plane<T>& rhs);

    // 比较（仅供STL容器使用）。
    template <typename T>
    bool operator==(const Plane<T>& lhs, const Plane<T>& rhs);

    template <typename T>
    bool operator<(const Plane<T>& lhs, const Plane<T>& rhs);

    using Planef = Plane<float>;
    using Planed = Plane<double>;
}

#endif  // MATHEMATICS_ALGEBRA_PLANE_H
