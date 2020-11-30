///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.4 (2020/11/24 14:11)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_EIGEN_DECOMPOSITION_ACHIEVE_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_EIGEN_DECOMPOSITION_ACHIEVE_H

#include "EigenDecomposition.h"
#include "Detail/EigenDecompositionImplDetail.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

template <typename Real>
Mathematics::EigenDecomposition<Real>::EigenDecomposition(int size)
    : m_Impl{ std::make_shared<ImplType>(size) }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::EigenDecomposition<Real>::EigenDecomposition(const EigenDecomposition& rhs)
    : m_Impl{ std::make_shared<ImplType>(*rhs.m_Impl) }
{
    IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;
}

template <typename Real>
Mathematics::EigenDecomposition<Real>& Mathematics::EigenDecomposition<Real>::operator=(const EigenDecomposition& rhs)
{
    IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;

    EigenDecomposition temp{ rhs };

    Swap(temp);

    return *this;
}

template <typename Real>
void Mathematics::EigenDecomposition<Real>::Swap(EigenDecomposition& rhs) noexcept
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    std::swap(m_Impl, rhs.m_Impl);
}

template <typename Real>
Mathematics::EigenDecomposition<Real>::EigenDecomposition(EigenDecomposition&& rhs) noexcept
    : m_Impl{ std::move(rhs.m_Impl) }
{
    IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;
}

template <typename Real>
Mathematics::EigenDecomposition<Real>& Mathematics::EigenDecomposition<Real>::operator=(EigenDecomposition&& rhs) noexcept
{
    IMPL_COPY_CONSTRUCTOR_FUNCTION_STATIC_ASSERT;

    m_Impl = std::move(rhs.m_Impl);

    return *this;
}

template <typename Real>
Mathematics::EigenDecomposition<Real>::EigenDecomposition(const Matrix2& rhs)
    : m_Impl{ std::make_shared<ImplType>(rhs) }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::EigenDecomposition<Real>::EigenDecomposition(const Matrix3& rhs)
    : m_Impl{ std::make_shared<ImplType>(rhs) }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::EigenDecomposition<Real>::EigenDecomposition(const VariableMatrix& rhs)
    : m_Impl{ std::make_shared<ImplType>(rhs) }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::EigenDecomposition<Real>& Mathematics::EigenDecomposition<Real>::operator=(const Matrix2& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    EigenDecomposition result{ rhs };

    Swap(result);

    return *this;
}

template <typename Real>
Mathematics::EigenDecomposition<Real>& Mathematics::EigenDecomposition<Real>::operator=(const Matrix3& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    EigenDecomposition result{ rhs };

    Swap(result);

    return *this;
}

template <typename Real>
Mathematics::EigenDecomposition<Real>& Mathematics::EigenDecomposition<Real>::operator=(const VariableMatrix& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    EigenDecomposition result{ rhs };

    Swap(result);

    return *this;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::EigenDecomposition<Real>::IsValid() const noexcept
{
    if (m_Impl != nullptr)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
int Mathematics::EigenDecomposition<Real>::GetSize() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetSize();
}

template <typename Real>
const Real& Mathematics::EigenDecomposition<Real>::operator()(int row, int column) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return (*m_Impl)(row, column);
}

template <typename Real>
Real& Mathematics::EigenDecomposition<Real>::operator()(int row, int column)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26492)
    return const_cast<Real&>(static_cast<const EigenDecomposition&>(*this)(row, column));
#include STSTEM_WARNING_POP
}

template <typename Real>
void Mathematics::EigenDecomposition<Real>::Solve(bool increasingSort)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    return m_Impl->Solve(increasingSort);
}

template <typename Real>
Real Mathematics::EigenDecomposition<Real>::GetEigenvalue(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetEigenvalue(index);
}

template <typename Real>
const Mathematics::Vector2D<Real> Mathematics::EigenDecomposition<Real>::GetEigenvector2(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetEigenvector2(index);
}

template <typename Real>
const Mathematics::Matrix2<Real> Mathematics::EigenDecomposition<Real>::GetEigenvectors2() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetEigenvectors2();
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::EigenDecomposition<Real>::GetEigenvector3(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetEigenvector3(index);
}

template <typename Real>
const Mathematics::Matrix3<Real> Mathematics::EigenDecomposition<Real>::GetEigenvectors3() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetEigenvectors3();
}

template <typename Real>
const Mathematics::VariableLengthVector<Real> Mathematics::EigenDecomposition<Real>::GetEigenvector(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetEigenvector(index);
}

template <typename Real>
const Mathematics::VariableMatrix<Real> Mathematics::EigenDecomposition<Real>::GetEigenvectors() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetEigenvectors();
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_EIGEN_DECOMPOSITION_ACHIEVE_H
