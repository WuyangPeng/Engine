///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.2 (2023/02/11 15:31)

#include "ExportMacroTestingDetail.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Export/CopyUnsharedMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Export/CopyUnsharedUseCloneMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Export/ExportConstImplMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Export/ExportCopyImplMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Export/ExportCopyUnsharedImplMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Export/ExportDelayCopyUnsharedImplMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Export/ExportImplMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Export/ExportNonCopyImplMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Export/ExportPerformanceUnsharedImplMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Export/ExportSharedImplMacroShared.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Export/ExportSharedPtrMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Export/ExportUniquePtrMacro.h"

CoreTools::ExportMacroTesting::ExportMacroTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, ExportMacroTesting)

void CoreTools::ExportMacroTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::ExportMacroTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ExportSharedPtrMacroTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ExportUniquePtrMacroTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ExportSharedImplMacroSharedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ExportNonCopyImplMacroTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ExportPerformanceUnsharedImplMacroTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CopyExportTest<ExportTest::ExportCopyUnsharedImplMacro>);
    ASSERT_NOT_THROW_EXCEPTION_0(CopyExportTest<ExportTest::ExportDelayCopyUnsharedImplMacro>);

    ASSERT_NOT_THROW_EXCEPTION_0(ExportImplMacroTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CopyExportTest<ExportCopyImplMacro>);
    ASSERT_NOT_THROW_EXCEPTION_0(ExportConstImplMacroTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CopyExportTest<ExportTest::CopyUnsharedMacro>);
    ASSERT_NOT_THROW_EXCEPTION_0(CopyExportTest<ExportTest::CopyUnsharedUseCloneMacro>);
}

void CoreTools::ExportMacroTesting::ExportSharedPtrMacroTest()
{
    const auto macro = ExportTest::ExportSharedPtrMacro::Create();
}

void CoreTools::ExportMacroTesting::ExportUniquePtrMacroTest() noexcept
{
    const ExportTest::ExportUniquePtrMacro macro{};
}

void CoreTools::ExportMacroTesting::ExportSharedImplMacroSharedTest()
{
    constexpr auto count = 10;
    ExportTest::ExportSharedImplMacroShared lhsMacro{ count };

    auto rhsMacro = lhsMacro;

    ASSERT_EQUAL(rhsMacro.GetCount(), count);

    lhsMacro.SetCount(0);

    ASSERT_EQUAL(lhsMacro.GetCount(), 0);
    ASSERT_EQUAL(rhsMacro.GetCount(), 0);
}

void CoreTools::ExportMacroTesting::ExportNonCopyImplMacroTest()
{
    const auto macro = ExportTest::ExportNonCopyImplMacro::Create();
}

void CoreTools::ExportMacroTesting::ExportPerformanceUnsharedImplMacroTest()
{
    constexpr auto count = 10;
    ExportTest::ExportPerformanceUnsharedImplMacro original{ count };

    auto copy = original;

    ASSERT_EQUAL(copy.GetCount(), count);
}

void CoreTools::ExportMacroTesting::ExportImplMacroTest()
{
    constexpr auto count = 10;
    const ExportImplMacro macro{ count };

    ASSERT_EQUAL(macro.GetCount(), count);
}

void CoreTools::ExportMacroTesting::ExportConstImplMacroTest()
{
    constexpr auto count = 10;
    const ExportConstImplMacro macro{ count };

    ASSERT_EQUAL(macro.GetCount(), count);
}
