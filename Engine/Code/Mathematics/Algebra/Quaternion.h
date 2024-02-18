/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.5 (2024/02/05 09:14)

#ifndef MATHEMATICS_ALGEBRA_QUATERNION_H
#define MATHEMATICS_ALGEBRA_QUATERNION_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"
#include "AxisAngle.h"
#include "QuaternionConstraints.h"
#include "QuaternionFactor.h"
#include "QuaternionSwingTwist.h"
#include "System/Helper/PragmaWarning/Operators.h"

#include <type_traits>
#include <vector>

namespace Mathematics
{
    /// 四元数的形式为
    /// q = x*i + y*j + z*k + w*1 = x*i + y*j + z*k + w
    /// 其中w、x、y和z是实数。标量部分和矢量部分分别为
    ///   Vector(q) = x * i + y * j + z * k
    ///   Scalar(q) = w
    ///   q = Vector(q) + Scalar(q)
    ///
    /// 与使用rotatedU = q * (0,u) * Conjugate(q)（对于MATHEMATICS_USE_MATRIX_VECTOR），
    /// rotatedU = Conjugate(q) * (0, u) * q（对于MATHEMATICS_USE_VECTOR_MATRIX）
    /// 的原始实现相比，Rotate(...)函数需要更少的算术运算。
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
        using Vector4Tools = Vector4Tools<Real>;
        using Matrix3 = Matrix3<Real>;
        using AxisAngle = AxisAngle<Real>;
        using QuaternionFactor = QuaternionFactor<Real>;
        using QuaternionConstraints = QuaternionConstraints<Real>;
        using QuaternionSwingTwist = QuaternionSwingTwist<Real>;
        using ArrayType = std::array<Real, entrySize>;
        using ContainerType = std::vector<Vector3>;
        using AlgebraVector3 = Algebra::Vector<3, Real>;
        using AlgebraVector4 = Algebra::Vector<4, Real>;

    public:
        /// 四元数的形式为q = w + x * i + y * j + z * k
        /// 这里(w,x,y,z)不一定是单位长度的四维向量。

        constexpr Quaternion() noexcept
            : w{}, x{}, y{}, z{}
        {
        }

        constexpr Quaternion(Real w, Real x, Real y, Real z) noexcept
            : w{ w }, x{ x }, y{ y }, z{ z }
        {
        }

        /// 输入为旋转矩阵构造四元数
        explicit Quaternion(const Matrix3& matrix);

        /// 通过轴-角的旋转构造四元数
        Quaternion(const Vector3& axis, Real angle) noexcept(gAssert < 1 || gMathematicsAssert < 1);

        /// 通过指定的列旋转矩阵构造四元数。
        explicit Quaternion(const ContainerType& rotationColumn);

        CLASS_INVARIANT_DECLARE;

        /// 坐标访问类似于数组:  0 = w, 1 = x, 2 = y, 3 = z.
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

        /// 一元运算。
        NODISCARD Quaternion operator+() const noexcept;
        NODISCARD Quaternion operator-() const noexcept;

        /// 线性代数运算。
        Quaternion& operator+=(const Quaternion& rhs) noexcept;
        Quaternion& operator-=(const Quaternion& rhs) noexcept;
        Quaternion& operator*=(Real scalar) noexcept;
        Quaternion& operator/=(Real scalar) noexcept;

        /// 算术运算
        Quaternion& operator*=(const Quaternion& rhs) noexcept;

        /// 四元数，矩阵和轴——角之间的转换。
        void FromRotationMatrix(const Matrix3& matrix);
        NODISCARD Matrix3 ToRotationMatrix() const noexcept;
        void FromRotationColumnVector3(const ContainerType& rotationColumn);
        NODISCARD ContainerType ToRotationColumnVector3() const;
        void FromAxisAngle(const Vector3& axis, Real angle) noexcept(gAssert < 1 || gMathematicsAssert < 1);
        NODISCARD Vector3 ToAxis() const;
        NODISCARD Real ToAngle() const noexcept;
        NODISCARD AxisAngle ToAngleAxis() const;

        /// 4-tuple的长度
        NODISCARD Real Length() const noexcept(gAssert < 3 || gMathematicsAssert < 3);

        /// 4-tuple的长度的平方
        NODISCARD Real SquaredLength() const noexcept;

