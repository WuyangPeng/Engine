///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.7 (2021/11/29 21:29)

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppExport.h"

#include "Terms31.h"
#include "System/Helper/PragmaWarning.h"

#include <functional>
#include <vector>

void BookExperience::EffectiveModernCpp::Chapter6::Terms31::AddDivisorFilter()
{
    using FilterContainer = std::vector<std::function<bool(int)>>;

    FilterContainer filters;

    const auto calc1 = ComputeSomeValue1();
    const auto calc2 = ComputeSomeValue2();

    auto divisor = ComputeDivisor(calc1, calc2);

    // Σ�գ���divisor��ָ����ܿ�����
    filters.emplace_back([&](int value) {
        return value % divisor == 0;
    });

    // Σ�գ���divisor��ָ����Ȼ���ܿ�����
    filters.emplace_back([&divisor](int value) {
        return value % divisor == 0;
    });

    // ����divisor�������
    filters.emplace_back([=](int value) {
        return value % divisor == 0;
    });
}

int BookExperience::EffectiveModernCpp::Chapter6::Terms31::ComputeSomeValue1() noexcept
{
    return 1;
}

int BookExperience::EffectiveModernCpp::Chapter6::Terms31::ComputeSomeValue2() noexcept
{
    return 2;
}

BookExperience::EffectiveModernCpp::Chapter6::Terms31::Example0::FilterContainer BookExperience::EffectiveModernCpp::Chapter6::Terms31::Example0::filters;

void BookExperience::EffectiveModernCpp::Chapter6::Terms31::Example0::Widget::AddFilter() const
{
    filters.emplace_back([=](int value) {
        return value % divisor == 0;
    });
}

BookExperience::EffectiveModernCpp::Chapter6::Terms31::Example1::FilterContainer BookExperience::EffectiveModernCpp::Chapter6::Terms31::Example1::filters;

void BookExperience::EffectiveModernCpp::Chapter6::Terms31::Example1::DoSomeWork()
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26414)

    auto pw = std::make_unique<Widget>();  // ����Widget

#include STSTEM_WARNING_POP

    pw->AddFilter();  // ���ʹ����Widget::divisor��ɸѡ����

    // ...
    // Widget�����٣�filters���ڳ��п���ָ�롣
}

void BookExperience::EffectiveModernCpp::Chapter6::Terms31::Example1::Widget::AddFilter() const
{
    // ����û�пɲ����divisor
    /*
    filters.emplace_back([](int value) {
        return value % divisor == 0;
    });
    */

    // ���󣡾ֲ�û�пɲ����divisor
    /*
    filters.emplace_back([divisor](int value) {
        return value % divisor == 0;
    });
     */

    auto currentObjectPtr = this;

    filters.emplace_back([currentObjectPtr](int value) {
        return value % currentObjectPtr->divisor == 0;
    });
}

BookExperience::EffectiveModernCpp::Chapter6::Terms31::Example2::FilterContainer BookExperience::EffectiveModernCpp::Chapter6::Terms31::Example2::filters;

void BookExperience::EffectiveModernCpp::Chapter6::Terms31::Example2::Widget::AddFilter() const
{
    const auto divisorCopy = divisor;  // ���Ƴ�Ա����

    filters.emplace_back([divisorCopy](int value) {  // ���񸱱�
        return value % divisorCopy == 0;  // ʹ�ø���
    });
}

BookExperience::EffectiveModernCpp::Chapter6::Terms31::Example3::FilterContainer BookExperience::EffectiveModernCpp::Chapter6::Terms31::Example3::filters;

void BookExperience::EffectiveModernCpp::Chapter6::Terms31::Example3::Widget::AddFilter() const
{
    const auto divisorCopy = divisor;  // ���Ƴ�Ա����

    filters.emplace_back([=](int value) {  // ���񸱱�
        return value % divisorCopy == 0;  // ʹ�ø���
    });
}

BookExperience::EffectiveModernCpp::Chapter6::Terms31::Example4::FilterContainer BookExperience::EffectiveModernCpp::Chapter6::Terms31::Example4::filters;

void BookExperience::EffectiveModernCpp::Chapter6::Terms31::Example4::Widget::AddFilter() const
{
    // C++14
    filters.emplace_back([divisor = divisor](int value) {  // ��divisor������հ�
        return value % divisor == 0;  // ʹ�ø���
    });
}

void BookExperience::EffectiveModernCpp::Chapter6::Terms31::Example1::AddDivisorFilter()
{
    static auto calc1 = ComputeSomeValue1();  // ������static�δ�����
    static auto calc2 = ComputeSomeValue2();  // ������static�δ�����

    static auto divisor = ComputeDivisor(calc1, calc2);  // ������static�δ�����

    // δ�����κζ�����
    // ָ�浽ǰ����static�δ������Ķ���
    filters.emplace_back([=](int value) {
        return value % divisor == 0;
    });

    ++divisor;  // �����޸���divisor
}