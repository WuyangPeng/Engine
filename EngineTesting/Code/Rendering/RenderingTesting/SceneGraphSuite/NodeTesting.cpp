/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.2 (2023/12/08 10:45)

#include "NodeTesting.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferInStream.h"
#include "CoreTools/ObjectSystems/BufferOutStream.h"
#include "CoreTools/ObjectSystems/OutTopLevel.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/BoundingSphereDetail.h"
#include "Mathematics/Algebra/TransformDetail.h"
#include "Rendering/SceneGraph/Node.h"
#include "Rendering/Visibility/Flags/CullingModeFlags.h"

Rendering::NodeTesting::NodeTesting(const OStreamShared& stream)
    : ParentType{ stream },
      viewVolumeTool{ GetEngineRandomSeed() },

      transformApproximateFunction{ Mathematics::Approximate<float> },
      aPointApproximateFunction{ Mathematics::Approximate<float> }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, NodeTesting)

void Rendering::NodeTesting::DoRunUnitTest()
{
    CoreTools::InitTerm::ExecuteInitializer();

    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);

    CoreTools::InitTerm::ExecuteTerminator();
}

void Rendering::NodeTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(InitTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CloneTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ParentTest);
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(TransformTest);
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(StreamTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ChildTest);
}

void Rendering::NodeTesting::InitTest()
{
    const auto name = "Node";

    const auto node = Node::Create(name);

    ASSERT_EQUAL(node->GetName(), name);
}

void Rendering::NodeTesting::CloneTest()
{
    const auto name = "Node";

    const auto node0 = Node::Create(name);
    const auto node1 = node0->Clone();

    node0->SetName("test");

    ASSERT_EQUAL(node1->GetName(), name);
}

void Rendering::NodeTesting::ParentTest()
{
    const auto name = "Node";

    const auto node0 = Node::Create(name);
    const auto node1 = Node::Create(name);

    ASSERT_EQUAL(node0->GetParent(), Node::GetNullObject());
    ASSERT_EQUAL(node1->GetParent(), Node::GetNullObject());

    node0->SetParent(node1);
    ASSERT_EQUAL(node0->GetParent(), node1);
    ASSERT_EQUAL(node1->GetParent(), Node::GetNullObject());
}

bool Rendering::NodeTesting::TransformTest()
{
    constexpr auto epsilon = 1e-4f;
    const auto name = "Node";

    const auto node = Node::Create(name);

    ASSERT_EQUAL(node->GetCullingMode(), CullingMode::Dynamic);
    ASSERT_APPROXIMATE_USE_FUNCTION(transformApproximateFunction, node->GetLocalTransform(), Transform::GetIdentityTransform(), epsilon);
    ASSERT_APPROXIMATE_USE_FUNCTION(transformApproximateFunction, node->GetWorldTransform(), Transform::GetIdentityTransform(), epsilon);

    ASSERT_APPROXIMATE_USE_FUNCTION(aPointApproximateFunction, node->GetWorldBound().GetCenter(), APoint::GetOrigin(), epsilon);
    ASSERT_APPROXIMATE(node->GetWorldBound().GetRadius(), 0.0f, epsilon);

    node->SetCullingMode(CullingMode::Always);
    ASSERT_EQUAL(node->GetCullingMode(), CullingMode::Always);

    const auto transform0 = viewVolumeTool.ComputeTransform(epsilon);
    node->SetLocalTransform(transform0);
    ASSERT_APPROXIMATE_USE_FUNCTION(transformApproximateFunction, node->GetLocalTransform(), transform0, epsilon);

    const auto transform1 = viewVolumeTool.ComputeTransform(epsilon);
    node->SetWorldTransform(transform1);
    ASSERT_APPROXIMATE_USE_FUNCTION(transformApproximateFunction, node->GetWorldTransform(), transform1, epsilon);

    const auto boundingSphere = viewVolumeTool.ComputeBoundingSphere();
    node->SetWorldBound(boundingSphere);

    ASSERT_APPROXIMATE_USE_FUNCTION(aPointApproximateFunction, node->GetWorldBound().GetCenter(), boundingSphere.GetCenter(), epsilon);
    ASSERT_APPROXIMATE(node->GetWorldBound().GetRadius(), boundingSphere.GetRadius(), epsilon);

    return true;
}

