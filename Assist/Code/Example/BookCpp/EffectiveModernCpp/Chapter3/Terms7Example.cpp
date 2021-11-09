///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.3 (2021/09/02 21:07)

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppExport.h"

#include "Terms7.h"
#include "Terms7Example.h"
#include "System/Helper/PragmaWarning.h"
#include "Example/BookCpp/EffectiveModernCpp/Helper/EffectiveModernCppClassInvariantMacro.h"

#include <vector>

BookExperience::EffectiveModernCpp::Chapter3::Terms7::Terms7Example::Terms7Example() noexcept
{
    EFFECTIVE_MODERN_CPP_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(BookExperience::EffectiveModernCpp::Chapter3::Terms7, Terms7Example)

void BookExperience::EffectiveModernCpp::Chapter3::Terms7::Terms7Example::InitExample() const noexcept
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    MAYBE_UNUSED constexpr int x(0);  // ��ʼ������С������

    MAYBE_UNUSED constexpr int y = 0;  // ��ʼ�����ڵȺ�֮��

    MAYBE_UNUSED constexpr int z{ 0 };  // ��ʼ�����ڴ�������

    MAYBE_UNUSED constexpr int z1 = { 0 };  // ʹ�õȺźʹ�������ָ����ʼ����
}

void BookExperience::EffectiveModernCpp::Chapter3::Terms7::Terms7Example::WidgetExample() const noexcept
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    Widget w1;  // ���õ���Ĭ�Ϲ��캯��

    const Widget w2 = w1;  // ���Ǹ�ֵ�����õ��Ǹ��ƹ��캯��

    w1 = w2;  // ���Ǹ�ֵ�����õ��Ǹ��Ƹ�ֵ�����
}

void BookExperience::EffectiveModernCpp::Chapter3::Terms7::Terms7Example::Vector0Example() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    std::vector<int> v{ 1, 3, 5 };  // v�ĳ�ʼ����Ϊ1��3��5
}

void BookExperience::EffectiveModernCpp::Chapter3::Terms7::Terms7Example::AtomicExample() const noexcept
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    const std::atomic<int> ai1{ 0 };  // ����

    const std::atomic<int> ai2(0);  // ����

    const std::atomic<int> ai3 = 0;  // �����У�VS��ͨ�����룩
}

void BookExperience::EffectiveModernCpp::Chapter3::Terms7::Terms7Example::SumExample() const noexcept
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    constexpr double x = 0.0, y = 0.0, z = 0.0;

    // ...

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(4244)

    // int sum1{ x + y + z };  // ����double�ͱ�֮�Ϳ����޷���int���
    MAYBE_UNUSED constexpr int sum2(x + y + z);  // û���⣨���ʽ��ֵ���ض�Ϊint��
    MAYBE_UNUSED constexpr int sum3 = x + y + z;  // ͬ��

#include STSTEM_WARNING_POP
}

void BookExperience::EffectiveModernCpp::Chapter3::Terms7::Terms7Example::WidgetConstruction0Example() const noexcept
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    const Example0::Widget w1(10);  // ����Widget�Ĺ��캯���������β�10

    // �����˿���֮�����﷨����
    // ������������һ����Ϊw2������һ��Widget�ͱ����ĺ�����
    // Example1::Widget w2();

    const Example0::Widget w3{};  // ����û���βε�Widget���캯��
}

void BookExperience::EffectiveModernCpp::Chapter3::Terms7::Terms7Example::WidgetConstruction1Example() const noexcept
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    const Example1::Widget w1(10, true);  // ���õ��ǵ�һ�����캯��

    const Example1::Widget w2{ 10, true };  // ���õĻ��ǵ�һ�����캯��

    const Example1::Widget w3(10, 5.0);  // ���õ��ǵڶ������캯��

    const Example1::Widget w4{ 10, 5.0 };  // ���õĻ��ǵڶ������캯��
}

