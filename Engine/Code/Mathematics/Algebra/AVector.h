///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/07 11:12)

#ifndef MATHEMATICS_ALGEBRA_A_VECTOR_H
#define MATHEMATICS_ALGEBRA_A_VECTOR_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"
#include "HomogeneousPoint.h"
#include "Flags/MatrixFlags.h"
#include "System/Helper/PragmaWarning/Operators.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"

#include <type_traits>
#include <vector>

namespace Mathematics
{
    template <typename T>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE AVector final : private boost::additive<AVector<T>, boost::multiplicative<AVector<T>, T>>
    {
    public:
        static_assert(std::is_arithmetic_v<T>, "T must be arithmetic.");

        using ClassType = AVector<T>;
        using Math = Math<T>;
        using Vector3 = Vector3<T>;
        using HomogeneousPoint = HomogeneousPoint<T>;
        using ContainerType = std::vector<ClassType>;

        static constexpr auto aVectorSize = System::EnumCastUnderlying(HomogeneousPoint::PointIndex::W);
        using ArrayType = std::array<T, aVectorSize>;

    public:
        // AVector表示仿射坐标 (x,y,z,0)。默认 (0,0,0,0)。
        constexpr AVector() noexcept
            : AVector{ Math::GetValue(0), Math::GetValue(0), Math::GetValue(0) }
        {
        }

        constexpr AVector(T x, T y, T z) noexcept
            : homogeneousPoint{ x, y, z, Math::GetValue(0) }
        {
        }

        explicit AVector(const Vector3& rhs) noexcept;
        explicit AVector(const ArrayType& rhs) noexcept;
        explicit AVector(const HomogeneousPoint& homogeneousPoint) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD Vector3 GetVector3() const noexcept;

        NODISCARD const T& operator[](int index) const;
        NODISCARD T& operator[](int index);

        NODISCARD T GetX() const noexcept;
        void SetX(T x) noexcept;
        NODISCARD T GetY() const noexcept;
        void SetY(T y) noexcept;
        NODISCARD T GetZ() const noexcept;
        void SetZ(T y) noexcept;

        // 算术更新
        NODISCARD AVector operator-() const noexcept;
        AVector& operator+=(const AVector& rhs);
        AVector& operator-=(const AVector& rhs);
        AVector& operator*=(T scalar);
        AVector& operator/=(T scalar);

        // 向量运算。
        NODISCARD T Length() const noexcept(gAssert < 3 || gMathematicsAssert < 3);
        NODISCARD T SquaredLength() const noexcept;
        void Normalize(const T epsilon = Math::GetZeroTolerance());
        NODISCARD bool IsZero(const T epsilon = Math::GetZeroTolerance()) const noexcept(gAssert < 3 || gMathematicsAssert < 3);
        NODISCARD bool IsNormalize(const T epsilon = Math::GetZeroTolerance()) const noexcept(gAssert < 3 || gMathematicsAssert < 3);

        NODISCARD ArrayType GetCoordinate() const noexcept;
        void Set(const ArrayType& coordinate) noexcept;

        // (0,0,0,0)
        static constexpr AVector GetZero() noexcept
        {
            return AVector{};
        };

        // (1,0,0,0)
        static constexpr AVector GetUnitX() noexcept
        {
            return AVector{ MathF::GetValue(1), MathF::GetValue(0), MathF::GetValue(0) };
        };

        // (0,1,0,0)
        static constexpr AVector GetUnitY() noexcept
        {
            return AVector{ MathF::GetValue(0), MathF::GetValue(1), MathF::GetValue(0) };
        };

        // (0,0,1,0)
        static constexpr AVector GetUnitZ() noexcept
        {
            return AVector{ MathF::GetValue(0), MathF::GetValue(0), MathF::GetValue(1) };
        };

        static constexpr AVector GetUnit(Mathematics::MatrixRotationAxis axisIndex) noexcept
        {
            switch (axisIndex)
            {
                case Mathematics::MatrixRotationAxis::X:
                    return GetUnitX();
                case Mathematics::MatrixRotationAxis::Y:
                    return GetUnitY();
                case Mathematics::MatrixRotationAxis::Z:
                    return GetUnitZ();
                default:
                    return GetZero();
            }
        };

    private:
        HomogeneousPoint homogeneousPoint;
    };

    template <typename T>
    NODISCARD bool Approximate(const AVector<T>& lhs, const AVector<T>& rhs, const T epsilon = Math<T>::GetZeroTolerance()) noexcept;

    template <typename T>
    NODISCARD T Dot(const AVector<T>& lhs, const AVector<T>& rhs) noexcept;
    template <typename T>
    NODISCARD const AVector<T> Cross(const AVector<T>& lhs, const AVector<T>& rhs) noexcept;
    template <typename T>
    NODISCARD const AVector<T> UnitCross(const AVector<T>& lhs, const AVector<T>& rhs, const T epsilon = Math<T>::GetZeroTolerance());

    // 输入必须初始化为非零向量
    template <typename T>
    NODISCARD const AVectorOrthonormalize<T> Orthonormalize(const AVector<T>& uVector, const AVector<T>& vVector, const AVector<T>& wVector, const T epsilon = Math<T>::GetZeroTolerance());
    template <typename T>
    NODISCARD const AVectorOrthonormalize<T> Orthonormalize(const std::vector<AVector<T>>& vectors, const T epsilon = Math<T>::GetZeroTolerance());

    // 输入值nonzeroVector必须是一个非零向量。返回值是一个标准正交基{U，V, W}。
    // 返回的W为通过此函数正则化的nonzeroVector。如果你已知W是单位长度，使用GenerateComplementBasis来计算U和V。
    template <typename T>
    NODISCARD const AVectorOrthonormalBasis<T> GenerateOrthonormalBasis(const AVector<T>& nonzeroVector, const T epsilon = Math<T>::GetZeroTolerance());

    // 输入值unitVector（W）必须是一个单位向量。返回值中的向量{U,V}是单位长度且互相垂直，且{U,V,W}是一个标准正交基。
    template <typename T>
    NODISCARD const AVectorOrthonormalBasis<T> GenerateComplementBasis(const AVector<T>& unitVector, const T epsilon = Math<T>::GetZeroTolerance());

    // 调试输出
    template <typename T>
    std::ostream& operator<<(std::ostream& outFile, const AVector<T>& vector);

    using AVectorF = AVector<float>;
    using AVectorD = AVector<double>;
}

#endif  // MATHEMATICS_ALGEBRA_A_VECTOR_H
