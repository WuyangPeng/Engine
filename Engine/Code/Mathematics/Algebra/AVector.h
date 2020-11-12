///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.2 (2020/11/02 16:30)

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
        using Vector3D = Vector3D<T>;
        using HomogeneousPoint = HomogeneousPoint<T>;
        using ContainerType = std::vector<ClassType>;

        static constexpr auto sm_AVectorSize = System::EnumCastUnderlying(HomogeneousPoint::PointIndex::W);
        using ArrayType = std::array<T, sm_AVectorSize>;

    public:
        // AVector��ʾ�������� (x,y,z,0)��Ĭ�� (0,0,0,0)��
        constexpr AVector() noexcept
            : AVector{ Math::GetValue(0), Math::GetValue(0), Math::GetValue(0) }
        {
        }

        constexpr AVector(T x, T y, T z) noexcept
            : m_HomogeneousPoint{ x, y, z, Math::GetValue(0) }
        {
        }

        explicit AVector(const Vector3D& rhs) noexcept;
        explicit AVector(const ArrayType& rhs) noexcept;
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

        // ��������
        [[nodiscard]] const AVector operator-() const noexcept;
        AVector& operator+=(const AVector& rhs);
        AVector& operator-=(const AVector& rhs);
        AVector& operator*=(T scalar);
        AVector& operator/=(T scalar);

        // �������㡣
        [[nodiscard]] T Length() const noexcept(g_Assert < 3 || g_MathematicsAssert < 3);
        [[nodiscard]] T SquaredLength() const noexcept;
        void Normalize(const T epsilon = Math::GetZeroTolerance());
        [[nodiscard]] bool IsZero(const T epsilon = Math::GetZeroTolerance()) const noexcept(g_Assert < 3 || g_MathematicsAssert < 3);
        [[nodiscard]] bool IsNormalize(const T epsilon = Math::GetZeroTolerance()) const noexcept(g_Assert < 3 || g_MathematicsAssert < 3);

        [[nodiscard]] const ArrayType GetCoordinate() const noexcept;
        void Set(const ArrayType& coordinate) noexcept;

        // (0,0,0,0)
        static constexpr AVector GetZero() noexcept
        {
            return AVector{};
        };

        // (1,0,0,0)
        static constexpr AVector GetUnitX() noexcept
        {
            return AVector{ FloatMath::GetValue(1), FloatMath::GetValue(0), FloatMath::GetValue(0) };
        };

        // (0,1,0,0)
        static constexpr AVector GetUnitY() noexcept
        {
            return AVector{ FloatMath::GetValue(0), FloatMath::GetValue(1), FloatMath::GetValue(0) };
        };

        // (0,0,1,0)
        static constexpr AVector GetUnitZ() noexcept
        {
            return AVector{ FloatMath::GetValue(0), FloatMath::GetValue(0), FloatMath::GetValue(1) };
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
        HomogeneousPoint m_HomogeneousPoint;
    };

    template <typename T>
    [[nodiscard]] bool Approximate(const AVector<T>& lhs, const AVector<T>& rhs, const T epsilon = Math<T>::GetZeroTolerance()) noexcept;

    template <typename T>
    [[nodiscard]] T Dot(const AVector<T>& lhs, const AVector<T>& rhs) noexcept;
    template <typename T>
    [[nodiscard]] const AVector<T> Cross(const AVector<T>& lhs, const AVector<T>& rhs) noexcept;
    template <typename T>
    [[nodiscard]] const AVector<T> UnitCross(const AVector<T>& lhs, const AVector<T>& rhs, const T epsilon = Math<T>::GetZeroTolerance());

    // ��������ʼ��Ϊ��������
    template <typename T>
    [[nodiscard]] const AVectorOrthonormalize<T> Orthonormalize(const AVector<T>& lhs, const AVector<T>& mhs, const AVector<T>& rhs, const T epsilon = Math<T>::GetZeroTolerance());
    template <typename T>
    [[nodiscard]] const AVectorOrthonormalize<T> Orthonormalize(const std::vector<AVector<T>>& vectors, const T epsilon = Math<T>::GetZeroTolerance());

    // ����ֵnonzeroVector������һ����������������ֵ��һ����׼������{U��V, W}��
    // ���ص�WΪͨ���˺������򻯵�nonzeroVector���������֪W�ǵ�λ���ȣ�ʹ��GenerateComplementBasis������U��V��
    template <typename T>
    [[nodiscard]] const AVectorOrthonormalBasis<T> GenerateOrthonormalBasis(const AVector<T>& nonzeroVector, const T epsilon = Math<T>::GetZeroTolerance());

    // ����ֵunitVector��W��������һ����λ����������ֵ�е�����{U,V}�ǵ�λ�����һ��ഹֱ����{U,V,W}��һ����׼��������
    template <typename T>
    [[nodiscard]] const AVectorOrthonormalBasis<T> GenerateComplementBasis(const AVector<T>& unitVector, const T epsilon = Math<T>::GetZeroTolerance());

    // �������
    template <typename T>
    std::ostream& operator<<(std::ostream& outFile, const AVector<T>& vector);

    using FloatAVector = AVector<float>;
    using DoubleAVector = AVector<double>;
}

#endif  // MATHEMATICS_ALGEBRA_A_VECTOR_H
