///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.0 (2023/01/16 23:31)

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
        void DoRunUnitTest() final;
        void MainTest();

        void SetGLBindBufferTest();
        void SetGLBufferDataTest();
        void SetGLBindBufferBaseTest();
        void SetGLBindBufferRangeTest();

        void DoSetGLBindBufferTest(OpenGLUInt buffer);
        void DoSetGLBufferDataTest(const BufferType& buffers);
        void DoSetGLBindBufferBaseTest(OpenGLUInt buffer) noexcept;
        void DoSetGLBindBufferRangeTest(OpenGLUInt buffer) noexcept;
        void SetBufferData(BindBuffer bindBuffer, const BufferType& buffers, int index);
    };
}

#endif  // SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_SET_BUFFERS_TESTING_H