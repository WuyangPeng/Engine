//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/26 15:46)

#include "CoreTools/CoreToolsExport.h"

#include "BaseEntity.h"
#include "EntityManager.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Base/Flags/UniqueIDSelectFlags.h"
#include "CoreTools/Base/UniqueIDManager.h"
#include "CoreTools/Contract/Noexcept.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

using namespace std::literals;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26455)
CoreTools::BaseEntity::BaseEntity()
    : m_EntityID{ UNIQUE_ID_MANAGER_SINGLETON.NextUniqueID(UniqueIDSelect::Entity) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}
#include STSTEM_WARNING_POP

CoreTools::BaseEntity::~BaseEntity() noexcept
{
    EXCEPTION_TRY
    {
        if (!ENTITY_MANAGER_SINGLETON.Unregister(m_EntityID))
        {
            LOG_SINGLETON_ENGINE_APPENDER(Warn, CoreTools)
                << SYSTEM_TEXT("注销EntityID = ")
                << m_EntityID
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

    return m_EntityID;
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
