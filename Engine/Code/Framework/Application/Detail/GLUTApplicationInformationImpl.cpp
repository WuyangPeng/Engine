///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/09 16:45)

#include "Framework/FrameworkExport.h"

#include "GLUTApplicationInformationImpl.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

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
