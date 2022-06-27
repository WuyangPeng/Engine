///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.9 (2022/06/16 20:43)

#include "ControlledObjectTest.h"
#include "ControllerTest.h"
#include "ControllerTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferInStream.h"
#include "CoreTools/ObjectSystems/BufferOutStream.h"
#include "CoreTools/ObjectSystems/InTopLevel.h"
#include "CoreTools/ObjectSystems/InitTerm.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/OutTopLevel.h"
#include "Mathematics/Base/MathDetail.h"
#include "Rendering/Controllers/Controller.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, ControllerTesting)

void Rendering::ControllerTesting::MainTest()
{
    CoreTools::InitTerm::ExecuteInitializers();

    ASSERT_NOT_THROW_EXCEPTION_0(InitTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CopyTest);
    ASSERT_NOT_THROW_EXCEPTION_0(UpdateTest);
    ASSERT_NOT_THROW_EXCEPTION_0(StreamTest);

    CoreTools::InitTerm::ExecuteTerminators();
}

void Rendering::ControllerTesting::InitTest() noexcept
{
}

void Rendering::ControllerTesting::CopyTest() noexcept
{
}

void Rendering::ControllerTesting::UpdateTest() noexcept
{
}

void Rendering::ControllerTesting::StreamTest() noexcept
{
}
