///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.4 (2023/03/06 14:18)

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
