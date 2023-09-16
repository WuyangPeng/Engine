///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/01 09:48)

#include "GlPluginMacroTesting.h"
#include "System/Helper/Detail/OpenGL/GLPluginMacro.h"
#include "System/SystemTesting/HelperSuite/Detail/GlPluginMacroHelper.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::GlPluginMacroTesting::GlPluginMacroTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, GlPluginMacroTesting)

void System::GlPluginMacroTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::GlPluginMacroTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(PluginMacroTest);
}

void System::GlPluginMacroTesting::PluginMacroTest() noexcept
{
    SYSTEM_ENTER_FUNCTION(GlFunction);
    SYSTEM_NONNULL_FUNCTION(GlFunction);
    SYSTEM_NULL_FUNCTION(GlFunction);
    SYSTEM_EXIT_FUNCTION(GlFunction);
}