        void Normalize(Real epsilon = Math::GetZeroTolerance()) noexcept(gAssert < 3 || gMathematicsAssert < 3);
        NODISCARD bool IsNormalize(Real epsilon = Math::GetZeroTolerance()) const noexcept(gAssert < 3 || gMathematicsAssert < 3);

        /// 对于非零四元数 q = (w,x,y,z)，inv(q) = (w,-x,-y,-z)/|q|^2，
        /// 其中|q|是四元数的长度。
        /// 当q为零时，函数返回零，这认为是不可能的情况。
        NODISCARD Quaternion Inverse() const;

        /// q = (w,x,y,z) 的共轭是conj(q) = (w,-x,-y,-z)。
        /// 取负数在 x, y, 和 z 上
        NODISCARD Quaternion Conjugate() const noexcept;

        /// 适用于四元数 w = 0
        NODISCARD Quaternion Exp() const noexcept(gAssert < 1 || gMathematicsAssert < 1);

        /// 适用于单位长度四元数
        NODISCARD Quaternion Log() const noexcept;

        /// 由四元数旋转向量。

        /// 使用四元数乘法旋转三维矢量u = (u0,u1,u2)。
        /// 输入四元数必须是单位长度。
        /// 如果R是对应于四元数q的旋转矩阵，
        /// 则当定义了MATHEMATICS_USE_MATRIX_VECTOR（项目的默认值）时，对应于u的旋转矢量v为v = R * u ，
        /// 或者当未定义MATHEMATICS_USE_MATRIX_VECTOR时，为v = u * R。
        NODISCARD Vector3 Rotate(const Vector3& uVector) const;
        NODISCARD AlgebraVector3 Rotate(const AlgebraVector3& uVector) const;

        /// 使用四元数乘法旋转三维矢量，表示为齐次4D矢量u = (u0,u1,u2,0)。
        /// 输入四元数必须是单位长度。
        /// 如果R是对应于四元数q的旋转矩阵，
        /// 则当定义了MATHEMATICS_USE_MATRIX_VECTOR（项目的默认值）时，对应于u的旋转矢量v为v = R * u ，
        /// 或者当未定义MATHEMATICS_USE_MATRIX_VECTOR时，为v = u * R。
        NODISCARD Vector4 Rotate(const Vector4& uVector) const;
        NODISCARD AlgebraVector4 Rotate(const AlgebraVector4& uVector) const;

        /// 球面线性插值
        /// [0,1]中t的单位长度四元数q0和q1的球面线性插值(slerp)为
        /// slerp(t,q0,q1) = [sin(t*theta)*q0 + sin((1-t)*theta)*q1]/sin(theta)
        /// 其中theta是q0和q1之间的角度[cos(theta) = Dot(q0,q1)]。
        /// 这个函数是单位超球面上q0和q1之间的大球面弧的参数化。
        /// 此外，参数化是归一化弧长的一种——粒子沿着弧在时间t内以恒定速度运动。
        ///
        /// 当在涉及四元数序列的动画中使用slerp时，通常对四元数进行预处理，
        /// 以便连续的四元数在[0,pi/2]中形成锐角A。
        /// 其他预处理可以帮助提高性能。请参阅下面的功能注释。
        ///
        /// 请参见SlerpEstimate.{h,inl}用于各种近似，
        /// 包括SLERP<Real>::EstimateRPH，
        /// 它为预处理的四元数提供了良好的性能和准确的结果。

        /// q0和q1之间的角度在[0,pi)中。
        /// 没有角度限制，也没有预先计算任何内容。
        void Slerp(Real t, const Quaternion& quaternion0, const Quaternion& quaternion1);

        /// q0和q1之间的角度必须在[0,pi/2]中。
        /// 后缀Restricted表示“受限”。
        /// 预处理代码为
        ///   Quaternion<Real> q[n];  // 假设已初始化
        ///   for (i0 = 0, i1 = 1; i1 < n; i0 = i1++)
        ///   {
        ///       cosA = Dot(q[i0], q[i1]);
        ///       if (cosA < 0)
        ///       {
        ///           q[i1] = -q[i1];  // 现在 Dot(q[i0], q[i]1) >= 0
        ///       }
        ///   }
        void SlerpChebyshevRatioRestricted(Real t, const Quaternion& quaternion0, const Quaternion& quaternion1);

