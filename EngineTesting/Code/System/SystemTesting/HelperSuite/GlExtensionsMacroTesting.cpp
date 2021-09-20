///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.1 (2021/03/15 16:52)

#include "GlExtensionsMacroTesting.h"
#include "System/Helper/GlExtensionsMacro.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::GlExtensionsMacroTesting::GlExtensionsMacroTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, GlExtensionsMacroTesting)

void System::GlExtensionsMacroTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::GlExtensionsMacroTesting ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MacroExistTest);
}

void System::GlExtensionsMacroTesting::MacroExistTest() noexcept
{
    // 保证以下宏是存在的。
    __gl_h_;
    __gl2_h_;
    __GL_H__;
    _GL_H;
    __gl_gl_h_;
    __gltypes_h_;
    __REGAL_H__;
    __X_GL_H;
    __glext_h_;
    __GLEXT_H_;
    __gl_glext_h_;
    __gl_ATI_h_;
}
