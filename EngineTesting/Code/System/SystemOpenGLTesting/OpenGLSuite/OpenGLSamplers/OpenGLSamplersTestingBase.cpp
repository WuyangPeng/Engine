///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.0 (2023/01/22 19:49)

#include "OpenGLSamplersTestingBase.h"
#include "System/OpenGL/OpenGLSamplers.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::OpenGLSamplersTestingBase::OpenGLSamplersTestingBase(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, OpenGLSamplersTestingBase)

void System::OpenGLSamplersTestingBase::SetGLDeleteSamplerTest(OpenGLInt sampler) noexcept
{
    SetGLDeleteSamplers(sampler);
}

void System::OpenGLSamplersTestingBase::SetGLDeleteSamplersTest(const SamplersType& samplers) noexcept
{
    SetGLDeleteSamplers(bufferSize, samplers.data());
}
