/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#include "Skill.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/TextParsing/CSV/CSVRowDetail.h"

using namespace std::literals;

CSVConfigure::Skill::Skill(const CoreTools::CSVRow& csvRow)
    : ParentType{},
      id{ csvRow.GetInt(SYSTEM_TEXT("id"s)) },
      nextId{ csvRow.GetInt(SYSTEM_TEXT("nextId"s)) },
      reward{ csvRow.GetInt(SYSTEM_TEXT("reward"s)) },
      skillName{ csvRow.GetString(SYSTEM_TEXT("skillName"s)) },
      vectorType{ csvRow.GetEnum<VectorType>(SYSTEM_TEXT("vectorType"s)) },
      position{ csvRow.GetIntVector3(SYSTEM_TEXT("position"s)) }
{
    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CSVConfigure, Skill)

int CSVConfigure::Skill::GetKey() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return  id * 100 + reward;
}

int CSVConfigure::Skill::GetId() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return id;
}

int CSVConfigure::Skill::GetNextId() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return nextId;
}

int CSVConfigure::Skill::GetReward() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return reward;
}

System::String CSVConfigure::Skill::GetSkillName() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return skillName;
}

CSVConfigure::VectorType CSVConfigure::Skill::GetVectorType() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return vectorType;
}

CoreTools::IntVector3 CSVConfigure::Skill::GetPosition() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return position;
}

