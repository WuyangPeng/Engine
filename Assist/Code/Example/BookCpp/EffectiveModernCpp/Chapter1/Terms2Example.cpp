///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.3 (2021/09/04 22:19)

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

    FuncForX0(27);  // �����Ե�����䣺�Ƶ��ó���param���ͱ����x���ͱ�
    FuncForX1(x);  // �����Ե�����䣺�Ƶ��ó���param���ͱ����cx���ͱ�
    FuncForX2(cx);  // �����Ե�����䣺�Ƶ��ó���param���ͱ����rx���ͱ�
}

void BookExperience::EffectiveModernCpp::Chapter1::Terms2::Terms2Example::Derivation0() const noexcept
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26496)

    auto x = 27;  // ���3��x�ȷ�ָ��Ҳ�����ã�

#include STSTEM_WARNING_POP

    const auto cx = x;  // ���3��cxͬ���ȷ�ָ��Ҳ�����ã�
    MAYBE_UNUSED const auto& rx = x;  // ���1��rx�Ǹ����ã��������������ã�

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26496)

    MAYBE_UNUSED auto&& uref1 = x;  // x���ͱ���int��������ֵ������uref1���ͱ���int&

#include STSTEM_WARNING_POP

    MAYBE_UNUSED auto&& uref2 = cx;  // cx���ͱ���const int��������ֵ������uref2���ͱ���const int&

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26496)

    MAYBE_UNUSED auto&& uref3 = 27;  // 27���ͱ���int��������ֵ������uref3���ͱ���int&&

#include STSTEM_WARNING_POP

    const char name[] = "R. N. Briggs";  // name���ͱ���const char[13];

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26485)

    MAYBE_UNUSED auto arr1 = name;  // arr1���ͱ���const char*

#include STSTEM_WARNING_POP

    MAYBE_UNUSED auto& arr2 = name;  // arr2���ͱ���const char(&)[13]

    MAYBE_UNUSED auto func1 = SomeFunc;  // func1���ͱ���void(*)(int, double)
    MAYBE_UNUSED auto& func2 = SomeFunc;  // func2���ͱ���void(&)(int, double)
}

void BookExperience::EffectiveModernCpp::Chapter1::Terms2::Terms2Example::Derivation1() const noexcept
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26496)

    MAYBE_UNUSED auto x1 = 27;  // �ͱ���int��ֵ��27
    MAYBE_UNUSED auto x2(27);  // ͬ��
    MAYBE_UNUSED auto x3 = { 27 };  // �ͱ���std::initializer_list<int>��ֵ��{ 27 }
    MAYBE_UNUSED auto x4{ 27 };  // �ͱ���int��ֵ��27

#include STSTEM_WARNING_POP

    // auto x5 = { 1, 2, 3.0 };  // �����Ƶ�����std::initializer_list<T>�е�T

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26496)

    auto x = { 11, 23, 9 };  // x���ͱ���std::initializer_list<int>

#include STSTEM_WARNING_POP

    // F({ 11, 23, 9 });  // �����޷��Ƶ�T���ͱ�
    F0({ 11, 23, 9 });  // T���ͱ��Ƶ�Ϊint���Ӷ�initList���ͱ�std::initializer_list<int>
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

    // resetV({ 1, 2, 3 }); // �����޷�Ϊ{ 1, 2, 3 }����ͱ��Ƶ�
}
