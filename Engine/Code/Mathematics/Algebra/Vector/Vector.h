/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.5 (2024/01/27 15:29)

#ifndef MATHEMATICS_ALGEBRA_ALGEBRA_VECTOR_H
#define MATHEMATICS_ALGEBRA_ALGEBRA_VECTOR_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Base/MathDetail.h"

#include <array>

namespace Mathematics::Algebra
{
    template <int N, typename Real>
    requires(1 <= N && N <= 4 && std::is_arithmetic_v<Real>)
    class Vector
    {
    public:
        using ClassType = Vector<N, Real>;

        using Container = std::array<Real, N>;
        using Math = Math<Real>;

    public:
        Vector() noexcept;

        /// 元组由输入完全初始化。
        explicit Vector(const Container& container) noexcept;

        Vector(Real x, Real y) noexcept requires(N == 2);
        Vector(Real x, Real y, Real z) noexcept requires(N == 3);
        Vector(Real x, Real y, Real z, Real w) noexcept requires(N == 4);

        /// 对于0 <= direction < N，元素direction是1，所有其他元素都是0。
        /// 如果direction无效，则创建零向量。
        /// 这对于创建标准欧几里得基向量是一种方便；
        /// 另请参见MakeUnit(int) and Unit(int).。
        explicit Vector(int direction);

        CLASS_INVARIANT_DECLARE;

        NODISCARD static constexpr int GetSize() noexcept
        {
            return N;
        }

        /// 成员访问。第一个运算符[]返回的是const引用，而不是Real值。
        /// 这支持通过需要指向数据的常量指针的标准文件操作进行写入。
        NODISCARD const Real& operator[](int index) const;
        NODISCARD Real& operator[](int index);

        /// 排序容器和几何排序的比较。
        NODISCARD bool operator==(const Vector& rhs) const noexcept;
        NODISCARD bool operator!=(const Vector& rhs) const noexcept;

        NODISCARD bool operator<(const Vector& rhs) const noexcept;
        NODISCARD bool operator<=(const Vector& rhs) const noexcept;
        NODISCARD bool operator>(const Vector& rhs) const noexcept;
        NODISCARD bool operator>=(const Vector& rhs) const noexcept;

        /// 特殊矢量。

        /// 所有组件均为0。
        void MakeZero();

        /// 所有组件均为1。
        void MakeOnes();

        /// 分量direction为1，所有其他分量均为零。
        void MakeUnit(int direction);

        NODISCARD static Vector GetZero() noexcept;
        NODISCARD static Vector GetOnes();
        NODISCARD static Vector GetUnit(int direction);

        /// 一元运算。
        NODISCARD Vector operator+() noexcept;
        NODISCARD Vector operator-();

        /// 线性代数运算。
        Vector& operator+=(const Vector& rhs);
        Vector& operator-=(const Vector& rhs);
        Vector& operator*=(Real scalar);
        Vector& operator/=(Real scalar);

        /// 组件代数运算。
        Vector& operator*=(const Vector& rhs);
        Vector& operator/=(const Vector& rhs);

        NODISCARD Real GetMaxComponent() const;

    private:
        // 此数据结构利用了MSVC中内置的运算符[]、范围检查和可视化工具。
        Container container;
    };

    template <int N, typename Real>
    requires(1 <= N && N <= 4 && std::is_arithmetic_v<Real>)
    NODISCARD Vector<N, Real> operator+(const Vector<N, Real>& lhs, const Vector<N, Real>& rhs);

    template <int N, typename Real>
    requires(1 <= N && N <= 4 && std::is_arithmetic_v<Real>)
    NODISCARD Vector<N, Real> operator-(const Vector<N, Real>& lhs, const Vector<N, Real>& rhs);

    template <int N, typename Real>
    requires(1 <= N && N <= 4 && std::is_arithmetic_v<Real>)
    NODISCARD Vector<N, Real> operator*(const Vector<N, Real>& lhs, Real scalar);

    template <int N, typename Real>
    requires(1 <= N && N <= 4 && std::is_arithmetic_v<Real>)
    NODISCARD Vector<N, Real> operator*(Real scalar, const Vector<N, Real>& rhs);

    template <int N, typename Real>
    requires(1 <= N && N <= 4 && std::is_arithmetic_v<Real>)
    NODISCARD Vector<N, Real> operator/(const Vector<N, Real>& lhs, Real scalar);

    template <int N, typename Real>
    requires(1 <= N && N <= 4 && std::is_arithmetic_v<Real>)
    NODISCARD Vector<N, Real> operator*(const Vector<N, Real>& lhs, const Vector<N, Real>& rhs);

