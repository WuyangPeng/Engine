///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/01 09:52)

#include "ExportMacroTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Toolset/CoreTools/ExportTest/System/ExportClass.h"
#include "Toolset/CoreTools/ExportTest/System/VisibleClass.h"

#define OPEN_NO_EXPORT_CLASS
#undef OPEN_NO_EXPORT_CLASS

// 这里开启OPEN_NO_EXPORT_CLASS会产生一个编译错误
#ifdef OPEN_NO_EXPORT_CLASS

    #include "Toolset/CoreTools/ExportTest/System/NoExportClass.h"

#endif  // OPEN_NO_EXPORT_CLASS

System::ExportMacroTesting::ExportMacroTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, ExportMacroTesting)

void System::ExportMacroTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::ExportMacroTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ExportTest);
}

void System::ExportMacroTesting::ExportTest() noexcept
{
    const ExportTest::ExportClass exportClass{};
    const ExportTest::VisibleClass visibleClass{};
}
