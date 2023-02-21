///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/07 14:06)

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
        // 平面表示为Dot(N,X) - c = 0，其中N = (n0,n1,n2,0)是一个单位长度的法线向量，
        // c是平面常数，且X = (x0,x1,x2,1) 是在平面上的任意点。
        // 用户必须保证法线的向量是单位长度，存储作为一个4元组是(n0,n1,n2,-c)。
        Plane() noexcept;
        explicit Plane(const T epsilon) noexcept;

        // 使用AVector构造平面必须保证输入的法线为单位向量，
        // 使用HomogeneousPoint或三个T构造平面，只需保证输入的法线向量是非零向量。

        // 直接指定N和c
        Plane(T normalX, T normalY, T normalZ, T constant, const T epsilon = Math::GetZeroTolerance());
        Plane(const AVector& normal, T constant, const T epsilon = Math::GetZeroTolerance()) noexcept;

        // N被指定，c = Dot(N,P)，其中 P = (p0,p1,p2,1)是在平面上的点。
        Plane(const AVector& normal, const APoint& point, const T epsilon = Math::GetZeroTolerance()) noexcept;

        // N = Cross(P1 - P0,P2 - P0) / Length(Cross(P1 - P0,P2 - P0))，c = Dot(N,P0)，这里P0，P1，P2是在平面上的点。
        Plane(const APoint& lhs, const APoint& mhs, const APoint& rhs, const T epsilon = Math::GetZeroTolerance());

        // 指定整个(n0,n1,n2,-c) 元组。
        Plane(const HomogeneousPoint& homogeneousPoint, const T epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_DECLARE;

        NODISCARD HomogeneousPoint GetHomogeneousPoint() const noexcept;

        // 坐标访问
        NODISCARD const T& operator[](int index) const;
        NODISCARD T& operator[](int index);

        // 访问单个组件。
        void SetConstant(T constant) noexcept;
        void SetEpsilon(T newEpsilon) noexcept;
        void SetNormal(const AVector& normal) noexcept(gAssert < 2 || gMathematicsAssert < 2);
        NODISCARD T GetConstant() const noexcept;
        NODISCARD T GetEpsilon() const noexcept;
        NODISCARD AVector GetNormal() const noexcept;

        // 计算d = Dot(N,P)-c 其中N是平面法线和c是平面常量。这是一个符号距离。
        // 如果返回值的符号是正的，则该点是在平面上的正方向，
        // 如果是负的，则在平面负方向，
        // 如果为零，则点在平面上。
        NODISCARD T DistanceTo(const APoint& point) const noexcept;

        // 平面的正面是法线点所在的半空间，背面是另一半空间。函数返回点在平面的哪一侧。
        NODISCARD NumericalValueSymbol WhichSide(const APoint& point) const noexcept;

    private:
        // 计算：L = Length(n0,n1,n2)，并设置平面为(n0,n1,n2,-c)/L。
        // 当平面通过齐次坐标矩阵进行转换，当不能保证单位长度法线时，这是很有用的。
        void Normalize();

    private:
        // 存储(n0,n1,n2,-c).
        HomogeneousPoint homogeneousPoint;
        T epsilon;
    };

    template <typename T>
    NODISCARD bool Approximate(const Plane<T>& lhs, const Plane<T>& rhs, const T epsilon = Math<T>::GetZeroTolerance());

    // 比较（仅供STL容器使用）。
    template <typename T>
    NODISCARD bool operator==(const Plane<T>& lhs, const Plane<T>& rhs);

    template <typename T>
    NODISCARD bool operator<(const Plane<T>& lhs, const Plane<T>& rhs);

    using PlaneF = Plane<float>;
    using PlaneD = Plane<double>;
}

#endif  // MATHEMATICS_ALGEBRA_PLANE_H
