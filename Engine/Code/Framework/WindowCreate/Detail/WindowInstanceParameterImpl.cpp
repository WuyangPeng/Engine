// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 09:40)

#include "Framework/FrameworkExport.h"

#include "WindowInstanceParameterImpl.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

Framework::WindowInstanceParameterImpl
	::WindowInstanceParameterImpl(HInstance hInstance,const System::String& className)
	:m_HInstance(hInstance),m_ClassName(className)
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool Framework::WindowInstanceParameterImpl
    ::IsValid() const noexcept
{
	if(m_HInstance != nullptr)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

Framework::WindowInstanceParameterImpl::HInstance Framework::WindowInstanceParameterImpl
    ::GetHInstance() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	return m_HInstance;
}

System::String Framework::WindowInstanceParameterImpl
	::GetWindowClassName() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	return m_ClassName;
}

