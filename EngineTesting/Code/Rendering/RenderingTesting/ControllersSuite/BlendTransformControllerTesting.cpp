///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/12 16:03)

#include "BlendTransformControllerTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferInStream.h"
#include "CoreTools/ObjectSystems/BufferOutStream.h"
#include "CoreTools/ObjectSystems/InTopLevel.h"
#include "CoreTools/ObjectSystems/InitTerm.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/OutTopLevel.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/APointDetail.h"
#include "Mathematics/Algebra/AQuaternionDetail.h"
#include "Mathematics/Algebra/Transform.h"
#include "Mathematics/Base/MathDetail.h"
#include "Rendering/Controllers/BlendTransformController.h"
#include "Rendering/RenderingTesting/SceneGraphSuite/Detail/SpatialTest.h"

Rendering::BlendTransformControllerTesting::BlendTransformControllerTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, BlendTransformControllerTesting)

void Rendering::BlendTransformControllerTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Rendering::BlendTransformControllerTesting::MainTest()
{
    CoreTools::InitTerm::ExecuteInitializer();

    ASSERT_NOT_THROW_EXCEPTION_0(InitTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CopyTest);
    ASSERT_NOT_THROW_EXCEPTION_0(UpdateTest);
    ASSERT_NOT_THROW_EXCEPTION_0(StreamTest);

    CoreTools::InitTerm::ExecuteTerminator();
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
