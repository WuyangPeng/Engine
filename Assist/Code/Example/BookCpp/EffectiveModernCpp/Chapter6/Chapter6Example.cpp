///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.7 (2021/11/29 21:31)

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppExport.h"

#include "Chapter6Example.h"
#include "System/Helper/PragmaWarning.h"
#include "Example/BookCpp/EffectiveModernCpp/Helper/EffectiveModernCppClassInvariantMacro.h"

#include <vector>

BookExperience::EffectiveModernCpp::Chapter6::Chapter6Example::Chapter6Example() noexcept
{
    EFFECTIVE_MODERN_CPP_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(BookExperience::EffectiveModernCpp::Chapter6, Chapter6Example)

void BookExperience::EffectiveModernCpp::Chapter6::Chapter6Example::FindExample() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    std::vector<int> container{};

    const auto iter = std::find_if(container.begin(), container.end(),
                                   [](int val) {
                                       return 0 < val && val < 10;
                                   });
}

void BookExperience::EffectiveModernCpp::Chapter6::Chapter6Example::LambdaExample() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    constexpr int x{};  // x�Ǹ��ֲ�����
        // ...

    const auto c1 = [x](int y) {
        return x * y > 55;
    };  // c1��lambda�����ıհ��ĸ���

    const auto c2 = c1;  // c2��c1�ĸ���

    const auto c3 = c2;  // c3��c2�ĸ���
}
