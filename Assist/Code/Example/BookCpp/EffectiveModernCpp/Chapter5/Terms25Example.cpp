///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.5 (2021/11/04 21:06)

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppExport.h"

#include "Terms25.h"
#include "Terms25Example.h"
#include "System/Helper/PragmaWarning.h"
#include "Example/BookCpp/EffectiveModernCpp/Helper/EffectiveModernCppClassInvariantMacro.h"

BookExperience::EffectiveModernCpp::Chapter5::Terms25::Terms25Example::Terms25Example() noexcept
{
    EFFECTIVE_MODERN_CPP_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(BookExperience::EffectiveModernCpp::Chapter5::Terms25, Terms25Example)

void BookExperience::EffectiveModernCpp::Chapter5::Terms25::Terms25Example::MoveExample() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    Example3::Widget w;

    auto n = Example3::GetWidgetName();  // n是个局部变量

    w.SetName(n);  // 将n移入了w!

    // ...
    // n的值变得未知
}

void BookExperience::EffectiveModernCpp::Chapter5::Terms25::Terms25Example::SetNameExample() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    Example4::Widget w;

    w.SetName("Adela Novak");
}
