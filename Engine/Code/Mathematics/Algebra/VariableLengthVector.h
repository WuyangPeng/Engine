/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.5 (2024/02/05 09:20)

#ifndef MATHEMATICS_ALGEBRA_VARIABLE_LENGTH_VECTOR_H
#define MATHEMATICS_ALGEBRA_VARIABLE_LENGTH_VECTOR_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"
#include "System/Helper/PragmaWarning/Operators.h"
#include "Mathematics/Base/MathDetail.h"

#include <vector>

namespace Mathematics
{
    template <typename Real>
    requires std::is_arithmetic_v<Real>
    class VariableLengthVector final : private boost::additive<VariableLengthVector<Real>, boost::multiplicative<VariableLengthVector<Real>, Real, boost::totally_ordered<VariableLengthVector<Real>>>>
    {
    public:
        using ClassType = VariableLengthVector;

        using MathType = Math<Real>;
        using ContainerType = std::vector<Real>;
        using ContainerTypeIter = typename ContainerType::iterator;
        using ContainerTypeConstIter = typename ContainerType::const_iterator;

    public:
        /// 元组的长度为零。
        VariableLengthVector() noexcept;

        /// 元组的长度为“size”。
        explicit VariableLengthVector(int size);

        explicit VariableLengthVector(const ContainerType& container);
        explicit VariableLengthVector(ContainerType&& container) noexcept;

        /// 对于0<=d<=size，元素d为1，所有其他元素均为零。如果d无效，则创建零向量。这对于创建标准欧几里得基向量是一种方便；另请参见MakeUnit（int32_t，int32_t）和Unit（int32_t，int32\ut）。
        VariableLengthVector(int size, int dimension);

        CLASS_INVARIANT_DECLARE;

        /// 成员访问。SetSize(int)未初始化元组。
        /// 第一个运算符[]返回的是const引用，而不是Real值。
        /// 这支持通过需要指向数据的常量指针的标准文件操作进行写入。

        NODISCARD int GetSize() const;

        void SetSize(int size);

        /// 坐标访问
        NODISCARD const Real& operator[](int index) const;
        NODISCARD Real& operator[](int index);

        /// 一元运算。
        NODISCARD VariableLengthVector operator+() const;
        NODISCARD VariableLengthVector operator-() const;

        VariableLengthVector& operator+=(const VariableLengthVector& rhs);
        VariableLengthVector& operator-=(const VariableLengthVector& rhs);
        VariableLengthVector& operator*=(Real scalar) noexcept;
        VariableLengthVector& operator/=(Real scalar) noexcept(gMathematicsAssert < 0);

        /// 几何运算。
        /// 将'robust'设置为'false'的函数使用标准算法对向量进行归一化，
        /// 方法是将长度计算为长度平方的平方根并除以它。
        /// 如果长度为零，则结果可以是无穷大（或NaN）。
        /// 当'robust'设置为'true'时，该算法旨在避免浮点溢出，
        /// 并在长度为零时将归一化向量设置为零。
        NODISCARD Real Length(bool robust = false) const;
        NODISCARD Real SquaredLength(bool robust = false) const;
        Real Normalize(Real epsilon = MathType::GetZeroTolerance(), bool robust = false);

        NODISCARD ContainerType GetContainer() const;
        void SetContainer(const ContainerType& aContainer);

        NODISCARD ContainerTypeConstIter begin() const noexcept;
        NODISCARD ContainerTypeConstIter end() const noexcept;

        NODISCARD ContainerTypeIter begin() noexcept;
        NODISCARD ContainerTypeIter end() noexcept;

        NODISCARD bool Equal(const VariableLengthVector& rhs) const;
        NODISCARD bool Less(const VariableLengthVector& rhs) const;

        /// 特殊矢量。

        /// 所有组件均为0。
        void MakeZero();

        /// 分量dimension为1，所有其他分量均为零。
        void MakeUnit(int dimension);

