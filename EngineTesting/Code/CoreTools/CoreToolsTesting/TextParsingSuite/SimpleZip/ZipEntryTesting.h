/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/17 09:41)

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
        using ZipEntry = SimpleZip::ZipEntry;
        using ZipEntryInfo = SimpleZip::ZipEntryInfo;
        using ZipEntryData = SimpleZip::ZipEntryData;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void ZipEntryInfoTest();
        void ZipEntryDataTest();
        void StringDataTest();
        void WriterAddMemTest();
        void ReaderExtractFileToMemTest();
        void RemoveFile();

        NODISCARD static ZipEntryInfo GetZipEntryInfo(mz_uint32 fileIndex);
        NODISCARD static std::string GetZipArchiveFileName();

        void ZipEntryInfoDataTest(const ZipEntry& zipEntry);
        void ZipEntryInfoBase0Test(mz_uint32 fileIndex, const ZipEntry& zipEntry);
        void ZipEntryInfoCommentTest(const ZipEntry& zipEntry);
        void GetZipEntryInfoTest(mz_uint32 fileIndex, const ZipEntry& zipEntry);
        void ZipEntryInfoBase1Test(ZipEntry& zipEntry);

        void ZipEntryData0Test(const ZipEntryData& originalZipEntryData, const ZipEntry& zipEntry);
        void ZipEntryData1Test(const ZipEntry& zipEntry);
        void ZipEntryData2Test(const ZipEntry& zipEntry);
        void ZipEntryData3Test(const ZipEntry& zipEntry);
        void ZipEntryData4Test(ZipEntry& zipEntry);

        void StringDataTest0Test(const ZipEntry& zipEntry);
        void StringDataTest1Test(const ZipEntry& zipEntry);
        void StringDataTest2Test(const ZipEntry& zipEntry);
        void StringDataTest3Test(const ZipEntry& zipEntry);
        void StringDataTest4Test(ZipEntry& zipEntry);
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_SUITE_ZIP_ENTRY_TESTING_H
