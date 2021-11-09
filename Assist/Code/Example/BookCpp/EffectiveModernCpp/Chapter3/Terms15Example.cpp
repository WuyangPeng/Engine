///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.4 (2021/10/05 14:26)

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppExport.h"

#include "Terms15.h"
#include "Terms15Example.h"
#include "System/Helper/PragmaWarning.h"
#include "Example/BookCpp/EffectiveModernCpp/Helper/EffectiveModernCppClassInvariantMacro.h"

#include <array>
#include <vector>

BookExperience::EffectiveModernCpp::Chapter3::Terms15::Terms15Example::Terms15Example() noexcept
{
    EFFECTIVE_MODERN_CPP_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(BookExperience::EffectiveModernCpp::Chapter3::Terms15, Terms15Example)

void BookExperience::EffectiveModernCpp::Chapter3::Terms15::Terms15Example::ConstexprExample() const noexcept
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26496)

    MAYBE_UNUSED int sz = 0;  // ��constexpr����

#include STSTEM_WARNING_POP

    // ...

    // constexpr auto arraySize1 = sz;  // ����sz��ֵ�ڱ�����δ֪

    // std::array<int, sz> data1;  // ����һ��������

    constexpr auto arraySize2 = 10;  //û���⣬10�Ǳ����ڳ���

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26496)

    MAYBE_UNUSED std::array<int, arraySize2> data2{};  // û���⣬arraySize2�Ǹ�constexpr

#include STSTEM_WARNING_POP
}

void BookExperience::EffectiveModernCpp::Chapter3::Terms15::Terms15Example::ConstExample() const noexcept
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26496)

    int sz = 0;  // ���Ƿ�constexpr����

#include STSTEM_WARNING_POP

    // ...

    const auto arraySize = sz;  // û���⣬arraySize��sz��һ��const����

    // std::array<int, arraySize> data1;  // ����arraySize��ֵ�Ǳ����ڿ�֪
}

void BookExperience::EffectiveModernCpp::Chapter3::Terms15::Terms15Example::Pow0Example() const noexcept
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    constexpr auto numConds = 5;  // ��������

    // result��3^numConds��Ԫ��
    const std::array<int, Example0::Pow(3, numConds)> result{};
}

void BookExperience::EffectiveModernCpp::Chapter3::Terms15::Terms15Example::Pow1Example() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    // ��ִ����ȡ����Щֵ
    auto base = Example0::ReadFromDB("base");
    auto exp = Example0::ReadFromDB("exponent");

    MAYBE_UNUSED const auto baseToExp = Example0::Pow(base, exp);  // pow������ִ���ڱ�����
}

void BookExperience::EffectiveModernCpp::Chapter3::Terms15::Terms15Example::Point0Example() const noexcept
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    constexpr Example0::Point p1(9.4, 27.7);  // û���⣬�ڱ����ڡ����С�constexpr���캯��

    constexpr Example0::Point p2(28.8, 5.3);  // ͬ��û����

    constexpr auto mid = Midpoint(p1, p2);
}

void BookExperience::EffectiveModernCpp::Chapter3::Terms15::Terms15Example::Point1Example() const noexcept
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    constexpr Example1::Point p1(9.4, 27.7);  // ͬ��

    constexpr Example1::Point p2(28.8, 5.3);  // ͬ��

    constexpr auto mid = Midpoint(p1, p2);

    constexpr auto reflectedMid = Reflection(mid);  // reflectedMid��ֵΪ��-19.1��-16.5�������ڱ����ھ���֪
}
