/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 16:40)

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
        void DoRunUnitTest() override;
        void MainTest();

        void PixelStoreTest();
        void DoPixelStoreTest(PixelStore pixelStore) const noexcept;
    };
}

#endif  // SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_PIXEL_STORE_TESTING_H