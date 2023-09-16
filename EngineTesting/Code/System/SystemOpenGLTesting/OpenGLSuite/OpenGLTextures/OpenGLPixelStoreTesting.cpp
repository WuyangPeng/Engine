///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/31 14:27)

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
    ASSERT_NOT_THROW_EXCEPTION_0(OpenGLPixelStoreTest);
}

void System::OpenGLPixelStoreTesting::OpenGLPixelStoreTest()
{
    ASSERT_NOT_THROW_EXCEPTION_1(DoOpenGLPixelStoreTest, PixelStore::UnpackAlignment);
    ASSERT_NOT_THROW_EXCEPTION_1(DoOpenGLPixelStoreTest, PixelStore::PackAlignment);
}

void System::OpenGLPixelStoreTesting::DoOpenGLPixelStoreTest(PixelStore pixelStore) noexcept
{
    SetGLPixelStore(pixelStore, 1);
    SetGLPixelStore(pixelStore, 2);
    SetGLPixelStore(pixelStore, 8);
    SetGLPixelStore(pixelStore, 4);
}
