// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/19 16:55)

#include "CoreTools/CoreToolsExport.h"

#include "OFStreamSeekManager.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

#include "System/Helper/PragmaWarning.h"

using namespace std::literals;
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
const CoreTools::OFStreamSeekManager::MasterPosType CoreTools::OFStreamSeekManager
	::sm_ErrorPosition{ -1 };
#include STSTEM_WARNING_POP

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
		THROW_EXCEPTION(SYSTEM_TEXT("��ȡ�ļ���ǰλ��ʧ��!"s));
	}
}

CoreTools::OFStreamSeekManager
	::~OFStreamSeekManager()
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
	EXCEPTION_TRY
	{

#include STSTEM_WARNING_PUSH
		#include SYSTEM_WARNING_DISABLE(26447)
	m_Master.seekp(m_CurrentPosition, MasterType::beg);
#include STSTEM_WARNING_POP
	}
		EXCEPTION_ALL_CATCH(CoreTools)
}

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::OFStreamSeekManager
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