        NODISCARD static VariableLengthVector Zero(int size);
        NODISCARD static VariableLengthVector Unit(int size, int dimension);

    private:
        /// 此数据结构利用了MSVC中内置的运算符[]、范围检查和可视化工具。
        ContainerType container;
    };

    // 比较（供STL容器使用）。
    template <typename Real>
    requires std::is_arithmetic_v<Real>
    NODISCARD bool operator==(const VariableLengthVector<Real>& lhs, const VariableLengthVector<Real>& rhs);

    template <typename Real>
    requires std::is_arithmetic_v<Real>
    NODISCARD bool operator<(const VariableLengthVector<Real>& lhs, const VariableLengthVector<Real>& rhs);

    template <typename Real>
    requires std::is_arithmetic_v<Real>
    NODISCARD Real Dot(const VariableLengthVector<Real>& lhs, const VariableLengthVector<Real>& rhs);

    template <typename Real>
    requires std::is_arithmetic_v<Real>
    NODISCARD bool Approximate(const VariableLengthVector<Real>& lhs,
                               const VariableLengthVector<Real>& rhs,
                               Real epsilon = Math<Real>::GetZeroTolerance());

    /// Gram-Schmidt正交归一化，从线性无关的输入生成正交矢量。
    /// 函数返回过程中计算的未规范化矢量的最小长度。
    /// 如果该值几乎为零，则输入可能是线性相关的（在数值舍入误差内）。
    /// 在输入时，必须初始化1<=numElements<=N和vector[0]到vector[numElements-1]。
    /// 在输出时，向量vector[0]到vector[numElements-1]形成正交集。
    template <typename Real>
    requires std::is_arithmetic_v<Real>
    Real Orthonormalize(int numInputs, std::vector<VariableLengthVector<Real>>& vector, bool robust = false);

    /// 计算矢量的轴对齐边界框。
    /// 如果输入无效，则抛出异常，
    /// 在没有抛出异常的情况下，vectorMin和vectorMax具有有效值。
    template <typename Real>
    requires std::is_arithmetic_v<Real>
    void ComputeExtremes(int numVectors, const std::vector<VariableLengthVector<Real>>& vector, VariableLengthVector<Real>& vectorMin, VariableLengthVector<Real>& vectorMax);

    /// 将n元组v提升到齐次(n+1)-元组(v,last)。
    template <typename Real>
    requires std::is_arithmetic_v<Real>
    NODISCARD VariableLengthVector<Real> HomogeneousLift(const VariableLengthVector<Real>& vector, Real last);

    /// 将齐次n元组v = (u,v[n-1])投影到(n-1)-元组u。
    template <typename Real>
    NODISCARD VariableLengthVector<Real> HomogeneousProject(const VariableLengthVector<Real>& vector);

    /// 将n元组v = (w0,w1)提升到(n+1)-元组u = (w0,u[inject],w1)。
    /// 根据推断，w0是(inject)-元组[当inject=0时不存在]，
    /// w1是-元组[inject=n时不存在]。
    template <typename Real>
    NODISCARD VariableLengthVector<Real> Lift(const VariableLengthVector<Real>& vector, int inject, Real value);

    /// 将n元组 v = (w0,v[reject],w1)投影到(n-1)-元组u = (w0,w1)。
    /// 通过推断，w0是(reject)-元组[当reject=0时不存在]，
    /// w1是(n-1-reject)-元组[当reject=n-1时不存在]。
    template <typename Real>
    NODISCARD VariableLengthVector<Real> Project(const VariableLengthVector<Real>& vector, int reject);

    // 调试输出。
    template <typename Real>
    requires std::is_arithmetic_v<Real>
    std::ostream& operator<<(std::ostream& outFile, const VariableLengthVector<Real>& vector);

    using VariableLengthVectorF = VariableLengthVector<float>;
    using VariableLengthVectorD = VariableLengthVector<double>;
}

#endif  // MATHEMATICS_ALGEBRA_VARIABLE_LENGTH_VECTOR_H
