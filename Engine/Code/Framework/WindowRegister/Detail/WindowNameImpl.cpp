// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 13:28)

#include "Framework/FrameworkExport.h"

#include "WindowNameImpl.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

Framework::WindowNameImpl
	::WindowNameImpl(const String& className, const String& menuName)
	:m_ClassName{ className }, m_MenuName{ menuName }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool Framework::WindowNameImpl
	::IsValid() const noexcept
{
	if (!m_ClassName.empty())
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

const System::String Framework::WindowNameImpl
	::GetWindowClassName() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	return m_ClassName;
}

const System::String Framework::WindowNameImpl
	::GetWindowMenuName() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	return m_MenuName;
}

