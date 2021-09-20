// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 13:34)

#include "Framework/FrameworkExport.h"

#include "WindowHBrush.h"
#include "System/Windows/WindowsRegister.h"
#include "CoreTools/Helper/LogMacro.h"  
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
 
Framework::WindowHBrush
	::WindowHBrush(WindowBrushTypes background) noexcept
	:m_HBrush{ System::GetSystemStockObject(background) }
{
	CheckUpHBrush();

	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}
 
// private
void Framework::WindowHBrush
	::CheckUpHBrush() noexcept
{
	if (m_HBrush == nullptr)
	{
		m_HBrush = System::GetSystemStockObject(WindowBrushTypes::WhiteBrush);

		LOG_SINGLETON_ENGINE_APPENDER(Warn, Framework)
			<< SYSTEM_TEXT("º”‘ÿ±≥æ∞ª≠À¢ ß∞‹£°")
			<< LOG_SINGLETON_TRIGGER_ASSERT;
	}
}

CLASS_INVARIANT_STUB_DEFINE(Framework, WindowHBrush)

System::WindowsHBrush Framework::WindowHBrush
	::GetHBrush() const noexcept
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return static_cast<HBrush>(m_HBrush);
}


