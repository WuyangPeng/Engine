///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.4 (2020/11/26 14:32)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_MINIMIZEN_GET_MINIMUM_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_MINIMIZEN_GET_MINIMUM_DETAIL_H

#include "MinimizeNGetMinimum.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Mathematics/Base/MathDetail.h"

template <typename Real, typename UserDataType>
Mathematics::MinimizeNGetMinimum<Real, UserDataType>::MinimizeNGetMinimum(int dimensions, const Container& initial, Function function,
                                                                          const UserDataType* userData, const Container& begin, const Container& end)
    : m_Dimensions{ dimensions },
      // 初始化设置为标准欧几里得基础方向。
      m_DirectionStorage(GetStorageSize(dimensions)),
      m_DirectionIndex{},
      m_DirectionConjugateIndex{ dimensions },
      m_DirectionCurrentIndex{ -1 },
      m_Save(initial),
      m_Function{ function },
      m_UserData{ userData },
      m_MinimizeNData{ initial, m_Function(initial, m_UserData) },
      m_Begin(begin),
      m_End(end)
{
    for (auto i = 0; i <= dimensions; ++i)
    {
        const auto index = i * dimensions;
        m_DirectionIndex.emplace_back(index);
        if (i != dimensions)
        {
            m_DirectionStorage.at(index) = Math::GetValue(1);
        }
    }

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real, typename UserDataType>
bool Mathematics::MinimizeNGetMinimum<Real, UserDataType>::IsValid() const noexcept
{
    if (0 < m_Dimensions)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real, typename UserDataType>
int Mathematics::MinimizeNGetMinimum<Real, UserDataType>::GetDimensions() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Dimensions;
}

template <typename Real, typename UserDataType>
Real Mathematics::MinimizeNGetMinimum<Real, UserDataType>::CalculateLineArg(int index, Real value) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;
    MATHEMATICS_ASSERTION_0(0 <= index && index < m_Dimensions, "索引错误！");

    return m_MinimizeNData.GetMinLocation(index) + value * GetDirectionCurrent(index);
}

template <typename Real, typename UserDataType>
Real Mathematics::MinimizeNGetMinimum<Real, UserDataType>::GetFunctionResult(const Container& lineArg) const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Function(lineArg, m_UserData);
}

template <typename Real, typename UserDataType>
typename const Mathematics::MinimizeNGetMinimum<Real, UserDataType>::MinimizeNData& Mathematics::MinimizeNGetMinimum<Real, UserDataType>::GetMinimizeNData() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_MinimizeNData;
}

template <typename Real, typename UserDataType>
void Mathematics::MinimizeNGetMinimum<Real, UserDataType>::FindEachDirection(int index, int maxLevel, int maxBracket)
{
    SetDirectionCurrent(index);

    const auto domainResult = ComputeDomain(m_Begin, m_End);

    // 对 1D 函数回调
    const Minimize1 minimizer{ LineFunction, maxLevel, maxBracket, this };

    const auto minimizerData = minimizer.GetMinimum(domainResult.m_BeginResult, domainResult.m_EndResult, Math::GetValue(0));

    auto minLocation = minimizerData.GetMinLocation();

    m_MinimizeNData.Set(minimizerData.GetMinValue(), minLocation, m_DirectionStorage, m_DirectionCurrentIndex);
}

template <typename Real, typename UserDataType>
Real Mathematics::MinimizeNGetMinimum<Real, UserDataType>::EstimateUnitLengthConjugateDirection()
{
    auto length = Math::GetValue(0);
    for (auto i = 0; i < m_Dimensions; ++i)
    {
        const auto storageIndex = m_DirectionConjugateIndex + i;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

        m_DirectionStorage[storageIndex] = m_MinimizeNData.GetMinLocation(i) - m_Save[i];
        length += m_DirectionStorage[storageIndex] * m_DirectionStorage[storageIndex];

#include STSTEM_WARNING_POP
    }

    return Math::Sqrt(length);
}

