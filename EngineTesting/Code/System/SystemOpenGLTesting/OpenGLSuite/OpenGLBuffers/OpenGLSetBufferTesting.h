/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/13 16:35)

#ifndef SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_SET_BUFFERS_TESTING_H
#define SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_SET_BUFFERS_TESTING_H

#include "OpenGLBuffersTestingBase.h"

namespace System
{
    class OpenGLSetBufferTesting final : public OpenGLBuffersTestingBase
    {
    public:
        using ClassType = OpenGLSetBufferTesting;
        using ParentType = OpenGLBuffersTestingBase;

    public:
        explicit OpenGLSetBufferTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void OpenGLSetBindBufferTest();
        void OpenGLSetBufferDataTest();
        void OpenGLSetBindBufferBaseTest();
        void OpenGLSetBindBufferRangeTest();

        void DoOpenGLSetBindBufferTest(OpenGLUnsignedInt buffer);
        void DoOpenGLSetBufferDataTest(const BufferType& buffers);
        void DoOpenGLSetBindBufferBaseTest(OpenGLUnsignedInt buffer) const noexcept;
        void DoOpenGLSetBindBufferRangeTest(OpenGLUnsignedInt buffer) const noexcept;
        void SetBufferData(BindBuffer bindBuffer, const BufferType& buffers, int index) const;
    };
}

#endif  // SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_SET_BUFFERS_TESTING_H