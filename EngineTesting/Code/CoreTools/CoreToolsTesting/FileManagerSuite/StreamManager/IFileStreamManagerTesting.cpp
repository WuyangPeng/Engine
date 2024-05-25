/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/05/03 23:21)

#include "IFileStreamManagerTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/FileManager/DeleteFileTools.h"
#include "CoreTools/FileManager/FileManager.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::IFileStreamManagerTesting::IFileStreamManagerTesting(const OStreamShared& stream)
    : ParentType{ stream }, backupFile{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, IFileStreamManagerTesting)

void CoreTools::IFileStreamManagerTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::IFileStreamManagerTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(IFileStreamManagerSucceedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(IFileStreamManagerBackupFileTest);
    ASSERT_NOT_THROW_EXCEPTION_0(IFileStreamManagerDeleteBackupFileTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SeparateTest);

    /// 文件已删除，测试找不到
    ASSERT_THROW_EXCEPTION_0(IFileStreamManagerBackupFileTest);
}

System::String CoreTools::IFileStreamManagerTesting::GetIFileStreamFileName()
{
    return SYSTEM_TEXT("Resource/StreamManagerTesting/IFileStreamManagerTest.txt");
}

System::String CoreTools::IFileStreamManagerTesting::GetIFileStreamFileContent()
{
    return SYSTEM_TEXT("IFileStreamManagerTest test text");
}

void CoreTools::IFileStreamManagerTesting::IFileStreamManagerSucceedTest()
{
    const auto fileStreamFileContent = GetIFileStreamFileContent();

    IFileStreamManager manager{ GetIFileStreamFileName() };
    manager.SetSimplifiedChinese();

    ASSERT_NOT_THROW_EXCEPTION_2(BackupFileTest, fileStreamFileContent, manager);

    ASSERT_NOT_THROW_EXCEPTION_1(StreamTest, manager);
}

void CoreTools::IFileStreamManagerTesting::BackupFileTest(const String& fileStreamFileContent, const IFileStreamManager& manager)
{
    /// 备份两次
    backupFile = manager.BackupFile();
    backupFile = manager.BackupFile();

    /// 测试两次
    ASSERT_EQUAL(manager.GetFileContent(), fileStreamFileContent);
    ASSERT_EQUAL(manager.GetFileContent(), fileStreamFileContent);
}

void CoreTools::IFileStreamManagerTesting::StreamTest(IFileStreamManager& manager)
{
    String result{};
    manager.GetFileStream() >> result;

    ASSERT_EQUAL(result, SYSTEM_TEXT("IFileStreamManagerTest"));
}

void CoreTools::IFileStreamManagerTesting::IFileStreamManagerBackupFileTest()
{
    IFileStreamManager backupManager{ backupFile };
    backupManager.SetSimplifiedChinese();

    const auto content = GetIFileStreamFileContent();
    ASSERT_EQUAL(backupManager.GetFileContent(), content + content);
}

void CoreTools::IFileStreamManagerTesting::IFileStreamManagerDeleteBackupFileTest()
{
    DeleteFileTools deleteFileTools{ backupFile };
}

void CoreTools::IFileStreamManagerTesting::SeparateTest()
{
    IFileStreamManager manager{ GetIFileStreamFileName() };
    manager.SetSimplifiedChinese();

    const auto fileContent = manager.GetFileContent(SYSTEM_TEXT(" "));

    ASSERT_EQUAL(fileContent.at(0), SYSTEM_TEXT("IFileStreamManagerTest"));
    ASSERT_EQUAL(fileContent.at(1), SYSTEM_TEXT("test"));
    ASSERT_EQUAL(fileContent.at(2), SYSTEM_TEXT("text"));
}
