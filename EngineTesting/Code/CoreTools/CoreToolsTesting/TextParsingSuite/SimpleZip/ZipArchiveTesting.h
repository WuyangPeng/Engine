///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/17 16:18)

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
