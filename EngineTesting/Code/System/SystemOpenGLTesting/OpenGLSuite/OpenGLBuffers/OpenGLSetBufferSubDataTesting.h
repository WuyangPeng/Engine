/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/13 16:35)

#ifndef SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_SET_BUFFERS_SUB_DATA_TESTING_H
#define SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_SET_BUFFERS_SUB_DATA_TESTING_H

#include "OpenGLBuffersTestingBase.h"

namespace System
{
    class OpenGLSetBufferSubDataTesting final : public OpenGLBuffersTestingBase
    {
    public:
        using ClassType = OpenGLSetBufferSubDataTesting;
        using ParentType = OpenGLBuffersTestingBase;

    public:
        explicit OpenGLSetBufferSubDataTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void SetBufferSubDataTest();
        void BindBufferTest(OpenGLUnsignedInt buffer, BindBuffer bindBuffer);
        void DoSetBufferSubDataTest(OpenGLUnsignedInt buffer);

        void GetBufferSubDataTest(BindBuffer bindBuffer);
        void BufferSubDataTest(BindBuffer bindBuffer);
        void GetBufferSubDataResultTest(const BufferDataType& result);
    };
}

#endif  // SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_SET_BUFFERS_SUB_DATA_TESTING_H