/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/13 10:41)

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
    std::ignore = ExportTest::ExportSharedPtrMacro::Create();
}

void CoreTools::ExportMacroTesting::ExportUniquePtrMacroTest()
{
    std::ignore = std::make_unique<ExportTest::ExportUniquePtrMacro>();
}

void CoreTools::ExportMacroTesting::ExportSharedImplMacroSharedTest()
{
    ExportTest::ExportSharedImplMacroShared lhsMacro{ count };

    const auto rhsMacro = lhsMacro;
    CountTest(lhsMacro, rhsMacro, count, count);

    lhsMacro.SetCount(0);
    CountTest(lhsMacro, rhsMacro, 0, 0);
}

void CoreTools::ExportMacroTesting::ExportNonCopyImplMacroTest()
{
    std::ignore = ExportTest::ExportNonCopyImplMacro::Create();
}

void CoreTools::ExportMacroTesting::ExportPerformanceUnsharedImplMacroTest()
{
    const ExportTest::ExportPerformanceUnsharedImplMacro original{ count };

    const auto copy = original;

    CountTest(original, copy, count, count);
}

void CoreTools::ExportMacroTesting::ExportImplMacroTest()
{
    const ExportImplMacro macro{ count };

    ASSERT_EQUAL(macro.GetCount(), count);
}

void CoreTools::ExportMacroTesting::ExportConstImplMacroTest()
{
    const ExportConstImplMacro macro{ count };

    ASSERT_EQUAL(macro.GetCount(), count);
}
