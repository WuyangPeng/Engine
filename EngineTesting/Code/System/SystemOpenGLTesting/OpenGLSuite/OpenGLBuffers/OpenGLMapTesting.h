/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/13 16:35)

#ifndef SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_MAP_TESTING_H
#define SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_MAP_TESTING_H

#include "OpenGLBuffersTestingBase.h"

namespace System
{
    class OpenGLMapTesting final : public OpenGLBuffersTestingBase
    {
    public:
        using ClassType = OpenGLMapTesting;
        using ParentType = OpenGLBuffersTestingBase;

    public:
        explicit OpenGLMapTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void InitTest();
        void MapTest();

    private:
        OpenGLUnsignedInt handler;
    };
}

#endif  // SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_MAP_TESTING_H