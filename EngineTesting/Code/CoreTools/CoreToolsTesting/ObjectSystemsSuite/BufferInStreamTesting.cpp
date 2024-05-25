/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/05/19 20:37)

#include "BufferInStreamTesting.h"
#include "Detail/BoolObject.h"
#include "Detail/EnumObject.h"
#include "Detail/IntObject.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferInStream.h"
#include "CoreTools/ObjectSystems/BufferOutStream.h"
#include "CoreTools/ObjectSystems/InitTerm.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/OutTopLevel.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::BufferInStreamTesting::BufferInStreamTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, BufferInStreamTesting)

void CoreTools::BufferInStreamTesting::DoRunUnitTest()
{
    InitTerm::ExecuteInitializer();

    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);

    InitTerm::ExecuteTerminator();
}

void CoreTools::BufferInStreamTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(BufferInStreamTest);
}

void CoreTools::BufferInStreamTesting::BufferInStreamTest()
{
    const auto fileBuffer = GetBufferInformation();

    const BufferInStream bufferInStream{ fileBuffer };

    const auto inTopLevel = bufferInStream.GetTopLevel();

    ASSERT_EQUAL_FAILURE_THROW(inTopLevel.GetTopLevelSize(), 3, "top level 大小错误。");

    const auto objects = GetObjectContainer(inTopLevel);

    ASSERT_NOT_THROW_EXCEPTION_1(IsExactlyTest, objects);
}

CoreTools::ConstFileBufferSharedPtr CoreTools::BufferInStreamTesting::GetBufferInformation()
{
    auto outTopLevel = OutTopLevel::Create();

    outTopLevel.Insert(std::make_shared<BoolObject>(DisableNotThrow::Disable));
    outTopLevel.Insert(std::make_shared<EnumObject>(DisableNotThrow::Disable));
    outTopLevel.Insert(std::make_shared<IntObject>(DisableNotThrow::Disable));

    const BufferOutStream bufferOutStream{ outTopLevel };

    return bufferOutStream.GetBufferOutStreamInformation();
}

void CoreTools::BufferInStreamTesting::IsExactlyTest(const ObjectContainer& objects)
{
    ASSERT_TRUE(objects.at(0)->IsExactly(BoolObject::GetCurrentRttiType()));
    ASSERT_TRUE(objects.at(1)->IsExactly(EnumObject::GetCurrentRttiType()));
    ASSERT_TRUE(objects.at(2)->IsExactly(IntObject::GetCurrentRttiType()));
}

CoreTools::BufferInStreamTesting::ObjectContainer CoreTools::BufferInStreamTesting::GetObjectContainer(const InTopLevel& inTopLevel)
{
    ObjectContainer objects{};
    for (const auto& element : inTopLevel)
    {
        ASSERT_TRUE(inTopLevel.IsTopLevel(element));
        objects.emplace_back(element);
    }

    return objects;
}
