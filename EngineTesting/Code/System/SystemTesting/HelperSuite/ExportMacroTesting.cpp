/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/07 17:37)

#include "ExportMacroTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Toolset/CoreTools/ExportTest/System/ExportClass.h"
#include "Toolset/CoreTools/ExportTest/System/ExportFunction.h"
#include "Toolset/CoreTools/ExportTest/System/VisibleClass.h"

#define OPEN_NO_EXPORT_CLASS
#undef OPEN_NO_EXPORT_CLASS

/// ���￪��OPEN_NO_EXPORT_CLASS�����һ���������
#ifdef OPEN_NO_EXPORT_CLASS

    #include "Toolset/CoreTools/ExportTest/System/NoExportClass.h"

#endif  // OPEN_NO_EXPORT_CLASS

System::ExportMacroTesting::ExportMacroTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, ExportMacroTesting)

void System::ExportMacroTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::ExportMacroTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ExportTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ExportFunctionTest);
}

void System::ExportMacroTesting::ExportTest() const noexcept
{
    MAYBE_UNUSED constexpr ExportTest::ExportClass exportClass{};
    MAYBE_UNUSED constexpr ExportTest::VisibleClass visibleClass{};
}

void System::ExportMacroTesting::ExportFunctionTest() const noexcept
{
    ExportTest::ExportFunction();
}
