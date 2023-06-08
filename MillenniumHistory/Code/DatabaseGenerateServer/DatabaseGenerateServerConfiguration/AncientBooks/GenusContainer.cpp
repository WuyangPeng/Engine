/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �Զ�����

#include "Genus.h"
#include "GenusContainerDetail.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/TextParsing/CSV/CSVContent.h"
#include "CoreTools/TextParsing/CSV/CSVHead.h"
#include "CoreTools/TextParsing/CSV/CSVRow.h"

#include <algorithm>

AncientBooks::GenusContainer::GenusContainer(const CoreTools::CSVContent& csvContent)
    : genus{}
{
    Parsing(csvContent);

    USER_SELF_CLASS_IS_VALID_9;
}

void AncientBooks::GenusContainer::Parsing(const CoreTools::CSVContent& csvContent)
{
    const auto size = csvContent.GetCount();
    for (auto i = 0; i < size; ++i)
    {
        CoreTools::CSVRow csvRow{ csvContent.GetCSVHead(), csvContent.GetContent(i) };

        genus.emplace_back(std::make_shared<Genus>(csvRow));
    }

    std::ranges::sort(genus, [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetKey() < (*rhs).GetKey();
    });

    const auto iter = std::ranges::unique(genus, [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetKey() == (*rhs).GetKey();
    });

    if (iter.begin() != iter.end())
    {
        LOG_SINGLETON_ENGINE_APPENDER(Warn, User,  SYSTEM_TEXT("genus������ظ�������"), CoreTools::LogAppenderIOManageSign::TriggerAssert);

        genus.erase(iter.begin(), iter.end());
    }
}

CLASS_INVARIANT_STUB_DEFINE(AncientBooks, GenusContainer)

AncientBooks::GenusContainer::ConstGenusBaseSharedPtr AncientBooks::GenusContainer::GetFirstGenus() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return genus.at(0);
}

AncientBooks::GenusContainer::ConstGenusBaseSharedPtr AncientBooks::GenusContainer::GetGenus(int key) const
{
    USER_CLASS_IS_VALID_CONST_9;

    const auto function = [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetKey() < (*rhs).GetKey();
    };

    const auto iter = std::ranges::lower_bound(genus, std::make_shared<GenusBase>(key), function);

    if (iter != genus.cend() && (*iter)->GetKey() == key)
    {
        return *iter;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("genus��δ�ҵ�key = "s) + System::ToString(key) + SYSTEM_TEXT("��������Ϣ��"s))
    }
}

AncientBooks::GenusContainer::Container AncientBooks::GenusContainer::GetContainer() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return genus;
}

