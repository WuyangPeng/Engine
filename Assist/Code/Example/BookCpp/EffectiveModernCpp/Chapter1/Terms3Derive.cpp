///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.3 (2021/09/05 12:25)

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppExport.h"

#include "Terms3Derive.h"
#include "CoreTools/Contract/Noexcept.h"

bool BookExperience::EffectiveModernCpp::Chapter1::Terms3::F(MAYBE_UNUSED const Widget& w)
{
    static_assert(std::is_same_v<decltype(w), const Widget&>);

    CoreTools::DisableNoexcept();

    return true;
}

void BookExperience::EffectiveModernCpp::Chapter1::Terms3::ActhenticateUser() noexcept
{
}

std::deque<std::string> BookExperience::EffectiveModernCpp::Chapter1::Terms3::MakeStringDeque()  // 工厂函数
{
    return { "1", "2", "3", "4", "5", "6", "7", "8" };
}
