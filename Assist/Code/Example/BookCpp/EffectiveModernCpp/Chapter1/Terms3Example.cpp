///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.3 (2021/09/05 12:25)

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppExport.h"

#include "Terms3Derive.h"
#include "Terms3Example.h"
#include "System/Helper/PragmaWarning.h"
#include "Example/BookCpp/EffectiveModernCpp/Helper/EffectiveModernCppClassInvariantMacro.h"

#include <deque>
#include <type_traits>

BookExperience::EffectiveModernCpp::Chapter1::Terms3::Terms3Example::Terms3Example() noexcept
{
    EFFECTIVE_MODERN_CPP_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(BookExperience::EffectiveModernCpp::Chapter1::Terms3, Terms3Example)

void BookExperience::EffectiveModernCpp::Chapter1::Terms3::Terms3Example::Derivation() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26814)

    const int i = 0;  // decltype(i)是const int

#include STSTEM_WARNING_POP

    static_assert(std::is_same_v<decltype(i), const int>);

    static_assert(std::is_same_v<decltype(F), bool(const Widget&)>);

    static_assert(std::is_same_v<decltype(Point::x), int>);
    static_assert(std::is_same_v<decltype(Point::y), int>);

    Widget w;  // decltype(w)是Widget1
    static_assert(std::is_same_v<decltype(w), Widget>);

    if (F(w))  // decltype(F(w))是bool
    {
    }

    static_assert(std::is_same_v<decltype(F(w)), bool>);

    Vector<int> v;  // decltype(v)是 Vector<int>
    static_assert(std::is_same_v<decltype(v), Vector<int>>);

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    if (v[0] == 0)  // // decltype(v[0])是 int&
    {
        // ...
    }

#include STSTEM_WARNING_POP

    static_assert(std::is_same_v<decltype(v[0]), int&>);
}

void BookExperience::EffectiveModernCpp::Chapter1::Terms3::Terms3Example::AuthAndAccessTest() const
{
    std::deque<int> d;
    //...
    // AuthAndAccess1(d, 5) = 10; // 验证用户，并返回d[5]，然后将其赋值为10；这段代码无法通过编译

    Widget w;

    const Widget& cw = w;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26496)

    MAYBE_UNUSED auto myWidget1 = cw;  // auto型别推导，myWidget1的型别是Widget1

#include STSTEM_WARNING_POP

    MAYBE_UNUSED decltype(auto) myWidget2 = cw;  // decltype型别推导，myWidget2的型别是const Widget1&

    // auto s = AuthAndAccess2(MakeStringDeque(), 5);  // 制作MakeStringDeque返回的deque的第5个元素的副本

    MAYBE_UNUSED auto s1 = AuthAndAccess3(MakeStringDeque(), 5);
    MAYBE_UNUSED auto s2 = AuthAndAccess4(MakeStringDeque(), 5);
}
