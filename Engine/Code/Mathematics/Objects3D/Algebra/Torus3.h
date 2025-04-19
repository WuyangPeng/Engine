///	Copyright (c) 2010-2024
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.6 (2024/02/27 20:13)

#ifndef MATHEMATICS_OBJECTS_3D_ALGEBRA_TORUS3_H
#define MATHEMATICS_OBJECTS_3D_ALGEBRA_TORUS3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector/Vector3.h"

/// 具有原点(0,0,0)、外半径r0和内半径r1（其中（r0 >= r1）的环面隐式定义如下。
/// 点P0 = (x,y,z)在环面上。它在xy平面上的投影是P1 = (x,y,0)。
/// 包含投影的圆环体的圆形横截面的半径为r0，中心P2 = r0*(x,y,0)/sqrt(x^2+y^2)。
/// 点三角形是在P1处具有直角的直角三角形。
/// 斜边的长度为r1，边为z，边为|r0 - sqrt(x^2+y^2)|。
/// 勾股定理说z^2 + |r0 - sqrt(x^2+y^2)|^2 = r1^2。这可以通过代数运算来实现
///   (x^2 + y^2 + z^2 + r0^2 - r1^2)^2 - 4 * r0^2 * (x^2 + y^2) = 0
///
/// 参数化形式是
///   x = (r0 + r1 * cos(v)) * cos(u)
///   y = (r0 + r1 * cos(v)) * sin(u)
///   z = r1 * sin(v)
///   对于[0,2*pi)中的u和[0,2*pi)中的v。
///
/// 一般来说，让环面中心为C，对称平面包含C并具有方向D0和D1。
/// 对称轴是包含C并且具有方向N（平面法线）的线。
/// 从圆环体中心开始的半径为r0，圆环体的管的半径为r1。
/// 点P可以写成P = C + x*D0 + y*D1 + z*N，
/// 其中矩阵[D0 D1N]是正交的并且具有行列式1。
/// 因此，x = Dot(D0,P-C)，y = Dot(D1,P-C)和z = Dot(N,P-C)。隐含形式是
///      [|P-C|^2 + r0^2 - r1^2]^2 - 4*r0^2*[|P-C|^2 - (Dot(N,P-C))^2] = 0
/// 观察到D0和D1不存在于方程中，这是对称性所期望的。参数形式为
///      P(u,v) = C + (r0 + r1*cos(v))*(cos(u)*D0 + sin(u)*D1) + r1*sin(v)*N
/// 对于[0,2*pi)中的u和[0,2*pi)中的v。
///
/// 在类Torus3中，成员是'center' C, 'direction0' D0,
/// 'direction1' D1, 'normal' N, 'radius0' r0 和 'radius1' r1。
namespace Mathematics::Algebra
{
    template <typename Real>
    requires(std::is_arithmetic_v<Real>)
    class Torus3
    {
    public:
        using ClassType = Torus3<Real>;

        using MathType = Math<Real>;
        using Vector3Type = Vector3<Real>;
        using EvaluateResult = std::vector<Vector3Type>;

    public:
        /// 默认构造函数设置
        // center到(0,0,0)，direction0到(1,0,0)，direction1到(0,1,0)、normal
        // 到(0,0,1)，radius0到2，radius1到1。
        Torus3() noexcept;
        Torus3(Vector3Type center,
               Vector3Type direction0,
               Vector3Type direction1,
               Vector3Type normal,
               Real radius0,
               Real radius1) noexcept;

        CLASS_INVARIANT_DECLARE;

        /// 表面评估。
        /// 该函数支持通过阶数2进行导数计算；
        /// 即maxOrder <= 2是必需的。
        /// 如果只需要位置，则传入maxOrder为0。
        /// 如果你想要位置和一阶导数，可以输入maxOrder为1，依此类推。
        /// 输出的'values'顺序为：position X；
        /// 一阶导数dX/du, dX/dv；
        /// 二阶导数d2X/du2, d2X/dudv, d2X/dv2。
        /// 输入数组'jet'必须有足够的存储空间才能满足指定的订单。
        NODISCARD EvaluateResult Evaluate(Real u, Real v, int maxOrder) const;

        /// 从位置反向查找参数。
        void GetParameters(const Vector3Type& x, Real& u, Real& v) const;

        NODISCARD Vector3Type GetCenter() const noexcept;
        void SetCenter(const Vector3Type& aCenter) noexcept;

        NODISCARD Vector3Type GetDirection0() const noexcept;
        void SetDirection0(const Vector3Type& aDirection0) noexcept;

        NODISCARD Vector3Type GetDirection1() const noexcept;
        void SetDirection1(const Vector3Type& aDirection1) noexcept;

        NODISCARD Vector3Type GetNormal() const noexcept;
        void SetNormal(const Vector3Type& aNormal) noexcept;

        NODISCARD Real GetRadius0() const noexcept;
        void SetRadius0(Real aRadius0) noexcept;

        NODISCARD Real GetRadius1() const noexcept;
        void SetRadius1(Real aRadius1) noexcept;

    private:
        Vector3Type center;
        Vector3Type direction0;
        Vector3Type direction1;
        Vector3Type normal;
        Real radius0;
        Real radius1;
    };

    /// 与支持排序容器的比较。
    template <typename Real>
    requires std::is_arithmetic_v<Real>
    NODISCARD bool operator==(const Torus3<Real>& lhs, const Torus3<Real>& rhs);

    template <typename Real>
    requires std::is_arithmetic_v<Real>
    NODISCARD bool operator!=(const Torus3<Real>& lhs, const Torus3<Real>& rhs);

    template <typename Real>
    requires std::is_arithmetic_v<Real>
    NODISCARD bool operator<(const Torus3<Real>& lhs, const Torus3<Real>& rhs);

    template <typename Real>
    requires std::is_arithmetic_v<Real>
    NODISCARD bool operator<=(const Torus3<Real>& lhs, const Torus3<Real>& rhs);

    template <typename Real>
    requires std::is_arithmetic_v<Real>
    NODISCARD bool operator>(const Torus3<Real>& lhs, const Torus3<Real>& rhs);

    template <typename Real>
    requires std::is_arithmetic_v<Real>
    NODISCARD bool operator>=(const Torus3<Real>& lhs, const Torus3<Real>& rhs);
}

#endif  // MATHEMATICS_OBJECTS_3D_ALGEBRA_TORUS3_H
