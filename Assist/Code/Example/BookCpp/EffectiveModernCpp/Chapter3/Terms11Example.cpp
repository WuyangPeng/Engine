///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.4 (2021/10/04 15:04)

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppExport.h"

#include "Terms11.h"
#include "Terms11Example.h"
#include "System/Helper/PragmaWarning.h"
#include "Example/BookCpp/EffectiveModernCpp/Helper/EffectiveModernCppClassInvariantMacro.h"

#include <vector>

BookExperience::EffectiveModernCpp::Chapter3::Terms11::Terms11Example::Terms11Example() noexcept
{
    EFFECTIVE_MODERN_CPP_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(BookExperience::EffectiveModernCpp::Chapter3::Terms11, Terms11Example)

void BookExperience::EffectiveModernCpp::Chapter3::Terms11::Terms11Example::IsLucky0Example() const noexcept
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    if (Example0::IsLucky('a'))  // 'a'是个幸运数吗？
    {
        // ...
    }

    if (Example0::IsLucky(true))  // “true”又如何？
    {
        // ...
    }

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(4244)

    if (Example0::IsLucky(3.5))  // 是不是应该先截断为3再检查是否为幸运数
    {
        // ...
    }

#include STSTEM_WARNING_POP
}

void BookExperience::EffectiveModernCpp::Chapter3::Terms11::Terms11Example::IsLucky1Example() const noexcept
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    //  if (Example1::IsLucky('a'))  // 错误！调用了删除函数
    {
        // ...
    }

    //  if (Example1::IsLucky(true))  // 错误！
    {
        // ...
    }

    //  if (Example1::IsLucky(3.5f))  // 错误！
    {
        // ...
    }
}

void BookExperience::EffectiveModernCpp::Chapter3::Terms11::Terms11Example::WidgetExample() const noexcept
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    Example0::Widget widget{};

    widget.ProcessPointer(&widget);

    MAYBE_UNUSED void* ptr = nullptr;

    // widget.ProcessPointer(ptr);
}
