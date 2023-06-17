///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/12 16:50)

#include "BoundTreeChildTesting.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "CoreTools/FileManager/WriteFileManager.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/PhysicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/APointDetail.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Mathematics/Algebra/HomogeneousPointDetail.h"
#include "Mathematics/Algebra/MatrixDetail.h"
#include "Mathematics/Algebra/VariableLengthVectorDetail.h"
#include "Rendering/DataTypes/Bound.h"
#include "Rendering/Renderers/RendererManager.h"
#include "Rendering/SceneGraph/LoadVisual.h"
#include "Rendering/SceneGraph/TrianglesMesh.h"
#include "Physics/CollisionDetection/BoundTreeDetail.h"

#include <random>

namespace Physics
{
    template class BoundTreeChild<Rendering::TrianglesMeshSharedPtr, Rendering::BoundF>;
    template class BoundTreeChild<Rendering::TrianglesMeshSharedPtr, Rendering::BoundF>;
}

Physics::BoundTreeChildTesting::BoundTreeChildTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    PHYSICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Physics, BoundTreeChildTesting)

void Physics::BoundTreeChildTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Physics::BoundTreeChildTesting::MainTest()
{
    CoreTools::InitTerm::ExecuteInitializer();

    Rendering::RendererManager::Create();

    ASSERT_NOT_THROW_EXCEPTION_0(CreateTrianglesMeshFile);
    ASSERT_NOT_THROW_EXCEPTION_0(InitTest);

    Rendering::RendererManager::Destroy();

    CoreTools::InitTerm::ExecuteTerminator();
}

void Physics::BoundTreeChildTesting::CreateTrianglesMeshFile() noexcept
{
}

void Physics::BoundTreeChildTesting::InitTest() noexcept
{
}
