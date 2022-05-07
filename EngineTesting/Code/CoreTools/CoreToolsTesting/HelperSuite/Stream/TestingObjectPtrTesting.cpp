///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.2.1 (2021/08/19 14:09)

#include "TestingObjectPtrTesting.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/CoreToolsTesting/HelperSuite/Detail/TestingObjectPtr.h"
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

CoreTools::TestingObjectPtrTesting::TestingObjectPtrTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, TestingObjectPtrTesting)

void CoreTools::TestingObjectPtrTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::TestingObjectPtrTesting::MainTest()
{
    ObjectManager::Create();

    ASSERT_NOT_THROW_EXCEPTION_0(SaveStreamTest);
    ASSERT_NOT_THROW_EXCEPTION_0(LoadStreamTest);
    ASSERT_NOT_THROW_EXCEPTION_0(LinkStreamTest);
    ASSERT_NOT_THROW_EXCEPTION_0(GetStreamingSizeTest);

    ObjectManager::Destroy();
}

void CoreTools::TestingObjectPtrTesting::SaveStreamTest()
{
    auto streamObject = TestingObjectPtr::Create("name"s);

    constexpr auto bufferSize = 256;

    auto objectRegister = ObjectRegister::Create();

    BufferTarget target{ bufferSize, objectRegister };

    ConstObjectAssociated<TestingObjectPtr> constObjectAssociated{ streamObject, 1 };
    ASSERT_LESS(0, objectRegister->Register(constObjectAssociated));

    streamObject->Save(target);
}

void CoreTools::TestingObjectPtrTesting::LoadStreamTest()
{
    auto streamObject = TestingObjectPtr::Create("name"s);

    constexpr auto bufferSize = 256;

    auto fileBuffer = make_shared<FileBuffer>(bufferSize);

    BufferSource source{ fileBuffer };

    streamObject->Load(source);
}

void CoreTools::TestingObjectPtrTesting::LinkStreamTest()
{
    auto streamObject = TestingObjectPtr::Create("name"s);

    auto link = ObjectLink::Create();

    streamObject->PostLink();
    streamObject->Link(*link);
}

void CoreTools::TestingObjectPtrTesting::GetStreamingSizeTest()
{
    const auto name = "name"s;
    auto streamObject = TestingObjectPtr::Create(name);
    string className{ streamObject->GetRttiType().GetName() };

    auto classNameSize = boost::numeric_cast<int>(className.size());
    classNameSize += Stream::GetPadding(classNameSize);

    auto nameSize = boost::numeric_cast<int>(name.size());
    nameSize += Stream::GetPadding(nameSize);

    const auto stringCountLength = boost::numeric_cast<int>(sizeof(int32_t)) * 2;

    ASSERT_EQUAL(streamObject->GetStreamingSize(), classNameSize + nameSize + g_ObjectSize + stringCountLength);
}