    template <int N, typename Real>
    requires(1 <= N && N <= 4 && std::is_arithmetic_v<Real>)
    NODISCARD Vector<N, Real> operator/(const Vector<N, Real>& lhs, const Vector<N, Real>& rhs);

    /// 几何运算。将“robust”设置为“false”的函数使用标准算法对向量进行归一化，
    /// 方法是将长度计算为长度平方的平方根并除以它。
    /// 如果长度为零，则结果可以是无穷大（或NaN）。
    /// 当“robust”设置为“true”时，
    /// 该算法旨在避免浮点溢出，并在长度为零时将归一化向量设置为零。
    template <int N, typename Real>
    requires(1 <= N && N <= 4 && std::is_arithmetic_v<Real>)
    NODISCARD Real Dot(const Vector<N, Real>& lhs, const Vector<N, Real>& rhs);

    template <int N, typename Real>
    requires(1 <= N && N <= 4 && std::is_arithmetic_v<Real>)
    NODISCARD Real Length(const Vector<N, Real>& vector, bool robust = false);

    template <int N, typename Real>
    requires(1 <= N && N <= 4 && std::is_arithmetic_v<Real>)
    Real Normalize(Vector<N, Real>& vector, bool robust = false);

    /// Gram-Schmidt正交归一化，从线性无关的输入生成正交矢量。
    /// 函数返回过程中计算的未规范化矢量的最小长度。
    /// 如果该值几乎为零，则输入可能是线性相关的（在数值舍入误差内）。
    /// 在输入时，必须初始化1 <= numElements <= N和v[0]到v[numElements-1]。
    /// 在输出时，向量v[0]到v[numElements-1]形成正交集。
    template <int N, typename Real>
    requires(1 <= N && N <= 4 && std::is_arithmetic_v<Real>)
    Real Orthonormalize(int numInputs, std::vector<Vector<N, Real>>& vector, bool robust = false);

    /// 构造与非零输入向量正交的单个向量。
    /// 如果最大绝对分量出现在索引i处，
    /// 则正交向量U具有u[i] = v[i+1], u[i+1] = -v[i]，并且所有其它分量为零。
    /// 索引相加i+1是以N为模计算的。
    template <int N, typename Real>
    requires(1 <= N && N <= 4 && std::is_arithmetic_v<Real>)
    NODISCARD Vector<N, Real> GetOrthogonal(const Vector<N, Real>& vector, bool unitLength);

    /// 计算矢量的轴对齐边界框。如果输入有效，则返回值为“true”，在这种情况下，vectorMin和vectorMax具有有效值。
    template <int N, typename Real>
    requires(1 <= N && N <= 4 && std::is_arithmetic_v<Real>)
    NODISCARD bool ComputeExtremes(int numVectors, std::vector<Vector<N, Real>>& vector, Vector<N, Real>& vectorMin, Vector<N, Real>& vectorMax);

    /// 将n元组vector提升到齐次(n+1)-元组(v,last)。
    template <int N, typename Real>
    requires(1 <= N && N <= 3 && std::is_arithmetic_v<Real>)
    NODISCARD Vector<N + 1, Real> HomogeneousLift(const Vector<N, Real>& vector, Real last);

    /// 将齐次n元组v = (u,v[n-1])投影到(n-1)-元组u。
    template <int N, typename Real>
    requires(2 <= N && N <= 4 && std::is_arithmetic_v<Real>)
    NODISCARD Vector<N - 1, Real> HomogeneousProject(const Vector<N, Real>& vector);

    /// 将n元组v = (w0,w1) 提升到(n+1)-元组u = (w0,u[inject],w1)。
    /// 根据推断，w0是 (inject)-元组[当inject=0时不存在]，
    /// w1是(n-inject)-元组[当inject=n时不存在]。
    template <int N, typename Real>
    requires(1 <= N && N <= 3 && std::is_arithmetic_v<Real>)
    NODISCARD Vector<N + 1, Real> Lift(const Vector<N, Real>& vector, int inject, Real value);

    /// 将n元组v = (w0,v[reject],w1) 投影到 (n-1)-元组u = (w0,w1)。
    /// 通过推断，w0是(reject)-元组[当reject=0时不存在]，
    /// w1是(n-1-reject)-元组（当reject=n-1时不存在）。
    template <int N, typename Real>
    requires(2 <= N && N <= 4 && std::is_arithmetic_v<Real>)
    NODISCARD Vector<N - 1, Real> Project(const Vector<N, Real>& vector, int reject);
}

#endif  // MATHEMATICS_ALGEBRA_ALGEBRA_VECTOR_H
