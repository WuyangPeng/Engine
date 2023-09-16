///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/08/31 15:22)

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
    ASSERT_UNEQUAL_NULL_PTR(GetSystemStockObject(WindowsBrushTypes::LightGrayBrush));
    ASSERT_UNEQUAL_NULL_PTR(GetSystemStockObject(WindowsBrushTypes::GrayBrush));
    ASSERT_UNEQUAL_NULL_PTR(GetSystemStockObject(WindowsBrushTypes::DarkGrayBrush));
    ASSERT_UNEQUAL_NULL_PTR(GetSystemStockObject(WindowsBrushTypes::BlackBrush));
    ASSERT_UNEQUAL_NULL_PTR(GetSystemStockObject(WindowsBrushTypes::NullBrush));
    ASSERT_EQUAL_NULL_PTR(GetSystemStockObject(WindowsBrushTypes::Null));
}
