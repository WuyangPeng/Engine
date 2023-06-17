///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 13:30)

#include "Rendering/RenderingExport.h"

#include "OpenGLDevice.h"
#include "System/OpenGL/OpenGLBase.h"
#include "CoreTools/Contract/Noexcept.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

Rendering::OpenGLDevice::OpenGLDevice() noexcept
    : ParentType{}
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, OpenGLDevice)

Rendering::OpenGLDevice::RenderingDeviceSharedPtr Rendering::OpenGLDevice::Clone() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return std::make_shared<ClassType>(*this);
}

void Rendering::OpenGLDevice::SwapBuffers()
{
    RENDERING_CLASS_IS_VALID_9;

    CoreTools::DisableNoexcept();
}

void Rendering::OpenGLDevice::ResetSize()
{
    RENDERING_CLASS_IS_VALID_9;

    CoreTools::DisableNoexcept();
}

void Rendering::OpenGLDevice::InitDevice() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    System::SetGLViewport(0, 0, GetXSize(), GetYSize());
    System::SetGLDepthRange(0.0, 1.0);
}
