// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.1 (2020/01/19 16:50)

#include "CoreTools/CoreToolsExport.h"

#include "IFStreamSeekManager.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

#include "System/Helper/PragmaWarning.h"
using namespace std::literals;


#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
const CoreTools::IFStreamSeekManager::MasterPosType CoreTools::IFStreamSeekManager
	::sm_ErrorPosition{ -1 };
#include STSTEM_WARNING_POP

CoreTools::IFStreamSeekManager
	::IFStreamSeekManager(MasterTypeReference master)
	:m_Master{ master }, m_CurrentPosition{ m_Master.tellg() }
{
	SeekBeginPosition();

	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

// private
void CoreTools::IFStreamSeekManager
	::SeekBeginPosition()
{
	if (m_Master && m_CurrentPosition != sm_ErrorPosition)
	{
		m_Master.seekg(0, MasterType::beg);
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("设置文件当前位置失败!"s));
	}
}

CoreTools::IFStreamSeekManager
	::~IFStreamSeekManager() noexcept
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;

	EXCEPTION_TRY
	{
		 
#include STSTEM_WARNING_PUSH
		#include SYSTEM_WARNING_DISABLE(26447)
		m_Master.seekg(m_CurrentPosition, MasterType::beg);
	#include STSTEM_WARNING_POP
	}	 
	EXCEPTION_ALL_CATCH(CoreTools)
	
}

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::IFStreamSeekManager
	::IsValid() const noexcept
{
	try
	{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26447)
		if (m_Master && m_CurrentPosition != sm_ErrorPosition)
			return true;
		else
			return false;
		#include STSTEM_WARNING_POP
	}
	catch (...)
	{
		return false;
	}	
}
#endif // OPEN_CLASS_INVARIANT

