///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/12 16:04)

#include "ControllerKeyInfoTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Rendering/Controllers/ControllerKeyInfo.h"

Rendering::ControllerKeyInfoTesting::ControllerKeyInfoTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, ControllerKeyInfoTesting)

void Rendering::ControllerKeyInfoTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Rendering::ControllerKeyInfoTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(InitTest);
}

void Rendering::ControllerKeyInfoTesting::InitTest()
{
    const ControllerKeyInfo firstMorphControllerInfo(3.0f, 5, 16);

    ASSERT_APPROXIMATE(firstMorphControllerInfo.GetNormTime(), 3.0f, 1e-8f);
    ASSERT_EQUAL(firstMorphControllerInfo.GetFirstIndex(), 5);
    ASSERT_EQUAL(firstMorphControllerInfo.GetSecondIndex(), 16);
}
