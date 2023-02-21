///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/18 15:34)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_SUITE_BUFFER_SOURCE_TESTING_H
#define CORE_TOOLS_OBJECT_SYSTEMS_SUITE_BUFFER_SOURCE_TESTING_H

#include "CoreTools/FileManager/FileManagerFwd.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class BufferSourceTesting : public UnitTest
    {
    public:
        using ClassType = BufferSourceTesting;
        using ParentType = UnitTest;

    public:
        explicit BufferSourceTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void MainTest() noexcept;

        void DoRunUnitTest() override;
    };
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_SUITE_BUFFER_SOURCE_TESTING_H