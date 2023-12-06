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
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/TextParsing/CSV/CSVContent.h"
#include "CoreTools/TextParsing/CSV/CSVHead.h"
#include "CoreTools/TextParsing/CSV/CSVRow.h"

#include <algorithm>

AncientBooks::CountryContainer::CountryContainer(const CSVContent& csvContent)
    : country{}
{
    Parsing(csvContent);

    USER_SELF_CLASS_IS_VALID_9;
}

void AncientBooks::CountryContainer::Parsing(const CSVContent& csvContent)
{
    LOG_SINGLETON_ENGINE_APPENDER(Info, User, SYSTEM_TEXT("country��ʼ���롭��"));

    Load(csvContent);
    Unique();

    LOG_SINGLETON_ENGINE_APPENDER(Info, User, SYSTEM_TEXT("country��������롭��"));
}

void AncientBooks::CountryContainer::Load(const CSVContent& csvContent)
{
    const auto size = csvContent.GetCount();
    const auto csvHead = csvContent.GetCSVHead();

    for (auto index = 0; index < size; ++index)
    {
        CoreTools::CSVRow csvRow{ csvHead, csvContent.GetContent(index) };

        country.emplace_back(std::make_shared<Country>(csvRow));
    }

    std::ranges::sort(country, [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetKey() < (*rhs).GetKey();
    });
}

void AncientBooks::CountryContainer::Unique()
{
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
        country.erase(iter.begin(), iter.end());
    }

    country.shrink_to_fit();
}

CLASS_INVARIANT_STUB_DEFINE(AncientBooks, CountryContainer)

AncientBooks::CountryContainer::ConstCountrySharedPtr AncientBooks::CountryContainer::GetFirstCountry() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return country.at(0);
}

AncientBooks::CountryContainer::ConstCountrySharedPtr AncientBooks::CountryContainer::GetCountry(int key) const
{
    USER_CLASS_IS_VALID_CONST_9;

    const auto function = [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetKey() < (*rhs).GetKey();
    };

    if (const auto iter = std::ranges::lower_bound(country, std::make_shared<CountryBase>(key), function);
        iter != country.cend() && (*iter)->GetKey() == key)
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

int AncientBooks::CountryContainer::GetContainerSize() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(country.size());
}

