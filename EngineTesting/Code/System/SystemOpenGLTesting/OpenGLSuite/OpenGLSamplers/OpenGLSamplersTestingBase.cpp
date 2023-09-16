///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/31 14:26)

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
