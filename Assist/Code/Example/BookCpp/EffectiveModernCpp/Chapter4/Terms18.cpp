///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.4 (2021/10/10 21:10)

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppExport.h"

#include "Terms18.h"

void BookExperience::EffectiveModernCpp::Chapter4::Terms18::MakeLogEntry(MAYBE_UNUSED Investment* pInvestment) noexcept
{
}

bool BookExperience::EffectiveModernCpp::Chapter4::Terms18::IsStock() noexcept
{
    return false;
}

bool BookExperience::EffectiveModernCpp::Chapter4::Terms18::IsBond() noexcept
{
    return false;
}

bool BookExperience::EffectiveModernCpp::Chapter4::Terms18::IsRealEstate() noexcept
{
    return false;
}

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26440)
void BookExperience::EffectiveModernCpp::Chapter4::Terms18::Example4::DelInvmt2(Investment* pInvestment)
{
    MakeLogEntry(pInvestment);

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26401)
#include SYSTEM_WARNING_DISABLE(26409)

    delete pInvestment;

#include STSTEM_WARNING_POP
}
#include STSTEM_WARNING_POP

BookExperience::EffectiveModernCpp::Chapter4::Terms18::Stock::Stock(MAYBE_UNUSED int arguments) noexcept
{
}

BookExperience::EffectiveModernCpp::Chapter4::Terms18::Bond::Bond(MAYBE_UNUSED int arguments) noexcept
{
}

BookExperience::EffectiveModernCpp::Chapter4::Terms18::RealEstate::RealEstate(MAYBE_UNUSED int arguments) noexcept
{
}
