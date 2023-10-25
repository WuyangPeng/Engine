/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �Զ�����

#include "Year.h"
#include "YearContainerDetail.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/TextParsing/CSV/CSVContent.h"
#include "CoreTools/TextParsing/CSV/CSVHead.h"
#include "CoreTools/TextParsing/CSV/CSVRow.h"

#include <algorithm>

AncientBooks::YearContainer::YearContainer(const CSVContent& csvContent)
    : year{}
{
    Parsing(csvContent);

    USER_SELF_CLASS_IS_VALID_9;
}

void AncientBooks::YearContainer::Parsing(const CSVContent& csvContent)
{
    LOG_SINGLETON_ENGINE_APPENDER(Info, User, SYSTEM_TEXT("year��ʼ���롭��"));

    Load(csvContent);
    Unique();

    LOG_SINGLETON_ENGINE_APPENDER(Info, User, SYSTEM_TEXT("year��������롭��"));
}

void AncientBooks::YearContainer::Load(const CSVContent& csvContent)
{
    const auto size = csvContent.GetCount();
    const auto csvHead = csvContent.GetCSVHead();

    for (auto index = 0; index < size; ++index)
    {
        CoreTools::CSVRow csvRow{ csvHead, csvContent.GetContent(index) };

        year.emplace_back(std::make_shared<Year>(csvRow));
    }

    std::ranges::sort(year, [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetKey() < (*rhs).GetKey();
    });
}

void AncientBooks::YearContainer::Unique()
{
    const auto iter = std::ranges::unique(year, [](const auto& lhs, const auto& rhs) noexcept {
        if((*lhs).GetKey() == (*rhs).GetKey())
        {
            LOG_SINGLETON_ENGINE_APPENDER(Warn, User, SYSTEM_TEXT("year������ظ�������key = "), (*lhs).GetKey(), SYSTEM_TEXT("��\n"), CoreTools::LogAppenderIOManageSign::TriggerAssert);

            return true;
        }
        else
        {
            return false;
        }
    });

    if (iter.begin() != iter.end())
    {
        year.erase(iter.begin(), iter.end());
    }

    year.shrink_to_fit();
}

CLASS_INVARIANT_STUB_DEFINE(AncientBooks, YearContainer)

AncientBooks::YearContainer::ConstYearSharedPtr AncientBooks::YearContainer::GetFirstYear() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return year.at(0);
}

AncientBooks::YearContainer::ConstYearSharedPtr AncientBooks::YearContainer::GetYear(int key) const
{
    USER_CLASS_IS_VALID_CONST_9;

    const auto function = [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetKey() < (*rhs).GetKey();
    };

    const auto iter = std::ranges::lower_bound(year, std::make_shared<YearBase>(key), function);

    if (iter != year.cend() && (*iter)->GetKey() == key)
    {
        return *iter;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("year��δ�ҵ�key = "s) + System::ToString(key) + SYSTEM_TEXT("��������Ϣ��"s))
    }
}

AncientBooks::YearContainer::Container AncientBooks::YearContainer::GetContainer() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return year;
}

int AncientBooks::YearContainer::GetContainerSize() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(year.size());
}

