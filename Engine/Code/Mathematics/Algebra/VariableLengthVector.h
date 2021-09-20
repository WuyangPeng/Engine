///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.2 (2020/11/11 13:41)

#ifndef MATHEMATICS_ALGEBRA_VARIABLE_LENGTH_VECTOR_H
#define MATHEMATICS_ALGEBRA_VARIABLE_LENGTH_VECTOR_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"
#include "System/Helper/PragmaWarning/Operators.h"
#include "Mathematics/Base/MathDetail.h"

#include <type_traits>
#include <vector>
#include <memory>

namespace Mathematics
{
    template <typename Real>
    class VariableLengthVectorImpl;

    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<VariableLengthVectorImpl<float>>;
    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<VariableLengthVectorImpl<double>>;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<VariableLengthVectorImpl<Real>>;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE VariableLengthVector final : private boost::additive<VariableLengthVector<Real>, boost::multiplicative<VariableLengthVector<Real>, Real, boost::totally_ordered<VariableLengthVector<Real>>>>
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using VariableLengthVectorImpl = VariableLengthVectorImpl<Real>;

    public:
        void Swap(VariableLengthVector& rhs) noexcept;

    public:
        TYPE_DECLARE(VariableLengthVector);
        using ClassShareType = CoreTools::CopyUnsharedClasses;
        ~VariableLengthVector() noexcept = default;
        VariableLengthVector(const VariableLengthVector& rhs);
        VariableLengthVector& operator=(const VariableLengthVector& rhs);
        VariableLengthVector(VariableLengthVector&& rhs) noexcept;
        VariableLengthVector& operator=(VariableLengthVector&& rhs) noexcept;

        using Math = Math<Real>;
        using ContainerType = std::vector<Real>;
        using ContainerTypeIter = typename ContainerType::iterator;
        using ContainerTypeConstIter = typename ContainerType::const_iterator;

    public:
        explicit VariableLengthVector(int size = 0);
        explicit VariableLengthVector(const ContainerType& container);

        CLASS_INVARIANT_DECLARE;

        // �������
        [[nodiscard]] int GetSize() const;

        [[nodiscard]] const Real& operator[](int index) const;
        [[nodiscard]] Real& operator[](int index);

        // �������ô�С�����ԭ�����ݡ�
        void ResetSize(int size);

        [[nodiscard]] const VariableLengthVector operator-() const;

        VariableLengthVector& operator+=(const VariableLengthVector& rhs);
        VariableLengthVector& operator-=(const VariableLengthVector& rhs);
        VariableLengthVector& operator*=(Real scalar);
        VariableLengthVector& operator/=(Real scalar);

        // ��������
        [[nodiscard]] Real Length() const;
        [[nodiscard]] Real SquaredLength() const;
        void Normalize(Real epsilon = Math::GetZeroTolerance());

        [[nodiscard]] const ContainerType GetContainer() const;
        void SetContainer(const ContainerType& container);

        [[nodiscard]] ContainerTypeConstIter begin() const noexcept;
        [[nodiscard]] ContainerTypeConstIter end() const noexcept;

        [[nodiscard]] ContainerTypeIter begin() noexcept;
        [[nodiscard]] ContainerTypeIter end() noexcept;

    private:
        using ImplPtr = std::shared_ptr<ImplType>;    private:        ImplPtr impl;
    };

    // STL
    template <typename Real>
    [[nodiscard]] bool operator==(const VariableLengthVector<Real>& lhs, const VariableLengthVector<Real>& rhs);

    template <typename Real>
    [[nodiscard]] bool operator<(const VariableLengthVector<Real>& lhs, const VariableLengthVector<Real>& rhs);

    template <typename Real>
    [[nodiscard]] Real Dot(const VariableLengthVector<Real>& lhs, const VariableLengthVector<Real>& rhs);

    template <typename Real>
    [[nodiscard]] bool Approximate(const VariableLengthVector<Real>& lhs, const VariableLengthVector<Real>& rhs,
                                   const Real epsilon = Math<Real>::GetZeroTolerance());

    // ���������
    template <typename Real>
    std::ostream& operator<<(std::ostream& outFile, const VariableLengthVector<Real>& vector);

    using FloatVariableLengthVector = VariableLengthVector<float>;
    using DoubleVariableLengthVector = VariableLengthVector<double>;
}

#endif  // MATHEMATICS_ALGEBRA_VARIABLE_LENGTH_VECTOR_H
