/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 16:47)

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
    ASSERT_NOT_THROW_EXCEPTION_0(GetSamplerTest);
    ASSERT_NOT_THROW_EXCEPTION_0(GetSamplersTest);
    ASSERT_NOT_THROW_EXCEPTION_0(BindSamplerTest);
}

void System::OpenGLGetSamplersTesting::GetSamplerTest()
{
    const auto sampler = GetGLGenSamplers();
    ASSERT_LESS(0u, sampler);

    ASSERT_NOT_THROW_EXCEPTION_1(DeleteSamplerTest, sampler);
}

void System::OpenGLGetSamplersTesting::GetSamplersTest()
{
    SamplersType samplers{};

    GetGLGenSamplers(bufferSize, samplers.data());
    ASSERT_NOT_THROW_EXCEPTION_1(DoGetSamplersTest, samplers);

    ASSERT_NOT_THROW_EXCEPTION_1(DeleteSamplersTest, samplers);
}

void System::OpenGLGetSamplersTesting::BindSamplerTest()
{
    const auto sampler = GetGLGenSamplers();
    ASSERT_LESS(0u, sampler);

    SetGLBindSampler(0, sampler);

    ASSERT_NOT_THROW_EXCEPTION_1(DeleteSamplerTest, sampler);
}

void System::OpenGLGetSamplersTesting::DoGetSamplersTest(const SamplersType& samplers)
{
    for (auto sampler : samplers)
    {
        ASSERT_LESS(0u, sampler);
    }
}
