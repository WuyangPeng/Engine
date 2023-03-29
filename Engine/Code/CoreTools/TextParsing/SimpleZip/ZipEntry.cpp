///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/06 14:16)

#include "CoreTools/CoreToolsExport.h"

#include "ZipEntry.h"
#include "Detail/ZipEntryImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

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

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools::SimpleZip, ZipEntry, GetEntryData, CoreTools::SimpleZip::ZipEntryData)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools::SimpleZip, ZipEntry, GetDataAsString, std::string)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools::SimpleZip, ZipEntry, SetData, std::string, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools::SimpleZip, ZipEntry, SetData, ZipEntryData, void)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools::SimpleZip, ZipEntry, GetIndex, uint32_t)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools::SimpleZip, ZipEntry, GetCompressedSize, uint64_t)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools::SimpleZip, ZipEntry, GetUncompressedSize, uint64_t)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools::SimpleZip, ZipEntry, IsDirectory, bool)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools::SimpleZip, ZipEntry, IsEncrypted, bool)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools::SimpleZip, ZipEntry, IsSupported, bool)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools::SimpleZip, ZipEntry, GetComment, std::string)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools::SimpleZip, ZipEntry, GetTime, time_t)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools::SimpleZip, ZipEntry, IsModified, bool)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools::SimpleZip, ZipEntry, GetFileName, std::string)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools::SimpleZip, ZipEntry, SetFileName, std::string, void)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools::SimpleZip, ZipEntry, GetZipEntryInfo, CoreTools::SimpleZip::ZipEntryInfo)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools::SimpleZip, ZipEntry, GetEntrySize, size_t)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools::SimpleZip, ZipEntry, IsEntryDataEmpty, bool)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(CoreTools::SimpleZip, ZipEntry, ResizeZipEntryData, int, void)

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
