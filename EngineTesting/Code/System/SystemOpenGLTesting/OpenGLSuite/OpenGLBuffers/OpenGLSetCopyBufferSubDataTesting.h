///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.0 (2023/01/19 21:33)

#ifndef SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_SET_COPY_BUFFER_SUB_DATA_TESTING_H
#define SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_SET_COPY_BUFFER_SUB_DATA_TESTING_H

#include "OpenGLBuffersTestingBase.h" 

namespace System
{
    class OpenGLSetCopyBufferSubDataTesting final : public OpenGLBuffersTestingBase
    {
    public:
        using ClassType = OpenGLSetCopyBufferSubDataTesting;
        using ParentType = OpenGLBuffersTestingBase;

    public:
        explicit OpenGLSetCopyBufferSubDataTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void GetBufferSubDataTest(BindBuffer bindBuffer);

        void SetGLCopyBufferSubDataTest();
        void DoSetGLCopyBufferSubDataTest(BufferType buffers);
        void CopyBufferSubDataTest(BindBuffer readTarget, BindBuffer writeTarget);
    };
}

#endif  // SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_SET_COPY_BUFFER_SUB_DATA_TESTING_H