///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.3 (2020/11/19 10:25)

#ifndef MATHEMATICS_RATIONAL_INTEGER_MULTIPLICATION_DETAIL_H
#define MATHEMATICS_RATIONAL_INTEGER_MULTIPLICATION_DETAIL_H

#include "IntegerDataAmendDetail.h"
#include "IntegerDataAnalysisDetail.h"
#include "IntegerMultiplication.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

template <int N>
Mathematics::IntegerMultiplication<N>::IntegerMultiplication(const IntegerData& lhs, const IntegerData& rhs)
    : m_LhsData{ lhs },
      m_RhsData{ rhs },
      m_ProductSign{ (m_LhsData.GetSign() == m_RhsData.GetSign() ? NumericalValueSymbol::Positive : NumericalValueSymbol::Negative) },
      m_AbsLhsData{ IntegerDataAnalysis{ m_LhsData }.GetAbsoluteValue() },
      m_AbsRhsData{ IntegerDataAnalysis{ m_RhsData }.GetAbsoluteValue() },
      m_Product(2 * sm_IntSize),
      m_Result(2 * sm_IntSize),
      m_Multiplication{}
{
    Calculate();

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

// private
template <int N>
void Mathematics::IntegerMultiplication<N>::Calculate()
{
    Product();
    OverflowTest();
    Negative();
}

// private
template <int N>
void Mathematics::IntegerMultiplication<N>::Product()
{
    for (auto lhsIndex = 0; lhsIndex < sm_IntSize; ++lhsIndex)
    {
        const auto lhsBit = m_AbsLhsData[lhsIndex];
        if (0 < lhsBit)
        {
            CalculateProduct(lhsBit, lhsIndex);
            const auto carry = CalculateResult(lhsIndex);
            DetermineCarry(carry, lhsIndex + sm_IntSize + 1);
        }
    }
}

// private
template <int N>
void Mathematics::IntegerMultiplication<N>::CalculateProduct(uint32_t lhsBit, uint32_t lhsIndex)
{
    // 将lhs的某个位同rhs的所有位相乘，
    // 结果保存在product中。
    auto productBufferIndex = lhsIndex;
    auto carry = 0;
    for (auto rhsIndex = 0; rhsIndex < sm_IntSize; ++rhsIndex)
    {
        const auto rhsBit = m_AbsRhsData[rhsIndex];
        const auto productBit = lhsBit * rhsBit + carry;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
        m_Product[productBufferIndex] = boost::numeric_cast<uint16_t>(productBit & sm_Low);
#include STSTEM_WARNING_POP

        carry = (productBit & sm_High) >> 16;
        ++productBufferIndex;
    }

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
    m_Product[productBufferIndex] = boost::numeric_cast<uint16_t>(carry);
#include STSTEM_WARNING_POP
}

// private
template <int N>
uint32_t Mathematics::IntegerMultiplication<N>::CalculateResult(uint32_t lhsIndex)
{
    // 将product中保存的值同result中保存的值相加，
    // 结果保存在result中。
    // 确保result的初始值已清零。
    auto bufferIndex = lhsIndex;
    auto carry = 0u;
    for (auto rhsIndex = 0u; rhsIndex <= sm_IntSize; ++rhsIndex)
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
        auto originalProduct = boost::numeric_cast<uint32_t>(m_Product[bufferIndex]);
        auto originalResult = boost::numeric_cast<uint32_t>(m_Result[bufferIndex]);
        auto sum = originalProduct + originalResult + carry;
        m_Result[bufferIndex] = boost::numeric_cast<uint16_t>(sum & sm_Low);
#include STSTEM_WARNING_POP

        carry = (sum & sm_Carry) ? 1 : 0;

        ++bufferIndex;
    }

    return carry;
}

// private
template <int N>
void Mathematics::IntegerMultiplication<N>::DetermineCarry(uint32_t carry, uint32_t resultBufferIndex)
{
    // 判断是否要进位，下面条件如果成立，则表示计算已溢出。
    for (auto rhsIndex = resultBufferIndex; 0 < carry && rhsIndex < m_Result.size(); ++rhsIndex)
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
        auto originalResult = boost::numeric_cast<uint32_t>(m_Result[rhsIndex]);
        auto sum = originalResult + carry;
        m_Result[rhsIndex] = boost::numeric_cast<uint16_t>(sum & sm_Low);
#include STSTEM_WARNING_POP

        carry = (sum & sm_Carry) ? 1 : 0;
    }
}

// private
template <int N>
void Mathematics::IntegerMultiplication<N>::OverflowTest()
{
    // 测试溢出。你可以在前面更早的循环中测试。
    // 但在这里测试，您可以得到溢出多少。
    // 这个信息对一个应用程序可能是有用的，以决定如何选择整数大小。

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
    for (auto i = 2 * sm_IntSize - 1; sm_IntSize <= i; --i)
    {
        if (m_Result[i] != 0)
        {
            THROW_EXCEPTION((CoreTools::Error::Format(SYSTEM_TEXT("Integer溢出在i = %1\n")) % i).str());
        }
    }

    if ((m_Result[sm_IntLast] & sm_Symbol) != 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("Integer溢出\n"s));
    }
#include STSTEM_WARNING_POP

    m_Multiplication = IntegerData{ m_Result };
}

// private
template <int N>
void Mathematics::IntegerMultiplication<N>::Negative()
{
    if (m_ProductSign == NumericalValueSymbol::Negative)
    {
        IntegerDataAmend<N> integerDataAmend{ m_Multiplication };
        integerDataAmend.Negative();
    }
}

#ifdef OPEN_CLASS_INVARIANT
template <int N>
bool Mathematics::IntegerMultiplication<N>::IsValid() const noexcept
{
    return true;
}
#endif  // OPEN_CLASS_INVARIANT

template <int N>
const Mathematics::IntegerData<N> Mathematics::IntegerMultiplication<N>::GetMultiplication() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Multiplication;
}

#endif  // MATHEMATICS_RATIONAL_INTEGER_MULTIPLICATION_DETAIL_H
