// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/19 16:50)

#include "CoreTools/CoreToolsExport.h"

#include "IFStreamSeekManager.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

const CoreTools::IFStreamSeekManager::MasterPosType CoreTools::IFStreamSeekManager
	::sm_ErrorPosition{ -1 };

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
		THROW_EXCEPTION(SYSTEM_TEXT("�����ļ���ǰλ��ʧ��!"));
	}
}

CoreTools::IFStreamSeekManager
	::~IFStreamSeekManager()
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;

	m_Master.seekg(m_CurrentPosition, MasterType::beg);
}

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::IFStreamSeekManager
	::IsValid() const noexcept
{
	if (m_Master && m_CurrentPosition != sm_ErrorPosition)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

