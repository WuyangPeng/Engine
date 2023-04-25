///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.6 (2023/04/24 09:55)

#include "FileOutStreamTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Base/Version.h"
#include "CoreTools/FileManager/CFileManagerHelper.h"
#include "CoreTools/FileManager/DeleteFileTools.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/FileInStream.h"
#include "CoreTools/ObjectSystems/FileOutStream.h"
#include "CoreTools/ObjectSystems/NullObject.h"
#include "CoreTools/ObjectSystems/OutTopLevel.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

namespace CoreTools
{
    const auto gFileName = SYSTEM_TEXT("FileOutStream.txt"s);
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
    ASSERT_NOT_THROW_EXCEPTION_0(WriteNullObjectTest);

    ASSERT_NOT_THROW_EXCEPTION_0(DeleteFileTest);
}

void CoreTools::FileOutStreamTesting::WriteNullObjectTest()
{
    OutTopLevel outTopLevel = OutTopLevel::Create();

    outTopLevel.Insert(Object::GetNullObject());

    FileOutStream fileOutStream{ outTopLevel };

    fileOutStream.Save(SYSTEM_TEXT("Resource/") + gFileName);

    const FileInStream fileInputStream{ SYSTEM_TEXT("Resource/") + gFileName };

    const auto inTopLevel = fileInputStream.GetInTopLevel();

    ASSERT_EQUAL_FAILURE_THROW(inTopLevel.GetTopLevelSize(), 1, "FileInStream is empty.");

    for (const auto& value : inTopLevel)
    {
        ASSERT_EQUAL(value->GetRttiType().GetName(), NullObject::GetCurrentRttiType().GetName());
    }
}

void CoreTools::FileOutStreamTesting::DeleteFileTest()
{
    DeleteFileTools deleteFileTools{ SYSTEM_TEXT("Resource/") + gFileName };
}
