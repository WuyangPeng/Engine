///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/26 14:40)

#ifndef MATHEMATICS_ALGEBRA_A_VECTOR_H
#define MATHEMATICS_ALGEBRA_A_VECTOR_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"
#include "HomogeneousPoint.h"
#include "Flags/MatrixFlags.h"
#include "System/Helper/PragmaWarning/Operators.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"

#include <vector>

namespace Mathematics
{
    template <typename T>
    requires std::is_arithmetic_v<T>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE AVector final : private boost::additive<AVector<T>, boost::multiplicative<AVector<T>, T>>
    {
    public:
        using ClassType = AVector<T>;

        using Math = Math<T>;
        using Vector3 = Vector3<T>;
        using HomogeneousPoint = HomogeneousPoint<T>;
        using ContainerType = std::vector<ClassType>;

        static constexpr auto vectorSize = System::EnumCastUnderlying(HomogeneousPoint::PointIndex::W);
        using ArrayType = std::array<T, vectorSize>;

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
        void SetZ(T z) noexcept;

        // ��������
        NODISCARD AVector operator-() const noexcept;
        AVector& operator+=(const AVector& rhs);
        AVector& operator-=(const AVector& rhs);
        AVector& operator*=(T scalar);
        AVector& operator/=(T scalar);

        // �������㡣
        NODISCARD T Length() const noexcept(gAssert < 3 || gMathematicsAssert < 3);
        NODISCARD T SquaredLength() const noexcept;
        void Normalize(T epsilon = Math::GetZeroTolerance());
        NODISCARD bool IsZero(T epsilon = Math::GetZeroTolerance()) const noexcept(gAssert < 3 || gMathematicsAssert < 3);
        NODISCARD bool IsNormalize(T epsilon = Math::GetZeroTolerance()) const noexcept(gAssert < 3 || gMathematicsAssert < 3);

        NODISCARD ArrayType GetCoordinate() const noexcept;
        void Set(const ArrayType& coordinate) noexcept;

        // (0,0,0,0)
        static constexpr AVector GetZero() noexcept
        {
            return AVector{};
        }

        // (1,0,0,0)
        static constexpr AVector GetUnitX() noexcept
        {
            return AVector{ Math::GetValue(1), Math::GetValue(0), Math::GetValue(0) };
        }

        // (0,1,0,0)
        static constexpr AVector GetUnitY() noexcept
        {
            return AVector{ Math::GetValue(0), Math::GetValue(1), Math::GetValue(0) };
        }

        // (0,0,1,0)
        static constexpr AVector GetUnitZ() noexcept
        {
            return AVector{ Math::GetValue(0), Math::GetValue(0), Math::GetValue(1) };
        }

        static constexpr AVector GetUnit(const MatrixRotationAxis axisIndex) noexcept
        {
            switch (axisIndex)
            {
                case MatrixRotationAxis::X:
                    return GetUnitX();
                case MatrixRotationAxis::Y:
                    return GetUnitY();
                case MatrixRotationAxis::Z:
                    return GetUnitZ();
                default:
                    return GetZero();
            }
        }

        NODISCARD HomogeneousPoint GetHomogeneousPoint() const noexcept;

    private:
        HomogeneousPoint homogeneousPoint;
    };

    template <typename T>
    NODISCARD bool Approximate(const AVector<T>& lhs, const AVector<T>& rhs, T epsilon = Math<T>::GetZeroTolerance()) noexcept;

    template <typename T>
    NODISCARD T Dot(const AVector<T>& lhs, const AVector<T>& rhs) noexcept;
    template <typename T>
    NODISCARD AVector<T> Cross(const AVector<T>& lhs, const AVector<T>& rhs) noexcept;
    template <typename T>
    NODISCARD AVector<T> UnitCross(const AVector<T>& lhs, const AVector<T>& rhs, T epsilon = Math<T>::GetZeroTolerance());

    // ��������ʼ��Ϊ��������
    template <typename T>
    NODISCARD AVectorOrthonormalize<T> Orthonormalize(const AVector<T>& uVector, const AVector<T>& vVector, const AVector<T>& wVector, T epsilon = Math<T>::GetZeroTolerance());
    template <typename T>
    NODISCARD AVectorOrthonormalize<T> Orthonormalize(const std::vector<AVector<T>>& vectors, T epsilon = Math<T>::GetZeroTolerance());

    // ����ֵnonzeroVector������һ����������������ֵ��һ����׼������{U��V, W}��
    // ���ص�WΪͨ���˺������򻯵�nonzeroVector���������֪W�ǵ�λ���ȣ�ʹ��GenerateComplementBasis������U��V��
    template <typename T>
    NODISCARD AVectorOrthonormalBasis<T> GenerateOrthonormalBasis(const AVector<T>& nonzeroVector, T epsilon = Math<T>::GetZeroTolerance());

    // ����ֵunitVector��W��������һ����λ����������ֵ�е�����{U,V}�ǵ�λ�����һ��ഹֱ����{U,V,W}��һ����׼��������
    template <typename T>
    NODISCARD AVectorOrthonormalBasis<T> GenerateComplementBasis(const AVector<T>& unitVector, T epsilon = Math<T>::GetZeroTolerance());

    // �������
    template <typename T>
    std::ostream& operator<<(std::ostream& outFile, const AVector<T>& vector);

    using AVectorF = AVector<float>;
    using AVectorD = AVector<double>;
}

#endif  // MATHEMATICS_ALGEBRA_A_VECTOR_H
