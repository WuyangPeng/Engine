///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.2.3 (2021/09/09 13:52)

#ifndef CORE_TOOLS_TEXT_PARSING_ZIP_ENTRY_META_DATA_H
#define CORE_TOOLS_TEXT_PARSING_ZIP_ENTRY_META_DATA_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/TextParsing/SimpleZip/SimpleZipInternalFwd.h"

#include <string>
#include <vector>

namespace CoreTools
{
    namespace SimpleZip
    {
        /// ZipEntryMetaData��������ZipEntryInfo�ṹ�İ�װ��������miniz�ṹ�ı�����
        class CORE_TOOLS_HIDDEN_DECLARE ZipEntryMetaData final
        {
        public:
            using ClassType = ZipEntryMetaData;

        public:
            explicit ZipEntryMetaData(const ZipEntryInfo& info);

            CLASS_INVARIANT_DECLARE;

            NODISCARD uint32_t GetIndex() const noexcept;
            NODISCARD uint64_t GetCompressedSize() const noexcept;
            NODISCARD uint64_t GetUncompressedSize() const noexcept;
            NODISCARD bool IsDirectory() const noexcept;
            NODISCARD bool IsEncrypted() const noexcept;
            NODISCARD bool IsSupported() const noexcept;
            NODISCARD std::string GetFileName() const;
            NODISCARD std::string GetComment() const;
            NODISCARD time_t GetTime() const noexcept;

        private:
            uint32_t index;
            uint64_t compressedSize;
            uint64_t uncompressedSize;
            bool isDirectory;
            bool isEncrypted;
            bool isSupported;
            std::string fileName;
            std::string comment;
            const time_t time;
        };
    }
}

#endif  // CORE_TOOLS_TEXT_PARSING_ZIP_ENTRY_META_DATA_H