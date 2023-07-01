///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/12 14:47)

#include "PlatformTexture2DTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h" 
#include "Rendering/RendererEngine/BaseRenderer.h"
#include "Rendering/Resources/Textures/LoadTexture.h"

Rendering::PlatformTexture2DTesting::PlatformTexture2DTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, PlatformTexture2DTesting)

void Rendering::PlatformTexture2DTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Rendering::PlatformTexture2DTesting::MainTest()
{
  

    ASSERT_NOT_THROW_EXCEPTION_0(Texture2DTest);

    
}

void Rendering::PlatformTexture2DTesting::Texture2DTest() noexcept
{
}
