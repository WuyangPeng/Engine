/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#include "Skill.h"
#include "SkillContainerDetail.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/TextParsing/CSV/CSVContent.h"
#include "CoreTools/TextParsing/CSV/CSVHead.h"
#include "CoreTools/TextParsing/CSV/CSVRow.h"

#include <algorithm>

CSVConfigure::SkillContainer::SkillContainer(const CoreTools::CSVContent& csvContent)
    : skill{}
{
    Parsing(csvContent);

    USER_SELF_CLASS_IS_VALID_9;
}

void CSVConfigure::SkillContainer::Parsing(const CoreTools::CSVContent& csvContent)
{
    LOG_SINGLETON_ENGINE_APPENDER(Info, User, SYSTEM_TEXT("skill表开始载入……"));

    const auto size = csvContent.GetCount();
    const auto csvHead = csvContent.GetCSVHead();

    for (auto i = 0; i < size; ++i)
    {
        CoreTools::CSVRow csvRow{ csvHead, csvContent.GetContent(i) };

        skill.emplace_back(std::make_shared<Skill>(csvRow));
    }

    std::ranges::sort(skill, [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetKey() < (*rhs).GetKey();
    });

    const auto iter = std::ranges::unique(skill, [](const auto& lhs, const auto& rhs) noexcept {
        if((*lhs).GetKey() == (*rhs).GetKey())
        {
            LOG_SINGLETON_ENGINE_APPENDER(Warn, User, SYSTEM_TEXT("skill表存在重复主键，key = "), (*lhs).GetKey(), SYSTEM_TEXT("。\n"), CoreTools::LogAppenderIOManageSign::TriggerAssert);

            return true;
        }
        else
        {
            return false;
        }
    });

    if (iter.begin() != iter.end())
    {
        LOG_SINGLETON_ENGINE_APPENDER(Warn, User,  SYSTEM_TEXT("skill表存在重复主键。"), CoreTools::LogAppenderIOManageSign::TriggerAssert);

        skill.erase(iter.begin(), iter.end());
    }

    LOG_SINGLETON_ENGINE_APPENDER(Info, User, SYSTEM_TEXT("skill表结束载入……"));
}

CLASS_INVARIANT_STUB_DEFINE(CSVConfigure, SkillContainer)

CSVConfigure::SkillContainer::ConstSkillBaseSharedPtr CSVConfigure::SkillContainer::GetFirstSkill() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return skill.at(0);
}

CSVConfigure::SkillContainer::ConstSkillBaseSharedPtr CSVConfigure::SkillContainer::GetSkill(int id, int reward) const
{
    USER_CLASS_IS_VALID_CONST_9;

    return GetSkill(Skill::GenerateKey(id, reward));
}

CSVConfigure::SkillContainer::ConstSkillBaseSharedPtr CSVConfigure::SkillContainer::GetSkill(int key) const
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
        THROW_EXCEPTION(SYSTEM_TEXT("skill表未找到key = "s) + System::ToString(key) + SYSTEM_TEXT("的配置信息。"s))
    }
}

CSVConfigure::SkillContainer::Container CSVConfigure::SkillContainer::GetContainer() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return skill;
}

