/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/04/23 13:01)

#include "Entity.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::Entity::EntitySharedPtr CoreTools::Entity::Create(int value)
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
