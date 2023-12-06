/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/11/25 16:47)

#include "ViewVolumeTesting.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferInStream.h"
#include "CoreTools/ObjectSystems/BufferOutStream.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/OutTopLevel.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Rendering/RenderingTesting/SceneGraphSuite/Detail/ViewVolumeTest.h"

Rendering::ViewVolumeTesting::ViewVolumeTesting(const OStreamShared& stream)
    : ParentType{ stream },
      aPointApproximateFunction{ Mathematics::Approximate<float> },
      aVectorApproximateFunction{ Mathematics::Approximate<float> },
      matrixApproximateFunction{ Mathematics::Approximate<float> },
      viewVolumeTool{ GetEngineRandomSeed() }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, ViewVolumeTesting)

void Rendering::ViewVolumeTesting::DoRunUnitTest()
{
    CoreTools::InitTerm::ExecuteInitializer();

    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);

    CoreTools::InitTerm::ExecuteTerminator();
}

void Rendering::ViewVolumeTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(NameTest);
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(StreamTest);
}

void Rendering::ViewVolumeTesting::NameTest()
{
    const auto changeViewVolumeName = "viewVolume";

    constexpr auto epsilon = 1e-4f;
    const auto viewVolume = ViewVolumeTest::Create(false, DepthType::MinusOneToOne, epsilon);

    ASSERT_EQUAL(viewVolume->GetName(), "ViewVolume");

    viewVolume->SetName(changeViewVolumeName);
    ASSERT_EQUAL(viewVolume->GetName(), changeViewVolumeName);
}

bool Rendering::ViewVolumeTesting::StreamTest()
{
    constexpr auto epsilon = 1e-4f;
    const auto viewVolume0 = ViewVolumeTest::Create(false, DepthType::MinusOneToOne, epsilon);

    const auto position = viewVolumeTool.ComputePosition();
    viewVolumeTool.ComputeAxes(epsilon);

    const auto vector0 = viewVolumeTool.GetDirectionVector();
    const auto vector1 = viewVolumeTool.GetUpVector();
    const auto vector2 = viewVolumeTool.GetRightVector();

    viewVolume0->SetFrame(position, vector0, vector1, vector2);

    const auto upFieldOfViewDegrees = 90.0f * viewVolumeTool.GetRandomProportion();
    const auto aspectRatio = 1.0f * viewVolumeTool.GetRandomProportion();
    const auto directionMin = 1.0f * viewVolumeTool.GetRandomProportion();
    const auto directionMax = 10000.0f * viewVolumeTool.GetRandomProportion();

    viewVolume0->SetFrustum(upFieldOfViewDegrees, aspectRatio, directionMin, directionMax);

    auto outTopLevel = CoreTools::OutTopLevel::Create();
    outTopLevel.Insert(viewVolume0);

    const CoreTools::BufferOutStream bufferOutStream{ outTopLevel };
    const auto buffer = bufferOutStream.GetBufferOutStreamInformation();

    const CoreTools::BufferInStream bufferInStream{ buffer };

    const auto inTopLevel = bufferInStream.GetTopLevel();

    ASSERT_EQUAL_FAILURE_THROW(inTopLevel.GetTopLevelSize(), 1, "流读取失败。");

    const auto viewVolume1 = boost::polymorphic_pointer_cast<ViewVolumeTest>(*inTopLevel.begin());

    ASSERT_APPROXIMATE_USE_FUNCTION(aPointApproximateFunction, viewVolume0->GetPosition(), viewVolume1->GetPosition(), epsilon);
    ASSERT_APPROXIMATE_USE_FUNCTION(aVectorApproximateFunction, viewVolume0->GetDirectionVector(), viewVolume1->GetDirectionVector(), epsilon);
    ASSERT_APPROXIMATE_USE_FUNCTION(aVectorApproximateFunction, viewVolume0->GetUpVector(), viewVolume1->GetUpVector(), epsilon);
    ASSERT_APPROXIMATE_USE_FUNCTION(aVectorApproximateFunction, viewVolume0->GetRightVector(), viewVolume1->GetRightVector(), epsilon);

    ASSERT_APPROXIMATE(viewVolume0->GetDirectionMin(), viewVolume1->GetDirectionMin(), epsilon);
    ASSERT_APPROXIMATE(viewVolume0->GetDirectionMax(), viewVolume1->GetDirectionMax(), epsilon);
    ASSERT_APPROXIMATE(viewVolume0->GetUpMin(), viewVolume1->GetUpMin(), epsilon);
    ASSERT_APPROXIMATE(viewVolume0->GetUpMax(), viewVolume1->GetUpMax(), epsilon);
    ASSERT_APPROXIMATE(viewVolume0->GetRightMin(), viewVolume1->GetRightMin(), epsilon);
    ASSERT_APPROXIMATE(viewVolume0->GetRightMax(), viewVolume1->GetRightMax(), epsilon);

    ASSERT_APPROXIMATE_USE_FUNCTION(matrixApproximateFunction, viewVolume0->GetProjectionMatrix(), viewVolume1->GetProjectionMatrix(), epsilon);

    return true;
}
