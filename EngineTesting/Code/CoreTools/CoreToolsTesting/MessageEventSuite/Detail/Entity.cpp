///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/18 16:26)

#include "Entity.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

std::shared_ptr<CoreTools::Entity> CoreTools::Entity::Create(int value)
{
    return std::make_shared<Entity>(value);
}

CoreTools::Entity::Entity(int value)
    : ParentType{ DisableNotThrow::Disable }, value{ value }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, Entity)

bool CoreTools::Entity::EventFunction(const Telegram& telegram)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    value += telegram.GetCallbackParameters().GetInt32Value(0);

    return true;
}

int CoreTools::Entity::GetValue() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return value;
}
