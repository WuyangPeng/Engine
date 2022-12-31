///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.5 (2022/12/17 15:01)

#include "ExportMacroTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Toolset/CoreTools/ExportTest/System/ExportClass.h"
#include "Toolset/CoreTools/ExportTest/System/VisibleClass.h"

#define OPEN_NO_EXPORT_CLASS
#undef OPEN_NO_EXPORT_CLASS

// ���￪��OPEN_NO_EXPORT_CLASS�����һ���������
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
