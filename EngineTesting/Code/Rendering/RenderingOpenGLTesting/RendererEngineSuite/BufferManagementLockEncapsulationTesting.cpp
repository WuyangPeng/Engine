///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/12 14:46)

#include "BufferManagementLockEncapsulationTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h" 
#include "Rendering/RendererEngine/BaseRenderer.h"
#include "Rendering/Resources/Buffers/IndexBuffer.h"
#include "Rendering/SceneGraph/Visual.h"

Rendering::BufferManagementLockEncapsulationTesting::BufferManagementLockEncapsulationTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, BufferManagementLockEncapsulationTesting)

void Rendering::BufferManagementLockEncapsulationTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Rendering::BufferManagementLockEncapsulationTesting::MainTest()
{
   

    ASSERT_NOT_THROW_EXCEPTION_0(VertexBufferTest);
    ASSERT_NOT_THROW_EXCEPTION_0(IndexBufferTest);

   
}

void Rendering::BufferManagementLockEncapsulationTesting::VertexBufferTest() noexcept
{
}

void Rendering::BufferManagementLockEncapsulationTesting::IndexBufferTest() noexcept
{
}