void BookExperience::EffectiveModernCpp::Chapter3::Terms7::Terms7Example::WidgetConstruction2Example() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    const Example2::Widget w1(10, true);  // ʹ��С���ţ�ͬǰ�����õ��ǵ�һ�����캯��

    // ʹ�ô����ţ����õ��Ǵ���std::initializer_list�ͱ��βεĹ��캯��
    // ��10��true��ǿ��ת����long double��
    const Example2::Widget w2{ 10, true };

    const Example2::Widget w3(10, 5.0);  // ʹ��С���ţ�ͬǰ�����õ��ǵڶ������캯��

    // ʹ�ô����ţ����õ��Ǵ���std::initializer_list�ͱ��βεĹ��캯��
    // ��10��5.0��ǿ��ת����long double��
    const Example2::Widget w4{ 10, 5.0 };
}

void BookExperience::EffectiveModernCpp::Chapter3::Terms7::Terms7Example::WidgetConstruction3Example() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    Example3::Widget w4{ 10, 5.0 };

    const Example3::Widget w5(w4);  // ʹ��С���ţ����õ��Ǹ��ƹ��캯��

    // ʹ�ô����ţ����õ��Ǵ���std::initializer_list�ͱ��βεĹ��캯��
    // ��w4�ķ���ֵ��ǿ��ת����float�����float�ֱ�ǿ��ת����long double��
    const Example3::Widget w6{ w4 };

    const Example3::Widget w7(std::move(w4));  // ʹ��С���ţ����õ����ƶ����캯��

    // ʹ�ô����ţ����õ��Ǵ���std::initializer_list�ͱ��βεĹ��캯��
    // ����w6�Ľ��������ͬ��
    // VS��û�е��ô���std::initializer_list�ͱ��βεĹ��캯����
    const Example3::Widget w8{ std::move(w4) };
}

void BookExperience::EffectiveModernCpp::Chapter3::Terms7::Terms7Example::WidgetConstruction4Example() const noexcept
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    // const Example4::Widget{ 10, 5.0 };  // ����Ҫ��խʽ�ͱ�ת��
}

void BookExperience::EffectiveModernCpp::Chapter3::Terms7::Terms7Example::WidgetConstruction5Example() const noexcept
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    const Example5::Widget w1(10, true);  // ʹ��С���ţ����õ��ǵ�һ�����캯��

    const Example5::Widget w2{ 10, true };  // ʹ�ô����ţ���ɵ��õ�һ�����캯��

    const Example5::Widget w3(10, 5.0);  // ʹ��С���ţ����õ����ǵڶ������캯��

    const Example5::Widget w4{ 10, 5.0 };  // ʹ�ô����ţ���ɵ��õڶ������캯��
}

void BookExperience::EffectiveModernCpp::Chapter3::Terms7::Terms7Example::WidgetConstruction6Example() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    MAYBE_UNUSED const Example6::Widget w1;  // ���õ���Ĭ�Ϲ��캯��

    const Example6::Widget w2{};  // ���õ�����Ĭ�Ϲ��캯��

    // Example6::Widget w3();  // �����˿��յĽ����﷨������ɺ����������

    const Example6::Widget w4({});  // ����std::initializer_list�ͱ��βεĹ��캯��������һ���յ�std::initializer_list

    const Example6::Widget w5{ {} };  // ���캯��ʹ�õ�Ԫ��std::initializer_list���ã������ǿյġ�
}

void BookExperience::EffectiveModernCpp::Chapter3::Terms7::Terms7Example::Vector1Example() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    // �������β���û���κ�һ���߱�std::initializer_list�ͱ�Ĺ��캯��
    // ����ǣ�������һ������10��Ԫ�ص�std::vector���е�Ԫ�ص�ֵ����20
    std::vector<int> v1(10, 20);

    // �������β��к���std::initializer_list�ͱ�Ĺ��캯����
    // ����ǣ�������һ������2��Ԫ�ص�std::vector��Ԫ�ص�ֵ�ֱ���10��20
    std::vector<int> v2{ 10, 20 };
}

void BookExperience::EffectiveModernCpp::Chapter3::Terms7::Terms7Example::DoSomeWorkExample() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    std::vector<int> v;

    // ...

    DoSomeWork<std::vector<int>>(10, 20);
}
