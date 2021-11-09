///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.3 (2021/09/02 21:07)

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppExport.h"

#include "Terms1Derive.h"
#include "Terms1Example.h"
#include "System/Helper/PragmaWarning.h"
#include "Example/BookCpp/EffectiveModernCpp/Helper/EffectiveModernCppClassInvariantMacro.h"

#include <array>

BookExperience::EffectiveModernCpp::Chapter1::Terms1::Terms1Example::Terms1Example() noexcept
{
    EFFECTIVE_MODERN_CPP_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(BookExperience::EffectiveModernCpp::Chapter1::Terms1, Terms1Example)

void BookExperience::EffectiveModernCpp::Chapter1::Terms1::Terms1Example::Derivation() const noexcept
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26496)
    int x = 0;
#include STSTEM_WARNING_POP

    F(x);  // 以一个int调用f

    // T被推导为int，而ParamType被推导为const int&
}

void BookExperience::EffectiveModernCpp::Chapter1::Terms1::Terms1Example::Derivation0() const noexcept
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    int x = 27;  // x的型别是int
    const int cx = x;  // cx的型别是const int
    const int& rx = x;  // rx的型别是const int 引用

    F0(x);  // T的型别是int，param的型别是int&
    F0(cx);  // T的型别是const int，param的型别是const int&
    F0(rx);  // T的型别是const int，param的型别是const int&
}

void BookExperience::EffectiveModernCpp::Chapter1::Terms1::Terms1Example::Derivation1() const noexcept
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26496)
    int x = 27;  // x的型别是int
#include STSTEM_WARNING_POP

    const int cx = x;  // cx的型别是const int
    const int& rx = x;  // rx的型别是const int 引用

    F1(x);  // T的型别是int，param的型别是const int&
    F1(cx);  // T的型别是int，param的型别是const int&
    F1(rx);  // T的型别是int，param的型别是const int&
}

void BookExperience::EffectiveModernCpp::Chapter1::Terms1::Terms1Example::Derivation2() const noexcept
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    int x = 27;  // x的型别是int
    const int* px = &x;  // px是指涉到x的指针，型别为const int

    F2(&x);  // T的型别是int，param的型别是int*
    F2(px);  // T的型别是const int，param的型别是const int*
}

void BookExperience::EffectiveModernCpp::Chapter1::Terms1::Terms1Example::Derivation3() const noexcept
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    int x = 27;  // x的型别是int
    const int cx = x;  // cx的型别是const int
    const int& rx = x;  // rx的型别是const int 引用

    F3(x);  // x是个左值，所以T的型别是int&，param的型别也是int&
    F3(cx);  // cx是个左值，所以T的型别是const int&，param的型别是const int&
    F3(rx);  // rx是个左值，所以T的型别是const int&，param的型别是const int&
    F3(27);  // 27是个右值，所以T的型别是int，param的型别就成了int&&
}

void BookExperience::EffectiveModernCpp::Chapter1::Terms1::Terms1Example::Derivation4() const noexcept
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26496)
    int x = 27;  // x的型别是int
#include STSTEM_WARNING_POP

    const int cx = x;  // cx的型别是const int
    const int& rx = x;  // rx的型别是const int 引用

    F4(x);  // T和param的型别都是int
    F4(cx);  // T和param的型别还都是int
    F4(rx);  // T和param的型别还都是int
}

void BookExperience::EffectiveModernCpp::Chapter1::Terms1::Terms1Example::Derivation5() const noexcept
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    const char* const ptr = "Fun with pointers";  // ptr是个指涉到const对象的const的指针

    F5(ptr);  // 传递型别为const char* const的实参

    // param的型别会被推导为const char*
}

void BookExperience::EffectiveModernCpp::Chapter1::Terms1::Terms1Example::ArrayDegeneratePointer() const noexcept
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    const char name[] = "J. P. Briggs";  // name的型别是const char[13];

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26485)

    MAYBE_UNUSED const char* ptrToName = name;  // 数组退化成指针

    F6(name);  // name是个数组，但T的型别却被推导成const char*

#include STSTEM_WARNING_POP
}

void BookExperience::EffectiveModernCpp::Chapter1::Terms1::Terms1Example::Derivation7() const noexcept
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    const char name[] = "J. P. Briggs";  // name的型别是const char[13];

    F7(name);  // 向f传递一个数组，T的推导型别结果是const char[13]，而F7的形参型别则被推导为const char(&)[13]
}

void BookExperience::EffectiveModernCpp::Chapter1::Terms1::Terms1Example::ArraySizeTest() const noexcept
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    const int keyVals[] = { 1, 3, 7, 9, 11, 22, 35 };  // keyVals含有7个元素

    MAYBE_UNUSED const int mappedVals0[ArraySize(keyVals)]{};  // mappedVals0被指定与之相同

    MAYBE_UNUSED const std::array<int, ArraySize(keyVals)> mappedVals1{};  // mappedVals1也指定为7个元素
}

void BookExperience::EffectiveModernCpp::Chapter1::Terms1::Terms1Example::Derivation8() const noexcept
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    F8(SomeFunc);  // param被推导为函数指针，具体型别是void(*)(int, double)

    F9(SomeFunc);  // param被推导为函数引用，具体型别是void(&)(int, double)
}
