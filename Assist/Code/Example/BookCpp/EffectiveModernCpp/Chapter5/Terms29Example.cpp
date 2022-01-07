///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.6 (2021/11/18 21:33)

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

    // 将数据放入vw1

    // ...

    // 移动vw1入vw2。
    // 完成执行仅须常数时间。
    // 仅仅是包含在vw1和vw2中的指针被修改了。
    auto vw2 = std::move(vw1);

    std::array<Widget, 10000> aw1;

    // 将数据放入aw1

    // ...

    // 移动aw1入aw2。
    // 完成执行仅须线性时间。
    // 需要把aw1中的所有元素移动入aw2。

    const auto aw2 = std::move(aw1);
}
#include STSTEM_WARNING_POP