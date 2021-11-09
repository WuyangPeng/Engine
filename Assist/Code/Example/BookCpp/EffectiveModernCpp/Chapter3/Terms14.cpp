///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.4 (2021/10/05 11:37)

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppExport.h"

#include "Terms14.h"
#include "CoreTools/Contract/Noexcept.h"

int BookExperience::EffectiveModernCpp::Chapter3::Terms14::Example0::F(MAYBE_UNUSED int x) throw()
{
    return 0;
}

int BookExperience::EffectiveModernCpp::Chapter3::Terms14::Example1::F(MAYBE_UNUSED int x) noexcept
{
    return 0;
}

void BookExperience::EffectiveModernCpp::Chapter3::Terms14::F(MAYBE_UNUSED const std::string& s) noexcept
{
}

void BookExperience::EffectiveModernCpp::Chapter3::Terms14::Setup()
{
    CoreTools::DisableNoexcept();
}

void BookExperience::EffectiveModernCpp::Chapter3::Terms14::Cleanup()
{
    CoreTools::DisableNoexcept();
}

void BookExperience::EffectiveModernCpp::Chapter3::Terms14::DoWork() noexcept
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26447)

    Setup();  // 建立要做的工作

    // 完成要做的工作
    // ...

    Cleanup();  // 执行清理工作

#include STSTEM_WARNING_POP
}
