///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.9 (2022/06/18 16:35)

#include "OpenGLBindTextureTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Rendering/OpenGLRenderer/OpenGLBindTexture.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, OpenGLBindTextureTesting)

void Rendering::OpenGLBindTextureTesting::MainTest() noexcept
{
}

void Rendering::OpenGLBindTextureTesting::TextureTest()
{
    ASSERT_EQUAL(GetBoundTexture(ShaderFlags::SamplerType::Sampler1D), 0u);
    ASSERT_EQUAL(GetBoundTexture(ShaderFlags::SamplerType::Sampler2D), 0u);
    ASSERT_EQUAL(GetBoundTexture(ShaderFlags::SamplerType::Sampler3D), 0u);
    ASSERT_EQUAL(GetBoundTexture(ShaderFlags::SamplerType::SamplerCube), 0u);

    ASSERT_EQUAL(BindTexture(ShaderFlags::SamplerType::Sampler1D, 1), 0u);

    ASSERT_EQUAL(GetBoundTexture(ShaderFlags::SamplerType::Sampler1D), 1u);
    ASSERT_EQUAL(GetBoundTexture(ShaderFlags::SamplerType::Sampler2D), 0u);
    ASSERT_EQUAL(GetBoundTexture(ShaderFlags::SamplerType::Sampler3D), 0u);
    ASSERT_EQUAL(GetBoundTexture(ShaderFlags::SamplerType::SamplerCube), 0u);

    ASSERT_EQUAL(BindTexture(ShaderFlags::SamplerType::Sampler2D, 2), 0u);

    ASSERT_EQUAL(GetBoundTexture(ShaderFlags::SamplerType::Sampler1D), 1u);
    ASSERT_EQUAL(GetBoundTexture(ShaderFlags::SamplerType::Sampler2D), 2u);
    ASSERT_EQUAL(GetBoundTexture(ShaderFlags::SamplerType::Sampler3D), 0u);
    ASSERT_EQUAL(GetBoundTexture(ShaderFlags::SamplerType::SamplerCube), 0u);

    ASSERT_EQUAL(BindTexture(ShaderFlags::SamplerType::Sampler3D, 3), 0u);

    ASSERT_EQUAL(GetBoundTexture(ShaderFlags::SamplerType::Sampler1D), 1u);
    ASSERT_EQUAL(GetBoundTexture(ShaderFlags::SamplerType::Sampler2D), 2u);
    ASSERT_EQUAL(GetBoundTexture(ShaderFlags::SamplerType::Sampler3D), 3u);
    ASSERT_EQUAL(GetBoundTexture(ShaderFlags::SamplerType::SamplerCube), 0u);

    ASSERT_EQUAL(BindTexture(ShaderFlags::SamplerType::SamplerCube, 4), 0u);

    ASSERT_EQUAL(GetBoundTexture(ShaderFlags::SamplerType::Sampler1D), 1u);
    ASSERT_EQUAL(GetBoundTexture(ShaderFlags::SamplerType::Sampler2D), 2u);
    ASSERT_EQUAL(GetBoundTexture(ShaderFlags::SamplerType::Sampler3D), 3u);
    ASSERT_EQUAL(GetBoundTexture(ShaderFlags::SamplerType::SamplerCube), 4u);

    ASSERT_EQUAL(BindTexture(ShaderFlags::SamplerType::Sampler1D, 5), 1u);

    ASSERT_EQUAL(GetBoundTexture(ShaderFlags::SamplerType::Sampler1D), 5u);
    ASSERT_EQUAL(GetBoundTexture(ShaderFlags::SamplerType::Sampler2D), 2u);
    ASSERT_EQUAL(GetBoundTexture(ShaderFlags::SamplerType::Sampler3D), 3u);
    ASSERT_EQUAL(GetBoundTexture(ShaderFlags::SamplerType::SamplerCube), 4u);

    ASSERT_EQUAL(BindTexture(ShaderFlags::SamplerType::Sampler2D, 6), 2u);

    ASSERT_EQUAL(GetBoundTexture(ShaderFlags::SamplerType::Sampler1D), 5u);
    ASSERT_EQUAL(GetBoundTexture(ShaderFlags::SamplerType::Sampler2D), 6u);
    ASSERT_EQUAL(GetBoundTexture(ShaderFlags::SamplerType::Sampler3D), 3u);
    ASSERT_EQUAL(GetBoundTexture(ShaderFlags::SamplerType::SamplerCube), 4u);

    ASSERT_EQUAL(BindTexture(ShaderFlags::SamplerType::Sampler3D, 7), 3u);

    ASSERT_EQUAL(GetBoundTexture(ShaderFlags::SamplerType::Sampler1D), 5u);
    ASSERT_EQUAL(GetBoundTexture(ShaderFlags::SamplerType::Sampler2D), 6u);
    ASSERT_EQUAL(GetBoundTexture(ShaderFlags::SamplerType::Sampler3D), 7u);
    ASSERT_EQUAL(GetBoundTexture(ShaderFlags::SamplerType::SamplerCube), 4u);

    ASSERT_EQUAL(BindTexture(ShaderFlags::SamplerType::SamplerCube, 8), 4u);

    ASSERT_EQUAL(GetBoundTexture(ShaderFlags::SamplerType::Sampler1D), 5u);
    ASSERT_EQUAL(GetBoundTexture(ShaderFlags::SamplerType::Sampler2D), 6u);
    ASSERT_EQUAL(GetBoundTexture(ShaderFlags::SamplerType::Sampler3D), 7u);
    ASSERT_EQUAL(GetBoundTexture(ShaderFlags::SamplerType::SamplerCube), 8u);

    ASSERT_EQUAL(BindTexture(ShaderFlags::SamplerType::Sampler1D, 0), 5u);
    ASSERT_EQUAL(BindTexture(ShaderFlags::SamplerType::Sampler2D, 0), 6u);
    ASSERT_EQUAL(BindTexture(ShaderFlags::SamplerType::Sampler3D, 0), 7u);
    ASSERT_EQUAL(BindTexture(ShaderFlags::SamplerType::SamplerCube, 0), 8u);
}
