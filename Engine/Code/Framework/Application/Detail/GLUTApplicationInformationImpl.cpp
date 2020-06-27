// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 13:51)

#include "Framework/FrameworkExport.h"

#include "GLUTApplicationInformationImpl.h"
#include "CoreTools/Helper/MemberFunctionMacro.h" 
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

Framework::GLUTApplicationInformationImpl
	::GLUTApplicationInformationImpl(int majorVersion, int minorVersion, FrameParameter frame) noexcept
	:m_OpenGLMajorVersion{ majorVersion }, m_OpenGLMinorVersion{ minorVersion }, m_Frame{ frame }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool  Framework::GLUTApplicationInformationImpl
	::IsValid() const noexcept
{
	if (0 < m_OpenGLMajorVersion && 0 <= m_OpenGLMinorVersion)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

int Framework::GLUTApplicationInformationImpl
	::GetOpenGLMajorVersion() const noexcept
{
	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	return m_OpenGLMajorVersion;
}

int  Framework::GLUTApplicationInformationImpl
	::GetOpenGLMinorVersion() const noexcept
{
	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	return m_OpenGLMinorVersion;
}

Framework::FrameParameter Framework::GLUTApplicationInformationImpl
	::GetFrame() const  noexcept
{
	FRAMEWORK_CLASS_IS_VALID_CONST_1;

	return m_Frame;
}

