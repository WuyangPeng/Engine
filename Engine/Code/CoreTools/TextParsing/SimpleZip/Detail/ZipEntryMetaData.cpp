///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/04/04 15:03)

#include "CoreTools/CoreToolsExport.h"

#include "ZipEntryMetaData.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::SimpleZip::ZipEntryMetaData::ZipEntryMetaData(const ZipEntryInfo& info)
    : index{ info.m_file_index },
      compressedSize{ info.m_comp_size },
      uncompressedSize{ info.m_uncomp_size },
      isDirectory{ info.m_is_directory != 0 },
      isEncrypted{ info.m_is_encrypted != 0 },
      isSupported{ info.m_is_supported != 0 },
      fileName{ info.m_filename },
      comment{ info.m_comment },
      time{ info.m_time }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools::SimpleZip, ZipEntryMetaData)

uint32_t CoreTools::SimpleZip::ZipEntryMetaData::GetIndex() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return index;
}

uint64_t CoreTools::SimpleZip::ZipEntryMetaData::GetCompressedSize() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return compressedSize;
}

uint64_t CoreTools::SimpleZip::ZipEntryMetaData::GetUncompressedSize() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return uncompressedSize;
}

bool CoreTools::SimpleZip::ZipEntryMetaData::IsDirectory() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return isDirectory;
}

bool CoreTools::SimpleZip::ZipEntryMetaData::IsEncrypted() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return isEncrypted;
}

bool CoreTools::SimpleZip::ZipEntryMetaData::IsSupported() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return isSupported;
}

std::string CoreTools::SimpleZip::ZipEntryMetaData::GetFileName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return fileName;
}

std::string CoreTools::SimpleZip::ZipEntryMetaData::GetComment() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return comment;
}

time_t CoreTools::SimpleZip::ZipEntryMetaData::GetTime() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return time;
}
