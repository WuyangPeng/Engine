//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.0.0 (2020/08/28 22:21)

#ifndef MATHEMATICS_ALGEBRA_A_VECTOR_H
#define MATHEMATICS_ALGEBRA_A_VECTOR_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"
#include "HomogeneousPoint.h"
#include "System/Helper/PragmaWarning/Operators.h"

#include <type_traits>

namespace Mathematics
{
    template <typename T>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE AVector : private boost::additive<AVector<T>, boost::multiplicative<AVector<T>, T>>
    {
    public:
        static_assert(std::is_arithmetic_v<T>, "T must be arithmetic.");

        using ClassType = AVector<T>;
        using Math = Math<T>;
        using Vector3D = Vector3D<T>;
        using HomogeneousPoint = HomogeneousPoint<T>;

    public:
        // AVector表示仿射坐标 (x,y,z,0)。默认 (0,0,0,0)。
        constexpr AVector() noexcept
            : AVector{ Math::GetValue(0), Math::GetValue(0), Math::GetValue(0) }
        {
        }

        constexpr AVector(T x, T y, T z) noexcept
            : m_HomogeneousPoint{ x, y, z, Math::GetValue(0) }
        {
        }

        AVector(const Vector3D& rhs);
        explicit AVector(const HomogeneousPoint& homogeneousPoint) noexcept;

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] const Vector3D GetVector3D() const noexcept;

        [[nodiscard]] const T& operator[](int index) const;
        [[nodiscard]] T& operator[](int index);

        [[nodiscard]] T GetX() const noexcept;
        void SetX(T x) noexcept;
        [[nodiscard]] T GetY() const noexcept;
        void SetY(T y) noexcept;
        [[nodiscard]] T GetZ() const noexcept;
        void SetZ(T y) noexcept;

        // 算术更新
        [[nodiscard]] const AVector operator-() const noexcept;
        AVector& operator+=(const AVector& rhs);
        AVector& operator-=(const AVector& rhs);
        AVector& operator*=(T scalar);
        AVector& operator/=(T scalar);

        // 向量运算。
        [[nodiscard]] T Length() const;
        [[nodiscard]] T SquaredLength() const noexcept;
        void Normalize(const T epsilon = Math::GetZeroTolerance());
        [[nodiscard]] bool IsZero(const T epsilon = Math::GetZeroTolerance()) const;
        [[nodiscard]] bool IsNormalize(const T epsilon = Math::GetZeroTolerance()) const;

    private:
        static constexpr auto sm_AVectorSize = System::EnumCastUnderlying(HomogeneousPoint::PointIndex::W);

    private:
        HomogeneousPoint m_HomogeneousPoint;
    };

    template <typename T>
    [[nodiscard]] bool Approximate(const AVector<T>& lhs, const AVector<T>& rhs, const T epsilon = Math<T>::GetZeroTolerance());

    template <typename T>
    [[nodiscard]] T Dot(const AVector<T>& lhs, const AVector<T>& rhs) noexcept;
    template <typename T>
    [[nodiscard]] const AVector<T> Cross(const AVector<T>& lhs, const AVector<T>& rhs);
    template <typename T>
    [[nodiscard]] const AVector<T> UnitCross(const AVector<T>& lhs, const AVector<T>& rhs, const T epsilon = Math<T>::GetZeroTolerance());

    // 输入必须初始化为非零向量
    template <typename T>
    [[nodiscard]] const AVectorOrthonormalize<T> Orthonormalize(const AVector<T>& lhs, const AVector<T>& mhs, const AVector<T>& rhs, const T epsilon = Math<T>::GetZeroTolerance());
    template <typename T>
    [[nodiscard]] const AVectorOrthonormalize<T> Orthonormalize(const std::vector<AVector<T>>& vectors, const T epsilon = Math<T>::GetZeroTolerance());

    // 输入值nonzeroVector必须是一个非零向量。返回值是一个标准正交基{U，V, W}。
    // 返回的W为通过此函数正则化的nonzeroVector。如果你已知W是单位长度，使用GenerateComplementBasis来计算U和V。
    template <typename T>
    [[nodiscard]] const AVectorOrthonormalBasis<T> GenerateOrthonormalBasis(const AVector<T>& nonzeroVector, const T epsilon = Math<T>::GetZeroTolerance());

    // 输入值unitVector（W）必须是一个单位向量。返回值中的向量{U,V}是单位长度且互相垂直，且{U,V,W}是一个标准正交基。
    template <typename T>
    [[nodiscard]] const AVectorOrthonormalBasis<T> GenerateComplementBasis(const AVector<T>& unitVector, const T epsilon = Math<T>::GetZeroTolerance());

    // 调试输出
    template <typename T>
    std::ostream& operator<<(std::ostream& outFile, const AVector<T>& vector);

    using AVectorf = AVector<float>;
    using AVectord = AVector<double>;

    // 特殊向量
    namespace Vectorf
    {
        // (0,0,0,0)
        constexpr AVectorf g_Zero;
        // (1,0,0,0)
        constexpr AVectorf g_UnitX{ Mathf::GetValue(1), Mathf::GetValue(0), Mathf::GetValue(0) };
        // (0,1,0,0)
        constexpr AVectorf g_UnitY{ Mathf::GetValue(0), Mathf::GetValue(1), Mathf::GetValue(0) };
        // (0,0,1,0)
        constexpr AVectorf g_UnitZ{ Mathf::GetValue(0), Mathf::GetValue(0), Mathf::GetValue(1) };
    }

    namespace Vectord
    {
        // (0,0,0,0)
        constexpr AVectord g_Zero;
        // (1,0,0,0)
        constexpr AVectord g_UnitX{ Mathd::GetValue(1), Mathd::GetValue(0), Mathd::GetValue(0) };
        // (0,1,0,0)
        constexpr AVectord g_UnitY{ Mathd::GetValue(0), Mathd::GetValue(1), Mathd::GetValue(0) };
        // (0,0,1,0)
        constexpr AVectord g_UnitZ{ Mathd::GetValue(0), Mathd::GetValue(0), Mathd::GetValue(1) };
    }
}

#endif  // MATHEMATICS_ALGEBRA_A_VECTOR_H
