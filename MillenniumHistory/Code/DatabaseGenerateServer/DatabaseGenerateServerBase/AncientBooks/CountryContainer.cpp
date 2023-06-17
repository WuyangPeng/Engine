/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �Զ�����

#include "Country.h"
#include "CountryContainerDetail.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/TextParsing/CSV/CSVContent.h"
#include "CoreTools/TextParsing/CSV/CSVHead.h"
#include "CoreTools/TextParsing/CSV/CSVRow.h"

#include <algorithm>

AncientBooks::CountryContainer::CountryContainer(const CoreTools::CSVContent& csvContent)
    : country{}
{
    Parsing(csvContent);

    USER_SELF_CLASS_IS_VALID_9;
}

void AncientBooks::CountryContainer::Parsing(const CoreTools::CSVContent& csvContent)
{
    LOG_SINGLETON_ENGINE_APPENDER(Info, User, SYSTEM_TEXT("country��ʼ���롭��"));

    const auto size = csvContent.GetCount();
    const auto csvHead = csvContent.GetCSVHead();

    for (auto i = 0; i < size; ++i)
    {
        CoreTools::CSVRow csvRow{ csvHead, csvContent.GetContent(i) };

        country.emplace_back(std::make_shared<Country>(csvRow));
    }

    std::ranges::sort(country, [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetKey() < (*rhs).GetKey();
    });

    const auto iter = std::ranges::unique(country, [](const auto& lhs, const auto& rhs) noexcept {
        if((*lhs).GetKey() == (*rhs).GetKey())
        {
            LOG_SINGLETON_ENGINE_APPENDER(Warn, User, SYSTEM_TEXT("country������ظ�������key = "), (*lhs).GetKey(), SYSTEM_TEXT("��\n"), CoreTools::LogAppenderIOManageSign::TriggerAssert);

            return true;
        }
        else
        {
            return false;
        }
    });

    if (iter.begin() != iter.end())
    {
        LOG_SINGLETON_ENGINE_APPENDER(Warn, User,  SYSTEM_TEXT("country������ظ�������"), CoreTools::LogAppenderIOManageSign::TriggerAssert);

        country.erase(iter.begin(), iter.end());
    }

    LOG_SINGLETON_ENGINE_APPENDER(Info, User, SYSTEM_TEXT("country��������롭��"));
}

CLASS_INVARIANT_STUB_DEFINE(AncientBooks, CountryContainer)

AncientBooks::CountryContainer::ConstCountryBaseSharedPtr AncientBooks::CountryContainer::GetFirstCountry() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return country.at(0);
}

AncientBooks::CountryContainer::ConstCountryBaseSharedPtr AncientBooks::CountryContainer::GetCountry(int key) const
{
    USER_CLASS_IS_VALID_CONST_9;

    const auto function = [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetKey() < (*rhs).GetKey();
    };

    const auto iter = std::ranges::lower_bound(country, std::make_shared<CountryBase>(key), function);

    if (iter != country.cend() && (*iter)->GetKey() == key)
    {
        return *iter;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("country��δ�ҵ�key = "s) + System::ToString(key) + SYSTEM_TEXT("��������Ϣ��"s))
    }
}

AncientBooks::CountryContainer::Container AncientBooks::CountryContainer::GetContainer() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return country;
}

