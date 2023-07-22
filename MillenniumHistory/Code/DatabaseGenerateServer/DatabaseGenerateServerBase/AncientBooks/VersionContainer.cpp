/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �Զ�����

#include "Version.h"
#include "VersionContainerDetail.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/TextParsing/CSV/CSVContent.h"
#include "CoreTools/TextParsing/CSV/CSVHead.h"
#include "CoreTools/TextParsing/CSV/CSVRow.h"

#include <algorithm>

AncientBooks::VersionContainer::VersionContainer(const CSVContent& csvContent)
    : version{}
{
    Parsing(csvContent);

    USER_SELF_CLASS_IS_VALID_9;
}

void AncientBooks::VersionContainer::Parsing(const CSVContent& csvContent)
{
    LOG_SINGLETON_ENGINE_APPENDER(Info, User, SYSTEM_TEXT("version����ʼ���롭��"));

    Load(csvContent);
    Unique();

    LOG_SINGLETON_ENGINE_APPENDER(Info, User, SYSTEM_TEXT("version���������롭��"));
}

void AncientBooks::VersionContainer::Load(const CSVContent& csvContent)
{
    const auto size = csvContent.GetCount();
    const auto csvHead = csvContent.GetCSVHead();

    for (auto i = 0; i < size; ++i)
    {
        CoreTools::CSVRow csvRow{ csvHead, csvContent.GetContent(i) };

        version.emplace_back(std::make_shared<Version>(csvRow));
    }

    std::ranges::sort(version, [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetKey() < (*rhs).GetKey();
    });
}

void AncientBooks::VersionContainer::Unique()
{
    const auto iter = std::ranges::unique(version, [](const auto& lhs, const auto& rhs) noexcept {
        if((*lhs).GetKey() == (*rhs).GetKey())
        {
            LOG_SINGLETON_ENGINE_APPENDER(Warn, User, SYSTEM_TEXT("version�������ظ�������key = "), (*lhs).GetKey(), SYSTEM_TEXT("��\n"), CoreTools::LogAppenderIOManageSign::TriggerAssert);

            return true;
        }
        else
        {
            return false;
        }
    });

    if (iter.begin() != iter.end())
    {
        version.erase(iter.begin(), iter.end());
    }

    version.shrink_to_fit();
}

CLASS_INVARIANT_STUB_DEFINE(AncientBooks, VersionContainer)

AncientBooks::VersionContainer::ConstVersionBaseSharedPtr AncientBooks::VersionContainer::GetFirstVersion() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return version.at(0);
}

AncientBooks::VersionContainer::ConstVersionBaseSharedPtr AncientBooks::VersionContainer::GetVersion(int key) const
{
    USER_CLASS_IS_VALID_CONST_9;

    const auto function = [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetKey() < (*rhs).GetKey();
    };

    const auto iter = std::ranges::lower_bound(version, std::make_shared<VersionBase>(key), function);

    if (iter != version.cend() && (*iter)->GetKey() == key)
    {
        return *iter;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("version��δ�ҵ�key = "s) + System::ToString(key) + SYSTEM_TEXT("��������Ϣ��"s))
    }
}

AncientBooks::VersionContainer::Container AncientBooks::VersionContainer::GetContainer() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return version;
}
