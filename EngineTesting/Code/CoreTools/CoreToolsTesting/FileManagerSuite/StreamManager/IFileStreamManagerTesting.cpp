/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/16 17:08)

#include "IFileStreamManagerTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/FileManager/DeleteFileTools.h"
#include "CoreTools/FileManager/FileManager.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::String CoreTools::IFileStreamManagerTesting::GetIFileStreamFileName()
{
    return SYSTEM_TEXT("Resource/StreamManagerTesting/IFileStreamManagerTest.txt");
}

System::String CoreTools::IFileStreamManagerTesting::GetIFileStreamFileContent()
{
    return SYSTEM_TEXT("IFileStreamManagerTest test text");
}

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

    /// �ļ���ɾ���������Ҳ���
    ASSERT_THROW_EXCEPTION_0(IFileStreamManagerBackupFileTest);
}

void CoreTools::IFileStreamManagerTesting::IFileStreamManagerSucceedTest()
{
    const auto ifStreamFileContent = GetIFileStreamFileContent();
    IFileStreamManager manager{ GetIFileStreamFileName() };
    manager.SetSimplifiedChinese();

    /// ��������
    backupFile = manager.BackupFile();
    backupFile = manager.BackupFile();

    /// ��������
    ASSERT_EQUAL(manager.GetFileContent(), ifStreamFileContent);
    ASSERT_EQUAL(manager.GetFileContent(), ifStreamFileContent);

    String result{};
    manager.GetFileStream() >> result;

    ASSERT_EQUAL(result, SYSTEM_TEXT("IFileStreamManagerTest"));
}

void CoreTools::IFileStreamManagerTesting::IFileStreamManagerBackupFileTest()
{
    IFileStreamManager backupManager{ backupFile };
    backupManager.SetSimplifiedChinese();

    const auto ifStreamFileContent = GetIFileStreamFileContent();
    ASSERT_EQUAL(backupManager.GetFileContent(), ifStreamFileContent + ifStreamFileContent);
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
