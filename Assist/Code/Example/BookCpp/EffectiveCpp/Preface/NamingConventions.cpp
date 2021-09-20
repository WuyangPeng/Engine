///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.0.1 (2021/02/16 17:47)

#include "Example/BookCpp/EffectiveCpp/EffectiveCppExport.h"

#include "NamingConventions.h"
#include "NamingConventionsDeclaration.h"
#include "Example/BookCpp/EffectiveCpp/Helper/EffectiveCppClassInvariantMacro.h"

BookExperience::EffectiveCpp::NamingConventions::NamingConventions() noexcept
{
    EFFECTIVE_CPP_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(BookExperience::EffectiveCpp, NamingConventions)

void BookExperience::EffectiveCpp::NamingConventions::Main() const noexcept
{
    EFFECTIVE_CPP_CLASS_IS_VALID_CONST_9;

    [[maybe_unused]] const Widget* pw = nullptr;

    [[maybe_unused]] const Airplane* pa = nullptr;

    [[maybe_unused]] const GameCharacter* pgc = nullptr;
}
