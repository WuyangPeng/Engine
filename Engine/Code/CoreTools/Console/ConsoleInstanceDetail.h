// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/19 11:04)

#ifndef CORE_TOOLS_CONSOLE_CONSOLE_INSTANCE_DETAIL_H
#define CORE_TOOLS_CONSOLE_CONSOLE_INSTANCE_DETAIL_H

#include "ConsoleInstance.h"
#include "System/Console/ConsoleHandle.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26455)
template <CoreTools::StandardHandle Handle>
CoreTools::ConsoleInstance<Handle>
	::ConsoleInstance()
	:m_Handle{ System::GetStandardHandle(Handle) }
{
	using namespace std::literals;

	if (!System::IsHandleValid(m_Handle))
	{
		THROW_EXCEPTION(SYSTEM_TEXT("��ȡ��׼�豸�ľ��ʧ�ܡ�"s));
	}

	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}
#include STSTEM_WARNING_POP

#ifdef OPEN_CLASS_INVARIANT
template <CoreTools::StandardHandle Handle>
bool CoreTools::ConsoleInstance<Handle>
	::IsValid() const noexcept
{
	if (System::IsHandleValid(m_Handle))
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

template <CoreTools::StandardHandle Handle>
typename CoreTools::ConsoleInstance<Handle>::ConsoleHandle CoreTools::ConsoleInstance<Handle>
	::GetHandle() noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	return m_Handle;
}

#endif // CORE_TOOLS_CONSOLE_CONSOLE_INSTANCE_DETAIL_H
