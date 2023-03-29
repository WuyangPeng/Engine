/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �Զ�����

#include "SystemConstant.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/TextParsing/CSV/CSVRowDetail.h"

using namespace std::literals;

CSVConfigure::SystemConstant::SystemConstant(const CoreTools::CSVRow& csvRow)
    : id{ csvRow.GetInt(SYSTEM_TEXT("id"s)) },
      nextId{ csvRow.GetInt(SYSTEM_TEXT("nextId"s)) },
      reward{ csvRow.GetInt(SYSTEM_TEXT("reward"s)) },
      skillName{ csvRow.GetString(SYSTEM_TEXT("skillName"s)) },
      vectorType{ csvRow.GetEnum<VectorType>(SYSTEM_TEXT("vectorType"s)) },
      position{ csvRow.GetIntVector3(SYSTEM_TEXT("position"s)) }
{
    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CSVConfigure, SystemConstant)

int CSVConfigure::SystemConstant::GetKey() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return id;
}

int CSVConfigure::SystemConstant::GetId() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return id;
}

int CSVConfigure::SystemConstant::GetNextId() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return nextId;
}

int CSVConfigure::SystemConstant::GetReward() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return reward;
}

System::String CSVConfigure::SystemConstant::GetSkillName() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return skillName;
}

CSVConfigure::VectorType CSVConfigure::SystemConstant::GetVectorType() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return vectorType;
}

CoreTools::IntVector3 CSVConfigure::SystemConstant::GetPosition() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return position;
}