bool Rendering::NodeTesting::StreamTest()
{
    constexpr auto epsilon = 1e-4f;
    const auto name = "Node";

    const auto node0 = Node::Create(name);

    node0->SetLocalTransform(viewVolumeTool.ComputeTransform(epsilon));
    node0->SetWorldTransform(viewVolumeTool.ComputeTransform(epsilon));
    node0->SetWorldBound(viewVolumeTool.ComputeBoundingSphere());
    node0->SetCullingMode(CullingMode::Always);

    auto outTopLevel = CoreTools::OutTopLevel::Create();
    outTopLevel.Insert(node0);

    const CoreTools::BufferOutStream bufferOutStream{ outTopLevel };
    const auto buffer = bufferOutStream.GetBufferOutStreamInformation();

    const CoreTools::BufferInStream bufferInStream{ buffer };

    const auto inTopLevel = bufferInStream.GetTopLevel();

    ASSERT_EQUAL_FAILURE_THROW(inTopLevel.GetTopLevelSize(), 1, "流读取失败。");

    const auto node1 = boost::polymorphic_pointer_cast<Node>(*inTopLevel.begin());

    ASSERT_EQUAL(node0->GetCullingMode(), node1->GetCullingMode());
    ASSERT_APPROXIMATE_USE_FUNCTION(transformApproximateFunction, node0->GetLocalTransform(), node1->GetLocalTransform(), epsilon);
    ASSERT_APPROXIMATE_USE_FUNCTION(transformApproximateFunction, node0->GetWorldTransform(), node1->GetWorldTransform(), epsilon);

    ASSERT_APPROXIMATE_USE_FUNCTION(aPointApproximateFunction, node0->GetWorldBound().GetCenter(), node1->GetWorldBound().GetCenter(), epsilon);
    ASSERT_APPROXIMATE(node0->GetWorldBound().GetRadius(), node1->GetWorldBound().GetRadius(), epsilon);

    return true;
}

void Rendering::NodeTesting::ChildTest()
{
    const auto name = "Node";

    const auto node0 = Node::Create(name);

    ASSERT_EQUAL(node0->GetNumChildren(), 0);

    const auto node1 = Node::Create(name);

    ASSERT_EQUAL(node0->AttachChild(node1), 0);
    ASSERT_EQUAL(node0->GetNumChildren(), 1);

    ASSERT_EQUAL(node0->GetChild(0), node1);
    ASSERT_EQUAL(node0->GetConstChild(0), node1);

    const auto node2 = Node::Create(name);

    ASSERT_EQUAL(node0->AttachChild(node2), 1);
    ASSERT_EQUAL(node0->GetNumChildren(), 2);

    ASSERT_EQUAL(node0->DetachChild(node2), 1);
    ASSERT_EQUAL(node0->GetNumChildren(), 2);

    ASSERT_EQUAL(node0->GetChild(1), Spatial::GetNullObject());

    ASSERT_EQUAL(node0->AttachChild(node2), 1);
    ASSERT_EQUAL(node0->GetNumChildren(), 2);

    ASSERT_EQUAL(node0->DetachChildAt(1), node2);
    ASSERT_EQUAL(node0->GetNumChildren(), 2);

    ASSERT_EQUAL(node0->AttachChild(node2), 1);
    ASSERT_EQUAL(node0->GetNumChildren(), 2);

    node0->DetachAllChildren();
    ASSERT_EQUAL(node0->GetNumChildren(), 2);

    ASSERT_EQUAL(node0->GetChild(0), Spatial::GetNullObject());
    ASSERT_EQUAL(node0->GetChild(1), Spatial::GetNullObject());

    ASSERT_EQUAL(node0->SetChild(1, node2), Spatial::GetNullObject());

    ASSERT_EQUAL(node0->GetNumChildren(), 2);
    ASSERT_EQUAL(node0->GetChild(0), Spatial::GetNullObject());
    ASSERT_EQUAL(node0->GetChild(1), node2);
}
