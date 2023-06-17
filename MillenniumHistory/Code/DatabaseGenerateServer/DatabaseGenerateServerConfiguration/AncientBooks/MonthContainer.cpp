/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �Զ�����

#include "Month.h"
#include "MonthContainerDetail.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/TextParsing/CSV/CSVContent.h"
#include "CoreTools/TextParsing/CSV/CSVHead.h"
#include "CoreTools/TextParsing/CSV/CSVRow.h"

#include <algorithm>

AncientBooks::MonthContainer::MonthContainer(const CoreTools::CSVContent& csvContent)
    : month{}
{
    Parsing(csvContent);

    USER_SELF_CLASS_IS_VALID_9;
}

void AncientBooks::MonthContainer::Parsing(const CoreTools::CSVContent& csvContent)
{
    const auto size = csvContent.GetCount();
    const auto csvHead = csvContent.GetCSVHead();

    for (auto i = 0; i < size; ++i)
    {
        CoreTools::CSVRow csvRow{ csvHead, csvContent.GetContent(i) };

        month.emplace_back(std::make_shared<Month>(csvRow));
    }

    std::ranges::sort(month, [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetKey() < (*rhs).GetKey();
    });

    const auto iter = std::ranges::unique(month, [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetKey() == (*rhs).GetKey();
    });

    if (iter.begin() != iter.end())
    {
        LOG_SINGLETON_ENGINE_APPENDER(Warn, User,  SYSTEM_TEXT("month������ظ�������"), CoreTools::LogAppenderIOManageSign::TriggerAssert);

        month.erase(iter.begin(), iter.end());
    }
}

CLASS_INVARIANT_STUB_DEFINE(AncientBooks, MonthContainer)

AncientBooks::MonthContainer::ConstMonthBaseSharedPtr AncientBooks::MonthContainer::GetFirstMonth() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return month.at(0);
}

AncientBooks::MonthContainer::ConstMonthBaseSharedPtr AncientBooks::MonthContainer::GetMonth(int key) const
{
    USER_CLASS_IS_VALID_CONST_9;

    const auto function = [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetKey() < (*rhs).GetKey();
    };

    const auto iter = std::ranges::lower_bound(month, std::make_shared<MonthBase>(key), function);

    if (iter != month.cend() && (*iter)->GetKey() == key)
    {
        return *iter;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("month��δ�ҵ�key = "s) + System::ToString(key) + SYSTEM_TEXT("��������Ϣ��"s))
    }
}

AncientBooks::MonthContainer::Container AncientBooks::MonthContainer::GetContainer() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return month;
}