        /// q0和q1之间的角度必须在[0,pi/2]中。
        /// 后缀Restricted表示“受限”，后缀Preprocessed表示“预处理”。
        /// 预处理代码是
        ///   Quaternion<Real> q[n];  // 假设已初始化
        ///   Real cosA[n-1]; // 待预计算
        ///   Real omCosA[n-1];  // 待预计算
        ///   for (i0 = 0, i1 = 1; i1 < n; i0 = i1++)
        ///   {
        ///       cs = Dot(q[i0], q[i1]);
        ///       if (cosA[i0] < 0)
        ///       {
        ///           q[i1] = -q[i1];
        ///           cs = -cs;
        ///       }
        ///
        ///       // 对 Quaternion<Real>::SlerpRP
        ///       cosA[i0] = cs;
        ///
        ///       // 对 SLERP<Real>::EstimateRP
        ///       omCosA[i0] = 1 - cs;
        ///   }
        void SlerpChebyshevRatioRestrictedPreprocessed(Real t, const Quaternion& quaternion0, const Quaternion& quaternion1, Real cosA);

        /// q0和q1之间的角度是A，并且必须在[0,pi/2]中。
        /// 后缀Restricted表示“受限”，
        /// 后缀Preprocessed表示“预处理”，
        /// 后缀Half表示“半”（预先计算q0和q1中间的四元数quaternionHalf）。
        /// 四元数quaternionHalf是 slerp(1/2,q0,q1) = (q0+q1)/|q0+q1|，
        /// 所以q0和quaternionHalf之间的角度是A/2，
        /// qh和q1之间的角度为A/2。
        /// 预处理代码是
        ///  Quaternion<Real> q[n];  // 假设已初始化
        //   Quaternion<Real> qh[n-1];  // 待预计算
        //   Real omCosAH[n-1];  // 待预计算
        //   for (i0 = 0, i1 = 1; i1 < n; i0 = i1++)
        //   {
        //       cosA = Dot(q[i0], q[i1]);
        //       if (cosA < 0)
        //       {
        //           q[i1] = -q[i1];
        //           cosA = -cosA;
        //       }
        //
        //       // 对 Quaternion<Real>::SlerpRPH 和 SLERP<Real>::EstimateRPH
        //       cosAH[i0] = sqrt((1+cosA)/2);
        //       qh[i0] = (q0 + q1) / (2 * cosAH[i0]);
        //
        //       // 对 SLERP<Real>::EstimateRPH
        //       omCosAH[i0] = 1 - cosAH[i0];
        //   }
        void SlerpChebyshevRatioRestrictedPreprocessedHalf(Real t, const Quaternion& quaternion0, const Quaternion& quaternion1, const Quaternion& quaternionHalf, Real cosAHalf);

        void SlerpExtraSpins(Real t, const Quaternion& quaternion0, const Quaternion& quaternion1, int extraSpins) noexcept;
        void SlerpChebyshevRatio(Real t, const Quaternion& quaternion0, const Quaternion& quaternion1);

        /// 中间条款球面二次插值
        void Intermediate(const Quaternion& quaternion0, const Quaternion& quaternion1, const Quaternion& quaternion2);

        /// 球面二次插值。
        void Squad(Real t, const Quaternion& q0, const Quaternion& a0, const Quaternion& a1, const Quaternion& q1);

        /// 计算旋转单位长度矢量vector0到单位长度矢量vector1的四元数。
        /// 旋转是围绕垂直于vector0和vector1的轴，
        /// 角度是vector0和vector1之间的角度。
        /// 如果vector0和vector1是平行的，旋转任意轴都行，
        /// 例如组合(z2,x2,y2)，其中，vector1 = (x2,y2,z2)。
        void Align(const Vector3& vector0, const Vector3& vector1, Real epsilon = Math::GetZeroTolerance());

        /// 分解四元数为q = q_twist * q_swing，其中q是'this'四元数。
        /// 如果V1是输入轴和V2为V1通过q的旋转，
        /// q_swing表示大约垂直于V1和V2的轴线旋转（见Quaternion::Align），
        /// 并q_twist是大约是V1旋转。
        /// 返回值的第一部分为twist，第二部分为swing。
        NODISCARD QuaternionSwingTwist DecomposeTwistTimesSwing(const Vector3& vector, Real epsilon = Math::GetZeroTolerance()) const;

        /// 分解四元数为q = swing * twist，其中q是'this'四元数。
        /// 如果V1是输入轴和V2为V1通过q的旋转，
        /// swing表示大约垂直于V1和V2的轴线旋转（见Quaternion::Align），
        /// 并twist是大约是V1旋转。
        /// 返回值的第一部分为swing，第二部分为twist。

