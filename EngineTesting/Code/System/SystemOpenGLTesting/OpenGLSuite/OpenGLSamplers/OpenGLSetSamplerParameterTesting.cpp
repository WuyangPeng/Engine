/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 16:47)

#include "OpenGLSetSamplerParameterTesting.h"
#include "System/OpenGL/Flags/OpenGLFlags.h"
#include "System/OpenGL/Flags/OpenGLTextureFlags.h"
#include "System/OpenGL/OpenGLSamplers.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::OpenGLSetSamplerParameterTesting::OpenGLSetSamplerParameterTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, OpenGLSetSamplerParameterTesting)

void System::OpenGLSetSamplerParameterTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::OpenGLSetSamplerParameterTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SetSamplerParameterTest);
}

void System::OpenGLSetSamplerParameterTesting::SetSamplerParameterTest()
{
    const auto sampler = GetGLGenSamplers();
    ASSERT_LESS(0u, sampler);

    ASSERT_NOT_THROW_EXCEPTION_1(DoSetSamplerParameterTest, sampler);

    ASSERT_NOT_THROW_EXCEPTION_1(DeleteSamplerTest, sampler);
}

void System::OpenGLSetSamplerParameterTesting::DoSetSamplerParameterTest(OpenGLInt sampler)
{
    ASSERT_NOT_THROW_EXCEPTION_1(MinFilterTest, sampler);
    ASSERT_NOT_THROW_EXCEPTION_1(MagFilterTest, sampler);
    ASSERT_NOT_THROW_EXCEPTION_1(LodTest, sampler);
    ASSERT_NOT_THROW_EXCEPTION_1(WrapTest, sampler);
    ASSERT_NOT_THROW_EXCEPTION_1(LodBiasTest, sampler);
    ASSERT_NOT_THROW_EXCEPTION_1(BorderColorTest, sampler);
}

void System::OpenGLSetSamplerParameterTesting::MinFilterTest(OpenGLInt sampler) const noexcept
{
    SetGLSamplerParameter(sampler, OpenGLTextureName::MinFilter, SamplerFilter::Nearest);
    SetGLSamplerParameter(sampler, OpenGLTextureName::MinFilter, SamplerFilter::Linear);
    SetGLSamplerParameter(sampler, OpenGLTextureName::MinFilter, SamplerFilter::NearestMipmapNearest);
    SetGLSamplerParameter(sampler, OpenGLTextureName::MinFilter, SamplerFilter::NearestMipmapLinear);
    SetGLSamplerParameter(sampler, OpenGLTextureName::MinFilter, SamplerFilter::LinearMipmapNearest);
    SetGLSamplerParameter(sampler, OpenGLTextureName::MinFilter, SamplerFilter::LinearMipmapLinear);
}

void System::OpenGLSetSamplerParameterTesting::MagFilterTest(OpenGLInt sampler) const noexcept
{
    SetGLSamplerParameter(sampler, OpenGLTextureName::MagFilter, SamplerFilter::Nearest);
    SetGLSamplerParameter(sampler, OpenGLTextureName::MagFilter, SamplerFilter::Linear);
}

void System::OpenGLSetSamplerParameterTesting::LodTest(OpenGLInt sampler) const noexcept
{
    SetGLSamplerParameter(sampler, OpenGLTextureName::MinLod, -999);
    SetGLSamplerParameter(sampler, OpenGLTextureName::MaxLod, 999);
}

void System::OpenGLSetSamplerParameterTesting::WrapTest(OpenGLInt sampler) const noexcept
{
    SetGLSamplerParameter(sampler, OpenGLTextureName::WrapS, TextureSamplerCoordinate::Repeat);
    SetGLSamplerParameter(sampler, OpenGLTextureName::WrapS, TextureSamplerCoordinate::MirroredRepeat);
    SetGLSamplerParameter(sampler, OpenGLTextureName::WrapS, TextureSamplerCoordinate::ClampEdge);
    SetGLSamplerParameter(sampler, OpenGLTextureName::WrapS, TextureSamplerCoordinate::ClampBorder);
    SetGLSamplerParameter(sampler, OpenGLTextureName::WrapT, TextureSamplerCoordinate::Repeat);
    SetGLSamplerParameter(sampler, OpenGLTextureName::WrapT, TextureSamplerCoordinate::MirroredRepeat);
    SetGLSamplerParameter(sampler, OpenGLTextureName::WrapT, TextureSamplerCoordinate::ClampEdge);
    SetGLSamplerParameter(sampler, OpenGLTextureName::WrapT, TextureSamplerCoordinate::ClampBorder);
    SetGLSamplerParameter(sampler, OpenGLTextureName::WrapR, TextureSamplerCoordinate::Repeat);
    SetGLSamplerParameter(sampler, OpenGLTextureName::WrapR, TextureSamplerCoordinate::MirroredRepeat);
    SetGLSamplerParameter(sampler, OpenGLTextureName::WrapR, TextureSamplerCoordinate::ClampEdge);
    SetGLSamplerParameter(sampler, OpenGLTextureName::WrapR, TextureSamplerCoordinate::ClampBorder);
}

void System::OpenGLSetSamplerParameterTesting::LodBiasTest(OpenGLInt sampler) const noexcept
{
    SetGLSamplerParameter(sampler, OpenGLTextureName::LodBias, 1.0f);
}

void System::OpenGLSetSamplerParameterTesting::BorderColorTest(OpenGLInt sampler) const noexcept
{
    constexpr BorderColorType borderColorType{ 0.5f, 0.3f, 0.2f, 0.4f };
    SetGLSamplerParameter(sampler, OpenGLTextureName::BorderColor, borderColorType.data());
}
