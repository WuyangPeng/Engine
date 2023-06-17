///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/12 16:51)

#include "BoundTreeTesting.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "CoreTools/FileManager/WriteFileManager.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/PhysicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/APointDetail.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Mathematics/Algebra/HomogeneousPointDetail.h"
#include "Mathematics/Algebra/MatrixDetail.h"
#include "Rendering/DataTypes/Bound.h"
#include "Rendering/DataTypes/BoundDetail.h"
#include "Rendering/Renderers/RendererManager.h"
#include "Rendering/SceneGraph/LoadVisual.h"
#include "Rendering/SceneGraph/TrianglesMesh.h"
#include "Physics/CollisionDetection/BoundTreeDetail.h"

#include <random>

namespace Physics
{
    template class BoundTree<Rendering::TrianglesMeshSharedPtr, Rendering::BoundF>;
    template class BoundTree<Rendering::TrianglesMeshSharedPtr, Rendering::BoundF>;
}

Physics::BoundTreeTesting::BoundTreeTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    PHYSICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Physics, BoundTreeTesting)

void Physics::BoundTreeTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Physics::BoundTreeTesting::MainTest()
{
    CoreTools::InitTerm::ExecuteInitializer();

    Rendering::RendererManager::Create();

    ASSERT_NOT_THROW_EXCEPTION_0(CreateTrianglesMeshFile);
    ASSERT_NOT_THROW_EXCEPTION_0(InitTest);

    Rendering::RendererManager::Destroy();

    CoreTools::InitTerm::ExecuteTerminator();
}

void Physics::BoundTreeTesting::CreateTrianglesMeshFile() noexcept
{
}

void Physics::BoundTreeTesting::InitTest() noexcept
{
}
