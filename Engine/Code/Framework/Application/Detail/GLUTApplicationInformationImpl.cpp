///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/05/06 11:19)

#include "Framework/FrameworkExport.h"

#include "GLUTApplicationInformationImpl.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

Framework::GLUTApplicationInformationImpl::GLUTApplicationInformationImpl(int majorVersion, int minorVersion, FrameParameter frame) noexcept
    : openGLMajorVersion{ majorVersion }, openGLMinorVersion{ minorVersion }, frame{ frame }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool Framework::GLUTApplicationInformationImpl::IsValid() const noexcept
{
    if (0 < openGLMajorVersion && 0 <= openGLMinorVersion)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

int Framework::GLUTApplicationInformationImpl::GetOpenGLMajorVersion() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    return openGLMajorVersion;
}

int Framework::GLUTApplicationInformationImpl::GetOpenGLMinorVersion() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    return openGLMinorVersion;
}

Framework::FrameParameter Framework::GLUTApplicationInformationImpl::GetFrame() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    return frame;
}
