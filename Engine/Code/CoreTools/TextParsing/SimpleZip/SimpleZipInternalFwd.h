///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/19 13:41)

#ifndef CORE_TOOLS_TEXT_PARSING_SIMPLE_ZIP_INTERNAL_FWD_H
#define CORE_TOOLS_TEXT_PARSING_SIMPLE_ZIP_INTERNAL_FWD_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/PragmaWarning/Miniz.h"
#include "CoreTools/TextParsing/TextParsingFwd.h"

#include <vector>

namespace CoreTools
{
    namespace SimpleZip
    {
        /// ZipEntryInfo ʵ����miniz����mz_zip_archive_file_stat�ı�����
        /// ZipEntryInfo/mz_zip_archive_file_stat�ṹ������zip�浵���ض���Ŀ������Ŀ����صĸ���Ԫ���ݣ����磺ע�͡��ļ���С�����ڴ��ȡ�
        /// ��Ӧ�ֶ������µ� ZipEntryInfo��
        using ZipEntryInfo = mz_zip_archive_file_stat;

        /// ZipEntryDataʵ����std::vector<uint8_t>�ı�����
        /// �������κ����͵��ļ����ݵ�ͨ�������������ַ����Ͷ������ļ���
        /// Ҳ����ʹ���ַ��������ַ����飬���ֽ�����������ر������������ڷ��ı����ݡ�
        using ZipEntryData = std::vector<uint8_t>;

        class ZipEntryImpl;
        class ZipArchiveImpl;
    }
}

#endif  // CORE_TOOLS_TEXT_PARSING_SIMPLE_ZIP_INTERNAL_FWD_H