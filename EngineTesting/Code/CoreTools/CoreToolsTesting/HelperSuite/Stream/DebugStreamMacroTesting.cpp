///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.2.1 (2021/08/19 14:09)

#include "DebugStreamMacroTesting.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/CoreToolsTesting/HelperSuite/Detail/StreamObject.h"
#include "CoreTools/FileManager/FileBuffer.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSource.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ConstObjectAssociated.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/ObjectRegisterDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using std::make_shared;
using std::string;
using std::vector;
using namespace std::literals;

CoreTools::DebugStreamMacroTesting::DebugStreamMacroTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, DebugStreamMacroTesting)

void CoreTools::DebugStreamMacroTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::DebugStreamMacroTesting::MainTest()
{
    ObjectManager::Create();

    ASSERT_NOT_THROW_EXCEPTION_0(SaveStreamTest);
    ASSERT_NOT_THROW_EXCEPTION_0(LoadStreamTest);

    ObjectManager::Destroy();
}

void CoreTools::DebugStreamMacroTesting::SaveStreamTest()
{
    auto streamObject = StreamObject::Create("name"s);

    constexpr auto bufferSize = 256;

    auto objectRegister = make_shared<ObjectRegister>(DisableNotThrow::Disable);

    auto target = make_shared<BufferTarget>(bufferSize, objectRegister);

    ConstObjectAssociated<StreamObject> constObjectAssociated{ streamObject, 1 };
    ASSERT_LESS(0, objectRegister->Register(constObjectAssociated));

    streamObject->Save(target);
}

void CoreTools::DebugStreamMacroTesting::LoadStreamTest()
{
    auto streamObject = StreamObject::Create("name"s);

    constexpr auto bufferSize = 256;

    auto fileBuffer = make_shared<FileBuffer>(bufferSize);

    auto source = make_shared<BufferSource>(fileBuffer);

    streamObject->Load(source);

    ASSERT_FALSE(streamObject->GetBoolValue());
}
