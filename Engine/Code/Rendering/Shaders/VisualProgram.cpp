///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.1 (2023/07/05 14:36)

#include "Rendering/RenderingExport.h"

#include "VisualProgram.h"
#include "Detail/VisualProgramImpl.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Rendering/Shaders/Reflection.h"

COPY_UNSHARED_CLONE_SELF_USE_CLONE_DEFINE(Rendering, VisualProgram)

Rendering::VisualProgram Rendering::VisualProgram::Create()
{
    return VisualProgram{ CoreTools::DisableNotThrow::Disable };
}

Rendering::VisualProgram::VisualProgram(CoreTools::DisableNotThrow disableNotThrow)
    : impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    System::UnusedFunction(disableNotThrow);

    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::VisualProgram::VisualProgram(OpenGLUInt programHandle, OpenGLUInt vertexShaderHandle, OpenGLUInt pixelShaderHandle, OpenGLUInt geometryShaderHandle)
    : impl{ CoreTools::ImplCreateUseFactory::Default, programHandle, vertexShaderHandle, pixelShaderHandle, geometryShaderHandle }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, VisualProgram)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, VisualProgram, GetVertexShader, Rendering::VisualProgram::ConstShaderSharedPtr)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, VisualProgram, GetPixelShader, Rendering::VisualProgram::ConstShaderSharedPtr)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, VisualProgram, GetGeometryShader, Rendering::VisualProgram::ConstShaderSharedPtr)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, VisualProgram, GetVertexShader, Rendering::VisualProgram::ShaderSharedPtr)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, VisualProgram, GetPixelShader, Rendering::VisualProgram::ShaderSharedPtr)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, VisualProgram, GetGeometryShader, Rendering::VisualProgram::ShaderSharedPtr)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, VisualProgram, SetVertexShader, ShaderSharedPtr, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, VisualProgram, SetPixelShader, ShaderSharedPtr, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, VisualProgram, SetGeometryShader, ShaderSharedPtr, void)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, VisualProgram, GetStreamingSize, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, VisualProgram, Save, BufferTarget&, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, VisualProgram, Load, BufferSource&, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, VisualProgram, Register, ObjectRegister&, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, VisualProgram, Link, ObjectLink&, void)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, VisualProgram, GetObjectByName, std::string, CoreTools::ObjectSharedPtr)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, VisualProgram, GetAllObjectsByName, std::string, Rendering::VisualProgram::ObjectSharedPtrContainer)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, VisualProgram, GetConstObjectByName, std::string, CoreTools::ConstObjectSharedPtr)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, VisualProgram, GetAllConstObjectsByName, std::string, Rendering::VisualProgram::ConstObjectSharedPtrContainer)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, VisualProgram, GetReflector, Rendering::Reflection)
