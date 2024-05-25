/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/05/23 16:58)

#include "FileOutStreamTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Base/Version.h"
#include "CoreTools/FileManager/CFileManagerHelper.h"
#include "CoreTools/FileManager/DeleteFileTools.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/FileInStream.h"
#include "CoreTools/ObjectSystems/FileOutStream.h"
#include "CoreTools/ObjectSystems/NullObject.h"
#include "CoreTools/ObjectSystems/OutTopLevel.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

namespace
{
    const auto gResource = SYSTEM_TEXT("Resource/");
    const auto gFileName = SYSTEM_TEXT("FileOutStream.txt"s);
    const auto gFullFileName = gResource + gFileName;
}

CoreTools::FileOutStreamTesting::FileOutStreamTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, FileOutStreamTesting)

void CoreTools::FileOutStreamTesting::DoRunUnitTest()
{
    InitTerm::ExecuteInitializer();

    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);

    InitTerm::ExecuteTerminator();
}

void CoreTools::FileOutStreamTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SaveFileOutStream);
    ASSERT_NOT_THROW_EXCEPTION_0(WriteNullObjectTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DeleteFileTest);
}

void CoreTools::FileOutStreamTesting::SaveFileOutStream() const
{
    OutTopLevel outTopLevel = OutTopLevel::Create();

    outTopLevel.Insert(Object::GetNullObject());

    FileOutStream fileOutStream{ outTopLevel };

    fileOutStream.Save(gFullFileName);
}

void CoreTools::FileOutStreamTesting::WriteNullObjectTest()
{
    const FileInStream fileInputStream{ gFullFileName };

    const auto inTopLevel = fileInputStream.GetInTopLevel();

    ASSERT_EQUAL_FAILURE_THROW(inTopLevel.GetTopLevelSize(), 1, "FileInStream is empty.");

    for (const auto& element : inTopLevel)
    {
        ASSERT_EQUAL(element->GetRttiType().GetName(), NullObject::GetCurrentRttiType().GetName());
    }
}

void CoreTools::FileOutStreamTesting::DeleteFileTest() const
{
    DeleteFileTools deleteFileTools{ gFullFileName };
}
