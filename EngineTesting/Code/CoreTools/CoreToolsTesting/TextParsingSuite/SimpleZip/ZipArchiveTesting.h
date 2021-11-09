///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.2.3 (2021/09/14 13:55)

#ifndef CORE_TOOLS_TEXT_PARSING_SUITE_ZIP_ARCHIVE_TESTING_H
#define CORE_TOOLS_TEXT_PARSING_SUITE_ZIP_ARCHIVE_TESTING_H

#include "CoreTools/TextParsing/SimpleZip/SimpleZipInternalFwd.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class ZipArchiveTesting final : public UnitTest
    {
    public:
        using ClassType = ZipArchiveTesting;
        using ParentType = UnitTest;

    public:
        explicit ZipArchiveTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void CreateZipArchiveTest();
        void ReadZipArchiveTest();
        void RemoveFile();
        void DefautlTest();

        NODISCARD static std::string GetZipArchiveFileName();
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_SUITE_ZIP_ARCHIVE_TESTING_H
