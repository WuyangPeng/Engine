///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.2.1 (2021/08/19 14:09)

#include "DefaultTestingNoObjectPtrTesting.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/CoreToolsTesting/HelperSuite/Detail/DefaultTestingNoObjectPtr.h"
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

CoreTools::DefaultTestingNoObjectPtrTesting::DefaultTestingNoObjectPtrTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, DefaultTestingNoObjectPtrTesting)

void CoreTools::DefaultTestingNoObjectPtrTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::DefaultTestingNoObjectPtrTesting::MainTest()
{
    ObjectManager::Create();

    ASSERT_NOT_THROW_EXCEPTION_0(SaveStreamTest);
    ASSERT_NOT_THROW_EXCEPTION_0(LoadStreamTest);
    ASSERT_NOT_THROW_EXCEPTION_0(LinkStreamTest);
    ASSERT_NOT_THROW_EXCEPTION_0(GetStreamingSizeTest);

    ObjectManager::Destroy();
}

void CoreTools::DefaultTestingNoObjectPtrTesting::SaveStreamTest()
{
    auto streamObject = DefaultTestingNoObjectPtr::Create("name"s);

    constexpr auto bufferSize = 256;

    auto objectRegister = ObjectRegister::Create();

    BufferTarget target{ bufferSize, objectRegister };

    ConstObjectAssociated<DefaultTestingNoObjectPtr> constObjectAssociated{ streamObject, 1 };
    ASSERT_LESS(0, objectRegister->Register(constObjectAssociated));

    streamObject->Save(target);
}

void CoreTools::DefaultTestingNoObjectPtrTesting::LoadStreamTest()
{
    auto streamObject = DefaultTestingNoObjectPtr::Create("name"s);

    constexpr auto bufferSize = 256;

    auto fileBuffer = make_shared<FileBuffer>(bufferSize);

    BufferSource source{ fileBuffer };

    streamObject->Load(source);
}

void CoreTools::DefaultTestingNoObjectPtrTesting::LinkStreamTest()
{
    auto streamObject = DefaultTestingNoObjectPtr::Create("name"s);

    auto link = ObjectLink::Create();

    streamObject->PostLink();
    streamObject->Link(*link);
}

void CoreTools::DefaultTestingNoObjectPtrTesting::GetStreamingSizeTest()
{
    const auto name = "name"s;
    auto streamObject = DefaultTestingNoObjectPtr::Create(name);
    string className{ streamObject->GetRttiType().GetName() };

    auto classNameSize = boost::numeric_cast<int>(className.size());
    classNameSize += Stream::GetPadding(classNameSize);

    auto nameSize = boost::numeric_cast<int>(name.size());
    nameSize += Stream::GetPadding(nameSize);

    const auto stringCountLength = boost::numeric_cast<int>(sizeof(int32_t)) * 2;

    ASSERT_EQUAL(streamObject->GetStreamingSize(), classNameSize + nameSize + g_ObjectSize + stringCountLength);
}
