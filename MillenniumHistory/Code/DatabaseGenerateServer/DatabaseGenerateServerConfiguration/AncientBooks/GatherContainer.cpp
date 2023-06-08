/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �Զ�����

#include "Gather.h"
#include "GatherContainerDetail.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/TextParsing/CSV/CSVContent.h"
#include "CoreTools/TextParsing/CSV/CSVHead.h"
#include "CoreTools/TextParsing/CSV/CSVRow.h"

#include <algorithm>

AncientBooks::GatherContainer::GatherContainer(const CoreTools::CSVContent& csvContent)
    : gather{}
{
    Parsing(csvContent);

    USER_SELF_CLASS_IS_VALID_9;
}

void AncientBooks::GatherContainer::Parsing(const CoreTools::CSVContent& csvContent)
{
    const auto size = csvContent.GetCount();
    for (auto i = 0; i < size; ++i)
    {
        CoreTools::CSVRow csvRow{ csvContent.GetCSVHead(), csvContent.GetContent(i) };

        gather.emplace_back(std::make_shared<Gather>(csvRow));
    }

    std::ranges::sort(gather, [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetKey() < (*rhs).GetKey();
    });

    const auto iter = std::ranges::unique(gather, [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetKey() == (*rhs).GetKey();
    });

    if (iter.begin() != iter.end())
    {
        LOG_SINGLETON_ENGINE_APPENDER(Warn, User,  SYSTEM_TEXT("gather������ظ�������"), CoreTools::LogAppenderIOManageSign::TriggerAssert);

        gather.erase(iter.begin(), iter.end());
    }
}

CLASS_INVARIANT_STUB_DEFINE(AncientBooks, GatherContainer)

AncientBooks::GatherContainer::ConstGatherBaseSharedPtr AncientBooks::GatherContainer::GetFirstGather() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return gather.at(0);
}

AncientBooks::GatherContainer::ConstGatherBaseSharedPtr AncientBooks::GatherContainer::GetGather(int key) const
{
    USER_CLASS_IS_VALID_CONST_9;

    const auto function = [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetKey() < (*rhs).GetKey();
    };

    const auto iter = std::ranges::lower_bound(gather, std::make_shared<GatherBase>(key), function);

    if (iter != gather.cend() && (*iter)->GetKey() == key)
    {
        return *iter;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("gather��δ�ҵ�key = "s) + System::ToString(key) + SYSTEM_TEXT("��������Ϣ��"s))
    }
}

AncientBooks::GatherContainer::Container AncientBooks::GatherContainer::GetContainer() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return gather;
}

