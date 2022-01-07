///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.6 (2021/11/18 21:33)

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppExport.h"

#include "Terms29.h"
#include "Terms29Example.h"
#include "System/Helper/PragmaWarning.h"
#include "Example/BookCpp/EffectiveModernCpp/Helper/EffectiveModernCppClassInvariantMacro.h"

#include <array>
#include <vector>

BookExperience::EffectiveModernCpp::Chapter5::Terms29::Terms29Example::Terms29Example() noexcept
{
    EFFECTIVE_MODERN_CPP_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(BookExperience::EffectiveModernCpp::Chapter5::Terms29, Terms29Example)

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(6262)

void BookExperience::EffectiveModernCpp::Chapter5::Terms29::Terms29Example::MoveExample() const noexcept
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    std::vector<Widget> vw1;

    // �����ݷ���vw1

    // ...

    // �ƶ�vw1��vw2��
    // ���ִ�н��볣��ʱ�䡣
    // �����ǰ�����vw1��vw2�е�ָ�뱻�޸��ˡ�
    auto vw2 = std::move(vw1);

    std::array<Widget, 10000> aw1;

    // �����ݷ���aw1

    // ...

    // �ƶ�aw1��aw2��
    // ���ִ�н�������ʱ�䡣
    // ��Ҫ��aw1�е�����Ԫ���ƶ���aw2��

    const auto aw2 = std::move(aw1);
}
#include STSTEM_WARNING_POP