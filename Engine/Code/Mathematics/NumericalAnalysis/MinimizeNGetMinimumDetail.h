///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 10:20)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_MINIMIZEN_GET_MINIMUM_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_MINIMIZEN_GET_MINIMUM_DETAIL_H

#include "MinimizeNGetMinimum.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Mathematics/Base/MathDetail.h"

template <typename Real, typename UserDataType>
Mathematics::MinimizeNGetMinimum<Real, UserDataType>::MinimizeNGetMinimum(int dimensions,
                                                                          const Container& initial,
                                                                          Function function,
                                                                          const UserDataType* userData,
                                                                          const Container& begin,
                                                                          const Container& end)
    : dimensions{ dimensions },
      // 初始化设置为标准欧几里得基础方向。
      directionStorage(GetStorageSize(dimensions)),
      directionIndex{},
      directionConjugateIndex{ dimensions },
      directionCurrentIndex{ -1 },
      save(initial),
      function{ function },
      userData{ userData },
      minimizeNData{ initial, this->function(initial, userData) },
      beginContainer(begin),
      endContainer(end)
{
    for (auto i = 0; i <= dimensions; ++i)
    {
        const auto index = i * dimensions;
        directionIndex.emplace_back(index);
        if (i != dimensions)
        {
            directionStorage.at(index) = Math::GetValue(1);
        }
    }

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real, typename UserDataType>
bool Mathematics::MinimizeNGetMinimum<Real, UserDataType>::IsValid() const noexcept
{
    if (0 < dimensions)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real, typename UserDataType>
int Mathematics::MinimizeNGetMinimum<Real, UserDataType>::GetDimensions() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return dimensions;
}

template <typename Real, typename UserDataType>
Real Mathematics::MinimizeNGetMinimum<Real, UserDataType>::CalculateLineArg(int index, Real value) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;
    MATHEMATICS_ASSERTION_0(0 <= index && index < dimensions, "索引错误！");

    return minimizeNData.GetMinLocation(index) + value * GetDirectionCurrent(index);
}

template <typename Real, typename UserDataType>
Real Mathematics::MinimizeNGetMinimum<Real, UserDataType>::GetFunctionResult(const Container& lineArg) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    if (function != nullptr)
    {
        return function(lineArg, userData);
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("function 指针为空。"s));
    }
}

template <typename Real, typename UserDataType>
const typename Mathematics::MinimizeNGetMinimum<Real, UserDataType>::MinimizeNData& Mathematics::MinimizeNGetMinimum<Real, UserDataType>::GetMinimizeNData() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return minimizeNData;
}

template <typename Real, typename UserDataType>
void Mathematics::MinimizeNGetMinimum<Real, UserDataType>::FindEachDirection(int index, int maxLevel, int maxBracket)
{
    SetDirectionCurrent(index);

    const auto domainResult = ComputeDomain(beginContainer, endContainer);

    // 对 1D 函数回调
    const Minimize1 minimizer{ LineFunction, maxLevel, maxBracket, this };

    const auto minimizerData = minimizer.GetMinimum(domainResult.beginResult, domainResult.endResult, Math::GetValue(0));

    auto minLocation = minimizerData.GetMinLocation();

    minimizeNData.Set(minimizerData.GetMinValue(), minLocation, directionStorage, directionCurrentIndex);
}

template <typename Real, typename UserDataType>
Real Mathematics::MinimizeNGetMinimum<Real, UserDataType>::EstimateUnitLengthConjugateDirection()
{
    auto length = Math::GetValue(0);
    for (auto i = 0; i < dimensions; ++i)
    {
        const auto storageIndex = directionConjugateIndex + i;

        directionStorage.at(storageIndex) = minimizeNData.GetMinLocation(i) - save.at(i);
        length += directionStorage.at(storageIndex) * directionStorage.at(storageIndex);
    }

    return Math::Sqrt(length);
}

template <typename Real, typename UserDataType>
void Mathematics::MinimizeNGetMinimum<Real, UserDataType>::MinimizeConjugateDirection(Real length, int maxLevel, int maxBracket)
{
    for (auto i = 0; i < dimensions; ++i)
    {
        const auto index = directionConjugateIndex + i;

        directionStorage.at(index) /= length;
    }

    // 最小化共轭方向。
    directionCurrentIndex = directionConjugateIndex;
    const auto domainResult = ComputeDomain(beginContainer, endContainer);

    const Minimize1 minimizer{ LineFunction, maxLevel, maxBracket, this };
    const auto minimizerData = minimizer.GetMinimum(domainResult.beginResult, domainResult.endResult, Math::GetValue(0));

    minimizeNData.Set(minimizerData.GetMinValue(), minimizerData.GetMinLocation(), directionStorage, directionCurrentIndex);

    // 循环方向，并添加共轭方向到集合
    directionConjugateIndex = 0;
    for (auto i = 0; i < dimensions; ++i)
    {
        const auto next = i + 1;

        directionStorage.at(directionIndex.at(i)) = directionStorage.at(directionIndex.at(next));
    }

    // 设置下次的参数。
    save = minimizeNData.GetMinLocation();
}

template <typename Real, typename UserDataType>
Mathematics::MinimizeNGetMinimum<Real, UserDataType>::DomainResult::DomainResult(Real beginResult, Real endResult) noexcept
    : beginResult{ beginResult }, endResult{ endResult }
{
}

template <typename Real, typename UserDataType>
typename Mathematics::MinimizeNGetMinimum<Real, UserDataType>::DomainResult Mathematics::MinimizeNGetMinimum<Real, UserDataType>::ComputeDomain(const Container& begin, const Container& end)
{
    DomainResult result{ -Math::maxReal, +Math::maxReal };

    for (auto i = 0; i < dimensions; ++i)
    {
        auto beginMinus = begin.at(i) - minimizeNData.GetMinLocation(i);
        auto endMinus = end.at(i) - minimizeNData.GetMinLocation(i);

        if (Math::GetValue(0) < GetDirectionCurrent(i))
        {
            // 有效的间隔是[b0,b1]。
            beginMinus /= GetDirectionCurrent(i);
            if (result.beginResult < beginMinus)
            {
                result.beginResult = beginMinus;
            }
            endMinus /= GetDirectionCurrent(i);
            if (endMinus < result.endResult)
            {
                result.endResult = endMinus;
            }
        }
        else if (GetDirectionCurrent(i) < Math::GetValue(0))
        {
            // 有效的间隔是[b1,b0]。
            beginMinus /= GetDirectionCurrent(i);
            if (beginMinus < result.endResult)
            {
                result.endResult = beginMinus;
            }
            endMinus /= GetDirectionCurrent(i);
            if (result.beginResult < endMinus)
            {
                result.beginResult = endMinus;
            }
        }
    }

    // 数字差错更正导致值几乎为零。
    if (Math::GetValue(0) < result.beginResult)
    {
        result.beginResult = Math::GetValue(0);
    }
    if (result.endResult < Math::GetValue(0))
    {
        result.endResult = Math::GetValue(0);
    }

    return result;
}

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
    const auto storageIndex = directionCurrentIndex + index;

    return directionStorage.at(storageIndex);
}

template <typename Real, typename UserDataType>
void Mathematics::MinimizeNGetMinimum<Real, UserDataType>::SetDirectionCurrent(int index) noexcept
{
    directionCurrentIndex = index;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_MINIMIZEN_GET_MINIMUM_DETAIL_H
