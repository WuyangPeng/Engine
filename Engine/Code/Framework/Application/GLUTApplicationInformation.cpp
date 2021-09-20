// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 13:57)

#include "Framework/FrameworkExport.h"

#include "GLUTApplicationInformation.h"
#include "Detail/GLUTApplicationInformationImpl.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h" 

using std::string;
using std::make_shared;

Framework::GLUTApplicationInformation
	::GLUTApplicationInformation(int majorVersion, int minorVersion, FrameParameter frame)
	: impl{ majorVersion, minorVersion, frame }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, GLUTApplicationInformation)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Framework, GLUTApplicationInformation, GetOpenGLMajorVersion, int);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Framework, GLUTApplicationInformation, GetOpenGLMinorVersion, int);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Framework, GLUTApplicationInformation, GetFrame, Framework::FrameParameter);


