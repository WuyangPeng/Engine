///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.0 (2023/01/15 0:37)

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
            "uniform PVWMatrix\n",
            "{\n",
            "     mat4 pvwMatrix;\n",
            "};\n",

            "in vec3 modelPosition;\n",
            "in vec3 inPosition;\n",

            "void main()\n",
            "{\n",
            "     gl_Position = pvwMatrix * vec4(modelPosition, 1.0f) * vec4(inPosition, 1.0f);\n",
            "}\n" }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, OpenGLShaderTestingBase)

void System::OpenGLShaderTestingBase::DeleteProgramTest(OpenGLUInt programHandle) noexcept
{
    DeleteGLProgram(programHandle);
}

void System::OpenGLShaderTestingBase::DeleteShaderTest(OpenGLUInt shaderHandle) noexcept
{
    DeleteGLShader(shaderHandle);
}

void System::OpenGLShaderTestingBase::ShaderSourceTest(OpenGLUInt shaderHandle)
{
    SetGLShaderSource(shaderHandle, boost::numeric_cast<OpenGLSize>(code.size()), code.data(), nullptr);
}