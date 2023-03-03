///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.3 (2023/03/03 09:13)

#include "IFStreamManagerTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/FileManager/DeleteFileTools.h"
#include "CoreTools/FileManager/FileManager.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

System::String CoreTools::IFStreamManagerTesting::GetIFStreamFileName()
{
    return SYSTEM_TEXT("Resource/StreamManagerTesting/IFStreamManagerTest.txt"s);
}

System::String CoreTools::IFStreamManagerTesting::GetIFStreamFileContent()
{
    return SYSTEM_TEXT("IFStreamManagerTest test text"s);
}

CoreTools::IFStreamManagerTesting::IFStreamManagerTesting(const OStreamShared& stream)
    : ParentType{ stream }, backupFile{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, IFStreamManagerTesting)

void CoreTools::IFStreamManagerTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::IFStreamManagerTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(IFStreamManagerSucceedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(IFStreamManagerBackupFileTest);
    ASSERT_NOT_THROW_EXCEPTION_0(IFStreamManagerDeleteBackupFileTest);

    // �ļ���ɾ���������Ҳ���
    ASSERT_THROW_EXCEPTION_0(IFStreamManagerBackupFileTest);
}

void CoreTools::IFStreamManagerTesting::IFStreamManagerSucceedTest()
{
    const auto ifStreamFileContent = GetIFStreamFileContent();
    IFStreamManager manager{ GetIFStreamFileName() };
    manager.SetSimplifiedChinese();

    // ��������
    backupFile = manager.BackupFile();
    backupFile = manager.BackupFile();

    // ��������
    ASSERT_EQUAL(manager.GetFileContent(), ifStreamFileContent);
    ASSERT_EQUAL(manager.GetFileContent(), ifStreamFileContent);
}

void CoreTools::IFStreamManagerTesting::IFStreamManagerBackupFileTest()
{
    IFStreamManager backupManager{ backupFile };
    backupManager.SetSimplifiedChinese();

    const auto ifStreamFileContent = GetIFStreamFileContent();
    ASSERT_EQUAL(backupManager.GetFileContent(), ifStreamFileContent + ifStreamFileContent);
}

void CoreTools::IFStreamManagerTesting::IFStreamManagerDeleteBackupFileTest()
{
    DeleteFileTools deleteFileTools{ backupFile };
}
