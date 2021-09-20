///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.0.1 (2021/02/16 17:47)

#include "Example/BookCpp/EffectiveCpp/EffectiveCppExport.h"

#include "TerminologyDeclaration.h"
#include "Example/BookCpp/EffectiveCpp/Helper/EffectiveCppClassInvariantMacro.h"

namespace BookExperience
{
    namespace EffectiveCpp
    {
        // 对象的定义式
        int x;
    }
}

BookExperience::EffectiveCpp::B::B([[maybe_unused]] int a, [[maybe_unused]] bool b) noexcept
{
}

BookExperience::EffectiveCpp::C::C([[maybe_unused]] int a) noexcept
{
}

void BookExperience::EffectiveCpp::DoSomething([[maybe_unused]] B bObject) noexcept
{
}

bool BookExperience::EffectiveCpp::HasAcceptableQuality([[maybe_unused]] Widget w) noexcept
{
    return false;
}
