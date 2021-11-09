/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++17
/// �Զ�����

#include "Skill.h"
#include "SkillContainerDetail.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/TextParsing/CSVContent.h"
#include "CoreTools/TextParsing/CSVHead.h"
#include "CoreTools/TextParsing/CSVRow.h"

#include <algorithm>

using std::make_shared;

CSVConfigure::SkillContainer::SkillContainer(const CoreTools::CSVContent& csvContent)
    : skill{}
{
    Parsing(csvContent);

    USER_SELF_CLASS_IS_VALID_9;
}

void CSVConfigure::SkillContainer::Parsing(const CoreTools::CSVContent& csvContent)
{
    const auto size = csvContent.GetCount();
    for (auto i = 0; i < size; ++i)
    {
        CoreTools::CSVRow csvRow{ csvContent.GetCSVHead(), csvContent.GetContent(i) };

        skill.emplace_back(make_shared<Skill>(csvRow));
    }

    std::sort(skill.begin(), skill.end(), [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetKey() < (*rhs).GetKey();
    });

    auto iter = unique(skill.begin(), skill.end(), [](const auto& lhs, const auto& rhs) noexcept {
        return (*lhs).GetKey() == (*rhs).GetKey();
    });

    if (iter != skill.cend())
    {
        LOG_SINGLETON_ENGINE_APPENDER(Warn, User)
            << SYSTEM_TEXT("skill������ظ�������")
            << LOG_SINGLETON_TRIGGER_ASSERT;

        skill.erase(iter, skill.end());
    }
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

    const auto iter = lower_bound(skill.begin(), skill.end(), make_shared<SkillBase>(key), function);

    if (iter != skill.cend() && (*iter)->GetKey() == key)
    {
        return *iter;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("skill��δ�ҵ�key = "s) + System::ToString(key) + SYSTEM_TEXT("��������Ϣ��"s));
    }
}

CSVConfigure::SkillContainer::Container CSVConfigure::SkillContainer::GetContainer() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return skill;
}

