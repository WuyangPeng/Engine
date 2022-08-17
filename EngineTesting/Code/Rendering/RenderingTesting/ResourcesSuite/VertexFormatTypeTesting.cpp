///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.9 (2022/06/15 16:25)

#include "VertexFormatTypeTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Rendering/Resources/Buffers/VertexFormatAttribute.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, VertexFormatTypeTesting)

void Rendering::VertexFormatTypeTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(BaseTest);
}

void Rendering::VertexFormatTypeTesting::BaseTest() noexcept
{
}
