///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.7 (2023/04/26 14:02)

#ifndef CORE_TOOLS_TEXT_PARSING_SUITE_ZIP_ARCHIVE_TESTING_H
#define CORE_TOOLS_TEXT_PARSING_SUITE_ZIP_ARCHIVE_TESTING_H

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
        void DoRunUnitTest() override;
        void MainTest();

        void CreateZipArchiveTest();
        void ReadZipArchiveTest();
        void RemoveFile();
        void DefaultTest();

        NODISCARD static std::string GetZipArchiveFileName();

    private:
        std::string entryName;
        std::string data;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_SUITE_ZIP_ARCHIVE_TESTING_H
