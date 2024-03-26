/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 11:25)

#include "CreateFileWithAttributesTestingBase.h"
#include "System/FileManager/Flags/FileFlags.h"
#include "System/Time/DeltaTime.h"
#include "System/Windows/Engineering.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/TemplateTools/MaxElement.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

System::CreateFileWithAttributesTestingBase::CreateFileWithAttributesTestingBase(const OStreamShared& stream)
    : ParentType{ stream },
      /// FileHandleDesiredAccess::All需要管理员身份运行。
      fileHandleDesiredAccesses{ FileHandleDesiredAccess::Read,
                                 FileHandleDesiredAccess::Write,
                                 FileHandleDesiredAccess::Execute,
                                 FileHandleDesiredAccess::ReadWrite },
      fileHandleShareModes{ FileHandleShareMode::Prevents,
                            FileHandleShareMode::ShareDelete,
                            FileHandleShareMode::ShareRead,
                            FileHandleShareMode::ShareWrite,
                            FileHandleShareMode::ReadWrite },
      fileHandleCreationDispositions{ FileHandleCreationDisposition::CreateNew,
                                      FileHandleCreationDisposition::CreateAlways,
                                      FileHandleCreationDisposition::OpenExisting,
                                      FileHandleCreationDisposition::OpenAlways,
                                      FileHandleCreationDisposition::TruncateExisting },
      fileHandleAttributes{ FileHandleAttribute::ReadOnly,
                            FileHandleAttribute::Hidden,
                            FileHandleAttribute::System,
                            FileHandleAttribute::Archive,
                            FileHandleAttribute::Device,
                            FileHandleAttribute::Normal,
                            FileHandleAttribute::Temporary,
                            FileHandleAttribute::Offline,
                            FileHandleAttribute::Encrypted,
                            FileHandleAttribute::IntegrityStream,
                            FileHandleAttribute::Virtual,
                            FileHandleAttribute::NoScrubData,
                            FileHandleAttribute::Ea,
                            FileHandleAttribute::Pinned,
                            FileHandleAttribute::Unpinned,
                            FileHandleAttribute::RecallOnOpen,
                            FileHandleAttribute::RecallOnDataAccess },
      fileHandleOthers{ FileHandleOther::Default,
                        FileHandleOther::WriteThrough,
                        FileHandleOther::Overlapped,
                        FileHandleOther::NoBuffering,
                        FileHandleOther::RandomAccess,
                        FileHandleOther::SequentialScan,
                        FileHandleOther::DeleteOnClose,
                        FileHandleOther::BackupSemantics,
                        FileHandleOther::PosixSemantics,
                        FileHandleOther::OpenReparsePoint,
                        FileHandleOther::OpenNoRecall,
                        FileHandleOther::FirstPipeInstance },
      fileHandleSecurities{ FileHandleSecurity::Default,
                            FileHandleSecurity::Anonymous,
                            FileHandleSecurity::Identification,
                            FileHandleSecurity::Impersonation,
                            FileHandleSecurity::Delegation,
                            FileHandleSecurity::ContextTracking,
                            FileHandleSecurity::EffectiveOnly,
                            FileHandleSecurity::SecurityQualityOfServicePresent,
                            FileHandleSecurity::ValidSecurityQualityOfServiceFlags },
      randomEngine{ GetEngineRandomSeed() },
      maxSize{ CoreTools::MaxElement({ fileHandleDesiredAccesses.size(),
                                       fileHandleShareModes.size(),
                                       fileHandleCreationDispositions.size(),
                                       fileHandleAttributes.size(),
                                       fileHandleOthers.size(),
                                       fileHandleSecurities.size() }) },
      extendName{ SYSTEM_TEXT(".txt"s) },
      fileNamePrefix{ SYSTEM_TEXT("Resource/FileTesting/CreateFile"s) }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, CreateFileWithAttributesTestingBase)

void System::CreateFileWithAttributesTestingBase::RandomFileHandleFlags()
{
    SYSTEM_CLASS_IS_VALID_9;

    std::ranges::shuffle(fileHandleDesiredAccesses, randomEngine);
    std::ranges::shuffle(fileHandleShareModes, randomEngine);
    std::ranges::shuffle(fileHandleCreationDispositions, randomEngine);
    std::ranges::shuffle(fileHandleAttributes, randomEngine);
    std::ranges::shuffle(fileHandleOthers, randomEngine);
    std::ranges::shuffle(fileHandleSecurities, randomEngine);
}

System::FileHandleDesiredAccess System::CreateFileWithAttributesTestingBase::GetFileHandleDesiredAccess(size_t index) const
{
    SYSTEM_CLASS_IS_VALID_CONST_9;

    return fileHandleDesiredAccesses.at(index % fileHandleDesiredAccesses.size());
}

System::FileHandleDesiredAccess System::CreateFileWithAttributesTestingBase::GetFileHandleDesiredAccess(size_t index, FileHandleCreationDisposition fileHandleCreationDisposition) const
{
    auto fileHandleDesiredAccess = GetFileHandleDesiredAccess(index);
    if (fileHandleCreationDisposition == FileHandleCreationDisposition::TruncateExisting)
    {
        fileHandleDesiredAccess |= FileHandleDesiredAccess::Write;
    }

    return fileHandleDesiredAccess;
}

System::FileHandleShareMode System::CreateFileWithAttributesTestingBase::GetFileHandleShareMode(size_t index) const
{
    SYSTEM_CLASS_IS_VALID_CONST_9;

    return fileHandleShareModes.at(index % fileHandleShareModes.size());
}

System::FileHandleCreationDisposition System::CreateFileWithAttributesTestingBase::GetFileHandleCreationDisposition(size_t index) const
{
    SYSTEM_CLASS_IS_VALID_CONST_9;

    return fileHandleCreationDispositions.at(index % fileHandleCreationDispositions.size());
}

System::FileHandleAttribute System::CreateFileWithAttributesTestingBase::GetFileHandleAttributes(size_t index) const
{
    SYSTEM_CLASS_IS_VALID_CONST_9;

    return fileHandleAttributes.at(index % fileHandleAttributes.size());
}

System::FileHandleOther System::CreateFileWithAttributesTestingBase::GetFileHandleOther(size_t index) const
{
    SYSTEM_CLASS_IS_VALID_CONST_9;

    return fileHandleOthers.at(index % fileHandleOthers.size());
}

System::FileHandleSecurity System::CreateFileWithAttributesTestingBase::GetFileHandleSecurity(size_t index) const
{
    SYSTEM_CLASS_IS_VALID_CONST_9;

    return fileHandleSecurities.at(index % fileHandleSecurities.size());
}

size_t System::CreateFileWithAttributesTestingBase::GetMaxSize() const noexcept
{
    SYSTEM_CLASS_IS_VALID_CONST_9;

    return maxSize;
}

System::String System::CreateFileWithAttributesTestingBase::GetCreateFileName(size_t index) const
{
    SYSTEM_CLASS_IS_VALID_CONST_9;

    return fileNamePrefix + ToString(GetTimeInSeconds()) + GetEngineeringTypesSuffix() + ToString(index) + extendName;
}
