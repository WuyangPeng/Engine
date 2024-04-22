/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/07 16:22)

#include "CoreTools/CoreToolsExport.h"

#include "ZipEntry.h"
#include "Detail/ZipEntryImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(CoreTools::SimpleZip, ZipEntry)

CoreTools::SimpleZip::ZipEntry::ZipEntry(const ZipEntryInfo& info)
    : impl{ info }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::SimpleZip::ZipEntry::ZipEntry(const std::string& name, const ZipEntryData& data)
    : impl{ name, data }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::SimpleZip::ZipEntry::ZipEntry(const std::string& name, const std::string& data)
    : impl{ name, data }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools::SimpleZip, ZipEntry)

CoreTools::SimpleZip::ZipEntryData CoreTools::SimpleZip::ZipEntry::GetEntryData() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetEntryData();
}

size_t CoreTools::SimpleZip::ZipEntry::GetEntrySize() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetEntrySize();
}

bool CoreTools::SimpleZip::ZipEntry::IsEntryDataEmpty() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->IsEntryDataEmpty();
}

std::string CoreTools::SimpleZip::ZipEntry::GetDataAsString() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetDataAsString();
}

void CoreTools::SimpleZip::ZipEntry::SetData(const std::string& data)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->SetData(data);
}

void CoreTools::SimpleZip::ZipEntry::SetData(const ZipEntryData& data)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->SetData(data);
}

std::string CoreTools::SimpleZip::ZipEntry::GetFileName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetFileName();
}

void CoreTools::SimpleZip::ZipEntry::SetFileName(const std::string& name)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->SetFileName(name);
}

uint32_t CoreTools::SimpleZip::ZipEntry::GetIndex() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetIndex();
}

uint64_t CoreTools::SimpleZip::ZipEntry::GetCompressedSize() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetCompressedSize();
}

uint64_t CoreTools::SimpleZip::ZipEntry::GetUncompressedSize() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetUncompressedSize();
}

bool CoreTools::SimpleZip::ZipEntry::IsDirectory() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->IsDirectory();
}

bool CoreTools::SimpleZip::ZipEntry::IsEncrypted() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->IsEncrypted();
}

bool CoreTools::SimpleZip::ZipEntry::IsSupported() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->IsSupported();
}

std::string CoreTools::SimpleZip::ZipEntry::GetComment() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetComment();
}

time_t CoreTools::SimpleZip::ZipEntry::GetTime() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetTime();
}

CoreTools::SimpleZip::ZipEntryInfo CoreTools::SimpleZip::ZipEntry::GetZipEntryInfo() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetZipEntryInfo();
}

void CoreTools::SimpleZip::ZipEntry::ResizeZipEntryData(int uncompressedSize)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->ResizeZipEntryData(uncompressedSize);
}

bool CoreTools::SimpleZip::ZipEntry::IsModified() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->IsModified();
}

void CoreTools::SimpleZip::ZipEntry::ReaderExtractFileToMem(mz_zip_archive* archive, const std::string& name)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->ReaderExtractFileToMem(archive, name);
}

bool CoreTools::SimpleZip::ZipEntry::WriterAddMem(mz_zip_archive* archive) const
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->WriterAddMem(archive);
}
