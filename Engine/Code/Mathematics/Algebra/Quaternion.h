///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.2 (2020/11/10 15:14)

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
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Quaternion final : private boost::additive<Quaternion<Real>, boost::multiplicative<Quaternion<Real>, Real, boost::totally_ordered<Quaternion<Real>>>>
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Quaternion<Real>;

        using Math = Math<Real>;
        using Vector3D = Vector3D<Real>;
        using Vector3DTools = Vector3DTools<Real>;
        using Matrix3 = Matrix3<Real>;
        using Matrix3Extract = Matrix3Extract<Real>;
        using QuaternionFactor = QuaternionFactor<Real>;
        using QuaternionConstraints = QuaternionConstraints<Real>;
        using QuaternionSwingTwist = QuaternionSwingTwist<Real>;

        enum class PointIndex
        {
            W = 0,
            X,
            Y,
            Z,
            Size
        };

        static constexpr auto sm_W = System::EnumCastUnderlying(PointIndex::W);
        static constexpr auto sm_X = System::EnumCastUnderlying(PointIndex::X);
        static constexpr auto sm_Y = System::EnumCastUnderlying(PointIndex::Y);
        static constexpr auto sm_Z = System::EnumCastUnderlying(PointIndex::Z);        
        static constexpr auto sm_EntrySize = System::EnumCastUnderlying(PointIndex::Size);
        using ArrayType = std::array<Real, sm_EntrySize>;
        using ContainerType = std::vector<Vector3D>;

    public:
        // 四元数q = w + x * i + y * j + z * k
        // 这里(w,x,y,z)不一定是单位长度的四维向量。

        constexpr Quaternion() noexcept
            : m_W{}, m_X{}, m_Y{}, m_Z{}
        {
        }

        constexpr Quaternion(Real w, Real x, Real y, Real z) noexcept
            : m_W{ w }, m_X{ x }, m_Y{ y }, m_Z{ z }
        {
        }

        // 输入为旋转矩阵构造四元数
        explicit Quaternion(const Matrix3& matrix);

        // 通过轴-角的旋转构造四元数
        Quaternion(const Vector3D& axis, Real angle) noexcept(g_Assert < 1 || g_MathematicsAssert < 1);

        // 通过指定的列旋转矩阵构造四元数。
        explicit Quaternion(const ContainerType& rotationColumn);

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
        Quaternion& operator*=(const Quaternion& rhs) noexcept;

        [[nodiscard]] const Quaternion operator-() const noexcept;

        Quaternion& operator+=(const Quaternion& rhs) noexcept;
        Quaternion& operator-=(const Quaternion& rhs) noexcept;
        Quaternion& operator*=(Real scalar) noexcept;
        Quaternion& operator/=(Real scalar) noexcept;

        // 四元数，矩阵和轴——角之间的转换。
        void FromRotationMatrix(const Matrix3& matrix);
        [[nodiscard]] const Matrix3 ToRotationMatrix() const noexcept;
        void FromRotationColumnVector3D(const ContainerType& rotationColumn);
        [[nodiscard]] const ContainerType ToRotationColumnVector3D() const;
        void FromAxisAngle(const Vector3D& axis, Real angle) noexcept(g_Assert < 1 || g_MathematicsAssert < 1);
        [[nodiscard]] const Vector3D ToAxis() const;
        [[nodiscard]] Real ToAngle() const noexcept;
        [[nodiscard]] const Matrix3Extract ToAngleAxis() const;

        [[nodiscard]] Real Length() const noexcept(g_Assert < 3 || g_MathematicsAssert < 3);  // 4-tuple的长度
        [[nodiscard]] Real SquaredLength() const noexcept;  // 4-tuple的长度的平方
        void Normalize(Real epsilon = Math::GetZeroTolerance()) noexcept(g_Assert < 1 || g_MathematicsAssert < 1);
        [[nodiscard]] const Quaternion Inverse() const noexcept(g_Assert < 1 || g_MathematicsAssert < 1);  // 适用于非零四元数
        [[nodiscard]] const Quaternion Conjugate() const noexcept;  // 取负数在 x, y, 和 z 上
        [[nodiscard]] const Quaternion Exp() const noexcept(g_Assert < 1 || g_MathematicsAssert < 1);  // 适用于四元数 w = 0
        [[nodiscard]] const Quaternion Log() const noexcept;  // 适用于单位长度四元数
        [[nodiscard]] bool IsNormalize(Real epsilon = Math::GetZeroTolerance()) const noexcept(g_Assert < 3 || g_MathematicsAssert < 3);

        // 由四元数旋转向量。
        [[nodiscard]] const Vector3D Rotate(const Vector3D& vector) const noexcept;

        // 球面线性插值
        void Slerp(Real t, const Quaternion& quaternion0, const Quaternion& quaternion1) noexcept;
        void SlerpExtraSpins(Real t, const Quaternion& quaternion0, const Quaternion& quaternion1, int extraSpins) noexcept;

        // 中间条款球面二次插值
        void Intermediate(const Quaternion& quaternion0, const Quaternion& quaternion1, const Quaternion& quaternion2);

        // 球面二次插值。
        void Squad(Real t, const Quaternion& q0, const Quaternion& a0, const Quaternion& a1, const Quaternion& q1) noexcept;

        // 计算旋转单位长度矢量vector0到单位长度矢量vector1的四元数。
        // 旋转是围绕垂直于vector0和vector1的轴，
        // 角度是vector0和vector1之间的角度。
        // 如果vector0和vector1是平行的，旋转任意轴都行，
        // 例如组合(z2,x2,y2)，其中，vector1 = (x2,y2,z2)。
        void Align(const Vector3D& vector0, const Vector3D& vector1, Real epsilon = Math::GetZeroTolerance());

        // 分解四元数为q = q_twist * q_swing，其中q是'this'四元数。
        // 如果V1是输入轴和V2为V1通过q的旋转，
        // q_swing表示大约垂直于V1和V2的轴线旋转（见Quaternion::Align），
        // 并q_twist是大约是V1旋转。
        // 返回值的第一部分为twist，第二部分为swing。
        [[nodiscard]] const QuaternionSwingTwist DecomposeTwistTimesSwing(const Vector3D& vector, Real epsilon = Math::GetZeroTolerance()) const;

        // 分解四元数为q = q_swing * q_twist，其中q是'this'四元数。
        // 如果V1是输入轴和V2为V1通过q的旋转，
        // q_swing表示大约垂直于V1和V2的轴线旋转（见Quaternion::Align），
        // 并q_twist是大约是V1旋转。
        // 返回值的第一部分为swing，第二部分为twist。

        [[nodiscard]] const QuaternionSwingTwist DecomposeSwingTimesTwist(const Vector3D& vector, Real epsilon = Math::GetZeroTolerance()) const;

        // *** 查找最近无约束的角度的四元数。

        // 距离最近的四元数形式(cx + sx * i)。
        [[nodiscard]] const Quaternion GetClosestX() const;

        // 距离最近的四元数形式 (cy + sy * j).
        [[nodiscard]] const Quaternion GetClosestY() const;

        // 距离最近的四元数形式 (cz + sz * k).
        [[nodiscard]] const Quaternion GetClosestZ() const;

        // 距离最近的四元数形式 (cx + sx * i) * (cy + sy * j).
        [[nodiscard]] const Quaternion GetClosestXY() const noexcept(g_Assert < 3 || g_MathematicsAssert < 3);

        // 距离最近的四元数形式 (cy + sy * j) * (cx + sx * i).
        [[nodiscard]] const Quaternion GetClosestYX() const noexcept(g_Assert < 3 || g_MathematicsAssert < 3);

        // 距离最近的四元数形式 (cz + sz * k) * (cx + sx * i).
        [[nodiscard]] const Quaternion GetClosestZX() const;

        // 距离最近的四元数形式 (cx + sx * i) * (cz + sz * k).
        [[nodiscard]] const Quaternion GetClosestXZ() const;

        // 距离最近的四元数形式 (cy + sy * j) * (cz + sz * k).
        [[nodiscard]] const Quaternion GetClosestYZ() const;

        // 距离最近的四元数形式 (cz + sz * k) * (cy + sy * j).
        [[nodiscard]] const Quaternion GetClosestZY() const;

        // 系数为 (cx + sx * i) * (cy + sy * j) * (cz + sz * k).
        [[nodiscard]] const QuaternionFactor FactorXYZ() const noexcept(g_Assert < 1 || g_MathematicsAssert < 1);

        // 系数为  (cx + sx * i) * (cz + sz * k) * (cy + sy * j).
        [[nodiscard]] const QuaternionFactor FactorXZY() const noexcept(g_Assert < 1 || g_MathematicsAssert < 1);

        // 系数为  (cy + sy * j) * (cz + sz * k) * (cx + sx * i).
        [[nodiscard]] const QuaternionFactor FactorYZX() const noexcept(g_Assert < 1 || g_MathematicsAssert < 1);

        // 系数为  (cy + sy * j) * (cx + sx * i) * (cz + sz * k).
        [[nodiscard]] const QuaternionFactor FactorYXZ() const noexcept(g_Assert < 1 || g_MathematicsAssert < 1);

        // 系数为 (cz + sz * k) * (cx + sx * i) * (cy + sy * j).
        [[nodiscard]] const QuaternionFactor FactorZXY() const noexcept(g_Assert < 1 || g_MathematicsAssert < 1);

        // 系数为  (cz + sz * k) * (cy + sy * j) * (cx + sx * i).
        [[nodiscard]] const QuaternionFactor FactorZYX() const noexcept(g_Assert < 1 || g_MathematicsAssert < 1);

        // 距离最近的约束四元数形式为 (cx + sx * i).
        [[nodiscard]] const Quaternion GetClosestX(const QuaternionConstraints& xCon) const;

        // 距离最近的约束四元数形式为 (cy + sy * j).
        [[nodiscard]] const Quaternion GetClosestY(const QuaternionConstraints& yCon) const;

        // 距离最近的约束四元数形式为 (cz + sz * k).
        [[nodiscard]] const Quaternion GetClosestZ(const QuaternionConstraints& zCon) const;

        // 距离最近的约束四元数形式为 (cx + sx * i)*(cy + sy * j).
        [[nodiscard]] const Quaternion GetClosestXY(const QuaternionConstraints& xCon, const QuaternionConstraints& yCon) const;

        // 距离最近的约束四元数形式为  (cy + sy * j)*(cx + sx * i).
        [[nodiscard]] const Quaternion GetClosestYX(const QuaternionConstraints& yCon, const QuaternionConstraints& xCon) const;

        // 距离最近的约束四元数形式为  (cz + sz * k)*(cx + sx * i).
        [[nodiscard]] const Quaternion GetClosestZX(const QuaternionConstraints& zCon, const QuaternionConstraints& xCon) const;

        // 距离最近的约束四元数形式为  (cx + sx * i)*(cz + sz * k).
        [[nodiscard]] const Quaternion GetClosestXZ(const QuaternionConstraints& xCon, const QuaternionConstraints& zCon) const;

        // 距离最近的约束四元数形式为  (cz + sz * k)*(cy + sy * j).
        [[nodiscard]] const Quaternion GetClosestZY(const QuaternionConstraints& zCon, const QuaternionConstraints& yCon) const;

        // 距离最近的约束四元数形式为  (cy + sy * j)*(cz + sz * k).
        [[nodiscard]] const Quaternion GetClosestYZ(const QuaternionConstraints& yCon, const QuaternionConstraints& zCon) const;

        [[nodiscard]] const ArrayType GetCoordinate() const noexcept;
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
        [[nodiscard]] const Quaternion GetClosest(QuaternionClosestAxis axis) const;

        // 距离最近四元数约束的形式：
        //   (cx + sx * i) 当 QuaternionClosestAxis = QuaternionClosestAxis::X,
        //   (cy + sy * j) 当 QuaternionClosestAxis = QuaternionClosestAxis::Y,
        //   (cz + sz * k) 当 QuaternionClosestAxis = QuaternionClosestAxis::Z,
        [[nodiscard]] const Quaternion GetClosest(QuaternionClosestAxis axis, const QuaternionConstraints& con) const;

    private:
        // 存储的顺序是(w,x,y,z)。
        Real m_W;
        Real m_X;
        Real m_Y;
        Real m_Z;
    };

    // 比较 (仅使用在 STL 容器).
    template <typename Real>
    [[nodiscard]] bool operator==(const Quaternion<Real>& lhs, const Quaternion<Real>& rhs);

    template <typename Real>
    [[nodiscard]] bool operator<(const Quaternion<Real>& lhs, const Quaternion<Real>& rhs) noexcept;

    template <typename Real>
    [[nodiscard]] const Quaternion<Real> operator*(const Quaternion<Real>& lhs, const Quaternion<Real>& rhs) noexcept;

    template <typename Real>
    [[nodiscard]] Real Dot(const Quaternion<Real>& lhs, const Quaternion<Real>& rhs) noexcept;  // 4元组的点积

    template <typename Real>
    [[nodiscard]] bool Approximate(const Quaternion<Real>& lhs, const Quaternion<Real>& rhs, const Real epsilon = Math<T>::GetZeroTolerance());

    // 调试输出。
    template <typename Real>
    std::ostream& operator<<(std::ostream& outFile, const Quaternion<Real>& quaternion);

    using FloatQuaternion = Quaternion<float>;
    using DoubleQuaternion = Quaternion<double>;
}

#endif  // MATHEMATICS_ALGEBRA_QUATERNION_H
