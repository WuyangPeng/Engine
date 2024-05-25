/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/05/23 16:54)

#include "FileInStreamTesting.h"
#include "Detail/BoolObject.h"
#include "Detail/EnumObject.h"
#include "Detail/IntObject.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/FileManager/DeleteFileTools.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/FileInStream.h"
#include "CoreTools/ObjectSystems/FileOutStream.h"
#include "CoreTools/ObjectSystems/OutTopLevel.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

namespace
{
    const auto gResource = SYSTEM_TEXT("Resource/");
    const auto gFileName = SYSTEM_TEXT("FileInStream.txt"s);
    const auto gFullFileName = gResource + gFileName;
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
    ASSERT_NOT_THROW_EXCEPTION_0(SaveFileOutStream);
    ASSERT_NOT_THROW_EXCEPTION_0(FileStreamTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DeleteFileTest);
}

void CoreTools::FileInStreamTesting::SaveFileOutStream() const
{
    OutTopLevel outTopLevel = OutTopLevel::Create();

    outTopLevel.Insert(std::make_shared<BoolObject>(DisableNotThrow::Disable));
    outTopLevel.Insert(std::make_shared<EnumObject>(DisableNotThrow::Disable));
    outTopLevel.Insert(std::make_shared<IntObject>(DisableNotThrow::Disable));

    FileOutStream fileOutStream{ outTopLevel };

    fileOutStream.Save(gFullFileName);
}

void CoreTools::FileInStreamTesting::FileStreamTest()
{
    const FileInStream fileInputStream{ gFullFileName };

    const auto inTopLevel = fileInputStream.GetInTopLevel();

    ASSERT_EQUAL_FAILURE_THROW(inTopLevel.GetTopLevelSize(), 3, "FileInStream is empty.");

    ASSERT_NOT_THROW_EXCEPTION_1(FileStreamResultTest, inTopLevel);
}

void CoreTools::FileInStreamTesting::FileStreamResultTest(const InTopLevel& inTopLevel)
{
    auto index = 0;
    for (const auto& element : inTopLevel)
    {
        ASSERT_NOT_THROW_EXCEPTION_2(DoFileStreamResultTest, index, *element);

        ++index;
    }
}

void CoreTools::FileInStreamTesting::DoFileStreamResultTest(int index, const ObjectInterface& element)
{
    switch (index)
    {
        case 0:
            ASSERT_EQUAL(element.GetRttiType().GetName(), BoolObject::GetCurrentRttiType().GetName());
            break;
        case 1:
            ASSERT_EQUAL(element.GetRttiType().GetName(), EnumObject::GetCurrentRttiType().GetName());
            break;
        case 2:
            ASSERT_EQUAL(element.GetRttiType().GetName(), IntObject::GetCurrentRttiType().GetName());
            break;
        default:
            break;
    }
}

void CoreTools::FileInStreamTesting::DeleteFileTest() const
{
    DeleteFileTools deleteFileTools{ gFullFileName };
}