        NODISCARD QuaternionSwingTwist DecomposeSwingTimesTwist(const Vector3& vector, Real epsilon = Math::GetZeroTolerance()) const;

        /// *** 查找最近无约束的角度的四元数。

        /// 距离最近的四元数形式(cx + sx * i)。
        NODISCARD Quaternion GetClosestX() const;

        /// 距离最近的四元数形式 (cy + sy * j).
        NODISCARD Quaternion GetClosestY() const;

        /// 距离最近的四元数形式 (cz + sz * k).
        NODISCARD Quaternion GetClosestZ() const;

        /// 距离最近的四元数形式 (cx + sx * i) * (cy + sy * j).
        NODISCARD Quaternion GetClosestXY() const noexcept(gAssert < 3 || gMathematicsAssert < 3);

        /// 距离最近的四元数形式 (cy + sy * j) * (cx + sx * i).
        NODISCARD Quaternion GetClosestYX() const noexcept(gAssert < 3 || gMathematicsAssert < 3);

        /// 距离最近的四元数形式 (cz + sz * k) * (cx + sx * i).
        NODISCARD Quaternion GetClosestZX() const;

        /// 距离最近的四元数形式 (cx + sx * i) * (cz + sz * k).
        NODISCARD Quaternion GetClosestXZ() const;

        /// 距离最近的四元数形式 (cy + sy * j) * (cz + sz * k).
        NODISCARD Quaternion GetClosestYZ() const;

        /// 距离最近的四元数形式 (cz + sz * k) * (cy + sy * j).
        NODISCARD Quaternion GetClosestZY() const;

        /// 系数为 (cx + sx * i) * (cy + sy * j) * (cz + sz * k).
        NODISCARD QuaternionFactor FactorXYZ() const noexcept(gAssert < 1 || gMathematicsAssert < 1);

        /// 系数为  (cx + sx * i) * (cz + sz * k) * (cy + sy * j).
        NODISCARD QuaternionFactor FactorXZY() const noexcept(gAssert < 1 || gMathematicsAssert < 1);

        /// 系数为  (cy + sy * j) * (cz + sz * k) * (cx + sx * i).
        NODISCARD QuaternionFactor FactorYZX() const noexcept(gAssert < 1 || gMathematicsAssert < 1);

        /// 系数为  (cy + sy * j) * (cx + sx * i) * (cz + sz * k).
        NODISCARD QuaternionFactor FactorYXZ() const noexcept(gAssert < 1 || gMathematicsAssert < 1);

        /// 系数为 (cz + sz * k) * (cx + sx * i) * (cy + sy * j).
        NODISCARD QuaternionFactor FactorZXY() const noexcept(gAssert < 1 || gMathematicsAssert < 1);

        /// 系数为  (cz + sz * k) * (cy + sy * j) * (cx + sx * i).
        NODISCARD QuaternionFactor FactorZYX() const noexcept(gAssert < 1 || gMathematicsAssert < 1);

        /// 距离最近的约束四元数形式为 (cx + sx * i).
        NODISCARD Quaternion GetClosestX(const QuaternionConstraints& xCon) const;

        /// 距离最近的约束四元数形式为 (cy + sy * j).
        NODISCARD Quaternion GetClosestY(const QuaternionConstraints& yCon) const;

        /// 距离最近的约束四元数形式为 (cz + sz * k).
        NODISCARD Quaternion GetClosestZ(const QuaternionConstraints& zCon) const;

        /// 距离最近的约束四元数形式为 (cx + sx * i)*(cy + sy * j).
        NODISCARD Quaternion GetClosestXY(const QuaternionConstraints& xCon, const QuaternionConstraints& yCon) const;

        /// 距离最近的约束四元数形式为  (cy + sy * j)*(cx + sx * i).
        NODISCARD Quaternion GetClosestYX(const QuaternionConstraints& yCon, const QuaternionConstraints& xCon) const;

        /// 距离最近的约束四元数形式为  (cz + sz * k)*(cx + sx * i).
        NODISCARD Quaternion GetClosestZX(const QuaternionConstraints& zCon, const QuaternionConstraints& xCon) const;

        /// 距离最近的约束四元数形式为  (cx + sx * i)*(cz + sz * k).
        NODISCARD Quaternion GetClosestXZ(const QuaternionConstraints& xCon, const QuaternionConstraints& zCon) const;

