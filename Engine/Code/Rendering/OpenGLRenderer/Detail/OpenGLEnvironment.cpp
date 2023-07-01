///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.0 (2023/06/25 16:29)

#include "Rendering/RenderingExport.h"

#include "OpenGLEnvironment.h"
#include "System/OpenGL/OpenGLInit.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

Rendering::OpenGLEnvironment::OpenGLEnvironment(const RendererParameter& rendererParameter) noexcept
    : ParentType{ rendererParameter }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, OpenGLEnvironment)

Rendering::OpenGLEnvironment::RenderingEnvironmentSharedPtr Rendering::OpenGLEnvironment::Clone() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return std::make_shared<ClassType>(*this);
}

void Rendering::OpenGLEnvironment::InitEnvironment()
{
    RENDERING_CLASS_IS_VALID_9;

    if (!System::OpenGLInit())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("��ʼ��OpenGL����ʧ�ܡ�"s));
    }

    System::PrintOpenGLInfo();
}
