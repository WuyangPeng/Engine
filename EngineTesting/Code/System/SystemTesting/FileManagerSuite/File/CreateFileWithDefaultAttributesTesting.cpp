///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.3 (2021/05/21 10:41)

#include "CreateFileWithDefaultAttributesTesting.h"
#include "System/FileManager/File.h"
#include "System/FileManager/Flags/FileFlags.h"
#include "System/Time/DeltaTime.h"
#include "System/Windows/Engineering.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/TemplateTools/MaxElement.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

System::CreateFileWithDefaultAttributesTesting::CreateFileWithDefaultAttributesTesting(const OStreamShared& stream)
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
      randomEngine{ GetEngineRandomSeed() },
      maxSize{ CoreTools::MaxElement<size_t>({ fileHandleDesiredAccessFlags.size(), fileHandleShareModeFlags.size(), fileHandleCreationDispositionFlags.size() }) }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, CreateFileWithDefaultAttributesTesting)

void System::CreateFileWithDefaultAttributesTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::CreateFileWithDefaultAttributesTesting::MainTest()
{
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(RandomShuffleFlags);
}

bool System::CreateFileWithDefaultAttributesTesting::RandomShuffleFlags()
{
    shuffle(fileHandleDesiredAccessFlags.begin(), fileHandleDesiredAccessFlags.end(), randomEngine);
    shuffle(fileHandleShareModeFlags.begin(), fileHandleShareModeFlags.end(), randomEngine);
    shuffle(fileHandleCreationDispositionFlags.begin(), fileHandleCreationDispositionFlags.end(), randomEngine);

    ASSERT_NOT_THROW_EXCEPTION_0(CreateFileTest);

    return true;
}

void System::CreateFileWithDefaultAttributesTesting::CreateFileTest()
{
    const auto extendName = SYSTEM_TEXT(".txt"s);
    const auto fileNamePrefix = SYSTEM_TEXT("Resource/FileTesting/CreateFile"s);
    const auto newFileName = fileNamePrefix + System::ToString(GetTimeInSeconds()) + GetEngineeringTypesSuffix();
    const auto existingFileName = SYSTEM_TEXT("Resource/FileTesting/CreateExistingFile.txt"s);

    for (auto index = 0u; index < maxSize; ++index)
    {
        auto fileHandleDesiredAccess = fileHandleDesiredAccessFlags.at(index % fileHandleDesiredAccessFlags.size());
        auto fileHandleShareMode = fileHandleShareModeFlags.at(index % fileHandleShareModeFlags.size());
        auto fileHandleCreationDisposition = fileHandleCreationDispositionFlags.at(index % fileHandleCreationDispositionFlags.size());

        auto createFileName = existingFileName;

        if (fileHandleCreationDisposition != FileHandleCreationDisposition::OpenExisting &&
            fileHandleCreationDisposition != FileHandleCreationDisposition::TruncateExisting)
        {
            createFileName = newFileName + ToString(index) + extendName;
        }

        if (fileHandleCreationDisposition == FileHandleCreationDisposition::TruncateExisting)
        {
            fileHandleDesiredAccess |= FileHandleDesiredAccess::Write;
        }

        auto fileHandle = CreateSystemFile(createFileName, fileHandleDesiredAccess, fileHandleShareMode, fileHandleCreationDisposition);

        ASSERT_TRUE(IsFileHandleValid(fileHandle));
        ASSERT_TRUE(CloseSystemFile(fileHandle));

        if (fileHandleCreationDisposition != FileHandleCreationDisposition::OpenExisting &&
            fileHandleCreationDisposition != FileHandleCreationDisposition::TruncateExisting)
        {
            ASSERT_TRUE(RemoveSystemFile(createFileName));
        }
    }
}
