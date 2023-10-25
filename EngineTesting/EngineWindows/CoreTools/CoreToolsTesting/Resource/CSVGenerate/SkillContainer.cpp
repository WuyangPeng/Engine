/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �Զ�����

#include "Skill.h"
#include "SkillContainerDetail.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/TextParsing/CSV/CSVContent.h"
#include "CoreTools/TextParsing/CSV/CSVHead.h"
#include "CoreTools/TextParsing/CSV/CSVRow.h"

#include <algorithm>

CSVConfigure::SkillContainer::SkillContainer(const CSVContent& csvContent)
    : skill{}
{
    Parsing(csvContent);

    USER_SELF_CLASS_IS_VALID_9;
}

void CSVConfigure::SkillContainer::Parsing(const CSVContent& csvContent)
{
    LOG_SINGLETON_ENGINE_APPENDER(Info, User, SYSTEM_TEXT("skill��ʼ���롭��"));

    Load(csvContent);
    Unique();

    LOG_SINGLETON_ENGINE_APPENDER(Info, User, SYSTEM_TEXT("skill��������롭��"));
}

void CSVConfigure::SkillContainer::Load(const CSVContent& csvContent)
{
    const auto size = csvContent.GetCount();
    const auto csvHead = csvContent.GetCSVHead();

    for (auto index = 0; index < size; ++index)
    {
        CoreTools::CSVRow csvRow{ csvHead, csvContent.GetContent(index) };

        skill.emplace_back(std::make_shared<Skill>(csvRow));
    }

    std::ranges::sort(skill, [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetKey() < (*rhs).GetKey();
    });
}

void CSVConfigure::SkillContainer::Unique()
{
    const auto iter = std::ranges::unique(skill, [](const auto& lhs, const auto& rhs) noexcept {
        if((*lhs).GetKey() == (*rhs).GetKey())
        {
            LOG_SINGLETON_ENGINE_APPENDER(Warn, User, SYSTEM_TEXT("skill������ظ�������key = "), (*lhs).GetKey(), SYSTEM_TEXT("��\n"), CoreTools::LogAppenderIOManageSign::TriggerAssert);

            return true;
        }
        else
        {
            return false;
        }
    });

    if (iter.begin() != iter.end())
    {
        skill.erase(iter.begin(), iter.end());
    }

    skill.shrink_to_fit();
}

CLASS_INVARIANT_STUB_DEFINE(CSVConfigure, SkillContainer)

CSVConfigure::SkillContainer::ConstSkillSharedPtr CSVConfigure::SkillContainer::GetFirstSkill() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return skill.at(0);
}

CSVConfigure::SkillContainer::ConstSkillSharedPtr CSVConfigure::SkillContainer::GetSkill(int key) const
{
    USER_CLASS_IS_VALID_CONST_9;

    const auto function = [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetKey() < (*rhs).GetKey();
    };

    const auto iter = std::ranges::lower_bound(skill, std::make_shared<SkillBase>(key), function);

    if (iter != skill.cend() && (*iter)->GetKey() == key)
    {
        return *iter;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("skill��δ�ҵ�key = "s) + System::ToString(key) + SYSTEM_TEXT("��������Ϣ��"s))
    }
}

CSVConfigure::SkillContainer::Container CSVConfigure::SkillContainer::GetContainer() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return skill;
}

int CSVConfigure::SkillContainer::GetContainerSize() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(skill.size());
}

