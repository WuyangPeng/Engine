///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/15 12:24)

#include "CreateFileWithAttributesTesting.h"
#include "System/FileManager/File.h"
#include "System/FileManager/Flags/FileFlags.h"
#include "System/Time/DeltaTime.h"
#include "System/Windows/Engineering.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/TemplateTools/MaxElement.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

System::CreateFileWithAttributesTesting::CreateFileWithAttributesTesting(const OStreamShared& stream)
    : ParentType{ stream },
      // FileHandleDesiredAccess::All需要管理员身份运行。
      fileHandleDesiredAccessFlags{ FileHandleDesiredAccess::Read,
                                    FileHandleDesiredAccess::Write,
                                    FileHandleDesiredAccess::Execute,
                                    FileHandleDesiredAccess::ReadWrite },
      fileHandleShareModeFlags{ FileHandleShareMode::Prevents,
                                FileHandleShareMode::ShareDelete,
                                FileHandleShareMode::ShareRead,
                                FileHandleShareMode::ShareWrite,
                                FileHandleShareMode::ReadWrite },
      fileHandleCreationDispositionFlags{ FileHandleCreationDisposition::CreateNew,
                                          FileHandleCreationDisposition::CreateAlways,
                                          FileHandleCreationDisposition::OpenExisting,
                                          FileHandleCreationDisposition::OpenAlways,
                                          FileHandleCreationDisposition::TruncateExisting },
      fileHandleAttributesFlags{ FileHandleAttributes::ReadOnly,
                                 FileHandleAttributes::Hidden,
                                 FileHandleAttributes::System,
                                 FileHandleAttributes::Archive,
                                 FileHandleAttributes::Device,
                                 FileHandleAttributes::Normal,
                                 FileHandleAttributes::Temporary,
                                 FileHandleAttributes::Offline,
                                 FileHandleAttributes::Encrypted },
      fileHandleOtherFlags{ FileHandleOther::Default,
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
      fileHandleSecurityFlags{ FileHandleSecurity::Default,
                               FileHandleSecurity::Anonymous,
                               FileHandleSecurity::Identification,
                               FileHandleSecurity::Impersonation,
                               FileHandleSecurity::Delegation,
                               FileHandleSecurity::ContextTracking,
                               FileHandleSecurity::EffectiveOnly,
                               FileHandleSecurity::SqosPresent,
                               FileHandleSecurity::ValidSqosFlags },
      randomEngine{ GetEngineRandomSeed() },
      maxSize{ CoreTools::MaxElement<size_t>({ fileHandleDesiredAccessFlags.size(),
                                               fileHandleShareModeFlags.size(),
                                               fileHandleCreationDispositionFlags.size(),
                                               fileHandleAttributesFlags.size(),
                                               fileHandleOtherFlags.size(),
                                               fileHandleSecurityFlags.size() }) }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, CreateFileWithAttributesTesting)

void System::CreateFileWithAttributesTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::CreateFileWithAttributesTesting::MainTest()
{
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(RandomShuffleFlags);
}

bool System::CreateFileWithAttributesTesting::RandomShuffleFlags()
{
    shuffle(fileHandleDesiredAccessFlags.begin(), fileHandleDesiredAccessFlags.end(), randomEngine);
    shuffle(fileHandleShareModeFlags.begin(), fileHandleShareModeFlags.end(), randomEngine);
    shuffle(fileHandleCreationDispositionFlags.begin(), fileHandleCreationDispositionFlags.end(), randomEngine);
    shuffle(fileHandleOtherFlags.begin(), fileHandleOtherFlags.end(), randomEngine);
    shuffle(fileHandleSecurityFlags.begin(), fileHandleSecurityFlags.end(), randomEngine);
    shuffle(fileHandleAttributesFlags.begin(), fileHandleAttributesFlags.end(), randomEngine);

    ASSERT_NOT_THROW_EXCEPTION_0(CreateFileTest);

    return true;
}

void System::CreateFileWithAttributesTesting::CreateFileTest()
{
    const auto extendName = SYSTEM_TEXT(".txt"s);
    const auto fileNamePrefix = SYSTEM_TEXT("Resource/FileTesting/CreateFile"s);
    const auto newFileName = fileNamePrefix + System::ToString(GetTimeInSeconds()) + GetEngineeringTypesSuffix();
    const auto existingFileName = SYSTEM_TEXT("Resource/FileTesting/CreateOnlyReadFile.txt"s);

    for (auto index = 0u; index < maxSize; ++index)
    {
        auto fileHandleDesiredAccess = fileHandleDesiredAccessFlags.at(index % fileHandleDesiredAccessFlags.size());
        auto fileHandleShareMode = fileHandleShareModeFlags.at(index % fileHandleShareModeFlags.size());
        auto fileHandleCreationDisposition = fileHandleCreationDispositionFlags.at(index % fileHandleCreationDispositionFlags.size());
        auto fileHandleOther = fileHandleOtherFlags.at(index % fileHandleOtherFlags.size());
        auto fileHandleAttributesFlag = fileHandleAttributesFlags.at(index % fileHandleAttributesFlags.size());
        auto fileHandleSecurityFlag = fileHandleSecurityFlags.at(index % fileHandleSecurityFlags.size());

        auto createFileName = existingFileName;

        if (fileHandleAttributesFlag == FileHandleAttributes::ReadOnly)
        {
            fileHandleDesiredAccess = FileHandleDesiredAccess::Read;
            fileHandleShareMode = FileHandleShareMode::ShareRead;
            fileHandleCreationDisposition = FileHandleCreationDisposition::OpenAlways;
            fileHandleOther = FileHandleOther::SequentialScan;
            fileHandleSecurityFlag = FileHandleSecurity::Default;
        }
        else if (fileHandleCreationDisposition != FileHandleCreationDisposition::OpenExisting &&
                 fileHandleCreationDisposition != FileHandleCreationDisposition::TruncateExisting)
        {
            createFileName = newFileName + ToString(index) + extendName;
        }

        if (fileHandleCreationDisposition == FileHandleCreationDisposition::CreateNew ||
            fileHandleOther == FileHandleOther::DeleteOnClose)
        {
            fileHandleCreationDisposition = FileHandleCreationDisposition::CreateNew;

            createFileName = newFileName + ToString(index) + extendName;
        }

        if (fileHandleCreationDisposition == FileHandleCreationDisposition::TruncateExisting)
        {
            fileHandleDesiredAccess |= FileHandleDesiredAccess::Write;
        }

        auto fileHandle = CreateSystemFile(createFileName,
                                           fileHandleDesiredAccess,
                                           fileHandleShareMode,
                                           nullptr,
                                           fileHandleCreationDisposition,
                                           fileHandleAttributesFlag,
                                           fileHandleOther,
                                           fileHandleSecurityFlag,
                                           nullptr);

        ASSERT_TRUE(IsFileHandleValid(fileHandle));
        ASSERT_TRUE(CloseSystemFile(fileHandle));

        if (createFileName != existingFileName && fileHandleOther != FileHandleOther::DeleteOnClose)
        {
            ASSERT_TRUE(RemoveSystemFile(createFileName));
        }
    }
}
