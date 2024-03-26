/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/16 17:29)

#include "OpenGLPixelStoreTesting.h"
#include "System/OpenGL/Flags/OpenGLFlags.h"
#include "System/OpenGL/OpenGLTextures.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::OpenGLPixelStoreTesting::OpenGLPixelStoreTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, OpenGLPixelStoreTesting)

void System::OpenGLPixelStoreTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::OpenGLPixelStoreTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(PixelStoreTest);
}

void System::OpenGLPixelStoreTesting::PixelStoreTest()
{
    ASSERT_NOT_THROW_EXCEPTION_1(DoPixelStoreTest, PixelStore::UnpackAlignment);
    ASSERT_NOT_THROW_EXCEPTION_1(DoPixelStoreTest, PixelStore::PackAlignment);
}

void System::OpenGLPixelStoreTesting::DoPixelStoreTest(PixelStore pixelStore) const noexcept
{
    SetGLPixelStore(pixelStore, 1);
    SetGLPixelStore(pixelStore, 2);
    SetGLPixelStore(pixelStore, 8);
    SetGLPixelStore(pixelStore, 4);
}
