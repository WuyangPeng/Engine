/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 23:19)

#ifndef MATHEMATICS_RATIONAL_INTEGER_MULTIPLICATION_DETAIL_H
#define MATHEMATICS_RATIONAL_INTEGER_MULTIPLICATION_DETAIL_H

#include "IntegerDataAmendDetail.h"
#include "IntegerDataAnalysisDetail.h"
#include "IntegerMultiplication.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <int N>
Mathematics::IntegerMultiplication<N>::IntegerMultiplication(const IntegerDataType& lhs, const IntegerDataType& rhs)
    : lhsData{ lhs },
      rhsData{ rhs },
      productSign{ (lhsData.GetSign() == rhsData.GetSign() ? NumericalValueSymbol::Positive : NumericalValueSymbol::Negative) },
      absLhsData{ IntegerDataAnalysisType{ lhsData }.GetAbsoluteValue() },
      absRhsData{ IntegerDataAnalysisType{ rhsData }.GetAbsoluteValue() },
      product(2 * intSize),
      result(2 * intSize),
      multiplication{}
{
    Calculate();

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <int N>
void Mathematics::IntegerMultiplication<N>::Calculate()
{
    Product();
    OverflowTest();
    Negative();
}

template <int N>
void Mathematics::IntegerMultiplication<N>::Product()
{
    for (auto lhsIndex = 0; lhsIndex < intSize; ++lhsIndex)
    {
        const auto lhsBit = absLhsData[lhsIndex];
        if (0 < lhsBit)
        {
            CalculateProduct(lhsBit, lhsIndex);
            const auto carry = CalculateResult(lhsIndex);
            DetermineCarry(carry, lhsIndex + intSize + 1);
        }
    }
}

template <int N>
void Mathematics::IntegerMultiplication<N>::CalculateProduct(uint32_t lhsBit, uint32_t lhsIndex)
{
    // ��lhs��ĳ��λͬrhs������λ��ˣ�
    // ���������product�С�
    auto productBufferIndex = lhsIndex;
    auto carry = 0;
    for (auto rhsIndex = 0; rhsIndex < intSize; ++rhsIndex)
    {
        const auto rhsBit = absRhsData[rhsIndex];
        const auto productBit = lhsBit * rhsBit + carry;

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

        product[productBufferIndex] = boost::numeric_cast<uint16_t>(productBit & low);

#include SYSTEM_WARNING_POP

        carry = (productBit & high) >> 16;
        ++productBufferIndex;
    }

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    product[productBufferIndex] = boost::numeric_cast<uint16_t>(carry);

#include SYSTEM_WARNING_POP
}

template <int N>
uint32_t Mathematics::IntegerMultiplication<N>::CalculateResult(uint32_t lhsIndex)
{
    // ��product�б����ֵͬresult�б����ֵ��ӣ�
    // ���������result�С�
    // ȷ��result�ĳ�ʼֵ�����㡣
    auto bufferIndex = lhsIndex;
    auto carry = 0u;
    for (auto rhsIndex = 0u; rhsIndex <= intSize; ++rhsIndex)
    {
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

        const auto originalProduct = boost::numeric_cast<uint32_t>(product[bufferIndex]);
        const auto originalResult = boost::numeric_cast<uint32_t>(result[bufferIndex]);
        const auto sum = originalProduct + originalResult + carry;
        result[bufferIndex] = boost::numeric_cast<uint16_t>(sum & low);

#include SYSTEM_WARNING_POP

        carry = (sum & integerCarry) ? 1 : 0;

        ++bufferIndex;
    }

    return carry;
}

template <int N>
void Mathematics::IntegerMultiplication<N>::DetermineCarry(uint32_t carry, uint32_t resultBufferIndex)
{
    // �ж��Ƿ�Ҫ��λ����������������������ʾ�����������
    for (auto rhsIndex = resultBufferIndex; 0 < carry && rhsIndex < result.size(); ++rhsIndex)
    {
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

        const auto originalResult = boost::numeric_cast<uint32_t>(result[rhsIndex]);
        const auto sum = originalResult + carry;
        result[rhsIndex] = boost::numeric_cast<uint16_t>(sum & low);

#include SYSTEM_WARNING_POP

        carry = (sum & integerCarry) ? 1 : 0;
    }
}

template <int N>
void Mathematics::IntegerMultiplication<N>::OverflowTest()
{
    // ����������������ǰ������ѭ���в��ԡ�
    // ����������ԣ������Եõ�������١�
    // �����Ϣ��һ��Ӧ�ó�����������õģ��Ծ������ѡ��������С��

    for (auto i = 2 * intSize - 1; intSize <= i; --i)
    {
        if (result.at(i) != 0)
        {
            THROW_EXCEPTION((CoreTools::Error::Format(SYSTEM_TEXT("Integer�����i = %1%\n")) % i).str());
        }
    }

    if ((result.at(intLast) & symbol) != 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("Integer���\n"s));
    }

    multiplication = IntegerDataType{ result };
}

template <int N>
void Mathematics::IntegerMultiplication<N>::Negative()
{
    if (productSign == NumericalValueSymbol::Negative)
    {
        IntegerDataAmend<N> integerDataAmend{ multiplication };
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
Mathematics::IntegerData<N> Mathematics::IntegerMultiplication<N>::GetMultiplication() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return multiplication;
}

#endif  // MATHEMATICS_RATIONAL_INTEGER_MULTIPLICATION_DETAIL_H
