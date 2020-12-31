///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.2 (2020/11/11 11:10)

#ifndef MATHEMATICS_ALGEBRA_VARIABLE_LENGTH_VECTOR_IMPL_H
#define MATHEMATICS_ALGEBRA_VARIABLE_LENGTH_VECTOR_IMPL_H

#include "Mathematics/MathematicsDll.h"

#include <type_traits>
#include <vector>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_HIDDEN_DECLARE VariableLengthVectorImpl final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = VariableLengthVectorImpl<Real>;
        using Math = Math<Real>;
        using ContainerType = std::vector<Real>;
        using ContainerTypeIter = typename ContainerType::iterator;
        using ContainerTypeConstIter = typename ContainerType::const_iterator;

    public:
        VariableLengthVectorImpl() noexcept;
        explicit VariableLengthVectorImpl(int size);
        explicit VariableLengthVectorImpl(const ContainerType& variableLengthVector);

        CLASS_INVARIANT_DECLARE;

        // 坐标访问
        int GetSize() const;

        const Real& operator[](int index) const;
        Real& operator[](int index);

        // 重新设置大小会清空原有数据。
        void ResetSize(int size);

        const ContainerType GetContainer() const;
        void SetContainer(const ContainerType& variableLengthVector);

        [[nodiscard]] ContainerTypeConstIter begin() const noexcept;
        [[nodiscard]] ContainerTypeConstIter end() const noexcept;

        [[nodiscard]] ContainerTypeIter begin() noexcept;
        [[nodiscard]] ContainerTypeIter end() noexcept;

        void Negative() noexcept;
        void Plus(const VariableLengthVectorImpl& rhs);
        void Minus(const VariableLengthVectorImpl& rhs);

    private:
        ContainerType m_Container;
    };
}

#endif  // MATHEMATICS_ALGEBRA_VARIABLE_LENGTH_VECTOR_IMPL_H
