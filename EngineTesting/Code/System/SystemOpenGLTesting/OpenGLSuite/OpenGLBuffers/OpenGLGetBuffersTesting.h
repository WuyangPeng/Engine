///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.0 (2023/01/16 23:31)

#ifndef SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_GET_BUFFERS_TESTING_H
#define SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_GET_BUFFERS_TESTING_H

#include "OpenGLBuffersTestingBase.h"

namespace System
{
    class OpenGLGetBuffersTesting final : public OpenGLBuffersTestingBase
    {
    public:
        using ClassType = OpenGLGetBuffersTesting;
        using ParentType = OpenGLBuffersTestingBase;

    public:
        explicit OpenGLGetBuffersTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void OpenGLGetBufferTest();
        void OpenGLGetBuffersTest();

        void DoOpenGLGetBuffersTest(const BufferType& buffers);
    };
}

#endif  // SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_GET_BUFFERS_TESTING_H