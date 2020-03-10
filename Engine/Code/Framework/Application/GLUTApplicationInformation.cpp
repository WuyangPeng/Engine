// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 11:23)

#include "Framework/FrameworkExport.h"

#include "GLUTApplicationInformation.h"
#include "Detail/GLUTApplicationInformationImpl.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h" 

using std::string;

Framework::GLUTApplicationInformation
	::GLUTApplicationInformation(int majorVersion,int minorVersion,FrameParameter frame)
	: m_Impl(new ImplType(majorVersion, minorVersion, frame))
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool Framework::GLUTApplicationInformation
	::IsValid() const noexcept
{
    if(m_Impl != nullptr)
        return true;
    else
        return false;
}
#endif // OPEN_CLASS_INVARIANT

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Framework, GLUTApplicationInformation,GetOpenGLMajorVersion, int);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Framework, GLUTApplicationInformation,GetOpenGLMinorVersion, int);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Framework, GLUTApplicationInformation,GetFrame, Framework::FrameParameter);


