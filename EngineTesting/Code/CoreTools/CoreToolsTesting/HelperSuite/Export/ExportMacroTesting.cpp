///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.2.1 (2021/08/14 17:45)

#include "ExportMacroTesting.h"
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
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
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
    ASSERT_NOT_THROW_EXCEPTION_0(ExportCopyUnsharedImplMacroTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ExportDelayCopyUnsharedImplMacroTest);

    ASSERT_NOT_THROW_EXCEPTION_0(ExportImplMacroTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ExportCopyImplMacroTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ExportConstImplMacroTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CopyUnsharedMacroTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CopyUnsharedUseCloneMacroTest);
}

void CoreTools::ExportMacroTesting::ExportSharedPtrMacroTest()
{
    ExportTest::ExportSharedPtrMacro macro{ CoreTools::DisableNotThrow::Disable };
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
    const ExportTest::ExportNonCopyImplMacro macro{ CoreTools::DisableNotThrow::Disable };
}

void CoreTools::ExportMacroTesting::ExportPerformanceUnsharedImplMacroTest()
{
    constexpr auto count = 10;
    ExportTest::ExportPerformanceUnsharedImplMacro lhsMacro{ count };

    auto rhsMacro = lhsMacro;

    ASSERT_EQUAL(rhsMacro.GetCount(), count);
}

void CoreTools::ExportMacroTesting::ExportCopyUnsharedImplMacroTest()
{
    constexpr auto count = 10;
    ExportTest::ExportCopyUnsharedImplMacro lhsMacro{ count };

    auto rhsMacro = lhsMacro;

    ASSERT_EQUAL(rhsMacro.GetCount(), count);

    lhsMacro.SetCount(0);

    ASSERT_EQUAL(lhsMacro.GetCount(), 0);
    ASSERT_EQUAL(rhsMacro.GetCount(), count);
}

void CoreTools::ExportMacroTesting::ExportDelayCopyUnsharedImplMacroTest()
{
    constexpr auto count = 10;
    ExportTest::ExportDelayCopyUnsharedImplMacro lhsMacro{ count };

    auto rhsMacro = lhsMacro;

    ASSERT_EQUAL(rhsMacro.GetCount(), count);

    lhsMacro.SetCount(0);

    ASSERT_EQUAL(lhsMacro.GetCount(), 0);
    ASSERT_EQUAL(rhsMacro.GetCount(), count);
}

void CoreTools::ExportMacroTesting::ExportImplMacroTest()
{
    constexpr auto count = 10;
    CoreTools::ExportImplMacro macro{ count };

    ASSERT_EQUAL(macro.GetCount(), count);
}

void CoreTools::ExportMacroTesting::ExportCopyImplMacroTest()
{
    constexpr auto count = 10;
    CoreTools::ExportCopyImplMacro lhsMacro{ count };

    auto rhsMacro = lhsMacro;

    ASSERT_EQUAL(rhsMacro.GetCount(), count);

    lhsMacro.SetCount(0);

    ASSERT_EQUAL(lhsMacro.GetCount(), 0);
    ASSERT_EQUAL(rhsMacro.GetCount(), count);
}

void CoreTools::ExportMacroTesting::ExportConstImplMacroTest()
{
    constexpr auto count = 10;
    CoreTools::ExportConstImplMacro macro{ count };

    ASSERT_EQUAL(macro.GetCount(), count);
}

void CoreTools::ExportMacroTesting::CopyUnsharedMacroTest()
{
    constexpr auto count = 10;
    ExportTest::CopyUnsharedMacro lhsMacro{ count };

    auto rhsMacro = lhsMacro;

    ASSERT_EQUAL(rhsMacro.GetCount(), count);

    lhsMacro.SetCount(0);

    ASSERT_EQUAL(lhsMacro.GetCount(), 0);
    ASSERT_EQUAL(rhsMacro.GetCount(), count);
}

void CoreTools::ExportMacroTesting::CopyUnsharedUseCloneMacroTest()
{
    constexpr auto count = 10;
    ExportTest::CopyUnsharedUseCloneMacro lhsMacro{ count };

    auto rhsMacro = lhsMacro;

    ASSERT_EQUAL(rhsMacro.GetCount(), count);

    lhsMacro.SetCount(0);

    ASSERT_EQUAL(lhsMacro.GetCount(), 0);
    ASSERT_EQUAL(rhsMacro.GetCount(), count);
}
