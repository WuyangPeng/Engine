///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/12 15:34)

#include "ProjectorTesting.h"
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
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Mathematics/Algebra/AxesAlignBoundingBox2Detail.h"
#include "Mathematics/Algebra/HomogeneousPointDetail.h"
#include "Mathematics/Algebra/MatrixDetail.h"
#include "Mathematics/Algebra/Vector2Detail.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"
#include "Rendering/SceneGraph/Camera.h"
#include "Rendering/SceneGraph/CameraFrustumData.h"

#include <random>
#include <vector>

Rendering::ProjectorTesting::ProjectorTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, ProjectorTesting)

void Rendering::ProjectorTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Rendering::ProjectorTesting::MainTest()
{
    CoreTools::InitTerm::ExecuteInitializer();

    ASSERT_NOT_THROW_EXCEPTION_0(FrameTest);
    ASSERT_NOT_THROW_EXCEPTION_0(FrustumTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ProjectionMatrixTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AxesAlignBoundingBoxTest);
    ASSERT_NOT_THROW_EXCEPTION_0(StreamTest);

    CoreTools::InitTerm::ExecuteTerminator();
}

void Rendering::ProjectorTesting::FrameTest()
{
    std::default_random_engine generator;
    std::uniform_real_distribution<float> firstFloatRandomDistribution(-100.0f, 100.0f);

    for (int loop = 0; loop < GetTestLoopCount(); ++loop)
    {
        const Camera::APoint firstPosition(firstFloatRandomDistribution(generator),
                                           firstFloatRandomDistribution(generator),
                                           firstFloatRandomDistribution(generator));

        Camera::AVector firstVector(firstFloatRandomDistribution(generator),
                                    firstFloatRandomDistribution(generator),
                                    firstFloatRandomDistribution(generator));

        firstVector.Normalize();

        Camera::AVector secondVector(firstFloatRandomDistribution(generator),
                                     firstFloatRandomDistribution(generator),
                                     firstFloatRandomDistribution(generator));

        secondVector.Normalize();

        Camera::AVector thirdVector(firstFloatRandomDistribution(generator),
                                    firstFloatRandomDistribution(generator),
                                    firstFloatRandomDistribution(generator));

        thirdVector.Normalize();
    }
}

void Rendering::ProjectorTesting::FrustumTest() noexcept
{
   
}

void Rendering::ProjectorTesting::ProjectionMatrixTest() noexcept
{
}

void Rendering::ProjectorTesting::AxesAlignBoundingBoxTest() noexcept
{
}

void Rendering::ProjectorTesting::StreamTest() noexcept
{
}
