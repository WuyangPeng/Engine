/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/14 00:04)

#include "DebugStreamMacroTesting.h"
#include "CoreTools/CoreToolsTesting/HelperSuite/Detail/StreamObject.h"
#include "CoreTools/FileManager/FileBuffer.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ConstObjectAssociated.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/ObjectRegisterDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::DebugStreamMacroTesting::DebugStreamMacroTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, DebugStreamMacroTesting)

void CoreTools::DebugStreamMacroTesting::DoRunUnitTest()
{
    ObjectManager::Create();

    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);

    ObjectManager::Destroy();
}

void CoreTools::DebugStreamMacroTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SaveStreamTest);
    ASSERT_NOT_THROW_EXCEPTION_0(LoadStreamTest);
}

void CoreTools::DebugStreamMacroTesting::SaveStreamTest()
{
    const auto streamObject = StreamObject::Create("name");

    const auto objectRegister = ObjectRegister::Create();

    BufferTarget target{ bufferSize, objectRegister };

    const ConstObjectAssociated<StreamObject> constObjectAssociated{ streamObject, 1 };
    ASSERT_LESS(0, objectRegister->Register(constObjectAssociated));

    streamObject->Save(target);
}

void CoreTools::DebugStreamMacroTesting::LoadStreamTest()
{
    const auto streamObject = StreamObject::Create("name");

    const auto fileBuffer = std::make_shared<FileBuffer>(bufferSize);

    BufferSource source{ fileBuffer };

    streamObject->Load(source);

    ASSERT_FALSE(streamObject->GetBoolValue());
}
