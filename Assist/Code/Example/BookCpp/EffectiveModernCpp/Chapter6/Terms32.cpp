///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.7 (2021/11/29 21:29)

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