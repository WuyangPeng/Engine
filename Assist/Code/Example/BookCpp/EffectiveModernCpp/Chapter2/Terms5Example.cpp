///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.3 (2021/09/02 21:07)

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppExport.h"

#include "Terms5.h"
#include "Terms5Example.h"
#include "System/Helper/PragmaWarning.h"
#include "Example/BookCpp/EffectiveModernCpp/Helper/EffectiveModernCppClassInvariantMacro.h"

#include <functional>
#include <vector>

BookExperience::EffectiveModernCpp::Chapter2::Terms5::Terms5Example::Terms5Example() noexcept
{
    EFFECTIVE_MODERN_CPP_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(BookExperience::EffectiveModernCpp::Chapter2::Terms5, Terms5Example)

void BookExperience::EffectiveModernCpp::Chapter2::Terms5::Terms5Example::AutoExample() const noexcept
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26494)

    MAYBE_UNUSED int x1;  // ��Ǳ�ڵ�δ��ʼ������

#include STSTEM_WARNING_POP

    // auto x2;  // ������󣬱����г�ʼ����

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26496)

    MAYBE_UNUSED auto x3 = 0;  // û���⣬x��ֵ���źϷ�����

#include STSTEM_WARNING_POP
}

void BookExperience::EffectiveModernCpp::Chapter2::Terms5::Terms5Example::LambadExample() const noexcept
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    const auto derefUPLess = [](const std::unique_ptr<Widget>& p1, const std::unique_ptr<Widget>& p2) noexcept {
        return *p1 < *p2;
    };

    const auto derefLess = [](const auto& p1, const auto& p2) noexcept {
        return *p1 < *p2;
    };
}

void BookExperience::EffectiveModernCpp::Chapter2::Terms5::Terms5Example::FunctionExample() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    // C++11�汾��std::unique_ptr<Widget>�ȽϺ���ǩ��
    // bool(const std::unique_ptr<Widget>&, const std::unique_ptr<Widget>&);

    std::function<bool(const std::unique_ptr<Widget>&, const std::unique_ptr<Widget>&)> func;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26440)

    std::function<bool(const std::unique_ptr<Widget>&, const std::unique_ptr<Widget>&)> derefUPLess = [](const std::unique_ptr<Widget>& p1, const std::unique_ptr<Widget>& p2) {
        return *p1 < *p2;
    };

#include STSTEM_WARNING_POP
}

void BookExperience::EffectiveModernCpp::Chapter2::Terms5::Terms5Example::TypeExample() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    std::vector<int> v;

    // ...

    // MAYBE_UNUSED unsigned sz = v.size();

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26496)

    MAYBE_UNUSED auto sz1 = v.size();  // sz1���ͱ���std::vector<int>::size_type

#include STSTEM_WARNING_POP

    std::unordered_map<std::string, int> m;

    for (MAYBE_UNUSED const std::pair<std::string, int>& p : m)
    {
        // ...
        // ��p��ʵʩĳЩ����
    }

    for (MAYBE_UNUSED const auto& p : m)
    {
        // ...
        // ͬǰ
    }
}
