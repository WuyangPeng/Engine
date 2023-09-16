///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/31 14:26)

#include "OpenGLGetSamplersTesting.h"
#include "System/OpenGL/OpenGLSamplers.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::OpenGLGetSamplersTesting::OpenGLGetSamplersTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, OpenGLGetSamplersTesting)

void System::OpenGLGetSamplersTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::OpenGLGetSamplersTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(OpenGLGetSamplerTest);
    ASSERT_NOT_THROW_EXCEPTION_0(OpenGLGetSamplersTest);
}

void System::OpenGLGetSamplersTesting::OpenGLGetSamplerTest()
{
    const auto sampler = GetGLGenSamplers();
    ASSERT_LESS(0u, sampler);

    ASSERT_NOT_THROW_EXCEPTION_1(SetGLDeleteSamplerTest, sampler);
}

void System::OpenGLGetSamplersTesting::OpenGLGetSamplersTest()
{
    SamplersType samplers{};

    GetGLGenSamplers(bufferSize, samplers.data());
    ASSERT_NOT_THROW_EXCEPTION_1(DoOpenGLGetSamplersTest, samplers);

    ASSERT_NOT_THROW_EXCEPTION_1(SetGLDeleteSamplersTest, samplers);
}

void System::OpenGLGetSamplersTesting::DoOpenGLGetSamplersTest(const SamplersType& samplers)
{
    for (auto sampler : samplers)
    {
        ASSERT_LESS(0u, sampler);
    }
}
