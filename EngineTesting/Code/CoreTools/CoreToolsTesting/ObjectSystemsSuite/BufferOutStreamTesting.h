/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.9 (2024/05/19 20:39)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_SUITE_BUFFER_OUT_STREAM_TESTING_H
#define CORE_TOOLS_OBJECT_SYSTEMS_SUITE_BUFFER_OUT_STREAM_TESTING_H

#include "CoreTools/FileManager/FileManagerFwd.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class BufferOutStreamTesting final : public UnitTest
    {
    public:
        using ClassType = BufferOutStreamTesting;
        using ParentType = UnitTest;

    public:
        explicit BufferOutStreamTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void BufferOutStreamTest();

        NODISCARD static ConstFileBufferSharedPtr GetBufferInformation();
    };
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_SUITE_BUFFER_OUT_STREAM_TESTING_H