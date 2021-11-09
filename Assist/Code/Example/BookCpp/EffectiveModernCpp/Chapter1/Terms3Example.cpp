///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.3 (2021/09/05 12:25)

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

    const int i = 0;  // decltype(i)��const int

#include STSTEM_WARNING_POP

    static_assert(std::is_same_v<decltype(i), const int>);

    static_assert(std::is_same_v<decltype(F), bool(const Widget&)>);

    static_assert(std::is_same_v<decltype(Point::x), int>);
    static_assert(std::is_same_v<decltype(Point::y), int>);

    Widget w;  // decltype(w)��Widget1
    static_assert(std::is_same_v<decltype(w), Widget>);

    if (F(w))  // decltype(F(w))��bool
    {
    }

    static_assert(std::is_same_v<decltype(F(w)), bool>);

    Vector<int> v;  // decltype(v)�� Vector<int>
    static_assert(std::is_same_v<decltype(v), Vector<int>>);

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    if (v[0] == 0)  // // decltype(v[0])�� int&
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
    // AuthAndAccess1(d, 5) = 10; // ��֤�û���������d[5]��Ȼ���丳ֵΪ10����δ����޷�ͨ������

    Widget w;

    const Widget& cw = w;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26496)

    MAYBE_UNUSED auto myWidget1 = cw;  // auto�ͱ��Ƶ���myWidget1���ͱ���Widget1

#include STSTEM_WARNING_POP

    MAYBE_UNUSED decltype(auto) myWidget2 = cw;  // decltype�ͱ��Ƶ���myWidget2���ͱ���const Widget1&

    // auto s = AuthAndAccess2(MakeStringDeque(), 5);  // ����MakeStringDeque���ص�deque�ĵ�5��Ԫ�صĸ���

    MAYBE_UNUSED auto s1 = AuthAndAccess3(MakeStringDeque(), 5);
    MAYBE_UNUSED auto s2 = AuthAndAccess4(MakeStringDeque(), 5);
}
