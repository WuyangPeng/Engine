// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 10:47)

#include "Framework/FrameworkExport.h"

#include "WindowRegisterParameter.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

Framework::WindowRegisterParameter
	::WindowRegisterParameter(HInstance hInstance,WindowClassStyleFlags styles,  int windowClassExtra,int windowExtra)
	:m_HInstance(hInstance),
	 m_Style(styles),
	 m_WindowClassExtra(windowClassExtra),
	 m_WindowExtra(windowExtra)
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool Framework::WindowRegisterParameter
	::IsValid() const noexcept
{
	if(m_HInstance != nullptr)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

System::WindowClassStyle Framework::WindowRegisterParameter
    ::GetStyle() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	return m_Style;
}

int Framework::WindowRegisterParameter
	::GetWindowClassExtra() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	return m_WindowClassExtra;
}

int Framework::WindowRegisterParameter
	::GetWindowExtra() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	return m_WindowExtra;
}

System::WindowHInstance Framework::WindowRegisterParameter
	::GetHInstance() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	return m_HInstance;
}


