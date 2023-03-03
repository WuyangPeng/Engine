///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.2 (2023/02/16 23:31)

#include "TestingObjectTesting.h"
#include "CoreTools/CoreToolsTesting/HelperSuite/Detail/TestingObject.h"
#include "CoreTools/FileManager/FileBuffer.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSource.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ConstObjectAssociated.h"
#include "CoreTools/ObjectSystems/ObjectLink.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/ObjectRegisterDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

CoreTools::TestingObjectTesting::TestingObjectTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, TestingObjectTesting)

void CoreTools::TestingObjectTesting::DoRunUnitTest()
{
    ObjectManager::Create();

    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);

    ObjectManager::Destroy();
}

void CoreTools::TestingObjectTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SaveStreamTest);
    ASSERT_NOT_THROW_EXCEPTION_0(LoadStreamTest);
    ASSERT_NOT_THROW_EXCEPTION_0(LinkStreamTest);
    ASSERT_NOT_THROW_EXCEPTION_0(GetStreamingSizeTest);
}

void CoreTools::TestingObjectTesting::SaveStreamTest()
{
    const auto streamObject = TestingObject::Create("name"s);

    const auto objectRegister = ObjectRegister::Create();

    BufferTarget target{ bufferSize, objectRegister };

    const ConstObjectAssociated<TestingObject> constObjectAssociated{ streamObject, 1 };
    ASSERT_LESS(0, objectRegister->Register(constObjectAssociated));

    streamObject->Save(target);
}

void CoreTools::TestingObjectTesting::LoadStreamTest()
{
    const auto streamObject = TestingObject::Create("name"s);

    const auto fileBuffer = std::make_shared<FileBuffer>(bufferSize);

    BufferSource source{ fileBuffer };

    streamObject->Load(source);
}

void CoreTools::TestingObjectTesting::LinkStreamTest()
{
    const auto streamObject = TestingObject::Create("name"s);

    const auto link = ObjectLink::Create();

    streamObject->PostLink();
    streamObject->Link(*link);
}

void CoreTools::TestingObjectTesting::GetStreamingSizeTest()
{
    const auto name = "name"s;
    const auto streamObject = TestingObject::Create(name);

    const auto classNameSize = Stream::GetStreamingSize(streamObject->GetRttiType().GetName());
    const auto nameSize = Stream::GetStreamingSize(streamObject->GetName());

    ASSERT_EQUAL(streamObject->GetStreamingSize(), classNameSize + nameSize + gObjectSize);
}