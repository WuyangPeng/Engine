///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/18 15:35)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_SUITE_FILE_OUT_STREAM_TESTING_H
#define CORE_TOOLS_OBJECT_SYSTEMS_SUITE_FILE_OUT_STREAM_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace CoreTools
{
    class FileOutStreamTesting : public UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(FileOutStreamTesting);

    private:
        NODISCARD std::string GetTopLevelContent() const;
        NODISCARD std::string GetAligningString(const std::string& original) const;
        NODISCARD std::string GetNullObjectContent(int uniqueID, const std::string& rttiTypeName) const;

        void MainTest();
        void WriteNullObjectTest() noexcept;

        void DoRunUnitTest() override;
    };
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_SUITE_FILE_OUT_STREAM_TESTING_H