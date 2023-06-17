///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 10:55)

#include "Rendering/RenderingExport.h"

#include "VisualProgram.h"
#include "Detail/VisualProgramImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

COPY_UNSHARED_CLONE_SELF_USE_CLONE_DEFINE(Rendering, VisualProgram)

Rendering::VisualProgram::VisualProgram(MAYBE_UNUSED CoreTools::DisableNotThrow disableNotThrow)
    : impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
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

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, VisualProgram, GetReflector, Rendering::GLSLReflection)
