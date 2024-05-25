/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/05/06 19:51)

#include "DefaultTestingNoObjectPtrTesting.h"
#include "CoreTools/FileManager/FileBuffer.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectLinkDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/ObjectRegisterDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

CoreTools::DefaultTestingNoObjectPtrTesting::DefaultTestingNoObjectPtrTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, DefaultTestingNoObjectPtrTesting)

void CoreTools::DefaultTestingNoObjectPtrTesting::DoRunUnitTest()
{
    ObjectManager::Create();

    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);

    ObjectManager::Destroy();
}

void CoreTools::DefaultTestingNoObjectPtrTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SaveStreamTest);
    ASSERT_NOT_THROW_EXCEPTION_0(LoadStreamTest);
    ASSERT_NOT_THROW_EXCEPTION_0(LinkStreamTest);
    ASSERT_NOT_THROW_EXCEPTION_0(GetStreamingSizeTest);
}

void CoreTools::DefaultTestingNoObjectPtrTesting::SaveStreamTest()
{
    const auto streamObject = DefaultTestingNoObjectPtr::Create("name"s);

    const auto objectRegister = ObjectRegister::Create();

    BufferTarget target{ bufferSize, objectRegister };

    const ConstObjectAssociated constObjectAssociated{ streamObject, 1 };
    ASSERT_LESS(0, objectRegister->Register(constObjectAssociated));

    streamObject->Save(target);
}

void CoreTools::DefaultTestingNoObjectPtrTesting::LoadStreamTest()
{
    const auto streamObject = DefaultTestingNoObjectPtr::Create("name");

    const auto fileBuffer = std::make_shared<FileBuffer>(bufferSize);

    BufferSource source{ fileBuffer };

    streamObject->Load(source);
}

void CoreTools::DefaultTestingNoObjectPtrTesting::LinkStreamTest()
{
    const auto streamObject = DefaultTestingNoObjectPtr::Create("name");

    const auto link = ObjectLink::Create();

    streamObject->PostLink();
    streamObject->Link(*link);
}

void CoreTools::DefaultTestingNoObjectPtrTesting::GetStreamingSizeTest()
{
    const auto name = "name"s;
    const auto streamObject = DefaultTestingNoObjectPtr::Create(name);

    const auto classNameSize = Stream::GetStreamingSize(streamObject->GetRttiType().GetName());
    const auto nameSize = Stream::GetStreamingSize(name);

    ASSERT_EQUAL(streamObject->GetStreamingSize(), classNameSize + nameSize + gObjectSize);
}
