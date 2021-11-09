///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.4 (2021/10/10 21:11)

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppExport.h"

#include "Terms20.h"
#include "Terms20Example.h"
#include "System/Helper/PragmaWarning.h"
#include "Example/BookCpp/EffectiveModernCpp/Helper/EffectiveModernCppClassInvariantMacro.h"

#include <vector>

BookExperience::EffectiveModernCpp::Chapter4::Terms20::Terms20Example::Terms20Example() noexcept
{
    EFFECTIVE_MODERN_CPP_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(BookExperience::EffectiveModernCpp::Chapter4::Terms20, Terms20Example)

void BookExperience::EffectiveModernCpp::Chapter4::Terms20::Terms20Example::WeakPtrExample() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    // spw构造成完成后，指涉到Widget的引用计数置为1
    auto spw = std::make_shared<Widget>();

    // ...

    // wpw和spw指涉到同一个Widget。
    // 引用计数保持为1
    std::weak_ptr<Widget> wpw(spw);

    // 引用计数变为0
    // Widget对象被析构。
    // wpw空悬
    spw = nullptr;

    // 若wpw不再指涉到任何对象
    if (wpw.expired())
    {
        // ...
    }

    // 若wpw失效，则spw1为空。
    std::shared_ptr<Widget> spw1 = wpw.lock();

    auto spw2 = wpw.lock();  // 同上，但使用auto

    // 或wpw失效，抛出std::bad_weak_ptr型别的异常。
    std::shared_ptr<Widget> spw3(wpw);
}
