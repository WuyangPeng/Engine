///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.3 (2021/09/04 22:19)

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppExport.h"

#include "Terms2Derive.h"
#include "Terms2Example.h"
#include "System/Helper/PragmaWarning.h"
#include "Example/BookCpp/EffectiveModernCpp/Helper/EffectiveModernCppClassInvariantMacro.h"

#include <array>
#include <vector>

BookExperience::EffectiveModernCpp::Chapter1::Terms2::Terms2Example::Terms2Example() noexcept
{
    EFFECTIVE_MODERN_CPP_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(BookExperience::EffectiveModernCpp::Chapter1::Terms2, Terms2Example)

void BookExperience::EffectiveModernCpp::Chapter1::Terms2::Terms2Example::Derivation() const noexcept
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26496)

    auto x = 27;

#include STSTEM_WARNING_POP

    const auto cx = x;
    MAYBE_UNUSED const auto& rx = x;

    FuncForX0(27);  // 概念性调用语句：推导得出的param的型别就是x的型别。
    FuncForX1(x);  // 概念性调用语句：推导得出的param的型别就是cx的型别。
    FuncForX2(cx);  // 概念性调用语句：推导得出的param的型别就是rx的型别。
}

void BookExperience::EffectiveModernCpp::Chapter1::Terms2::Terms2Example::Derivation0() const noexcept
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26496)

    auto x = 27;  // 情况3（x既非指针也非引用）

#include STSTEM_WARNING_POP

    const auto cx = x;  // 情况3（cx同样既非指针也非引用）
    MAYBE_UNUSED const auto& rx = x;  // 情况1（rx是个引用，但不是万能引用）

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26496)

    MAYBE_UNUSED auto&& uref1 = x;  // x的型别是int，且是左值，所以uref1的型别是int&

#include STSTEM_WARNING_POP

    MAYBE_UNUSED auto&& uref2 = cx;  // cx的型别是const int，且是左值，所以uref2的型别是const int&

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26496)

    MAYBE_UNUSED auto&& uref3 = 27;  // 27的型别是int，且是右值，所以uref3的型别是int&&

#include STSTEM_WARNING_POP

    const char name[] = "R. N. Briggs";  // name的型别是const char[13];

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26485)

    MAYBE_UNUSED auto arr1 = name;  // arr1的型别是const char*

#include STSTEM_WARNING_POP

    MAYBE_UNUSED auto& arr2 = name;  // arr2的型别是const char(&)[13]

    MAYBE_UNUSED auto func1 = SomeFunc;  // func1的型别是void(*)(int, double)
    MAYBE_UNUSED auto& func2 = SomeFunc;  // func2的型别是void(&)(int, double)
}

void BookExperience::EffectiveModernCpp::Chapter1::Terms2::Terms2Example::Derivation1() const noexcept
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26496)

    MAYBE_UNUSED auto x1 = 27;  // 型别是int，值是27
    MAYBE_UNUSED auto x2(27);  // 同上
    MAYBE_UNUSED auto x3 = { 27 };  // 型别是std::initializer_list<int>，值是{ 27 }
    MAYBE_UNUSED auto x4{ 27 };  // 型别是int，值是27

#include STSTEM_WARNING_POP

    // auto x5 = { 1, 2, 3.0 };  // 错误！推导不出std::initializer_list<T>中的T

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26496)

    auto x = { 11, 23, 9 };  // x的型别是std::initializer_list<int>

#include STSTEM_WARNING_POP

    // F({ 11, 23, 9 });  // 错误！无法推导T的型别
    F0({ 11, 23, 9 });  // T的型别推导为int，从而initList的型别std::initializer_list<int>
}

void BookExperience::EffectiveModernCpp::Chapter1::Terms2::Terms2Example::Derivation2() const noexcept
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    std::vector<int> v;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26496)

    auto resetV = [&v](const auto& newValue) {
        v = newValue;
    };

#include STSTEM_WARNING_POP

    // resetV({ 1, 2, 3 }); // 错误！无法为{ 1, 2, 3 }完成型别推导
}
