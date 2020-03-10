// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.4 (2019/08/01 10:45)

#include "Framework/FrameworkExport.h"

#include "WindowHBrush.h"
#include "CoreTools/Helper/LogMacro.h" 
#include "CoreTools/Helper/Assertion/FrameworkCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "System/Window/WindowRegister.h"

Framework::WindowHBrush
	::WindowHBrush(System::WindowBrushTypes background)
	:m_HBrush(System::GetSystemStockObject(background))
{
	FRAMEWORK_ASSERTION_2(background != System::WindowBrushTypes::Null, "��ˢ���ʹ���");

	CheckUpHBrush();

	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

// private
void Framework::WindowHBrush
	::CheckUpHBrush()
{
	if(m_HBrush == nullptr)
	{
		m_HBrush = System::GetSystemStockObject(System::WindowBrushTypes::WhiteBrush);
		LOG_SINGLETON_ENGINE_APPENDER(Warn, Framework)
			<< SYSTEM_TEXT("���ر�����ˢʧ�ܣ�")
			<< CoreTools::LogAppenderIOManageSign::TriggerAssert
			<< CoreTools::LogAppenderIOManageSign::Refresh;
	}
}

#ifdef OPEN_CLASS_INVARIANT
bool Framework::WindowHBrush
	::IsValid() const noexcept
{
	if(m_HBrush != nullptr)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

System::WindowHBrush Framework::WindowHBrush
	::GetHBrush() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	return static_cast<HBrush>(m_HBrush);
}


