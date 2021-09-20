// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎测试版本：0.0.2.3 (2020/03/05 15:46)

#include "StreamManagerTesting.h"
#include "CoreTools/FileManager/DeleteFileTools.h"
#include "CoreTools/FileManager/FileManager.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

#include "System/Helper/PragmaWarning/NumericCast.h"

using std::ostream;
using namespace std::literals;
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
const System::String CoreTools::StreamManagerTesting ::sm_IFStreamFileName(SYSTEM_TEXT("Resource/StreamManagerTesting/IFStreamManagerTest.txt"s));

const System::String CoreTools::StreamManagerTesting ::sm_IFStreamFileContent(SYSTEM_TEXT("IFStreamManagerTest test text"s));

const System::String CoreTools::StreamManagerTesting ::sm_OFStreamFileName(SYSTEM_TEXT("Resource/StreamManagerTesting/OFStreamManagerTest.txt"s));

const System::String CoreTools::StreamManagerTesting ::sm_OFStreamFileContent(SYSTEM_TEXT("OFStreamManagerTest test text"s));
#include STSTEM_WARNING_POP
CoreTools::StreamManagerTesting ::StreamManagerTesting(const OStreamShared& osPtr)
    : ParentType{ osPtr }, m_BackupFile{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, StreamManagerTesting)
void CoreTools::StreamManagerTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::StreamManagerTesting ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(IFStreamManageTest);
    ASSERT_NOT_THROW_EXCEPTION_0(OFStreamManageTest);
}

// IFStreamManage测试
void CoreTools::StreamManagerTesting ::IFStreamManageTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(IFStreamManageSucceedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(IFStreamManageBackupFileTest);
    ASSERT_NOT_THROW_EXCEPTION_0(IFStreamManageDeleteBackupFileTest);

    // 文件已删除，测试找不到
    ASSERT_THROW_EXCEPTION_0(IFStreamManageBackupFileTest);
}

void CoreTools::StreamManagerTesting ::IFStreamManageSucceedTest()
{
    IFStreamManager manager{ sm_IFStreamFileName };
    manager.SetSimplifiedChinese();

    // 备份两次
    m_BackupFile = manager.BackupFile();
    [[maybe_unused]] auto value = manager.BackupFile();

    // 测试两次
    ASSERT_EQUAL(manager.GetFileContent(), sm_IFStreamFileContent);
    ASSERT_EQUAL(manager.GetFileContent(), sm_IFStreamFileContent);
}

void CoreTools::StreamManagerTesting ::IFStreamManageBackupFileTest()
{
    IFStreamManager backupManage{ m_BackupFile };
    backupManage.SetSimplifiedChinese();

    ASSERT_EQUAL(backupManage.GetFileContent(), sm_IFStreamFileContent + sm_IFStreamFileContent);
}

void CoreTools::StreamManagerTesting ::IFStreamManageDeleteBackupFileTest()
{
    CoreTools::DeleteFileTools deleteFileTools{ m_BackupFile };
}

// OFStreamManage测试
void CoreTools::StreamManagerTesting ::OFStreamManageTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(OFStreamManageMessageTest);
    ASSERT_NOT_THROW_EXCEPTION_0(OFStreamManageSizeTest);
}

void CoreTools::StreamManagerTesting ::OFStreamManageMessageTest()
{
    OFStreamManager manager{ sm_OFStreamFileName, false };

    manager.SetSimplifiedChinese();
    manager << sm_OFStreamFileContent;
}

void CoreTools::StreamManagerTesting ::OFStreamManageSizeTest()
{
    OFStreamManager manager{ sm_OFStreamFileName, true };

    manager.SetSimplifiedChinese();
    auto fileSize = manager.GetOFStreamSize();
    const auto contentSize = sm_OFStreamFileContent.size();

    ASSERT_EQUAL(fileSize, boost::numeric_cast<int>(contentSize));

    manager << SYSTEM_TEXT(" ") << sm_OFStreamFileContent;
    fileSize = manager.GetOFStreamSize();

    ASSERT_EQUAL(fileSize, boost::numeric_cast<int>(contentSize) * 2 + 1);
}
