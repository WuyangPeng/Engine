///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.5 (2022/12/12 16:10)

#include "CFileTestingBase.h"
#include "System/FileManager/CFile.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Base/Version.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <vector>

using namespace std::literals;

System::CFileTestingBase::CFileTestingBase(const OStreamShared& stream)
    : ParentType{ stream },
      cFileContent{ CoreTools::Version::GetVersion() },
      fileName{ SYSTEM_FILE_TEXT("Resource/CFileTesting/CFileTestingText.txt"s) },
      originalBuffer{ cFileContent.begin(), cFileContent.end() }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, CFileTestingBase)

FILE* System::CFileTestingBase::OpenFile(const CFileString& mode)
{
    SYSTEM_CLASS_IS_VALID_9;

    FILE* file{ nullptr };
    ASSERT_TRUE(OpenCFile(file, GetFileName(), mode));
    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(file, "打开文件失败。"s);

    return file;
}

void System::CFileTestingBase::CloseFile(FILE* file)
{
    SYSTEM_CLASS_IS_VALID_9;

    ASSERT_TRUE(CloseCFile(file));
}

System::CFileString System::CFileTestingBase::GetFileName() const
{
    SYSTEM_CLASS_IS_VALID_CONST_9;

    return fileName;
}

void System::CFileTestingBase::FileContentSizeEqualTest(size_t length)
{
    SYSTEM_CLASS_IS_VALID_9;

    ASSERT_EQUAL(length, cFileContent.size());
}

void System::CFileTestingBase::OriginalBufferEqualTest(const BufferType& buffer)
{
    SYSTEM_CLASS_IS_VALID_9;

    ASSERT_EQUAL(buffer, originalBuffer);
}

size_t System::CFileTestingBase::WriteFile(FILE* file) noexcept
{
    SYSTEM_CLASS_IS_VALID_9;

    return WriteCFile(originalBuffer.data(), 1, originalBuffer.size(), file);
}

std::string System::CFileTestingBase::GetFileContent() const
{
    SYSTEM_CLASS_IS_VALID_CONST_9;

    return cFileContent;
}
