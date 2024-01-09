/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/26 15:05)

#include "Rendering/RenderingExport.h"

#include "ComputeProgramFactory.h"
#include "ComputeProgramImpl.h"
#include "NullComputeProgram.h"
#include "Rendering/OpenGLRenderer/Detail/GLSL/GLSLComputeProgram.h"

CLASS_INVARIANT_STUB_DEFINE(Rendering, ComputeProgramFactory)

Rendering::ComputeProgramFactory::ComputeProgramSharedPtr Rendering::ComputeProgramFactory::Create(OpenGLUInt programHandle, OpenGLUInt computeShaderHandle)
{
    return std::make_shared<GLSLComputeProgram>(programHandle, computeShaderHandle);
}

Rendering::ComputeProgramFactory::ComputeProgramSharedPtr Rendering::ComputeProgramFactory::Create()
{
    return std::make_shared<NullComputeProgram>();
}
