/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/16 17:16)

#include "OpenGLShaderTestingBase.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/OpenGL/OpenGLProgram.h"
#include "System/OpenGL/OpenGLShader.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::OpenGLShaderTestingBase::OpenGLShaderTestingBase(const OStreamShared& stream)
    : ParentType{ stream },
      code{ "#version 400\n",
            "uniform ProjectionViewWorldMatrix\n",
            "{\n",
            "     mat4 projectionViewWorldMatrix;\n",
            "};\n",

            "in vec3 modelPosition;\n",
            "in vec3 inPosition;\n",

            "void main()\n",
            "{\n",
            "     gl_Position = projectionViewWorldMatrix * vec4(modelPosition, 1.0f) * vec4(inPosition, 1.0f);\n",
            "}\n" }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, OpenGLShaderTestingBase)

void System::OpenGLShaderTestingBase::DeleteProgramTest(OpenGLUnsignedInt programHandle) const noexcept
{
    DeleteGLProgram(programHandle);
}

void System::OpenGLShaderTestingBase::DeleteShaderTest(OpenGLUnsignedInt shaderHandle) const noexcept
{
    DeleteGLShader(shaderHandle);
}

void System::OpenGLShaderTestingBase::ShaderSourceTest(OpenGLUnsignedInt shaderHandle) const
{
    SetGLShaderSource(shaderHandle, boost::numeric_cast<OpenGLSize>(code.size()), code.data(), nullptr);
}