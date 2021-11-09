///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.4 (2021/09/30 20:38)

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppExport.h"

#include "Terms16.h"

#include <cmath>

BookExperience::EffectiveModernCpp::Chapter3::Terms16::Example0::Polynomial::RootsType BookExperience::EffectiveModernCpp::Chapter3::Terms16::Example0::Polynomial::Roots() const
{
    return RootsType{ 1.0 };
}

BookExperience::EffectiveModernCpp::Chapter3::Terms16::Example1::Polynomial::RootsType BookExperience::EffectiveModernCpp::Chapter3::Terms16::Example1::Polynomial::Roots() const
{
    if (!rootsAreValid)  // 如果缓存无效
    {
        // ...
        rootsAreValid = true;  // 则计算根，并将其存入rootVals
    }

    return rootVals;
}

BookExperience::EffectiveModernCpp::Chapter3::Terms16::Example2::Polynomial::RootsType BookExperience::EffectiveModernCpp::Chapter3::Terms16::Example2::Polynomial::Roots() const
{
    std::lock_guard<std::mutex> g(m);  // 加上互斥量

    if (!rootsAreValid)  // 如果缓存无效则计算，存储roots
    {
        // ...
        rootsAreValid = true;
    }

    return rootVals;  // 解锁互斥量
}

double BookExperience::EffectiveModernCpp::Chapter3::Terms16::Point::DistanceFromOrgin() const noexcept
{
    ++callCount;

    return std::sqrt((x * x) + (y * y));
}

int BookExperience::EffectiveModernCpp::Chapter3::Terms16::Example0::Widget::MagicValue() const noexcept
{
    if (cachedValue)
    {
        return cachedValue;
    }
    else
    {
        const auto val1 = ExpensiveComputation1();
        const auto val2 = ExpensiveComputation2();
        cachedValue = val1 + val2;  // 第一部分
        cacheValid = true;  // 第二部分

        return cachedValue;
    }
}

int BookExperience::EffectiveModernCpp::Chapter3::Terms16::Example1::Widget::MagicValue() const noexcept
{
    if (cachedValue)
    {
        return cachedValue;
    }
    else
    {
        const auto val1 = ExpensiveComputation1();
        const auto val2 = ExpensiveComputation2();
        cacheValid = true;  // 第一部分
        cachedValue = val1 + val2;  // 第二部分

        return cachedValue;
    }
}

int BookExperience::EffectiveModernCpp::Chapter3::Terms16::Example2::Widget::MagicValue() const
{
    std::lock_guard<std::mutex> guard(m);  // 给m加上互斥量

    if (cachedValue)
    {
        return cachedValue;
    }
    else
    {
        const auto val1 = ExpensiveComputation1();
        const auto val2 = ExpensiveComputation2();
        cachedValue = val1 + val2;
        cacheValid = true;

        return cachedValue;
    }  // 为m解锁互斥量
}

int BookExperience::EffectiveModernCpp::Chapter3::Terms16::ExpensiveComputation1() noexcept
{
    return 0;
}

int BookExperience::EffectiveModernCpp::Chapter3::Terms16::ExpensiveComputation2() noexcept
{
    return 0;
}
