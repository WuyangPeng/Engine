///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.3 (2021/09/18 21:45)

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppExport.h"

#include "Terms6.h"

using std::vector;

vector<bool> BookExperience::EffectiveModernCpp::Chapter2::Terms6::Features(MAYBE_UNUSED const Widget& w)
{
    return vector<bool>{ false, false, false, false, true, false, false, true };
}

void BookExperience::EffectiveModernCpp::Chapter2::Terms6::ProcessWidget(MAYBE_UNUSED const Widget& w, MAYBE_UNUSED bool highPriority) noexcept
{
}

BookExperience::EffectiveModernCpp::Chapter2::Terms6::Matrix BookExperience::EffectiveModernCpp::Chapter2::Terms6::operator+(const Matrix& lhs, MAYBE_UNUSED const Matrix& rhs) noexcept
{
    return lhs;
}

double BookExperience::EffectiveModernCpp::Chapter2::Terms6::CalcEpsilon() noexcept
{
    return 0.0;
}
