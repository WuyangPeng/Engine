///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/19 11:37)

#include "DefaultTestingObjectPtrTesting.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/CoreToolsTesting/HelperSuite/Detail/DefaultTestingObjectPtr.h"
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

using std::make_shared;
using std::string;
using std::vector;
using namespace std::literals;

CoreTools::DefaultTestingObjectPtrTesting::DefaultTestingObjectPtrTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, DefaultTestingObjectPtrTesting)

void CoreTools::DefaultTestingObjectPtrTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::DefaultTestingObjectPtrTesting::MainTest()
{
    ObjectManager::Create();

    ASSERT_NOT_THROW_EXCEPTION_0(SaveStreamTest);
    ASSERT_NOT_THROW_EXCEPTION_0(LoadStreamTest);
    ASSERT_NOT_THROW_EXCEPTION_0(LinkStreamTest);
    ASSERT_NOT_THROW_EXCEPTION_0(GetStreamingSizeTest);

    ObjectManager::Destroy();
}

void CoreTools::DefaultTestingObjectPtrTesting::SaveStreamTest()
{
    auto streamObject = DefaultTestingObjectPtr::Create("name"s);

    constexpr auto bufferSize = 256;

    auto objectRegister = ObjectRegister::Create();

    BufferTarget target{ bufferSize, objectRegister };

    ConstObjectAssociated<DefaultTestingObjectPtr> constObjectAssociated{ streamObject, 1 };
    ASSERT_LESS(0, objectRegister->Register(constObjectAssociated));

    streamObject->Save(target);
}

void CoreTools::DefaultTestingObjectPtrTesting::LoadStreamTest()
{
    auto streamObject = DefaultTestingObjectPtr::Create("name"s);

    constexpr auto bufferSize = 256;

    auto fileBuffer = make_shared<FileBuffer>(bufferSize);

    BufferSource source{ fileBuffer };

    streamObject->Load(source);
}

void CoreTools::DefaultTestingObjectPtrTesting::LinkStreamTest()
{
    auto streamObject = DefaultTestingObjectPtr::Create("name"s);

    auto link = ObjectLink::Create();

    streamObject->PostLink();
    streamObject->Link(*link);
}

void CoreTools::DefaultTestingObjectPtrTesting::GetStreamingSizeTest()
{
    const auto name = "name"s;
    auto streamObject = DefaultTestingObjectPtr::Create(name);
    string className{ streamObject->GetRttiType().GetName() };

    auto classNameSize = boost::numeric_cast<int>(className.size());
    classNameSize += Stream::GetPadding(classNameSize);

    auto nameSize = boost::numeric_cast<int>(name.size());
    nameSize += Stream::GetPadding(nameSize);

    const auto stringCountLength = boost::numeric_cast<int>(sizeof(int32_t)) * 2;

    ASSERT_EQUAL(streamObject->GetStreamingSize(), classNameSize + nameSize + g_ObjectSize + stringCountLength);
}
