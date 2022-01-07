///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.5 (2021/11/04 21:06)

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppExport.h"

#include "Terms24.h"
#include "Terms24Example.h"
#include "System/Helper/PragmaWarning.h"
#include "Example/BookCpp/EffectiveModernCpp/Helper/EffectiveModernCppClassInvariantMacro.h"

BookExperience::EffectiveModernCpp::Chapter5::Terms24::Terms24Example::Terms24Example() noexcept
{
    EFFECTIVE_MODERN_CPP_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(BookExperience::EffectiveModernCpp::Chapter5::Terms24, Terms24Example)

void BookExperience::EffectiveModernCpp::Chapter5::Terms24::Terms24Example::UniversalReference0Example() const noexcept
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    Widget&& var1 = Widget();  // ��ֵ����

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26496)

    MAYBE_UNUSED auto&& var2 = var1;  // ����ֵ����

#include STSTEM_WARNING_POP
}

void BookExperience::EffectiveModernCpp::Chapter5::Terms24::Terms24Example::UniversalReference1Example() const noexcept
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    // ���漰�ͱ��Ƶ���var1�Ǹ���ֵ����
    Widget&& var1 = Widget();

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26496)

    // var2�Ǹ���������
    MAYBE_UNUSED auto&& var2 = var1;

#include STSTEM_WARNING_POP
}

void BookExperience::EffectiveModernCpp::Chapter5::Terms24::Terms24Example::Universa1Reference2Example() const noexcept
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    Widget w;

    // ��ֵ�����ݸ�F;
    // param���ͱ���Widget&����һ����ֵ���ã�
    Example2::F(w);

    // ��ֵ�����ݸ�F;
    // param���ͱ���Widget&&����һ����ֵ���ã�
    Example2::F(std::move(w));
}

void BookExperience::EffectiveModernCpp::Chapter5::Terms24::Terms24Example::Vector0Example() const noexcept
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    std::vector<int> v;
    // Example3::F(v);  // ���󣡲��ܸ���ֵ���ð�һ����ֵ
}

void BookExperience::EffectiveModernCpp::Chapter5::Terms24::Terms24Example::Vector1Example() const noexcept
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    std::vector<Widget> v;
}

void BookExperience::EffectiveModernCpp::Chapter5::Terms24::Terms24Example::TimeFuncInvocationExample() const noexcept
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    const auto timeFuncInvocation = [](auto&& func, auto&&... params)  // C++14
    {
        // ��ʱ������;
        std::forward<decltype(func)>(func)(  // ����func
            std::forward<decltype(params)>(params)...  // ����params
        );

        // ��ʱ�����ϲ���¼���ŵ�ʱ�䡣
    };
}
