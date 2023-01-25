///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.0 (2023/01/20 15:24)

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