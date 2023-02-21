///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.2 (2023/02/16 23:28)

#include "TestingObjectSizeTesting.h"
#include "CoreTools/CoreToolsTesting/HelperSuite/Detail/TestingObjectSize.h"
#include "CoreTools/FileManager/FileBuffer.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ConstObjectAssociated.h"
#include "CoreTools/ObjectSystems/ObjectLinkDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/ObjectRegisterDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

CoreTools::TestingObjectSizeTesting::TestingObjectSizeTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, TestingObjectSizeTesting)

void CoreTools::TestingObjectSizeTesting::DoRunUnitTest()
{
    ObjectManager::Create();

    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);

    ObjectManager::Destroy();
}

void CoreTools::TestingObjectSizeTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SaveStreamTest);
    ASSERT_NOT_THROW_EXCEPTION_0(LoadStreamTest);
    ASSERT_NOT_THROW_EXCEPTION_0(LinkStreamTest);
    ASSERT_NOT_THROW_EXCEPTION_0(GetStreamingSizeTest);
}

void CoreTools::TestingObjectSizeTesting::SaveStreamTest()
{
    const auto streamObject = TestingObjectSize::Create(10);

    const auto objectRegister = ObjectRegister::Create();

    BufferTarget target{ bufferSize, objectRegister };

    ConstObjectAssociated<TestingObjectSize> constObjectAssociated{ streamObject, 1 };
    ASSERT_LESS(0, objectRegister->Register(constObjectAssociated));

    streamObject->Save(target);
}

void CoreTools::TestingObjectSizeTesting::LoadStreamTest()
{
    auto streamObject = TestingObjectSize::Create(10);

    const auto fileBuffer = std::make_shared<FileBuffer>(bufferSize);

    BufferSource source{ fileBuffer };

    streamObject->Load(source);
}

void CoreTools::TestingObjectSizeTesting::LinkStreamTest()
{
    auto streamObject = TestingObjectSize::Create(10);

    auto link = ObjectLink::Create();

    streamObject->PostLink();
    streamObject->Link(*link);
}

void CoreTools::TestingObjectSizeTesting::GetStreamingSizeTest()
{
    const auto streamObject = TestingObjectSize::Create(10);

    const auto classNameSize = Stream::GetStreamingSize(streamObject->GetRttiType().GetName());
    const auto nameSize = Stream::GetStreamingSize(streamObject->GetName());

    const auto intValueSize = boost::numeric_cast<int>(sizeof(int32_t));

    ASSERT_EQUAL(streamObject->GetStreamingSize(), classNameSize + intValueSize + gObjectSize + nameSize);
}