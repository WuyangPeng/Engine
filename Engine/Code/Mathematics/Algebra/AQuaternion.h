///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/26 14:39)

#ifndef MATHEMATICS_ALGEBRA_A_QUATERNION_H
#define MATHEMATICS_ALGEBRA_A_QUATERNION_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"
#include "System/Helper/PragmaWarning/Operators.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "Mathematics/Base/MathDetail.h"

#include <array>

namespace Mathematics
{
    template <typename Real>
    requires std::is_arithmetic_v<Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE AQuaternion final : private boost::additive<AQuaternion<Real>, boost::multiplicative<AQuaternion<Real>, Real, boost::totally_ordered<AQuaternion<Real>>>>
    {
    public:
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

        static constexpr auto entrySize = System::EnumCastUnderlying(PointIndex::Size);

        using ArrayType = std::array<Real, entrySize>;

    public:
        // 四元数q = w + x * i + y * j + z * k
        // 这里(w,x,y,z)不一定是单位长度的四维向量。

        constexpr AQuaternion() noexcept
            : w{}, x{}, y{}, z{}
        {
        }

        constexpr AQuaternion(Real w, Real x, Real y, Real z) noexcept
            : w{ w }, x{ x }, y{ y }, z{ z }
        {
        }

        explicit AQuaternion(const ArrayType& coordinate) noexcept;

        // 输入为旋转矩阵构造四元数
        explicit AQuaternion(const Matrix& matrix);

        // 通过轴-角的旋转构造四元数
        AQuaternion(const AVector& axis, Real angle) noexcept(gAssert < 1 || gMathematicsAssert < 1);

        CLASS_INVARIANT_DECLARE;

        // 坐标访问类似于数组:  0 = w, 1 = x, 2 = y, 3 = z.
        NODISCARD const Real& operator[](int index) const;
        NODISCARD Real& operator[](int index);
        NODISCARD Real GetW() const noexcept;
        void SetW(Real aW) noexcept;
        NODISCARD Real GetX() const noexcept;
        void SetX(Real aX) noexcept;
        NODISCARD Real GetY() const noexcept;
        void SetY(Real aY) noexcept;
        NODISCARD Real GetZ() const noexcept;
        void SetZ(Real aZ) noexcept;

        // 算术运算
        AQuaternion& operator*=(const AQuaternion& rhs) noexcept;

        NODISCARD AQuaternion operator-() const noexcept;

        AQuaternion& operator+=(const AQuaternion& rhs) noexcept;
        AQuaternion& operator-=(const AQuaternion& rhs) noexcept;
        AQuaternion& operator*=(Real scalar) noexcept;
        AQuaternion& operator/=(Real scalar) noexcept(gAssert < 1 || gMathematicsAssert < 1);

        // 四元数，矩阵和轴——角之间的转换。
        void FromRotationMatrix(const Matrix& matrix);
        NODISCARD Matrix ToRotationMatrix() const noexcept;
        void FromAxisAngle(const AVector& axis, Real angle) noexcept(gAssert < 1 || gMathematicsAssert < 1);
        NODISCARD AVector ToAxis() const noexcept(gAssert < 3 || gMathematicsAssert < 3);
        NODISCARD Real ToAngle() const noexcept;

        // 4-tuple的长度
        NODISCARD Real Length() const noexcept(gAssert < 3 || gMathematicsAssert < 3);

        // 4-tuple的长度的平方
        NODISCARD Real SquaredLength() const noexcept;

        void Normalize(Real epsilon = Math::GetZeroTolerance()) noexcept(gAssert < 1 || gMathematicsAssert < 1);

        // 适用于非零四元数
        NODISCARD AQuaternion Inverse() const noexcept(gAssert < 1 || gMathematicsAssert < 1);

        // 取负数在 x, y, 和 z 上
        NODISCARD AQuaternion Conjugate() const noexcept;

        // 适用于四元数 w = 0
        NODISCARD AQuaternion Exp() const noexcept(gAssert < 1 || gMathematicsAssert < 1);

        // 适用于单位长度四元数
        NODISCARD AQuaternion Log() const noexcept;

        NODISCARD bool IsNormalize(Real epsilon = Math::GetZeroTolerance()) const noexcept(gAssert < 1 || gMathematicsAssert < 1);

        // 由四元数旋转向量。
        NODISCARD AVector Rotate(const AVector& vector) const noexcept;

        // 球面线性插值
        void Slerp(Real t, const AQuaternion& quaternion0, const AQuaternion& quaternion1) noexcept;

        // 中间条款球面二次插值
        void Intermediate(const AQuaternion& quaternion0, const AQuaternion& quaternion1, const AQuaternion& quaternion2);

        // 球面二次插值。
        void Squad(Real t, const AQuaternion& q0, const AQuaternion& a0, const AQuaternion& a1, const AQuaternion& q1) noexcept;

        NODISCARD ArrayType GetCoordinate() const noexcept;
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
        Real w;
        Real x;
        Real y;
        Real z;
    };

    // 比较 (仅使用在 STL 容器).
    template <typename Real>
    NODISCARD bool operator==(const AQuaternion<Real>& lhs, const AQuaternion<Real>& rhs);

    template <typename Real>
    NODISCARD bool operator<(const AQuaternion<Real>& lhs, const AQuaternion<Real>& rhs) noexcept;

    template <typename Real>
    NODISCARD AQuaternion<Real> operator*(const AQuaternion<Real>& lhs, const AQuaternion<Real>& rhs) noexcept;

    // 4元组的点积
    template <typename Real>
    NODISCARD Real Dot(const AQuaternion<Real>& lhs, const AQuaternion<Real>& rhs) noexcept;

    template <typename Real>
    NODISCARD bool Approximate(const AQuaternion<Real>& lhs, const AQuaternion<Real>& rhs, Real epsilon = Math<Real>::GetZeroTolerance()) noexcept;

    // 调试输出
    template <typename Real>
    std::ostream& operator<<(std::ostream& outFile, const AQuaternion<Real>& quaternion);

    using AQuaternionF = AQuaternion<float>;
    using AQuaternionD = AQuaternion<double>;
}

#endif  // MATHEMATICS_ALGEBRA_A_QUATERNION_H
