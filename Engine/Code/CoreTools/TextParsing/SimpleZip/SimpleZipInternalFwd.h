///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/04/03 20:13)

#ifndef CORE_TOOLS_TEXT_PARSING_SIMPLE_ZIP_INTERNAL_FWD_H
#define CORE_TOOLS_TEXT_PARSING_SIMPLE_ZIP_INTERNAL_FWD_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/PragmaWarning/Miniz.h"
#include "CoreTools/TextParsing/TextParsingFwd.h"

#include <vector>

namespace CoreTools::SimpleZip
{
    /// ZipEntryInfo 实体是miniz库中mz_zip_archive_file_stat的别名。
    /// ZipEntryInfo/mz_zip_archive_file_stat结构保存与zip存档中特定条目（或项目）相关的各种元数据，例如：注释、文件大小、日期戳等。
    /// 不应手动创建新的 ZipEntryInfo。
    using ZipEntryInfo = mz_zip_archive_file_stat;

    /// ZipEntryData实体是std::vector<uint8_t>的别名。
    /// 这用作任何类型的文件数据的通用容器，包括字符串和二进制文件。
    /// 也可以使用字符向量或字符数组，但字节向量更清楚地表明它可以用于非文本数据。
    using ZipEntryData = std::vector<uint8_t>;

    class ZipEntryImpl;
    class ZipArchiveImpl;
}

#endif  // CORE_TOOLS_TEXT_PARSING_SIMPLE_ZIP_INTERNAL_FWD_H