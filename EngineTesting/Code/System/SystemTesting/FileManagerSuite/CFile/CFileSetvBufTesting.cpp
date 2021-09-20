///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.3 (2021/05/18 15:40)

#include "CFileSetvBufTesting.h"
#include "System/FileManager/CFile.h"
#include "System/FileManager/Flags/CFileFlags.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Base/Version.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

System::CFileSetvBufTesting::CFileSetvBufTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, CFileSetvBufTesting)

void System::CFileSetvBufTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::CFileSetvBufTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SetvBufTest);
}

void System::CFileSetvBufTesting::SetvBufTest()
{
    const auto cFileName = SYSTEM_FILE_TEXT("Resource/CFileTesting/CFileTestingText.txt"s);

    FILE* file{ nullptr };
    ASSERT_TRUE(OpenCFile(file, cFileName, SYSTEM_FILE_TEXT("r"s)));
    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(file, "打开文件失败。"s);

    ASSERT_TRUE(SetvBuf(file, FileSetvBuf::IOFBF, 512));
    ASSERT_TRUE(CloseCFile(file));
}
