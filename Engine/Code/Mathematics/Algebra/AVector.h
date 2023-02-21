///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.2 (2022/02/07 11:12)

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
        // AVector��ʾ�������� (x,y,z,0)��Ĭ�� (0,0,0,0)��
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

        // ��������
        NODISCARD AVector operator-() const noexcept;
        AVector& operator+=(const AVector& rhs);
        AVector& operator-=(const AVector& rhs);
        AVector& operator*=(T scalar);
        AVector& operator/=(T scalar);

        // �������㡣
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

    // ��������ʼ��Ϊ��������
    template <typename T>
    NODISCARD const AVectorOrthonormalize<T> Orthonormalize(const AVector<T>& uVector, const AVector<T>& vVector, const AVector<T>& wVector, const T epsilon = Math<T>::GetZeroTolerance());
    template <typename T>
    NODISCARD const AVectorOrthonormalize<T> Orthonormalize(const std::vector<AVector<T>>& vectors, const T epsilon = Math<T>::GetZeroTolerance());

    // ����ֵnonzeroVector������һ����������������ֵ��һ����׼������{U��V, W}��
    // ���ص�WΪͨ���˺������򻯵�nonzeroVector���������֪W�ǵ�λ���ȣ�ʹ��GenerateComplementBasis������U��V��
    template <typename T>
    NODISCARD const AVectorOrthonormalBasis<T> GenerateOrthonormalBasis(const AVector<T>& nonzeroVector, const T epsilon = Math<T>::GetZeroTolerance());

    // ����ֵunitVector��W��������һ����λ����������ֵ�е�����{U,V}�ǵ�λ�����һ��ഹֱ����{U,V,W}��һ����׼��������
    template <typename T>
    NODISCARD const AVectorOrthonormalBasis<T> GenerateComplementBasis(const AVector<T>& unitVector, const T epsilon = Math<T>::GetZeroTolerance());

    // �������
    template <typename T>
    std::ostream& operator<<(std::ostream& outFile, const AVector<T>& vector);

    using AVectorF = AVector<float>;
    using AVectorD = AVector<double>;
}

#endif  // MATHEMATICS_ALGEBRA_A_VECTOR_H
