/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++17
/// �Զ�����

#ifndef C_S_V_CONFIGURE_SKILL_CONTAINER_DETAIL_H
#define C_S_V_CONFIGURE_SKILL_CONTAINER_DETAIL_H

#include "SkillContainer.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

template <typename Function>
CSVConfigure::SkillContainer::ConstSkillBaseSharedPtr CSVConfigure::SkillContainer::GetFirstSkill(Function function) const
{
    USER_CLASS_IS_VALID_CONST_9;

    const auto iter = std::find_if(skill.cbegin(), skill.cend(), function);

    if (iter != skill.cend())
    {
        return *iter;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("skill��δ�ҵ�����������������Ϣ��"s));
}

template <typename Function>
CSVConfigure::SkillContainer::Container CSVConfigure::SkillContainer::GetSkill(Function function) const
{
    USER_CLASS_IS_VALID_CONST_9;

    Container result{};

    for (const auto& value : skill)
    {
        if (function(value))
        {
            result.emplace_back(value);
        }
    }

    return result;
}

#endif  // C_S_V_CONFIGURE_SKILL_CONTAINER_DETAIL_H
