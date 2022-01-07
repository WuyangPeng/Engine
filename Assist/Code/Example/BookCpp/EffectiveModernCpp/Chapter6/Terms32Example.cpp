///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.7 (2021/11/29 21:31)

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppExport.h"

#include "Terms32.h"
#include "Terms32Example.h"
#include "System/Helper/PragmaWarning.h"
#include "Example/BookCpp/EffectiveModernCpp/Helper/EffectiveModernCppClassInvariantMacro.h"

#include <vector>
#include <functional>

BookExperience::EffectiveModernCpp::Chapter6::Terms32::Terms32Example::Terms32Example() noexcept
{
    EFFECTIVE_MODERN_CPP_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(BookExperience::EffectiveModernCpp::Chapter6::Terms32, Terms32Example)

void BookExperience::EffectiveModernCpp::Chapter6::Terms32::Terms32Example::Widget0Example() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    auto pw = std::make_unique<Example0::Widget>();  // ����Widget

    // ...
    // ����*pw

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26440)

    auto func = [pw = std::move(pw)] {
        return pw->IsValidated() && pw->IsArchived();
    };  // ����std::move(pw)��ʼ���հ�������ݳ�Ա

#include STSTEM_WARNING_POP
}

void BookExperience::EffectiveModernCpp::Chapter6::Terms32::Terms32Example::Widget1Example() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26440)

    auto func = [pw = std::make_unique<Example0::Widget>()] {
        return pw->IsValidated() && pw->IsArchived();
    };  // ����make_unique�ĵ��ý����ʼ���հ���ĳ�Ա

#include STSTEM_WARNING_POP
}

void BookExperience::EffectiveModernCpp::Chapter6::Terms32::Terms32Example::IsValAndArchExample() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    MAYBE_UNUSED auto func = Example0::IsValAndArch(std::make_unique<Example0::Widget>());
}

void BookExperience::EffectiveModernCpp::Chapter6::Terms32::Terms32Example::Vector0Example() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    std::vector<double> data;  // ������հ��Ķ���

    // ...
    // ��������

    auto func = [data = std::move(data)] {
        /* �����ݼ������� */
    };
}

void BookExperience::EffectiveModernCpp::Chapter6::Terms32::Terms32Example::Vector1Example() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    std::vector<double> data;  // ͬǰ

    // ...
    // ͬǰ

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26440)

    // C++11��ģ���ʼ������Ĳ���
    auto func = std::bind([](const std::vector<double> data) { /* �����ݼ������� */ },
                          std::move(data));

#include STSTEM_WARNING_POP
}

void BookExperience::EffectiveModernCpp::Chapter6::Terms32::Terms32Example::Vector2Example() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    std::vector<double> data;  // ͬǰ

    // ...
    // ͬǰ

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26440)

    // C++11����Կɱ�lambdaʽģ���ʼ������Ĳ���
    auto func = std::bind([](std::vector<double> data) mutable { /* �����ݼ������� */ },
                          std::move(data));

#include STSTEM_WARNING_POP
}

void BookExperience::EffectiveModernCpp::Chapter6::Terms32::Terms32Example::Widget2Example() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26440)

    auto func = std::bind([](const std::unique_ptr<Example0::Widget>& pw) {
        return pw->IsValidated() && pw->IsArchived();
    },
                          std::make_unique<Example0::Widget>());

#include STSTEM_WARNING_POP
}
