///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.0 (2023/01/20 15:24)

#ifndef SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_PIXEL_STORE_TESTING_H
#define SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_PIXEL_STORE_TESTING_H

#include "OpenGLTexturesTestingBase.h"

namespace System
{
    class OpenGLPixelStoreTesting final : public OpenGLTexturesTestingBase
    {
    public:
        using ClassType = OpenGLPixelStoreTesting;
        using ParentType = OpenGLTexturesTestingBase;

    public:
        explicit OpenGLPixelStoreTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void OpenGLPixelStoreTest();
        void DoOpenGLPixelStoreTest(PixelStore pixelStore) noexcept;
    };
}

#endif  // SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_PIXEL_STORE_TESTING_H