template <typename Real, typename UserDataType>
void Mathematics::MinimizeNGetMinimum<Real, UserDataType>::MinimizeConjugateDirection(Real length, int maxLevel, int maxBracket)
{
    for (auto i = 0; i < m_Dimensions; ++i)
    {
        const auto index = m_DirectionConjugateIndex + i;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
        m_DirectionStorage[index] /= length;
#include STSTEM_WARNING_POP
    }

    // 最小化共轭方向。
    m_DirectionCurrentIndex = m_DirectionConjugateIndex;
    const auto domainResult = ComputeDomain(m_Begin, m_End);

    const Minimize1 minimizer{ LineFunction, maxLevel, maxBracket, this };
    const auto minimizerData = minimizer.GetMinimum(domainResult.m_BeginResult, domainResult.m_EndResult, Math::GetValue(0));

    m_MinimizeNData.Set(minimizerData.GetMinValue(), minimizerData.GetMinLocation(), m_DirectionStorage, m_DirectionCurrentIndex);

    // 循环方向，并添加共轭方向到集合
    m_DirectionConjugateIndex = 0;
    for (auto i = 0; i < m_Dimensions; ++i)
    {
        const auto next = i + 1;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
        m_DirectionStorage[m_DirectionIndex[i]] = m_DirectionStorage[m_DirectionIndex[next]];
#include STSTEM_WARNING_POP
    }

    // 设置下次的参数。
    m_Save = m_MinimizeNData.GetMinLocation();
}

template <typename Real, typename UserDataType>
Mathematics::MinimizeNGetMinimum<Real, UserDataType>::DomainResult::DomainResult(Real beginResult, Real endResult) noexcept
    : m_BeginResult{ beginResult }, m_EndResult{ endResult }
{
}

template <typename Real, typename UserDataType>
typename Mathematics::MinimizeNGetMinimum<Real, UserDataType>::DomainResult Mathematics::MinimizeNGetMinimum<Real, UserDataType>::ComputeDomain(const Container& begin, const Container& end)
{
    DomainResult result{ -Math::sm_MaxReal, +Math::sm_MaxReal };

    for (auto i = 0; i < m_Dimensions; ++i)
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

        auto beginMinus = begin[i] - m_MinimizeNData.GetMinLocation(i);
        auto endMinus = end[i] - m_MinimizeNData.GetMinLocation(i);

#include STSTEM_WARNING_POP

        if (Math::GetValue(0) < GetDirectionCurrent(i))
        {
            // 有效的间隔是[b0,b1]。
            beginMinus /= GetDirectionCurrent(i);
            if (result.m_BeginResult < beginMinus)
            {
                result.m_BeginResult = beginMinus;
            }
            endMinus /= GetDirectionCurrent(i);
            if (endMinus < result.m_EndResult)
            {
                result.m_EndResult = endMinus;
            }
        }
        else if (GetDirectionCurrent(i) < Math::GetValue(0))
        {
            // 有效的间隔是[b1,b0]。
            beginMinus /= GetDirectionCurrent(i);
            if (beginMinus < result.m_EndResult)
            {
                result.m_EndResult = beginMinus;
            }
            endMinus /= GetDirectionCurrent(i);
            if (result.m_BeginResult < endMinus)
            {
                result.m_BeginResult = endMinus;
            }
        }
    }

    // 数字差错更正导致值几乎为零。
    if (Math::GetValue(0) < result.m_BeginResult)
    {
        result.m_BeginResult = Math::GetValue(0);
    }
    if (result.m_EndResult < Math::GetValue(0))
    {
        result.m_EndResult = Math::GetValue(0);
    }

    return result;
}

// static
template <typename Real, typename UserDataType>
Real Mathematics::MinimizeNGetMinimum<Real, UserDataType>::LineFunction(Real value, const MinimizeNGetMinimum* userData)
{
    if (userData == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("userData指针为空"s));
    }

    const auto dimensions = userData->GetDimensions();

    Container lineArg{};

    for (auto index = 0; index < dimensions; ++index)
    {
        lineArg.emplace_back(userData->CalculateLineArg(index, value));
    }

    return userData->GetFunctionResult(lineArg);
}

template <typename Real, typename UserDataType>
Real Mathematics::MinimizeNGetMinimum<Real, UserDataType>::GetDirectionCurrent(int index) const
{
    const auto storageIndex = m_DirectionCurrentIndex + index;

    return m_DirectionStorage.at(storageIndex);
}

template <typename Real, typename UserDataType>
void Mathematics::MinimizeNGetMinimum<Real, UserDataType>::SetDirectionCurrent(int index) noexcept
{
    m_DirectionCurrentIndex = index;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_MINIMIZEN_GET_MINIMUM_DETAIL_H
