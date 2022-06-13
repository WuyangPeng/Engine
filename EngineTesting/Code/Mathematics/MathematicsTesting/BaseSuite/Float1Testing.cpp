///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/06/08 11:25)

#include "Float1Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Base/Float.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, Float1Testing)

void Mathematics::Float1Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ConstructorTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DelayCopyTest);
}

void Mathematics::Float1Testing::ConstructorTest() noexcept
{
}

void Mathematics::Float1Testing::DelayCopyTest() noexcept
{
}
