///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/06/06 21:09)

#include "TriangleProjectOntoAxisTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <random>

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, TriangleProjectOntoAxisTesting)

void Mathematics::TriangleProjectOntoAxisTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ProjectTest);
}

void Mathematics::TriangleProjectOntoAxisTesting::ProjectTest() noexcept
{
}
