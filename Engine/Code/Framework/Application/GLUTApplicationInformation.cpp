/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 15:27)

#include "Framework/FrameworkExport.h"

#include "GLUTApplicationInformation.h"
#include "Detail/GLUTApplicationInformationImpl.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

Framework::GLUTApplicationInformation::GLUTApplicationInformation(int majorVersion, int minorVersion, FrameParameter frame)
    : impl{ majorVersion, minorVersion, frame }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, GLUTApplicationInformation)

int Framework::GLUTApplicationInformation::GetOpenGLMajorVersion() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return impl->GetOpenGLMajorVersion();
}

int Framework::GLUTApplicationInformation::GetOpenGLMinorVersion() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return impl->GetOpenGLMinorVersion();
}

Framework::FrameParameter Framework::GLUTApplicationInformation::GetFrame() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return impl->GetFrame();
}
