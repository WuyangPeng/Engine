///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.1 (2023/02/02 21:12)

#include "GetStockObjectTesting.h"
#include "System/Windows/Flags/WindowsPictorialFlags.h"
#include "System/Windows/WindowsRegister.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::GetStockObjectTesting::GetStockObjectTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, GetStockObjectTesting)

void System::GetStockObjectTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::GetStockObjectTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(GetStockObjectTest);
}

void System::GetStockObjectTesting::GetStockObjectTest()
{
    ASSERT_UNEQUAL_NULL_PTR(GetSystemStockObject(WindowsBrushTypes::WhiteBrush));
    ASSERT_UNEQUAL_NULL_PTR(GetSystemStockObject(WindowsBrushTypes::LtgrayBrush));
    ASSERT_UNEQUAL_NULL_PTR(GetSystemStockObject(WindowsBrushTypes::GrayBrush));
    ASSERT_UNEQUAL_NULL_PTR(GetSystemStockObject(WindowsBrushTypes::DkgrayBrush));
    ASSERT_UNEQUAL_NULL_PTR(GetSystemStockObject(WindowsBrushTypes::BlackBrush));
    ASSERT_UNEQUAL_NULL_PTR(GetSystemStockObject(WindowsBrushTypes::NullBrush));
    ASSERT_EQUAL_NULL_PTR(GetSystemStockObject(WindowsBrushTypes::Null));
}
