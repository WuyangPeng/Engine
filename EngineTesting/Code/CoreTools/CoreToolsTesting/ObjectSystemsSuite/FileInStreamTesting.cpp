///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/25 14:17)

#include "FileInStreamTesting.h"
#include "Detail/BoolObject.h"
#include "Detail/EnumObject.h"
#include "Detail/IntObject.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/FileManager/DeleteFileTools.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/FileInStream.h"
#include "CoreTools/ObjectSystems/FileOutStream.h"
#include "CoreTools/ObjectSystems/OutTopLevel.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

namespace CoreTools
{
    const auto gFileName = SYSTEM_TEXT("FileInStream.txt"s);
}

CoreTools::FileInStreamTesting::FileInStreamTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, FileInStreamTesting)

void CoreTools::FileInStreamTesting::DoRunUnitTest()
{
    InitTerm::ExecuteInitializer();

    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);

    InitTerm::ExecuteTerminator();
}

void CoreTools::FileInStreamTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FileStreamTest);

    ASSERT_NOT_THROW_EXCEPTION_0(DeleteFileTest);
}

void CoreTools::FileInStreamTesting::FileStreamTest()
{
    OutTopLevel outTopLevel = OutTopLevel::Create();

    outTopLevel.Insert(std::make_shared<BoolObject>(DisableNotThrow::Disable));
    outTopLevel.Insert(std::make_shared<EnumObject>(DisableNotThrow::Disable));
    outTopLevel.Insert(std::make_shared<IntObject>(DisableNotThrow::Disable));

    FileOutStream fileOutStream{ outTopLevel };

    fileOutStream.Save(SYSTEM_TEXT("Resource/") + gFileName);

    const FileInStream fileInputStream{ SYSTEM_TEXT("Resource/") + gFileName };

    const auto inTopLevel = fileInputStream.GetInTopLevel();

    ASSERT_EQUAL_FAILURE_THROW(inTopLevel.GetTopLevelSize(), 3, "FileInStream is empty.");

    auto index = 0;
    for (const auto& value : inTopLevel)
    {
        switch (index)
        {
            case 0:
                ASSERT_EQUAL(value->GetRttiType().GetName(), BoolObject::GetCurrentRttiType().GetName());
                break;
            case 1:
                ASSERT_EQUAL(value->GetRttiType().GetName(), EnumObject::GetCurrentRttiType().GetName());
                break;
            case 2:
                ASSERT_EQUAL(value->GetRttiType().GetName(), IntObject::GetCurrentRttiType().GetName());
                break;
            default:
                break;
        }

        ++index;
    }
}

void CoreTools::FileInStreamTesting::DeleteFileTest()
{
    DeleteFileTools deleteFileTools{ SYSTEM_TEXT("Resource/") + gFileName };
}
