/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �Զ�����

#include "Day.h"
#include "DayContainerDetail.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/TextParsing/CSV/CSVContent.h"
#include "CoreTools/TextParsing/CSV/CSVHead.h"
#include "CoreTools/TextParsing/CSV/CSVRow.h"

#include <algorithm>

AncientBooks::DayContainer::DayContainer(const CoreTools::CSVContent& csvContent)
    : day{}
{
    Parsing(csvContent);

    USER_SELF_CLASS_IS_VALID_9;
}

void AncientBooks::DayContainer::Parsing(const CoreTools::CSVContent& csvContent)
{
    LOG_SINGLETON_ENGINE_APPENDER(Info, User, SYSTEM_TEXT("day��ʼ���롭��"));

    const auto size = csvContent.GetCount();
    const auto csvHead = csvContent.GetCSVHead();

    for (auto i = 0; i < size; ++i)
    {
        CoreTools::CSVRow csvRow{ csvHead, csvContent.GetContent(i) };

        day.emplace_back(std::make_shared<Day>(csvRow));
    }

    std::ranges::sort(day, [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetKey() < (*rhs).GetKey();
    });

    const auto iter = std::ranges::unique(day, [](const auto& lhs, const auto& rhs) noexcept {
        if((*lhs).GetKey() == (*rhs).GetKey())
        {
            LOG_SINGLETON_ENGINE_APPENDER(Warn, User, SYSTEM_TEXT("day������ظ�������key = "), (*lhs).GetKey(), SYSTEM_TEXT("��\n"), CoreTools::LogAppenderIOManageSign::TriggerAssert);

            return true;
        }
        else
        {
            return false;
        }
    });

    if (iter.begin() != iter.end())
    {
        LOG_SINGLETON_ENGINE_APPENDER(Warn, User,  SYSTEM_TEXT("day������ظ�������"), CoreTools::LogAppenderIOManageSign::TriggerAssert);

        day.erase(iter.begin(), iter.end());
    }

    LOG_SINGLETON_ENGINE_APPENDER(Info, User, SYSTEM_TEXT("day��������롭��"));
}

CLASS_INVARIANT_STUB_DEFINE(AncientBooks, DayContainer)

AncientBooks::DayContainer::ConstDayBaseSharedPtr AncientBooks::DayContainer::GetFirstDay() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return day.at(0);
}

AncientBooks::DayContainer::ConstDayBaseSharedPtr AncientBooks::DayContainer::GetDay(int key) const
{
    USER_CLASS_IS_VALID_CONST_9;

    const auto function = [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetKey() < (*rhs).GetKey();
    };

    const auto iter = std::ranges::lower_bound(day, std::make_shared<DayBase>(key), function);

    if (iter != day.cend() && (*iter)->GetKey() == key)
    {
        return *iter;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("day��δ�ҵ�key = "s) + System::ToString(key) + SYSTEM_TEXT("��������Ϣ��"s))
    }
}

AncientBooks::DayContainer::Container AncientBooks::DayContainer::GetContainer() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return day;
}

