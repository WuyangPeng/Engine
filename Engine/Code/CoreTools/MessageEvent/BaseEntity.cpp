// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 17:11)

#include "CoreTools/CoreToolsExport.h"

#include "BaseEntity.h"
#include "EntityManager.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Contract/Noexcept.h"

using namespace std::literals;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26455)
CoreTools::BaseEntity
::BaseEntity()
	:m_EntityID{ ENTITY_MANAGER_SINGLETON.NextUniqueID() }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::BaseEntity
::~BaseEntity() noexcept
{
	EXCEPTION_TRY
	{
		
#include STSTEM_WARNING_PUSH
		#include SYSTEM_WARNING_DISABLE(26447)
		if (!ENTITY_MANAGER_SINGLETON.Unregister(m_EntityID))
		{
			LOG_SINGLETON_ENGINE_APPENDER(Warn, CoreTools)
				<< SYSTEM_TEXT("◊¢œ˙EntityID = ")
				<< m_EntityID
				<< SYSTEM_TEXT("  ß∞‹°£")
				<< LOG_SINGLETON_TRIGGER_ASSERT;
		}
	#include STSTEM_WARNING_POP
	}
	EXCEPTION_ALL_CATCH(CoreTools)


	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, BaseEntity)

uint64_t CoreTools::BaseEntity
::GetEntityID() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return m_EntityID;
}

void CoreTools::BaseEntity
::Register()
{
	if (!ENTITY_MANAGER_SINGLETON.Register(shared_from_this()))
	{
		THROW_EXCEPTION(SYSTEM_TEXT("÷ÿ∏¥◊¢≤·Entity"s));
	}
	else
	{
		DoRegister();
	}
}

void CoreTools::BaseEntity
::DoRegister()
{
	CoreTools::DisableNoexcept();
}

#include STSTEM_WARNING_POP