///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.2.3 (2021/09/13 12:50)

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
        void DoRunUnitTest() final;
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
