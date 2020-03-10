// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.1 (2020/01/19 16:55)

#include "CoreTools/CoreToolsExport.h"

#include "OFStreamSeekManager.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

const CoreTools::OFStreamSeekManager::MasterPosType CoreTools::OFStreamSeekManager
	::sm_ErrorPosition{ -1 };

CoreTools::OFStreamSeekManager
	::OFStreamSeekManager(MasterTypeReference master)
	:m_Master{ master }, m_CurrentPosition{ m_Master.tellp() }
{
	SeekBeginPosition();

	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

// private
void CoreTools::OFStreamSeekManager
	::SeekBeginPosition()
{
	if (m_Master && m_CurrentPosition != sm_ErrorPosition)
	{
		m_Master.seekp(0, MasterType::beg);
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("获取文件当前位置失败!"));
	}
}

CoreTools::OFStreamSeekManager
	::~OFStreamSeekManager()
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;

	m_Master.seekp(m_CurrentPosition, MasterType::beg);
}

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::OFStreamSeekManager
	::IsValid() const noexcept
{
	if (m_Master && m_CurrentPosition != sm_ErrorPosition)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT
