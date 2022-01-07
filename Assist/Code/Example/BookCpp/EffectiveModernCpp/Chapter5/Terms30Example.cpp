///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.6 (2021/11/20 21:47)

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppExport.h"

#include "Terms30.h"
#include "Terms30Example.h"
#include "System/Helper/PragmaWarning.h"
#include "Example/BookCpp/EffectiveModernCpp/Helper/EffectiveModernCppClassInvariantMacro.h"

BookExperience::EffectiveModernCpp::Chapter5::Terms30::Terms30Example::Terms30Example() noexcept
{
    EFFECTIVE_MODERN_CPP_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(BookExperience::EffectiveModernCpp::Chapter5::Terms30, Terms30Example)

void BookExperience::EffectiveModernCpp::Chapter5::Terms30::Terms30Example::BracesExample() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    Example2::F({ 1, 2, 3 });  // û���⣬��{ 1, 2, 3 }������ʽת��Ϊstd::vector<int>

    // Example2::Fwd({ 1, 2, 3 });  // �����޷�ͨ������

    auto il = { 1, 2, 3 };  // il���ͱ��Ƶ����Ϊstd::initializer_list<int>

    Example2::Fwd(il);  // û���⣬��il����ת����F
}

void BookExperience::EffectiveModernCpp::Chapter5::Terms30::Terms30Example::StaticExample() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    std::vector<int> widgetData;

    widgetData.reserve(Example3::Widget::MinVals);  // �˴��õ���MinVals

    Example3::F(Example3::Widget::MinVals);  // û���⣬��F(28)����

    Example3::Fwd(Example3::Widget::MinVals);  // ����Ӧ���޷�����
}

void BookExperience::EffectiveModernCpp::Chapter5::Terms30::Terms30Example::ProcessValExample() const noexcept
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    Example5::F(Example5::ProcessVal);  // û����

    // Example5::Fwd(Example5::ProcessVal);  // �����ĸ�ProcessVal���ذ汾��

    // Example5::Fwd(Example5::WorkOnVal);  // ����WorkOnVal���ĸ�ʵ��

    using ProcessFuncType = int (*)(int);  // �൱�ڴ���һ��typedef

    ProcessFuncType processValPTr = Example5::ProcessVal;

    Example5::Fwd(processValPTr);  // û����

    Example5::Fwd(static_cast<ProcessFuncType>(Example5::WorkOnVal));  // Ҳû����
}

void BookExperience::EffectiveModernCpp::Chapter5::Terms30::Terms30Example::IPv4Example() const noexcept
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    Example6::IPv4Header h{};

    // ...

    Example6::F(h.totalLength);  // û����

    //  Example6::Fwd(h.totalLength);  // ����

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26472)

    auto length = static_cast<std::uint16_t>(h.totalLength);

#include STSTEM_WARNING_POP

    Example6::Fwd(length);  // ת���ø���
}
