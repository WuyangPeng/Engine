///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.4 (2021/09/30 20:38)

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppExport.h"

#include "Terms17.h"
#include "System/Helper/PragmaWarning.h"

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26439)

BookExperience::EffectiveModernCpp::Chapter3::Terms17::Example0::Widget::Widget(MAYBE_UNUSED Widget&& rhs)
{
}

BookExperience::EffectiveModernCpp::Chapter3::Terms17::Example0::Widget& BookExperience::EffectiveModernCpp::Chapter3::Terms17::Example0::Widget::operator=(MAYBE_UNUSED Widget&& rhs)
{
    return *this;
}

#include STSTEM_WARNING_POP

BookExperience::EffectiveModernCpp::Chapter3::Terms17::Example1::Widget::~Widget() noexcept
{
}

BookExperience::EffectiveModernCpp::Chapter3::Terms17::Example0::StringTable::StringTable() noexcept
{
}

void BookExperience::EffectiveModernCpp::Chapter3::Terms17::MakeLogEntry(MAYBE_UNUSED std::string_view log) noexcept
{
}

BookExperience::EffectiveModernCpp::Chapter3::Terms17::Example1::StringTable::StringTable() noexcept
{
    MakeLogEntry("Creating StringTable object");  // 这是后加的
}

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26432)

BookExperience::EffectiveModernCpp::Chapter3::Terms17::Example1::StringTable::~StringTable() noexcept
{
    MakeLogEntry("Destroying StringTable object");  // 这也是后加的
}

#include STSTEM_WARNING_POP