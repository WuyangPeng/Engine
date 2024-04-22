/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/07 16:22)

#include "CoreTools/CoreToolsExport.h"

#include "ZipArchive.h"
#include "System/Helper/PragmaWarning/Miniz.h"
#include "System/Helper/Tools.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/TextParsing/SimpleZip/Detail/ZipArchiveImpl.h"
#include "CoreTools/TextParsing/SimpleZip/Detail/ZipEntryImpl.h"
#include "CoreTools/TextParsing/SimpleZip/ZipEntry.h"

CoreTools::SimpleZip::ZipArchive::ZipArchive(const std::string& fileName)
    : impl{ fileName }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::SimpleZip::ZipArchive::ZipArchive(const std::string& fileName, bool isCreate)
    : impl{ fileName, isCreate }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::SimpleZip::ZipArchive CoreTools::SimpleZip::ZipArchive::Create()
{
    return ZipArchive{ DisableNotThrow::Disable };
}

CoreTools::SimpleZip::ZipArchive::ZipArchive(DisableNotThrow disableNotThrow)
    : impl{ ImplCreateUseDefaultConstruction::Default }
{
    System::UnusedFunction(disableNotThrow);

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools::SimpleZip, ZipArchive)

void CoreTools::SimpleZip::ZipArchive::Save(const std::string& path)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->Save(path);
}

void CoreTools::SimpleZip::ZipArchive::DeleteEntry(const std::string& entryName)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->DeleteEntry(entryName);
}

bool CoreTools::SimpleZip::ZipArchive::HasEntry(const std::string& entryName)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->HasEntry(entryName);
}

void CoreTools::SimpleZip::ZipArchive::AddEntry(const std::string& name, const std::string& data)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    impl->AddEntry(name, data);
}

std::string CoreTools::SimpleZip::ZipArchive::GetEntry(const std::string& name)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->GetEntry(name).GetDataAsString();
}
