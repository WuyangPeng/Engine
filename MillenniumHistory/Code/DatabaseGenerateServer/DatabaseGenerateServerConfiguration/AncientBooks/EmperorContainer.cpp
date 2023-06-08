/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �Զ�����

#include "Emperor.h"
#include "EmperorContainerDetail.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/TextParsing/CSV/CSVContent.h"
#include "CoreTools/TextParsing/CSV/CSVHead.h"
#include "CoreTools/TextParsing/CSV/CSVRow.h"

#include <algorithm>

AncientBooks::EmperorContainer::EmperorContainer(const CoreTools::CSVContent& csvContent)
    : emperor{}
{
    Parsing(csvContent);

    USER_SELF_CLASS_IS_VALID_9;
}

void AncientBooks::EmperorContainer::Parsing(const CoreTools::CSVContent& csvContent)
{
    const auto size = csvContent.GetCount();
    for (auto i = 0; i < size; ++i)
    {
        CoreTools::CSVRow csvRow{ csvContent.GetCSVHead(), csvContent.GetContent(i) };

        emperor.emplace_back(std::make_shared<Emperor>(csvRow));
    }

    std::ranges::sort(emperor, [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetKey() < (*rhs).GetKey();
    });

    const auto iter = std::ranges::unique(emperor, [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetKey() == (*rhs).GetKey();
    });

    if (iter.begin() != iter.end())
    {
        LOG_SINGLETON_ENGINE_APPENDER(Warn, User,  SYSTEM_TEXT("emperor������ظ�������"), CoreTools::LogAppenderIOManageSign::TriggerAssert);

        emperor.erase(iter.begin(), iter.end());
    }
}

CLASS_INVARIANT_STUB_DEFINE(AncientBooks, EmperorContainer)

AncientBooks::EmperorContainer::ConstEmperorBaseSharedPtr AncientBooks::EmperorContainer::GetFirstEmperor() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return emperor.at(0);
}

AncientBooks::EmperorContainer::ConstEmperorBaseSharedPtr AncientBooks::EmperorContainer::GetEmperor(int key) const
{
    USER_CLASS_IS_VALID_CONST_9;

    const auto function = [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetKey() < (*rhs).GetKey();
    };

    const auto iter = std::ranges::lower_bound(emperor, std::make_shared<EmperorBase>(key), function);

    if (iter != emperor.cend() && (*iter)->GetKey() == key)
    {
        return *iter;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("emperor��δ�ҵ�key = "s) + System::ToString(key) + SYSTEM_TEXT("��������Ϣ��"s))
    }
}

AncientBooks::EmperorContainer::Container AncientBooks::EmperorContainer::GetContainer() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return emperor;
}

