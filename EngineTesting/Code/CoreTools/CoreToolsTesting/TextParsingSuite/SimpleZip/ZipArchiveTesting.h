/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/17 09:41)

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
        using ZipArchive = SimpleZip::ZipArchive;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void CreateZipArchiveTest();
        void ReadZipArchiveTest();
        void RemoveFile();
        void DefaultTest();

        NODISCARD static std::string GetZipArchiveFileName();

        void CreateZipArchiveAddEntryTest(ZipArchive& zipArchive);
        void CreateZipArchiveDeleteEntryTest(ZipArchive& zipArchive);

    private:
        std::string entryName;
        std::string data;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_SUITE_ZIP_ARCHIVE_TESTING_H
