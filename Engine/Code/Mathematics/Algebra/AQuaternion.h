///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.2 (2020/11/02 13:42)

#ifndef MATHEMATICS_ALGEBRA_AQUATERNION_H
#define MATHEMATICS_ALGEBRA_AQUATERNION_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"
#include "System/Helper/PragmaWarning/Operators.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "Mathematics/Base/MathDetail.h"

#include <array>
#include <type_traits>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE AQuaternion final : private boost::additive<AQuaternion<Real>, boost::multiplicative<AQuaternion<Real>, Real, boost::totally_ordered<AQuaternion<Real>>>>
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = AQuaternion<Real>;
        using Math = Math<Real>;
        using Matrix = Matrix<Real>;
        using AVector = AVector<Real>;

        enum class PointIndex
        {
            W = 0,
            X,
            Y,
            Z,
            Size
        };

        static constexpr auto sm_EntrySize = System::EnumCastUnderlying(PointIndex::Size);

        using ArrayType = std::array<Real, sm_EntrySize>;

    public:
        // 四元数q = w + x * i + y * j + z * k
        // 这里(w,x,y,z)不一定是单位长度的四维向量。

        constexpr AQuaternion() noexcept
            : m_W{}, m_X{}, m_Y{}, m_Z{}
        {
        }

        constexpr AQuaternion(Real w, Real x, Real y, Real z) noexcept
            : m_W{ w }, m_X{ x }, m_Y{ y }, m_Z{ z }
        {
        }

        AQuaternion(const ArrayType& coordinate) noexcept;

        // 输入为旋转矩阵构造四元数
        AQuaternion(const Matrix& matrix);

        // 通过轴-角的旋转构造四元数
        AQuaternion(const AVector& axis, Real angle) noexcept(g_Assert < 1 || g_MathematicsAssert < 1);

        CLASS_INVARIANT_DECLARE;

        // 坐标访问类似于数组:  0 = w, 1 = x, 2 = y, 3 = z.
        [[nodiscard]] const Real& operator[](int index) const;
        [[nodiscard]] Real& operator[](int index);
        [[nodiscard]] Real GetW() const noexcept;
        void SetW(Real w) noexcept;
        [[nodiscard]] Real GetX() const noexcept;
        void SetX(Real x) noexcept;
        [[nodiscard]] Real GetY() const noexcept;
        void SetY(Real y) noexcept;
        [[nodiscard]] Real GetZ() const noexcept;
        void SetZ(Real z) noexcept;

        // 算术运算
        AQuaternion& operator*=(const AQuaternion& rhs) noexcept;

        [[nodiscard]] const AQuaternion operator-() const noexcept;

        AQuaternion& operator+=(const AQuaternion& rhs) noexcept;
        AQuaternion& operator-=(const AQuaternion& rhs) noexcept;
        AQuaternion& operator*=(Real scalar) noexcept;
        AQuaternion& operator/=(Real scalar) noexcept;

        // 四元数，矩阵和轴——角之间的转换。
        void FromRotationMatrix(const Matrix& matrix);
        [[nodiscard]] const Matrix ToRotationMatrix() const noexcept;
        void FromAxisAngle(const AVector& axis, Real angle) noexcept(g_Assert < 1 || g_MathematicsAssert < 1);
        [[nodiscard]] const AVector ToAxis() const noexcept(g_Assert < 3 || g_MathematicsAssert < 3);
        [[nodiscard]] Real ToAngle() const noexcept;

        // 4-tuple的长度
        [[nodiscard]] Real Length() const noexcept(g_Assert < 3 || g_MathematicsAssert < 3);

        // 4-tuple的长度的平方
        [[nodiscard]] Real SquaredLength() const noexcept;

        void Normalize(Real epsilon = Math::GetZeroTolerance()) noexcept(g_Assert < 1 || g_MathematicsAssert < 1);

        // 适用于非零四元数
        [[nodiscard]] const AQuaternion Inverse() const noexcept(g_Assert < 1 || g_MathematicsAssert < 1);

        // 取负数在 x, y, 和 z 上
        [[nodiscard]] const AQuaternion Conjugate() const noexcept;

        // 适用于四元数 w = 0
        [[nodiscard]] const AQuaternion Exp() const noexcept(g_Assert < 1 || g_MathematicsAssert < 1);

        // 适用于单位长度四元数
        [[nodiscard]] const AQuaternion Log() const noexcept;

        [[nodiscard]] bool IsNormalize(Real epsilon = Math::GetZeroTolerance()) const noexcept(g_Assert < 1 || g_MathematicsAssert < 1);

        // 由四元数旋转向量。
        [[nodiscard]] const AVector Rotate(const AVector& vector) const noexcept;

        // 球面线性插值
        void Slerp(Real t, const AQuaternion& quaternion0, const AQuaternion& quaternion1) noexcept;

        // 中间条款球面二次插值
        void Intermediate(const AQuaternion& quaternion0, const AQuaternion& quaternion1, const AQuaternion& quaternion2);

        // 球面二次插值。
        void Squad(Real t, const AQuaternion& q0, const AQuaternion& a0, const AQuaternion& a1, const AQuaternion& q1) noexcept;

        [[nodiscard]] const ArrayType GetCoordinate() const noexcept;
        void Set(const ArrayType& coordinate) noexcept;

        // 特殊四元数
        static constexpr AQuaternion GetZero()
        {
            return AQuaternion{};
        }

        static constexpr AQuaternion GetIdentity()
        {
            return AQuaternion{ Math::GetValue(1), Math::GetValue(0), Math::GetValue(0), Math::GetValue(0) };
        }

    private:
        // 存储的顺序是(w,x,y,z)。
        Real m_W;
        Real m_X;
        Real m_Y;
        Real m_Z;
    };

    // 比较 (仅使用在 STL 容器).
    template <typename Real>
    [[nodiscard]] bool operator==(const AQuaternion<Real>& lhs, const AQuaternion<Real>& rhs);

    template <typename Real>
    [[nodiscard]] bool operator<(const AQuaternion<Real>& lhs, const AQuaternion<Real>& rhs) noexcept;

    template <typename Real>
    [[nodiscard]] const AQuaternion<Real> operator*(const AQuaternion<Real>& lhs, const AQuaternion<Real>& rhs) noexcept;

    // 4元组的点积
    template <typename Real>
    [[nodiscard]] Real Dot(const AQuaternion<Real>& lhs, const AQuaternion<Real>& rhs) noexcept;

    template <typename Real>
    [[nodiscard]] bool Approximate(const AQuaternion<Real>& lhs, const AQuaternion<Real>& rhs, const Real epsilon = Math<Real>::GetZeroTolerance()) noexcept;

    // 调试输出
    template <typename Real>
    std::ostream& operator<<(std::ostream& outFile, const AQuaternion<Real>& quaternion);

    using FloatAQuaternion = AQuaternion<float>;
    using DoubleAQuaternion = AQuaternion<double>;
}

#endif  // MATHEMATICS_ALGEBRA_AQUATERNION_H
