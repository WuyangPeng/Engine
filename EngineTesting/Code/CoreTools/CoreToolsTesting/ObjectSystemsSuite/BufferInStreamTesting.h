/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/05/19 20:05)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_SUITE_BUFFER_IN_STREAM_TESTING_H
#define CORE_TOOLS_OBJECT_SYSTEMS_SUITE_BUFFER_IN_STREAM_TESTING_H

#include "CoreTools/FileManager/FileManagerFwd.h"
#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class BufferInStreamTesting final : public UnitTest
    {
    public:
        using ClassType = BufferInStreamTesting;
        using ParentType = UnitTest;

    public:
        explicit BufferInStreamTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        using ObjectContainer = std::vector<ObjectInterfaceSharedPtr>;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void BufferInStreamTest();

        NODISCARD static ConstFileBufferSharedPtr GetBufferInformation();

        void IsExactlyTest(const ObjectContainer& objects);
        NODISCARD ObjectContainer GetObjectContainer(const InTopLevel& inTopLevel);
    };
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_SUITE_BUFFER_IN_STREAM_TESTING_H