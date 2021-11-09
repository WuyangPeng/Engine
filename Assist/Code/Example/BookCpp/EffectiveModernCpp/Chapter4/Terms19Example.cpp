///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.4 (2021/10/10 21:11)

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppExport.h"

#include "Terms19.h"
#include "Terms19Example.h"
#include "System/Helper/PragmaWarning.h"
#include "Example/BookCpp/EffectiveModernCpp/Helper/EffectiveModernCppClassInvariantMacro.h"

#include <vector>

BookExperience::EffectiveModernCpp::Chapter4::Terms19::Terms19Example::Terms19Example() noexcept
{
    EFFECTIVE_MODERN_CPP_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(BookExperience::EffectiveModernCpp::Chapter4::Terms19, Terms19Example)

void BookExperience::EffectiveModernCpp::Chapter4::Terms19::Terms19Example::SharedPtr0Example() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    // �Զ���������
    const auto loggingDel = [](Example0::Widget* pw) noexcept {
        MakeLogEntry(pw);

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26401)
#include SYSTEM_WARNING_DISABLE(26409)

        delete pw;

#include STSTEM_WARNING_POP
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26409)

    // �������ͱ�������ָ���ͱ��һ����
    std::unique_ptr<Example0::Widget, decltype(loggingDel)> upw(new Example0::Widget, loggingDel);

    // �������ͱ�������ָ���ͱ��һ����
    std::shared_ptr<Example0::Widget> spw(new Example0::Widget, loggingDel);

#include STSTEM_WARNING_POP
}

void BookExperience::EffectiveModernCpp::Chapter4::Terms19::Terms19Example::SharedPtr1Example() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    // �Զ������������в�ͬ�ͱ�
    const auto customDeleter1 = [](Example0::Widget* pw) noexcept {
        // ...
        MakeLogEntry(pw);

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26401)
#include SYSTEM_WARNING_DISABLE(26409)

        delete pw;

#include STSTEM_WARNING_POP
    };

    const auto customDeleter2 = [](Example0::Widget* pw) noexcept {
        // ...
        MakeLogEntry(pw);

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26401)
#include SYSTEM_WARNING_DISABLE(26409)

        delete pw;

#include STSTEM_WARNING_POP
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26409)

    std::shared_ptr<Example0::Widget> pw1(new Example0::Widget, customDeleter1);
    std::shared_ptr<Example0::Widget> pw2(new Example0::Widget, customDeleter2);

#include STSTEM_WARNING_POP

    std::vector<std::shared_ptr<Example0::Widget>> vpw{ pw1, pw2 };
}

void BookExperience::EffectiveModernCpp::Chapter4::Terms19::Terms19Example::ErrorSharedPtrExample() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    const auto loggingDel = [](Example0::Widget* pw) noexcept {
        MakeLogEntry(pw);

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26401)
#include SYSTEM_WARNING_DISABLE(26409)

        delete pw;

#include STSTEM_WARNING_POP
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26403)
#include SYSTEM_WARNING_DISABLE(26409)

    auto pw = new Example0::Widget;  // pw�Ǹ���ָ��

#include STSTEM_WARNING_POP

    // ...

    // Ϊ*pw����һ�����ƿ�
    std::shared_ptr<Example0::Widget> spw1(pw, loggingDel);

    // ...

    // Ϊ*pw�����ڶ������ƿ顣
    // std::shared_ptr<Widget> spw2(pw, loggingDel);
}

void BookExperience::EffectiveModernCpp::Chapter4::Terms19::Terms19Example::SharedPtr2Example() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    const auto loggingDel = [](Example0::Widget* pw) noexcept {
        MakeLogEntry(pw);

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26401)
#include SYSTEM_WARNING_DISABLE(26409)

        delete pw;

#include STSTEM_WARNING_POP
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26409)

    // ֱ�Ӵ���new���ʽ
    std::shared_ptr<Example0::Widget> spw1(new Example0::Widget, loggingDel);

#include STSTEM_WARNING_POP

    // spw2ʹ�õ��Ǻ�spw1ͬһ�����ƿ顣
    std::shared_ptr<Example0::Widget> spw2(spw1);
}
