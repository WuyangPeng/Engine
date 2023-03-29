///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.4 (2023/03/06 14:18)

#ifndef CORE_TOOLS_TEXT_PARSING_SUITE_ZIP_ENTRY_TESTING_H
#define CORE_TOOLS_TEXT_PARSING_SUITE_ZIP_ENTRY_TESTING_H

#include "CoreTools/TextParsing/SimpleZip/SimpleZipInternalFwd.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class ZipEntryTesting final : public UnitTest
    {
    public:
        using ClassType = ZipEntryTesting;
        using ParentType = UnitTest;

    public:
        explicit ZipEntryTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void ZipEntryInfoTest();
        void ZipEntryDataTest();
        void StringDataTest();
        void WriterAddMemTest();
        void ReaderExtractFileToMemTest();
        void RemoveFile();

        NODISCARD SimpleZip::ZipEntryInfo GetZipEntryInfo(mz_uint32 fileIndex);
        NODISCARD static std::string GetZipArchiveFileName();
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_SUITE_ZIP_ENTRY_TESTING_H
