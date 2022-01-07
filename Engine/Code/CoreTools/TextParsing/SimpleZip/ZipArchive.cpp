///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 22:36)

#include "CoreTools/CoreToolsExport.h"

#include "ZipArchive.h"
#include "System/Helper/PragmaWarning/Miniz.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/TextParsing/SimpleZip/Detail/ZipArchiveImpl.h"
#include "CoreTools/TextParsing/SimpleZip/Detail/ZipEntryImpl.h"
#include "CoreTools/TextParsing/SimpleZip/ZipEntry.h"

using std::string;

CoreTools::SimpleZip::ZipArchive::ZipArchive(const string& fileName)
    : impl{ fileName }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::SimpleZip::ZipArchive::ZipArchive(const string& fileName, bool isCreate)
    : impl{ fileName, isCreate }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::SimpleZip::ZipArchive::ZipArchive(MAYBE_UNUSED DisableNotThrow disableNotThrow)
    : impl{ ImplCreateUseDefaultConstruction::Default }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools::SimpleZip, ZipArchive)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools::SimpleZip, ZipArchive, Save, string, void)

void CoreTools::SimpleZip::ZipArchive::AddEntry(const string& name, const string& data)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    impl->AddEntry(name, data);
}

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools::SimpleZip, ZipArchive, DeleteEntry, string, void)

string CoreTools::SimpleZip::ZipArchive::GetEntry(const string& name)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->GetEntry(name).GetDataAsString();
}

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools::SimpleZip, ZipArchive, HasEntry, string, bool)
