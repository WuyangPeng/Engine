///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/19 13:41)

#ifndef CORE_TOOLS_TEXT_PARSING_ZIP_ENTRY_IMPL_H
#define CORE_TOOLS_TEXT_PARSING_ZIP_ENTRY_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "ZipEntryMetaData.h"
#include "System/Helper/PragmaWarning/Miniz.h"

namespace CoreTools
{
    namespace SimpleZip
    {
        /// ZipEntryImpl��ʵ���˲���zip�浵�е���Ŀ����Ĺ��ܡ�
        /// ����ʵ���ࡣ
        class CORE_TOOLS_HIDDEN_DECLARE ZipEntryImpl final
        {
        public:
            using ClassType = ZipEntryImpl;

        public:
            explicit ZipEntryImpl(const ZipEntryInfo& info);

            /// ʹ�ø��������ƺͶ��������ݴ���һ���µ�ZipEntryImpl����Ӧ�ý����ڴ�������Ŀ��
            ZipEntryImpl(const std::string& name, const ZipEntryData& data);

            /// ʹ�ø��������ƺ��ַ������ݴ���һ���µ�ZipEntryImpl����Ӧ�ý����ڴ�������Ŀ��
            ZipEntryImpl(const std::string& name, const std::string& data);

            virtual ~ZipEntryImpl() noexcept = default;
            ZipEntryImpl(const ZipEntryImpl& rhs) = default;
            ZipEntryImpl& operator=(const ZipEntryImpl& rhs) = default;
            ZipEntryImpl(ZipEntryImpl&& rhs) noexcept = default;
            ZipEntryImpl& operator=(ZipEntryImpl&& rhs) noexcept = default;

            CLASS_INVARIANT_DECLARE;

            NODISCARD ZipEntryData GetEntryData() const;
            NODISCARD size_t GetEntrySize() const noexcept;
            NODISCARD bool IsEntryDataEmpty() const noexcept;

            NODISCARD std::string GetDataAsString() const;
            void SetData(const std::string& data);
            void SetData(const ZipEntryData& data);

            NODISCARD std::string GetFileName() const;
            void SetFileName(const std::string& name);

            NODISCARD uint32_t GetIndex() const noexcept;
            NODISCARD uint64_t GetCompressedSize() const noexcept;
            NODISCARD uint64_t GetUncompressedSize() const noexcept;
            NODISCARD bool IsDirectory() const noexcept;
            NODISCARD bool IsEncrypted() const noexcept;
            NODISCARD bool IsSupported() const noexcept;
            NODISCARD std::string GetComment() const;
            NODISCARD time_t GetTime() const noexcept;

            NODISCARD ZipEntryInfo GetZipEntryInfo() const noexcept;
            void ResizeZipEntryData(int uncompressedSize);

            NODISCARD bool IsModified() const noexcept;

            void ReaderExtractFileToMem(mz_zip_archive* archive, const std::string& name) noexcept;
            NODISCARD bool WriterAddMem(mz_zip_archive* archive) const;

        private:
            /// ����һ���µ�ZipEntryInfo�ṹ��
            /// �˺���������������ļ�������һ���µ�ZipEntryInfo�ṹ��
            /// �����ļ�������ʱ������ļ�����is_directory��־�⣬�ṹֵ���������ֵ��
            NODISCARD static ZipEntryInfo CreateInfo(const std::string& fileName);

        private:
            ZipEntryInfo entryInfo;
            ZipEntryData entryData;
            bool isModified;
        };
    }
}

#endif  // CORE_TOOLS_TEXT_PARSING_ZIP_ENTRY_IMPL_H