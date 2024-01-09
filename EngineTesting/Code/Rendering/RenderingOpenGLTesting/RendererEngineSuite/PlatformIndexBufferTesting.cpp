///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/12 14:47)

#include "PlatformIndexBufferTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h" 
#include "Rendering/RendererEngine/BaseRenderer.h"
#include "Rendering/Resources/Buffers/IndexBuffer.h"

Rendering::PlatformIndexBufferTesting::PlatformIndexBufferTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, PlatformIndexBufferTesting)

void Rendering::PlatformIndexBufferTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Rendering::PlatformIndexBufferTesting::MainTest()
{


    ASSERT_NOT_THROW_EXCEPTION_0(IndexBufferTest);

 
}

void Rendering::PlatformIndexBufferTesting::IndexBufferTest() noexcept
{
}
