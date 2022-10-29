///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.1 (2022/08/21 15:13)

#include "Rendering/RenderingExport.h"

#include "GLSLProgramFactory.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Rendering/Shaders/Flags/ShaderAPIType.h"

Rendering::GLSLProgramFactory::GLSLProgramFactory(CoreTools::DisableNotThrow disableNotThrow)
    : ParentType{ disableNotThrow }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, GLSLProgramFactory)

Rendering::ShaderAPIType Rendering::GLSLProgramFactory::GetAPI() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return ShaderAPIType::GLSL;
}

Rendering::GLSLProgramFactory::VisualProgramSharedPtr Rendering::GLSLProgramFactory::CreateFromNamedSources(MAYBE_UNUSED const std::string& vsName, MAYBE_UNUSED const std::string& vsSource, MAYBE_UNUSED const std::string& psName, MAYBE_UNUSED const std::string& psSource, MAYBE_UNUSED const std::string& gsName, MAYBE_UNUSED const std::string& gsSource)
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("����δʵ�֡�"));
}

Rendering::GLSLProgramFactory::ComputeProgramSharedPtr Rendering::GLSLProgramFactory::CreateFromNamedSource(MAYBE_UNUSED const std::string& csName, MAYBE_UNUSED const std::string& csSource)
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("����δʵ�֡�"));
}
