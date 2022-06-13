///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/18 15:38)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_SUITE_STREAM_TESTING_H
#define CORE_TOOLS_OBJECT_SYSTEMS_SUITE_STREAM_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace CoreTools
{
    class StreamTesting : public UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(StreamTesting);

    private:
        void MainTest();
        void StreamTest();

        void DoRunUnitTest() override;
    };
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_SUITE_STREAM_TESTING_H