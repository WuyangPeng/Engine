///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/12 14:47)

#include "TextureManagementLockEncapsulationTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Rendering/RendererEngine/BaseRenderer.h"
#include "Rendering/Resources/Buffers/IndexBuffer.h"

Rendering::TextureManagementLockEncapsulationTesting::TextureManagementLockEncapsulationTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, TextureManagementLockEncapsulationTesting)

void Rendering::TextureManagementLockEncapsulationTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Rendering::TextureManagementLockEncapsulationTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(Texture1DTest);
    ASSERT_NOT_THROW_EXCEPTION_0(Texture2DTest);
    ASSERT_NOT_THROW_EXCEPTION_0(Texture3DTest);
    ASSERT_NOT_THROW_EXCEPTION_0(TextureCubeTest);
}

void Rendering::TextureManagementLockEncapsulationTesting::Texture1DTest() noexcept
{
}

void Rendering::TextureManagementLockEncapsulationTesting::Texture2DTest() noexcept
{
}

void Rendering::TextureManagementLockEncapsulationTesting::Texture3DTest() noexcept
{
}

void Rendering::TextureManagementLockEncapsulationTesting::TextureCubeTest() noexcept
{
}