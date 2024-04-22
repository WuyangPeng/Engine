/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/12 15:21)

#include "CoreTools/CoreToolsExport.h"

#include "BaseEntity.h"
#include "EntityManager.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Base/Flags/UniqueIdSelect.h"
#include "CoreTools/Base/UniqueIdManager.h"
#include "CoreTools/Contract/Noexcept.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

CoreTools::BaseEntity::BaseEntity(DisableNotThrow disableNotThrow)
    : entityId{ UNIQUE_ID_MANAGER_SINGLETON.NextUniqueId(UniqueIdSelect::Entity) }
{
    System::UnusedFunction(disableNotThrow);

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::BaseEntity::~BaseEntity() noexcept
{
    EXCEPTION_TRY
    {
        if (!ENTITY_MANAGER_SINGLETON.UnRegister(entityId))
        {
            LOG_SINGLETON_ENGINE_APPENDER(Warn, CoreTools, SYSTEM_TEXT("注销EntityID = "), entityId, SYSTEM_TEXT(" 失败。"), CoreTools::LogAppenderIOManageSign::TriggerAssert);
        }
    }
    EXCEPTION_ALL_CATCH(CoreTools)

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, BaseEntity)

int64_t CoreTools::BaseEntity::GetEntityId() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return entityId;
}

void CoreTools::BaseEntity::Register()
{
    if (!ENTITY_MANAGER_SINGLETON.Register(shared_from_this()))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("重复注册Entity"s))
    }
    else
    {
        DoRegister();
    }
}

void CoreTools::BaseEntity::DoRegister()
{
    DisableNoexcept();
}
