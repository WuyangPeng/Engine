///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.4 (2021/09/30 20:38)

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppExport.h"

#include "Terms16.h"

#include <cmath>

BookExperience::EffectiveModernCpp::Chapter3::Terms16::Example0::Polynomial::RootsType BookExperience::EffectiveModernCpp::Chapter3::Terms16::Example0::Polynomial::Roots() const
{
    return RootsType{ 1.0 };
}

BookExperience::EffectiveModernCpp::Chapter3::Terms16::Example1::Polynomial::RootsType BookExperience::EffectiveModernCpp::Chapter3::Terms16::Example1::Polynomial::Roots() const
{
    if (!rootsAreValid)  // ���������Ч
    {
        // ...
        rootsAreValid = true;  // �����������������rootVals
    }

    return rootVals;
}

BookExperience::EffectiveModernCpp::Chapter3::Terms16::Example2::Polynomial::RootsType BookExperience::EffectiveModernCpp::Chapter3::Terms16::Example2::Polynomial::Roots() const
{
    std::lock_guard<std::mutex> g(m);  // ���ϻ�����

    if (!rootsAreValid)  // ���������Ч����㣬�洢roots
    {
        // ...
        rootsAreValid = true;
    }

    return rootVals;  // ����������
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
        cachedValue = val1 + val2;  // ��һ����
        cacheValid = true;  // �ڶ�����

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
        cacheValid = true;  // ��һ����
        cachedValue = val1 + val2;  // �ڶ�����

        return cachedValue;
    }
}

int BookExperience::EffectiveModernCpp::Chapter3::Terms16::Example2::Widget::MagicValue() const
{
    std::lock_guard<std::mutex> guard(m);  // ��m���ϻ�����

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
    }  // Ϊm����������
}

int BookExperience::EffectiveModernCpp::Chapter3::Terms16::ExpensiveComputation1() noexcept
{
    return 0;
}

int BookExperience::EffectiveModernCpp::Chapter3::Terms16::ExpensiveComputation2() noexcept
{
    return 0;
}
