///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.9 (2022/06/16 20:29)

#include "BlendTransformControllerTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferInStream.h"
#include "CoreTools/ObjectSystems/BufferOutStream.h"
#include "CoreTools/ObjectSystems/InTopLevel.h"
#include "CoreTools/ObjectSystems/InitTerm.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/OutTopLevel.h"
#include "Mathematics/Algebra/APointDetail.h"
#include "Mathematics/Algebra/AQuaternionDetail.h"
#include "Mathematics/Base/MathDetail.h"
#include "Rendering/Controllers/BlendTransformController.h"
#include "Rendering/DataTypes/Transform.h"
#include "Rendering/RenderingTesting/SceneGraphSuite/SpatialTest.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, BlendTransformControllerTesting)

void Rendering::BlendTransformControllerTesting::MainTest()
{
    CoreTools::InitTerm::ExecuteInitializers();

    ASSERT_NOT_THROW_EXCEPTION_0(InitTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CopyTest);
    ASSERT_NOT_THROW_EXCEPTION_0(UpdateTest);
    ASSERT_NOT_THROW_EXCEPTION_0(StreamTest);

    CoreTools::InitTerm::ExecuteTerminators();
}

void Rendering::BlendTransformControllerTesting::InitTest() noexcept
{
}

void Rendering::BlendTransformControllerTesting::CopyTest() noexcept
{
}

void Rendering::BlendTransformControllerTesting::UpdateTest() noexcept
{
}

void Rendering::BlendTransformControllerTesting::StreamTest() noexcept
{
}
