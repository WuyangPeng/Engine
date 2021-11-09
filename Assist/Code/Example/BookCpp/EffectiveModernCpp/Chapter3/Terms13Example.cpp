///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.4 (2021/10/04 21:36)

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppExport.h"

#include "Terms13.h"
#include "Terms13Example.h"
#include "System/Helper/PragmaWarning.h"
#include "Example/BookCpp/EffectiveModernCpp/Helper/EffectiveModernCppClassInvariantMacro.h"

#include <vector>

BookExperience::EffectiveModernCpp::Chapter3::Terms13::Terms13Example::Terms13Example() noexcept
{
    EFFECTIVE_MODERN_CPP_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(BookExperience::EffectiveModernCpp::Chapter3::Terms13, Terms13Example)

void BookExperience::EffectiveModernCpp::Chapter3::Terms13::Terms13Example::FindExample() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    std::vector<int> values;

    // ...

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26496)

    std::vector<int>::iterator it = std::find(values.begin(), values.end(), 1983);

#include STSTEM_WARNING_POP

    values.insert(it, 1998);
}

void BookExperience::EffectiveModernCpp::Chapter3::Terms13::Terms13Example::ConstFindCpp98Example() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    // 一些typedef
    typedef std::vector<int>::iterator IterT;
    typedef std::vector<int>::const_iterator ConstIterT;

    std::vector<int> values;

    // ...

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26496)

    ConstIterT ci = std::find(static_cast<ConstIterT>(values.begin()),  // 强制型别转换
                              static_cast<ConstIterT>(values.end()),  // 强制型别转换
                              1983);

#include STSTEM_WARNING_POP

    // values.insert(static_cast<IterT>(ci), 1998); // 可能无法通过编译
}

void BookExperience::EffectiveModernCpp::Chapter3::Terms13::Terms13Example::ConstFindCpp11Example() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    std::vector<int> values;  // 同前

    // ...

    auto it = std::find(values.cbegin(),  // 使用cbegin
                        values.cend(),  // 使用cend
                        1983);

    values.insert(it, 1998);
}
