///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/26 18:30)

#include "CoreTools/CoreToolsExport.h"

#include "BaseEntity.h"
#include "EntityManager.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Base/Flags/UniqueIDSelectFlags.h"
#include "CoreTools/Base/UniqueIDManager.h"
#include "CoreTools/Contract/Noexcept.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

CoreTools::BaseEntity::BaseEntity(MAYBE_UNUSED DisableNotThrow dDisableNotThrow)
    : entityID{ UNIQUE_ID_MANAGER_SINGLETON.NextUniqueID(UniqueIDSelect::Entity) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::BaseEntity::~BaseEntity() noexcept
{
    EXCEPTION_TRY
    {
        if (!ENTITY_MANAGER_SINGLETON.Unregister(entityID))
        {
            LOG_SINGLETON_ENGINE_APPENDER(Warn, CoreTools)
                << SYSTEM_TEXT("注销EntityID = ")
                << entityID
                << SYSTEM_TEXT(" 失败。")
                << LOG_SINGLETON_TRIGGER_ASSERT;
        }
    }
    EXCEPTION_ALL_CATCH(CoreTools)

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, BaseEntity)

uint64_t CoreTools::BaseEntity::GetEntityID() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return entityID;
}

void CoreTools::BaseEntity::Register()
{
    if (!ENTITY_MANAGER_SINGLETON.Register(shared_from_this()))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("重复注册Entity"s));
    }
    else
    {
        DoRegister();
    }
}

void CoreTools::BaseEntity::DoRegister()
{
    CoreTools::DisableNoexcept();
}
