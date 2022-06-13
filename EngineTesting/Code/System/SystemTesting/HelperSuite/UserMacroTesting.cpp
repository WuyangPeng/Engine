///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/15 1:13)

#include "UserMacroTesting.h"
#include "System/Helper/UserMacro.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::UserMacroTesting::UserMacroTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, UserMacroTesting)

void System::UserMacroTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::UserMacroTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CloseSystemMaxTest);
    ASSERT_NOT_THROW_EXCEPTION_0(MacroExistTest);
}

void System::UserMacroTesting::CloseSystemMaxTest()
{
    ASSERT_EQUAL(CLOSE_GLUT | CLOSE_ENABLE_GL_ERROR_CHECKING | CLOSE_DIRECTX, CLOSE_SYSTEM_MAX);
}

void System::UserMacroTesting::MacroExistTest()
{
#ifdef SYSTEM_USE_WINDOWS_MACRO

    SYSTEM_PLATFORM_WIN32;

#endif  // SYSTEM_USE_WINDOWS_MACRO

#ifdef SYSTEM_USE_SPIN_COUNT_CRITICAL_SECTION

    TCRE_USE_GCC;

#endif  // SYSTEM_USE_SPIN_COUNT_CRITICAL_SECTION

#if !defined(COMPILE_SYSTEM_CLOSE)

    SYSTEM_USE_GLUT;

#else  // defined(COMPILE_SYSTEM_CLOSE)

    #ifdef SYSTEM_USE_GLUT

    ASSERT_UNEQUAL((COMPILE_SYSTEM_CLOSE & CLOSE_GLUT), CLOSE_GLUT);

    #endif  // SYSTEM_USE_GLUT

#endif  // !defined(COMPILE_SYSTEM_CLOSE)

#ifdef SYSTEM_ENABLE_GL_ERROR_CHECKING

    ASSERT_EQUAL(_DEBUG, 1);

#endif  // SYSTEM_ENABLE_GL_ERROR_CHECKING

#ifdef SYSTEM_USE_DIRECT_X_9

    SYSTEM_PLATFORM_WIN32;

#endif  // SYSTEM_USE_DIRECT_X_9

#ifdef SYSTEM_USE_DIRECT_X_10

    SYSTEM_PLATFORM_WIN32;

#endif  // SYSTEM_USE_DIRECT_X_10

#ifdef SYSTEM_USE_DIRECT_X_11

    SYSTEM_PLATFORM_WIN32;

#endif  // SYSTEM_USE_DIRECT_X_11

#ifdef BUILDING_SYSTEM_STATIC

    BUILDING_STATIC;

#endif  // BUILDING_SYSTEM_STATIC
}
