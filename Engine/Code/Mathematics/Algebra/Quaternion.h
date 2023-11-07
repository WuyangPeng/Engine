///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/26 14:55)

#ifndef MATHEMATICS_ALGEBRA_QUATERNION_H
#define MATHEMATICS_ALGEBRA_QUATERNION_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"
#include "Matrix3Extract.h"
#include "QuaternionConstraints.h"
#include "QuaternionFactor.h"
#include "QuaternionSwingTwist.h"
#include "System/Helper/PragmaWarning/Operators.h"

#include <type_traits>
#include <vector>

namespace Mathematics
{
    template <typename Real>
    requires std::is_arithmetic_v<Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Quaternion final : private boost::additive<Quaternion<Real>, boost::multiplicative<Quaternion<Real>, Real, boost::totally_ordered<Quaternion<Real>>>>
    {
    public:
        using ClassType = Quaternion<Real>;

        enum class PointIndex
        {
            W = 0,
            X,
            Y,
            Z,
            Size
        };

        static constexpr auto wIndex = System::EnumCastUnderlying(PointIndex::W);
        static constexpr auto xIndex = System::EnumCastUnderlying(PointIndex::X);
        static constexpr auto yIndex = System::EnumCastUnderlying(PointIndex::Y);
        static constexpr auto zIndex = System::EnumCastUnderlying(PointIndex::Z);
        static constexpr auto entrySize = System::EnumCastUnderlying(PointIndex::Size);

        using Math = Math<Real>;
        using Vector3 = Vector3<Real>;
        using Vector4 = Vector4<Real>;
        using Vector3Tools = Vector3Tools<Real>;
        using Matrix3 = Matrix3<Real>;
        using Matrix3Extract = Matrix3Extract<Real>;
        using QuaternionFactor = QuaternionFactor<Real>;
        using QuaternionConstraints = QuaternionConstraints<Real>;
        using QuaternionSwingTwist = QuaternionSwingTwist<Real>;
        using ArrayType = std::array<Real, entrySize>;
        using ContainerType = std::vector<Vector3>;

    public:
        // 四元数q = w + x * i + y * j + z * k
        // 这里(w,x,y,z)不一定是单位长度的四维向量。

        constexpr Quaternion() noexcept
            : w{}, x{}, y{}, z{}
        {
        }

        constexpr Quaternion(Real w, Real x, Real y, Real z) noexcept
            : w{ w }, x{ x }, y{ y }, z{ z }
        {
        }

        // 输入为旋转矩阵构造四元数
        explicit Quaternion(const Matrix3& matrix);

        // 通过轴-角的旋转构造四元数
        Quaternion(const Vector3& axis, Real angle) noexcept(gAssert < 1 || gMathematicsAssert < 1);

        // 通过指定的列旋转矩阵构造四元数。
        explicit Quaternion(const ContainerType& rotationColumn);

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
        Quaternion& operator*=(const Quaternion& rhs) noexcept;

        NODISCARD Quaternion operator-() const noexcept;

        Quaternion& operator+=(const Quaternion& rhs) noexcept;
        Quaternion& operator-=(const Quaternion& rhs) noexcept;
        Quaternion& operator*=(Real scalar) noexcept;
        Quaternion& operator/=(Real scalar) noexcept(gAssert < 1 || gMathematicsAssert < 1);

        // 四元数，矩阵和轴——角之间的转换。
        void FromRotationMatrix(const Matrix3& matrix);
        NODISCARD Matrix3 ToRotationMatrix() const noexcept;
        void FromRotationColumnVector3(const ContainerType& rotationColumn);
        NODISCARD ContainerType ToRotationColumnVector3() const;
        void FromAxisAngle(const Vector3& axis, Real angle) noexcept(gAssert < 1 || gMathematicsAssert < 1);
        NODISCARD Vector3 ToAxis() const;
        NODISCARD Real ToAngle() const noexcept;
        NODISCARD Matrix3Extract ToAngleAxis() const;

        NODISCARD Real Length() const noexcept(gAssert < 3 || gMathematicsAssert < 3);  // 4-tuple的长度
        NODISCARD Real SquaredLength() const noexcept;  // 4-tuple的长度的平方
        void Normalize(Real epsilon = Math::GetZeroTolerance()) noexcept(gAssert < 1 || gMathematicsAssert < 1);
        NODISCARD Quaternion Inverse() const noexcept(gAssert < 1 || gMathematicsAssert < 1);  // 适用于非零四元数
        NODISCARD Quaternion Conjugate() const noexcept;  // 取负数在 x, y, 和 z 上
        NODISCARD Quaternion Exp() const noexcept(gAssert < 1 || gMathematicsAssert < 1);  // 适用于四元数 w = 0
        NODISCARD Quaternion Log() const noexcept;  // 适用于单位长度四元数
        NODISCARD bool IsNormalize(Real epsilon = Math::GetZeroTolerance()) const noexcept(gAssert < 3 || gMathematicsAssert < 3);

        // 由四元数旋转向量。
        NODISCARD Vector3 Rotate(const Vector3& vector) const noexcept;
        NODISCARD Vector4 Rotate(const Vector4& vector) const noexcept;

        // 球面线性插值
        void Slerp(Real t, const Quaternion& quaternion0, const Quaternion& quaternion1) noexcept;
        void SlerpExtraSpins(Real t, const Quaternion& quaternion0, const Quaternion& quaternion1, int extraSpins) noexcept;
        void SlerpChebyshevRatio(Real t, const Quaternion& quaternion0, const Quaternion& quaternion1);
        void SlerpChebyshevRatioRestricted(Real t, const Quaternion& quaternion0, const Quaternion& quaternion1);
        void SlerpChebyshevRatioRestrictedPreprocessed(Real t, const Quaternion& quaternion0, const Quaternion& quaternion1, Real cosA);
        void SlerpChebyshevRatioRestrictedPreprocessedHalf(Real t, const Quaternion& quaternion0, const Quaternion& quaternion1, const Quaternion& quaternionHalf, Real cosAHalf);

        // 中间条款球面二次插值
        void Intermediate(const Quaternion& quaternion0, const Quaternion& quaternion1, const Quaternion& quaternion2);

        // 球面二次插值。
        void Squad(Real t, const Quaternion& q0, const Quaternion& a0, const Quaternion& a1, const Quaternion& q1) noexcept;

        // 计算旋转单位长度矢量vector0到单位长度矢量vector1的四元数。
        // 旋转是围绕垂直于vector0和vector1的轴，
        // 角度是vector0和vector1之间的角度。
        // 如果vector0和vector1是平行的，旋转任意轴都行，
        // 例如组合(z2,x2,y2)，其中，vector1 = (x2,y2,z2)。
        void Align(const Vector3& vector0, const Vector3& vector1, Real epsilon = Math::GetZeroTolerance());

        // 分解四元数为q = q_twist * q_swing，其中q是'this'四元数。
        // 如果V1是输入轴和V2为V1通过q的旋转，
        // q_swing表示大约垂直于V1和V2的轴线旋转（见Quaternion::Align），
        // 并q_twist是大约是V1旋转。
        // 返回值的第一部分为twist，第二部分为swing。
        NODISCARD QuaternionSwingTwist DecomposeTwistTimesSwing(const Vector3& vector, Real epsilon = Math::GetZeroTolerance()) const;

        // 分解四元数为q = q_swing * q_twist，其中q是'this'四元数。
        // 如果V1是输入轴和V2为V1通过q的旋转，
        // q_swing表示大约垂直于V1和V2的轴线旋转（见Quaternion::Align），
        // 并q_twist是大约是V1旋转。
        // 返回值的第一部分为swing，第二部分为twist。

        NODISCARD QuaternionSwingTwist DecomposeSwingTimesTwist(const Vector3& vector, Real epsilon = Math::GetZeroTolerance()) const;

        // *** 查找最近无约束的角度的四元数。

        // 距离最近的四元数形式(cx + sx * i)。
        NODISCARD Quaternion GetClosestX() const;

        // 距离最近的四元数形式 (cy + sy * j).
        NODISCARD Quaternion GetClosestY() const;

        // 距离最近的四元数形式 (cz + sz * k).
        NODISCARD Quaternion GetClosestZ() const;

        // 距离最近的四元数形式 (cx + sx * i) * (cy + sy * j).
        NODISCARD Quaternion GetClosestXY() const noexcept(gAssert < 3 || gMathematicsAssert < 3);

        // 距离最近的四元数形式 (cy + sy * j) * (cx + sx * i).
        NODISCARD Quaternion GetClosestYX() const noexcept(gAssert < 3 || gMathematicsAssert < 3);

        // 距离最近的四元数形式 (cz + sz * k) * (cx + sx * i).
        NODISCARD Quaternion GetClosestZX() const;

        // 距离最近的四元数形式 (cx + sx * i) * (cz + sz * k).
        NODISCARD Quaternion GetClosestXZ() const;

        // 距离最近的四元数形式 (cy + sy * j) * (cz + sz * k).
        NODISCARD Quaternion GetClosestYZ() const;

        // 距离最近的四元数形式 (cz + sz * k) * (cy + sy * j).
        NODISCARD Quaternion GetClosestZY() const;

        // 系数为 (cx + sx * i) * (cy + sy * j) * (cz + sz * k).
        NODISCARD QuaternionFactor FactorXYZ() const noexcept(gAssert < 1 || gMathematicsAssert < 1);

        // 系数为  (cx + sx * i) * (cz + sz * k) * (cy + sy * j).
        NODISCARD QuaternionFactor FactorXZY() const noexcept(gAssert < 1 || gMathematicsAssert < 1);

        // 系数为  (cy + sy * j) * (cz + sz * k) * (cx + sx * i).
        NODISCARD QuaternionFactor FactorYZX() const noexcept(gAssert < 1 || gMathematicsAssert < 1);

        // 系数为  (cy + sy * j) * (cx + sx * i) * (cz + sz * k).
        NODISCARD QuaternionFactor FactorYXZ() const noexcept(gAssert < 1 || gMathematicsAssert < 1);

        // 系数为 (cz + sz * k) * (cx + sx * i) * (cy + sy * j).
        NODISCARD QuaternionFactor FactorZXY() const noexcept(gAssert < 1 || gMathematicsAssert < 1);

        // 系数为  (cz + sz * k) * (cy + sy * j) * (cx + sx * i).
        NODISCARD QuaternionFactor FactorZYX() const noexcept(gAssert < 1 || gMathematicsAssert < 1);

        // 距离最近的约束四元数形式为 (cx + sx * i).
        NODISCARD Quaternion GetClosestX(const QuaternionConstraints& xCon) const;

        // 距离最近的约束四元数形式为 (cy + sy * j).
        NODISCARD Quaternion GetClosestY(const QuaternionConstraints& yCon) const;

        // 距离最近的约束四元数形式为 (cz + sz * k).
        NODISCARD Quaternion GetClosestZ(const QuaternionConstraints& zCon) const;

        // 距离最近的约束四元数形式为 (cx + sx * i)*(cy + sy * j).
        NODISCARD Quaternion GetClosestXY(const QuaternionConstraints& xCon, const QuaternionConstraints& yCon) const;

        // 距离最近的约束四元数形式为  (cy + sy * j)*(cx + sx * i).
        NODISCARD Quaternion GetClosestYX(const QuaternionConstraints& yCon, const QuaternionConstraints& xCon) const;

        // 距离最近的约束四元数形式为  (cz + sz * k)*(cx + sx * i).
        NODISCARD Quaternion GetClosestZX(const QuaternionConstraints& zCon, const QuaternionConstraints& xCon) const;

        // 距离最近的约束四元数形式为  (cx + sx * i)*(cz + sz * k).
        NODISCARD Quaternion GetClosestXZ(const QuaternionConstraints& xCon, const QuaternionConstraints& zCon) const;

        // 距离最近的约束四元数形式为  (cz + sz * k)*(cy + sy * j).
        NODISCARD Quaternion GetClosestZY(const QuaternionConstraints& zCon, const QuaternionConstraints& yCon) const;

        // 距离最近的约束四元数形式为  (cy + sy * j)*(cz + sz * k).
        NODISCARD Quaternion GetClosestYZ(const QuaternionConstraints& yCon, const QuaternionConstraints& zCon) const;

        NODISCARD ArrayType GetCoordinate() const noexcept;
        void SetCoordinate(const ArrayType& coordinate) noexcept;

        // 特殊四元数
        static constexpr Quaternion GetZero() noexcept
        {
            return Quaternion{};
        }

        static constexpr Quaternion GetIdentity() noexcept
        {
            return Quaternion{ Math::GetValue(1), Math::GetValue(0), Math::GetValue(0), Math::GetValue(0) };
        }

    private:
        // 距离最近四元数约束的形式：
        //   (cx + sx * i) 当 QuaternionClosestAxis = QuaternionClosestAxis::X,
        //   (cy + sy * j) 当 QuaternionClosestAxis = QuaternionClosestAxis::Y,
        //   (cz + sz * k) 当 QuaternionClosestAxis = QuaternionClosestAxis::Z,
        NODISCARD Quaternion GetClosest(QuaternionClosestAxis axis) const;

        // 距离最近四元数约束的形式：
        //   (cx + sx * i) 当 QuaternionClosestAxis = QuaternionClosestAxis::X,
        //   (cy + sy * j) 当 QuaternionClosestAxis = QuaternionClosestAxis::Y,
        //   (cz + sz * k) 当 QuaternionClosestAxis = QuaternionClosestAxis::Z,
        NODISCARD Quaternion GetClosest(QuaternionClosestAxis axis, const QuaternionConstraints& con) const;

    private:
        // 存储的顺序是(w,x,y,z)。
        Real w;
        Real x;
        Real y;
        Real z;
    };

    // 比较 (仅使用在 STL 容器).
    template <typename Real>
    NODISCARD bool operator==(const Quaternion<Real>& lhs, const Quaternion<Real>& rhs);

    template <typename Real>
    NODISCARD bool operator<(const Quaternion<Real>& lhs, const Quaternion<Real>& rhs) noexcept;

    template <typename Real>
    NODISCARD Quaternion<Real> operator*(const Quaternion<Real>& lhs, const Quaternion<Real>& rhs) noexcept;

    template <typename Real>
    NODISCARD Real Dot(const Quaternion<Real>& lhs, const Quaternion<Real>& rhs) noexcept;  // 4元组的点积

    template <typename Real>
    NODISCARD bool Approximate(const Quaternion<Real>& lhs, const Quaternion<Real>& rhs, Real epsilon = Math<Real>::GetZeroTolerance()) noexcept;

    // 调试输出。
    template <typename Real>
    std::ostream& operator<<(std::ostream& outFile, const Quaternion<Real>& quaternion);

    using QuaternionF = Quaternion<float>;
    using QuaternionD = Quaternion<double>;
}

#endif  // MATHEMATICS_ALGEBRA_QUATERNION_H
