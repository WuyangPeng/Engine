///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/08/31 13:56)

#ifndef SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_FRAME_BUFFER_TESTING_H
#define SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_FRAME_BUFFER_TESTING_H

#include "OpenGLBuffersTestingBase.h"

namespace System
{
    class OpenGLFrameBufferTesting final : public OpenGLBuffersTestingBase
    {
    public:
        using ClassType = OpenGLFrameBufferTesting;
        using ParentType = OpenGLBuffersTestingBase;

    public:
        explicit OpenGLFrameBufferTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void OpenGLGetFrameBufferTest();
        void OpenGLGetFrameBuffersTest();

        void DoOpenGLGetFrameBuffersTest(const BufferType& buffers);
    };
}

#endif  // SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_FRAME_BUFFER_TESTING_H