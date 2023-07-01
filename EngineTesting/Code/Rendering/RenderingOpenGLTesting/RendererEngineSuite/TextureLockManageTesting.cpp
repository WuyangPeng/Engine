///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/12 14:47)

#include "TextureLockManageTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Rendering/RendererEngine/BaseRenderer.h"
#include "Rendering/Resources/Textures/LoadTexture.h"

Rendering::TextureLockManageTesting::TextureLockManageTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, TextureLockManageTesting)

void Rendering::TextureLockManageTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Rendering::TextureLockManageTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(Texture1DTest);
    ASSERT_NOT_THROW_EXCEPTION_0(Texture2DTest);
    ASSERT_NOT_THROW_EXCEPTION_0(Texture3DTest);
    ASSERT_NOT_THROW_EXCEPTION_0(TextureCubeTest);
}

void Rendering::TextureLockManageTesting::Texture1DTest() noexcept
{
}

void Rendering::TextureLockManageTesting::Texture2DTest() noexcept
{
}

void Rendering::TextureLockManageTesting::Texture3DTest() noexcept
{
}

void Rendering::TextureLockManageTesting::TextureCubeTest() noexcept
{
}
