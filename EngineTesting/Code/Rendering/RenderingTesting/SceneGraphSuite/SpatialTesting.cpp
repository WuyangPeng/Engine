/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.2 (2023/12/07 14:18)

#include "SpatialTesting.h"
#include "Detail/SpatialTest.h"
#include "Detail/ViewVolumeTest.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferInStream.h"
#include "CoreTools/ObjectSystems/BufferOutStream.h"
#include "CoreTools/ObjectSystems/OutTopLevel.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/BoundingSphereDetail.h"
#include "Mathematics/Algebra/TransformDetail.h"
#include "Rendering/Visibility/Flags/CullingModeFlags.h"

Rendering::SpatialTesting::SpatialTesting(const OStreamShared& stream)
    : ParentType{ stream },
      viewVolumeTool{ GetEngineRandomSeed() },

      transformApproximateFunction{ Mathematics::Approximate<float> },
      aPointApproximateFunction{ Mathematics::Approximate<float> }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, SpatialTesting)

void Rendering::SpatialTesting::DoRunUnitTest()
{
    CoreTools::InitTerm::ExecuteInitializer();

    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);

    CoreTools::InitTerm::ExecuteTerminator();
}

void Rendering::SpatialTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(InitTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CloneTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ParentTest);
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(TransformTest);
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(StreamTest);
}

void Rendering::SpatialTesting::InitTest()
{
    const auto name = "SpatialTest";

    const auto spatialTest = SpatialTest::Create(name);

    ASSERT_EQUAL(spatialTest->GetName(), name);
}

void Rendering::SpatialTesting::CloneTest()
{
    const auto name = "SpatialTest";

    const auto spatialTest0 = SpatialTest::Create(name);
    const auto spatialTest1 = spatialTest0->Clone();

    spatialTest0->SetName("test");

    ASSERT_EQUAL(spatialTest1->GetName(), name);
}

void Rendering::SpatialTesting::ParentTest()
{
    const auto name = "SpatialTest";

    const auto spatialTest0 = SpatialTest::Create(name);
    const auto spatialTest1 = SpatialTest::Create(name);

    ASSERT_EQUAL(spatialTest0->GetParent(), SpatialTest::GetNullObject());
    ASSERT_EQUAL(spatialTest1->GetParent(), SpatialTest::GetNullObject());

    spatialTest0->SetParent(spatialTest1);
    ASSERT_EQUAL(spatialTest0->GetParent(), spatialTest1);
    ASSERT_EQUAL(spatialTest1->GetParent(), SpatialTest::GetNullObject());
}

bool Rendering::SpatialTesting::TransformTest()
{
    constexpr auto epsilon = 1e-4f;
    const auto name = "SpatialTest";

    const auto spatialTest = SpatialTest::Create(name);

    ASSERT_EQUAL(spatialTest->GetCullingMode(), CullingMode::Dynamic);
    ASSERT_APPROXIMATE_USE_FUNCTION(transformApproximateFunction, spatialTest->GetLocalTransform(), Transform::GetIdentityTransform(), epsilon);
    ASSERT_APPROXIMATE_USE_FUNCTION(transformApproximateFunction, spatialTest->GetWorldTransform(), Transform::GetIdentityTransform(), epsilon);

    ASSERT_APPROXIMATE_USE_FUNCTION(aPointApproximateFunction, spatialTest->GetWorldBound().GetCenter(), APoint::GetOrigin(), epsilon);
    ASSERT_APPROXIMATE(spatialTest->GetWorldBound().GetRadius(), 0.0f, epsilon);

    spatialTest->SetCullingMode(CullingMode::Always);
    ASSERT_EQUAL(spatialTest->GetCullingMode(), CullingMode::Always);

    const auto transform0 = viewVolumeTool.ComputeTransform(epsilon);
    spatialTest->SetLocalTransform(transform0);
    ASSERT_APPROXIMATE_USE_FUNCTION(transformApproximateFunction, spatialTest->GetLocalTransform(), transform0, epsilon);

    const auto transform1 = viewVolumeTool.ComputeTransform(epsilon);
    spatialTest->SetWorldTransform(transform1);
    ASSERT_APPROXIMATE_USE_FUNCTION(transformApproximateFunction, spatialTest->GetWorldTransform(), transform1, epsilon);

    const auto boundingSphere = viewVolumeTool.ComputeBoundingSphere();
    spatialTest->SetWorldBound(boundingSphere);

    ASSERT_APPROXIMATE_USE_FUNCTION(aPointApproximateFunction, spatialTest->GetWorldBound().GetCenter(), boundingSphere.GetCenter(), epsilon);
    ASSERT_APPROXIMATE(spatialTest->GetWorldBound().GetRadius(), boundingSphere.GetRadius(), epsilon);

    return true;
}

bool Rendering::SpatialTesting::StreamTest()
{
    constexpr auto epsilon = 1e-4f;
    const auto name = "SpatialTest";

    const auto spatialTest0 = SpatialTest::Create(name);

    spatialTest0->SetLocalTransform(viewVolumeTool.ComputeTransform(epsilon));
    spatialTest0->SetWorldTransform(viewVolumeTool.ComputeTransform(epsilon));
    spatialTest0->SetWorldBound(viewVolumeTool.ComputeBoundingSphere());
    spatialTest0->SetCullingMode(CullingMode::Always);

    auto outTopLevel = CoreTools::OutTopLevel::Create();
    outTopLevel.Insert(spatialTest0);

    const CoreTools::BufferOutStream bufferOutStream{ outTopLevel };
    const auto buffer = bufferOutStream.GetBufferOutStreamInformation();

    const CoreTools::BufferInStream bufferInStream{ buffer };

    const auto inTopLevel = bufferInStream.GetTopLevel();

    ASSERT_EQUAL_FAILURE_THROW(inTopLevel.GetTopLevelSize(), 1, "流读取失败。");

    const auto spatialTest1 = boost::polymorphic_pointer_cast<SpatialTest>(*inTopLevel.begin());

    ASSERT_EQUAL(spatialTest0->GetCullingMode(), spatialTest1->GetCullingMode());
    ASSERT_APPROXIMATE_USE_FUNCTION(transformApproximateFunction, spatialTest0->GetLocalTransform(), spatialTest1->GetLocalTransform(), epsilon);
    ASSERT_APPROXIMATE_USE_FUNCTION(transformApproximateFunction, spatialTest0->GetWorldTransform(), spatialTest1->GetWorldTransform(), epsilon);

    ASSERT_APPROXIMATE_USE_FUNCTION(aPointApproximateFunction, spatialTest0->GetWorldBound().GetCenter(), spatialTest1->GetWorldBound().GetCenter(), epsilon);
    ASSERT_APPROXIMATE(spatialTest0->GetWorldBound().GetRadius(), spatialTest1->GetWorldBound().GetRadius(), epsilon);

    return true;
}