        /// 距离最近的约束四元数形式为  (cz + sz * k)*(cy + sy * j).
        NODISCARD Quaternion GetClosestZY(const QuaternionConstraints& zCon, const QuaternionConstraints& yCon) const;

        /// 距离最近的约束四元数形式为  (cy + sy * j)*(cz + sz * k).
        NODISCARD Quaternion GetClosestYZ(const QuaternionConstraints& yCon, const QuaternionConstraints& zCon) const;

        NODISCARD ArrayType GetCoordinate() const noexcept;
        void SetCoordinate(const ArrayType& coordinate) noexcept;

        /// 特殊四元数
        static constexpr Quaternion GetZero() noexcept
        {
            return Quaternion{};
        }

        static constexpr Quaternion GetI() noexcept
        {
            return Quaternion{ Math::GetValue(0), Math::GetValue(1), Math::GetValue(0), Math::GetValue(0) };
        }

        static constexpr Quaternion GetJ() noexcept
        {
            return Quaternion{ Math::GetValue(0), Math::GetValue(0), Math::GetValue(1), Math::GetValue(0) };
        }

        static constexpr Quaternion GetK() noexcept
        {
            return Quaternion{ Math::GetValue(0), Math::GetValue(0), Math::GetValue(0), Math::GetValue(1) };
        }

        static constexpr Quaternion GetIdentity() noexcept
        {
            return Quaternion{ Math::GetValue(1), Math::GetValue(0), Math::GetValue(0), Math::GetValue(0) };
        }

    private:
        /// 距离最近四元数约束的形式：
        ///   (cx + sx * i) 当 QuaternionClosestAxis = QuaternionClosestAxis::X,
        ///   (cy + sy * j) 当 QuaternionClosestAxis = QuaternionClosestAxis::Y,
        ///   (cz + sz * k) 当 QuaternionClosestAxis = QuaternionClosestAxis::Z,
        NODISCARD Quaternion GetClosest(QuaternionClosestAxis axis) const;

        /// 距离最近四元数约束的形式：
        ///   (cx + sx * i) 当 QuaternionClosestAxis = QuaternionClosestAxis::X,
        ///   (cy + sy * j) 当 QuaternionClosestAxis = QuaternionClosestAxis::Y,
        ///   (cz + sz * k) 当 QuaternionClosestAxis = QuaternionClosestAxis::Z,
        NODISCARD Quaternion GetClosest(QuaternionClosestAxis axis, const QuaternionConstraints& con) const;

    private:
        /// 存储的顺序是(w,x,y,z)。
        Real w;
        Real x;
        Real y;
        Real z;
    };

    /// 比较 (仅使用在 STL 容器).
    template <typename Real>
    NODISCARD bool operator==(const Quaternion<Real>& lhs, const Quaternion<Real>& rhs) noexcept;

    template <typename Real>
    NODISCARD bool operator<(const Quaternion<Real>& lhs, const Quaternion<Real>& rhs) noexcept;

    /// 四元数的乘积。乘法一般不是可交换的；所以在大多数情况下，
    /// p * q != q * p
    /// (x0*i + y0*j + z0*k + w0)*(x1*i + y1*j + z1*k + w1)
    /// =
    /// i*(+x0*w1 + y0*z1 - z0*y1 + w0*x1) +
    /// j*(-x0*z1 + y0*w1 + z0*x1 + w0*y1) +
    /// k*(+x0*y1 - y0*x1 + z0*w1 + w0*z1) +
    /// 1*(-x0*x1 - y0*y1 - z0*z1 + w0*w1)
    template <typename Real>
    NODISCARD Quaternion<Real> operator*(const Quaternion<Real>& lhs, const Quaternion<Real>& rhs) noexcept;

    /// 几何运算
    /// 4元组的点积
    template <typename Real>
    NODISCARD Real Dot(const Quaternion<Real>& lhs, const Quaternion<Real>& rhs) noexcept;

    template <typename Real>
    NODISCARD bool Approximate(const Quaternion<Real>& lhs, const Quaternion<Real>& rhs, Real epsilon = Math<Real>::GetZeroTolerance()) noexcept;

    /// 调试输出。
    template <typename Real>
    std::ostream& operator<<(std::ostream& stream, const Quaternion<Real>& quaternion);

    using QuaternionF = Quaternion<float>;
    using QuaternionD = Quaternion<double>;
}

#endif  // MATHEMATICS_ALGEBRA_QUATERNION_H
