/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �Զ�����

#include "Scene.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/TextParsing/CSV/CSVRowDetail.h"

using namespace std::literals;

CSVConfigure::Scene::Scene(const CSVRow& csvRow)
    : id{ csvRow.GetInt(SYSTEM_TEXT("id"s)) },
      nextId{ csvRow.GetInt(SYSTEM_TEXT("nextId"s)) },
      reward{ csvRow.GetInt(SYSTEM_TEXT("reward"s)) },
      sceneName{ csvRow.GetString(SYSTEM_TEXT("sceneName"s)) },
      length{ csvRow.GetDouble(SYSTEM_TEXT("length"s)) },
      position{ csvRow.GetIntVector2(SYSTEM_TEXT("position"s)) }
{
    USER_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CSVConfigure, Scene)

int CSVConfigure::Scene::GetKey() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return id;
}

int CSVConfigure::Scene::GetId() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return id;
}

int CSVConfigure::Scene::GetNextId() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return nextId;
}

int CSVConfigure::Scene::GetReward() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return reward;
}

System::String CSVConfigure::Scene::GetSceneName() const
{
    USER_CLASS_IS_VALID_CONST_9;

    return sceneName;
}

double CSVConfigure::Scene::GetLength() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return length;
}

CoreTools::IntVector2 CSVConfigure::Scene::GetPosition() const noexcept
{
    USER_CLASS_IS_VALID_CONST_9;

    return position;
}

