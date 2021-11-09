///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.4 (2021/09/30 20:38)

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
    MakeLogEntry("Creating StringTable object");  // ���Ǻ�ӵ�
}

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26432)

BookExperience::EffectiveModernCpp::Chapter3::Terms17::Example1::StringTable::~StringTable() noexcept
{
    MakeLogEntry("Destroying StringTable object");  // ��Ҳ�Ǻ�ӵ�
}

#include STSTEM_WARNING_POP