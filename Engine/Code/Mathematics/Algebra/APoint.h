///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/26 14:39)

#ifndef MATHEMATICS_ALGEBRA_A_POINT_H
#define MATHEMATICS_ALGEBRA_A_POINT_H

#include "Mathematics/MathematicsDll.h"

#include "AVector.h"
#include "HomogeneousPoint.h"
#include "Mathematics/Base/BaseFwd.h"
#include "Mathematics/Base/MathDetail.h"

#include <vector>

namespace Mathematics
{
    template <typename T>
    requires std::is_arithmetic_v<T>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE APoint final
    {
    public:
        using ClassType = APoint<T>;

        using MathType = Math<T>;
        using AVectorType = AVector<T>;
        using Vector3Type = Vector3<T>;
        using HomogeneousPointType = HomogeneousPoint<T>;
        using ContainerType = std::vector<ClassType>;

        static constexpr auto pointSize = System::EnumCastUnderlying(HomogeneousPointType::PointIndex::W);
        using ArrayType = std::array<T, pointSize>;

    public:
        // APoint表示仿射坐标 (x,y,z,1)。 默认 (0,0,0,1)
        constexpr APoint() noexcept
            : APoint{ MathType::GetValue(0), MathType::GetValue(0), MathType::GetValue(0) }
        {
        }

        constexpr APoint(T x, T y, T z) noexcept
            : homogeneousPoint{ x, y, z, MathType::GetValue(1) }
        {
        }

        explicit APoint(const Vector3Type& rhs) noexcept;
        explicit APoint(const ArrayType& rhs);

        CLASS_INVARIANT_DECLARE;

        NODISCARD T GetX() const noexcept;
        void SetX(T x) noexcept;
        NODISCARD T GetY() const noexcept;
        void SetY(T y) noexcept;
        NODISCARD T GetZ() const noexcept;
        void SetZ(T z) noexcept;

        NODISCARD Vector3Type GetVector3() const noexcept;
        NODISCARD HomogeneousPointType GetHomogeneousPoint() const noexcept;

        NODISCARD const T& operator[](int index) const;
        NODISCARD T& operator[](int index);

        // 算术运算支持仿射代数。

        // 一个点加或减一个向量的结果是一个点
        APoint& operator+=(const AVectorType& rhs);
        APoint& operator-=(const AVectorType& rhs);

        APoint& operator+=(const APoint& rhs);
        APoint& operator-=(const APoint& rhs);
        APoint& operator*=(T scalar);
        APoint& operator/=(T scalar);
        NODISCARD APoint operator-() const noexcept;

        NODISCARD T GetNorm() const;

        NODISCARD ArrayType GetCoordinate() const noexcept;
        void Set(const ArrayType& coordinate);

        NODISCARD static constexpr APoint GetOrigin() noexcept
        {
            return APoint{};
        }

        NODISCARD static constexpr APoint GetUnit() noexcept
        {
            return APoint{ MathType::GetValue(1), MathType::GetValue(1), MathType::GetValue(1) };
        }

    private:
        HomogeneousPointType homogeneousPoint;
    };

    // 两个点相减为一个向量
    template <typename T>
    NODISCARD AVector<T> operator-(const APoint<T>& lhs, const APoint<T>& rhs) noexcept;

    // 一个点增加或减小一个向量的结果是一个点
    template <typename T>
    NODISCARD APoint<T> operator+(const APoint<T>& lhs, const AVector<T>& rhs);
    template <typename T>
    NODISCARD APoint<T> operator-(const APoint<T>& lhs, const AVector<T>& rhs);

    // 在仿射代数，点不能随意加减。然而，仿射和和仿射差是允许的。您有责任确保您在计算哪一个。

    // 一个仿射和是来自
    // r = s1 * p1 + s2 * p2 + ... + sn * pn
    // 这里p1到pn是齐次坐标的点（w值是1）和 s1到sn是标量，且s1 + s2 + ... + sn = 1，其结果r是齐次坐标点。

    // 一个仿射差是来自
    // r = d1 * p1 + d2 * p2 + ... + dn * pn
    // 这里p1到pn是齐次坐标的点（w值是1）和 d1到dn是标量，且d1 + d2 + ... + dn = 0，其结果r是齐次坐标点。

    // 注意：这个类的算法操作返回APoint对象，但仿射差需要返回一个AVector对象。
    // 下面的代码显示了如何实现这一点：
    // APoint p1, p2, p3;  // 初始化为任何值
    // APoint difference = 1.5f * p1 + (-0.2f) * p2 + (-0.3f) * p3;
    // AVector r { difference.GetHomogeneousPoint() };
    // r仅复制x，y和z分量，并将w分量设置为零。
    template <typename T>
    NODISCARD APoint<T> operator+(const APoint<T>& lhs, const APoint<T>& rhs);

    template <typename T>
    NODISCARD APoint<T> operator*(const APoint<T>& lhs, T scalar);

    template <typename T>
    NODISCARD APoint<T> operator/(const APoint<T>& lhs, T scalar);

    template <typename T>
    NODISCARD APoint<T> operator*(T scalar, const APoint<T>& rhs);

    // 在仿射代数是不允许计算一个点和一个向量的内积。 然而，当处理平面时，这是一个方便的定义。
    // 具体而言，平面是Dot(N,X-P) = 0，其中N是一个向量，P是平面上一个特定的点，且X是在平面上的任意点。
    // 差X - P是一个向量，那么Dot(N,X - P)被很好地定义。如果平面被重写为Dot(N,X) = Dot(N,P)，这在仿射代数中是不支持的，
    // 无论无如，我们有时需要计算Dot(N,P)。在下文中，APoint的w分量被忽略，这意味着APoint被视为向量。
    template <typename T>
    NODISCARD T Dot(const APoint<T>& lhs, const AVector<T>& rhs) noexcept;

    template <typename T>
    NODISCARD bool Approximate(const APoint<T>& lhs, const APoint<T>& rhs, T epsilon = Math<T>::GetZeroTolerance()) noexcept;

    // 调试输出
    template <typename T>
    std::ostream& operator<<(std::ostream& outFile, const APoint<T>& point);

    using APointF = APoint<float>;
    using APointD = APoint<double>;
}

#endif  // MATHEMATICS_ALGEBRA_A_POINT_H
