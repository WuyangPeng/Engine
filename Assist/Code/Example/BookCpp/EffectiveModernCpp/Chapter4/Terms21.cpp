///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.5 (2021/10/22 20:49)

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppExport.h"

#include "Terms21.h"
#include "CoreTools/Helper/ExceptionMacro.h"

void BookExperience::EffectiveModernCpp::Chapter4::Terms21::ProcessWidget(MAYBE_UNUSED std::shared_ptr<Widget> spw, MAYBE_UNUSED int priority) noexcept
{
}

int BookExperience::EffectiveModernCpp::Chapter4::Terms21::ComputePriority() noexcept
{
    return 0;
}

void BookExperience::EffectiveModernCpp::Chapter4::Terms21::CusDel(Widget* ptr) noexcept
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26401)
#include SYSTEM_WARNING_DISABLE(26409)

    delete ptr;

#include STSTEM_WARNING_POP
}
