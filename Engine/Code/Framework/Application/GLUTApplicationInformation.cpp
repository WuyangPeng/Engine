///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.7 (2022/05/06 11:29)

#include "Framework/FrameworkExport.h"

#include "GLUTApplicationInformation.h"
#include "Detail/GLUTApplicationInformationImpl.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::make_shared;
using std::string;

Framework::GLUTApplicationInformation::GLUTApplicationInformation(int majorVersion, int minorVersion, FrameParameter frame)
    : impl{ majorVersion, minorVersion, frame }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, GLUTApplicationInformation)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Framework, GLUTApplicationInformation, GetOpenGLMajorVersion, int);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Framework, GLUTApplicationInformation, GetOpenGLMinorVersion, int);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Framework, GLUTApplicationInformation, GetFrame, Framework::FrameParameter);
