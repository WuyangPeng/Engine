///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/06/08 11:26)

#include "Float2Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Base/Float.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, Float2Testing)

void Mathematics::Float2Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ConstructorTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DelayCopyTest);
}

void Mathematics::Float2Testing::ConstructorTest() noexcept
{
}

void Mathematics::Float2Testing::DelayCopyTest() noexcept
{
}
