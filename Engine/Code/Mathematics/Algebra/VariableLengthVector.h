///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.11 (2023/05/31 18:04)

#ifndef MATHEMATICS_ALGEBRA_VARIABLE_LENGTH_VECTOR_H
#define MATHEMATICS_ALGEBRA_VARIABLE_LENGTH_VECTOR_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"
#include "System/Helper/PragmaWarning/Operators.h"
#include "Mathematics/Base/MathDetail.h"

#include <memory>
#include <type_traits>
#include <vector>

namespace Mathematics
{
    template <typename Real>
    requires std::is_arithmetic_v<Real>
    class VariableLengthVector final : private boost::additive<VariableLengthVector<Real>, boost::multiplicative<VariableLengthVector<Real>, Real, boost::totally_ordered<VariableLengthVector<Real>>>>
    {
    public:
        using ClassType = VariableLengthVector;

        using Math = Math<Real>;
        using ContainerType = std::vector<Real>;
        using ContainerTypeIter = typename ContainerType::iterator;
        using ContainerTypeConstIter = typename ContainerType::const_iterator;

    public:
        VariableLengthVector() noexcept;
        explicit VariableLengthVector(int size);
        explicit VariableLengthVector(const ContainerType& container);
        explicit VariableLengthVector(ContainerType&& container) noexcept;

        CLASS_INVARIANT_DECLARE;

        // 坐标访问
        NODISCARD int GetSize() const;

        NODISCARD const Real& operator[](int index) const;
        NODISCARD Real& operator[](int index);

        // 重新设置大小会清空原有数据。
        void ResetSize(int size);

        NODISCARD VariableLengthVector operator-() const;

        VariableLengthVector& operator+=(const VariableLengthVector& rhs);
        VariableLengthVector& operator-=(const VariableLengthVector& rhs);
        VariableLengthVector& operator*=(Real scalar) noexcept;
        VariableLengthVector& operator/=(Real scalar) noexcept(gMathematicsAssert < 0);

        // 向量运算
        NODISCARD Real Length() const noexcept(gMathematicsAssert < 2);
        NODISCARD Real SquaredLength() const noexcept(gMathematicsAssert < 2);
        void Normalize(Real epsilon = Math::GetZeroTolerance()) noexcept(gMathematicsAssert < 2);

        NODISCARD ContainerType GetContainer() const;
        void SetContainer(const ContainerType& newContainer);

        NODISCARD ContainerTypeConstIter begin() const noexcept;
        NODISCARD ContainerTypeConstIter end() const noexcept;

        NODISCARD ContainerTypeIter begin() noexcept;
        NODISCARD ContainerTypeIter end() noexcept;

    private:
        ContainerType container;
    };

    // STL
    template <typename Real>
    NODISCARD bool operator==(const VariableLengthVector<Real>& lhs, const VariableLengthVector<Real>& rhs);

    template <typename Real>
    NODISCARD bool operator<(const VariableLengthVector<Real>& lhs, const VariableLengthVector<Real>& rhs);

    template <typename Real>
    NODISCARD Real Dot(const VariableLengthVector<Real>& lhs, const VariableLengthVector<Real>& rhs);

    template <typename Real>
    NODISCARD bool Approximate(const VariableLengthVector<Real>& lhs,
                               const VariableLengthVector<Real>& rhs,
                               const Real epsilon = Math<Real>::GetZeroTolerance());

    // 调试输出。
    template <typename Real>
    std::ostream& operator<<(std::ostream& outFile, const VariableLengthVector<Real>& vector);

    using VariableLengthVectorF = VariableLengthVector<float>;
    using VariableLengthVectorD = VariableLengthVector<double>;
}

#endif  // MATHEMATICS_ALGEBRA_VARIABLE_LENGTH_VECTOR_H
