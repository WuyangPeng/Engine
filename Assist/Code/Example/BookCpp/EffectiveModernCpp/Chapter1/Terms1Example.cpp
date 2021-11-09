///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.3 (2021/09/02 21:07)

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

    F(x);  // ��һ��int����f

    // T���Ƶ�Ϊint����ParamType���Ƶ�Ϊconst int&
}

void BookExperience::EffectiveModernCpp::Chapter1::Terms1::Terms1Example::Derivation0() const noexcept
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    int x = 27;  // x���ͱ���int
    const int cx = x;  // cx���ͱ���const int
    const int& rx = x;  // rx���ͱ���const int ����

    F0(x);  // T���ͱ���int��param���ͱ���int&
    F0(cx);  // T���ͱ���const int��param���ͱ���const int&
    F0(rx);  // T���ͱ���const int��param���ͱ���const int&
}

void BookExperience::EffectiveModernCpp::Chapter1::Terms1::Terms1Example::Derivation1() const noexcept
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26496)
    int x = 27;  // x���ͱ���int
#include STSTEM_WARNING_POP

    const int cx = x;  // cx���ͱ���const int
    const int& rx = x;  // rx���ͱ���const int ����

    F1(x);  // T���ͱ���int��param���ͱ���const int&
    F1(cx);  // T���ͱ���int��param���ͱ���const int&
    F1(rx);  // T���ͱ���int��param���ͱ���const int&
}

void BookExperience::EffectiveModernCpp::Chapter1::Terms1::Terms1Example::Derivation2() const noexcept
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    int x = 27;  // x���ͱ���int
    const int* px = &x;  // px��ָ�浽x��ָ�룬�ͱ�Ϊconst int

    F2(&x);  // T���ͱ���int��param���ͱ���int*
    F2(px);  // T���ͱ���const int��param���ͱ���const int*
}

void BookExperience::EffectiveModernCpp::Chapter1::Terms1::Terms1Example::Derivation3() const noexcept
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    int x = 27;  // x���ͱ���int
    const int cx = x;  // cx���ͱ���const int
    const int& rx = x;  // rx���ͱ���const int ����

    F3(x);  // x�Ǹ���ֵ������T���ͱ���int&��param���ͱ�Ҳ��int&
    F3(cx);  // cx�Ǹ���ֵ������T���ͱ���const int&��param���ͱ���const int&
    F3(rx);  // rx�Ǹ���ֵ������T���ͱ���const int&��param���ͱ���const int&
    F3(27);  // 27�Ǹ���ֵ������T���ͱ���int��param���ͱ�ͳ���int&&
}

void BookExperience::EffectiveModernCpp::Chapter1::Terms1::Terms1Example::Derivation4() const noexcept
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26496)
    int x = 27;  // x���ͱ���int
#include STSTEM_WARNING_POP

    const int cx = x;  // cx���ͱ���const int
    const int& rx = x;  // rx���ͱ���const int ����

    F4(x);  // T��param���ͱ���int
    F4(cx);  // T��param���ͱ𻹶���int
    F4(rx);  // T��param���ͱ𻹶���int
}

void BookExperience::EffectiveModernCpp::Chapter1::Terms1::Terms1Example::Derivation5() const noexcept
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    const char* const ptr = "Fun with pointers";  // ptr�Ǹ�ָ�浽const�����const��ָ��

    F5(ptr);  // �����ͱ�Ϊconst char* const��ʵ��

    // param���ͱ�ᱻ�Ƶ�Ϊconst char*
}

void BookExperience::EffectiveModernCpp::Chapter1::Terms1::Terms1Example::ArrayDegeneratePointer() const noexcept
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    const char name[] = "J. P. Briggs";  // name���ͱ���const char[13];

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26485)

    MAYBE_UNUSED const char* ptrToName = name;  // �����˻���ָ��

    F6(name);  // name�Ǹ����飬��T���ͱ�ȴ���Ƶ���const char*

#include STSTEM_WARNING_POP
}

void BookExperience::EffectiveModernCpp::Chapter1::Terms1::Terms1Example::Derivation7() const noexcept
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    const char name[] = "J. P. Briggs";  // name���ͱ���const char[13];

    F7(name);  // ��f����һ�����飬T���Ƶ��ͱ�����const char[13]����F7���β��ͱ����Ƶ�Ϊconst char(&)[13]
}

void BookExperience::EffectiveModernCpp::Chapter1::Terms1::Terms1Example::ArraySizeTest() const noexcept
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    const int keyVals[] = { 1, 3, 7, 9, 11, 22, 35 };  // keyVals����7��Ԫ��

    MAYBE_UNUSED const int mappedVals0[ArraySize(keyVals)]{};  // mappedVals0��ָ����֮��ͬ

    MAYBE_UNUSED const std::array<int, ArraySize(keyVals)> mappedVals1{};  // mappedVals1Ҳָ��Ϊ7��Ԫ��
}

void BookExperience::EffectiveModernCpp::Chapter1::Terms1::Terms1Example::Derivation8() const noexcept
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    F8(SomeFunc);  // param���Ƶ�Ϊ����ָ�룬�����ͱ���void(*)(int, double)

    F9(SomeFunc);  // param���Ƶ�Ϊ�������ã������ͱ���void(&)(int, double)
}
