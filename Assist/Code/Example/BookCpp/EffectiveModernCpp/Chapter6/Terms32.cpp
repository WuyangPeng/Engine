///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.7 (2021/11/29 21:29)

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppExport.h"

#include "Terms32.h"
#include "System/Helper/PragmaWarning.h"

bool BookExperience::EffectiveModernCpp::Chapter6::Terms32::Example0::Widget::IsValidated() const noexcept
{
    return false;
}

bool BookExperience::EffectiveModernCpp::Chapter6::Terms32::Example0::Widget::IsProcessed() const noexcept
{
    return false;
}

bool BookExperience::EffectiveModernCpp::Chapter6::Terms32::Example0::Widget::IsArchived() const noexcept
{
    return false;
}

BookExperience::EffectiveModernCpp::Chapter6::Terms32::Example0::IsValAndArch::IsValAndArch(DataType&& ptr) noexcept
    : pw(std::move(ptr))
{
}

bool BookExperience::EffectiveModernCpp::Chapter6::Terms32::Example0::IsValAndArch::operator()() const noexcept
{
    return pw->IsValidated() && pw->IsArchived();
}