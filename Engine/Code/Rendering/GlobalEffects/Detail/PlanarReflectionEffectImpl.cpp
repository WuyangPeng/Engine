///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/17 15:55)

#include "Rendering/RenderingExport.h"

#include "PlanarReflectionEffectImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Mathematics/Algebra/MatrixDetail.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Algebra/Vector4ToolsDetail.h"
#include "Rendering/RendererEngine/BaseRenderer.h"
#include "Rendering/SceneGraph/Node.h"
#include "Rendering/SceneGraph/ProjectionViewWorldUpdater.h"
#include "Rendering/State/BlendState.h"
#include "Rendering/State/DepthStencilState.h"
#include "Rendering/State/Flags/BlendStateColorWrite.h"
#include "Rendering/State/Flags/BlendStateMode.h"
#include "Rendering/State/Flags/DepthStencilStateComparison.h"
#include "Rendering/State/Flags/DepthStencilStateOperation.h"
#include "Rendering/State/Flags/DepthStencilStateWriteMask.h"
#include "Rendering/State/Flags/RasterizerStateCull.h"
#include "Rendering/State/RasterizerState.h"
#include "Rendering/Visibility/Flags/CullingModeFlags.h"

Rendering::PlanarReflectionEffectImpl::PlanarReflectionEffectImpl(const NodeSharedPtr& reflectionCaster,
                                                                  const VisualContainer& planeVisuals,
                                                                  const ReflectanceType& reflectances)
    : reflectionCaster{ reflectionCaster },
      planeVisuals{ planeVisuals },
      reflectances{ reflectances },

      casterVisuals{},
      planeOrigins{},
      planeNormals{},

      noColorWrites{ BlendState::Create("noColorWrites") },
      reflectanceBlend{ BlendState::Create("reflectanceBlend") },
      cullReverse{ RasterizerState::Create("cullReverse") },
      dSPass0{ DepthStencilState::Create("dSPass0") },
      dSPass1{ DepthStencilState::Create("dSPass1") },
      dSPass2{ DepthStencilState::Create("dSPass2") },
      dSPass3{ DepthStencilState::Create("dSPass3") }
{
    GatherVisuals(reflectionCaster);

    GetModelSpacePlanes();

    BlendStateTarget noColorWritesBlendStateTarget{};
    noColorWritesBlendStateTarget.SetEnable(true);
    noColorWritesBlendStateTarget.SetMask(BlendStateColorWrite::DisEnable);

    noColorWrites->SetBlendStateTarget(0, noColorWritesBlendStateTarget);

    BlendStateTarget reflectanceBlendStateTarget{};
    reflectanceBlendStateTarget.SetEnable(true);
    reflectanceBlendStateTarget.SetSourceColor(BlendStateMode::OneMinusConstantColor);
    reflectanceBlendStateTarget.SetDestinationColor(BlendStateMode::ConstantColor);
    reflectanceBlendStateTarget.SetSourceAlpha(BlendStateMode::OneMinusConstantColor);
    reflectanceBlendStateTarget.SetDestinationAlpha(BlendStateMode::ConstantColor);

    noColorWrites->SetBlendStateTarget(0, noColorWritesBlendStateTarget);

    dSPass0->SetDepthEnable(true);
    dSPass0->SetWriteMask(DepthStencilStateWriteMask::Zero);
    dSPass0->SetComparison(DepthStencilStateComparison::LessEqual);
    dSPass0->SetStencilEnable(true);
    dSPass0->SetFrontFaceFail(DepthStencilStateOperation::Keep);
    dSPass0->SetFrontFaceDepthFail(DepthStencilStateOperation::Keep);
    dSPass0->SetFrontFacePass(DepthStencilStateOperation::Replace);
    dSPass0->SetFrontFaceComparison(DepthStencilStateComparison::Always);
    dSPass0->SetBackFaceFail(DepthStencilStateOperation::Keep);
    dSPass0->SetBackFaceDepthFail(DepthStencilStateOperation::Keep);
    dSPass0->SetBackFacePass(DepthStencilStateOperation::Replace);
    dSPass0->SetBackFaceComparison(DepthStencilStateComparison::Always);

    dSPass1->SetDepthEnable(true);
    dSPass1->SetWriteMask(DepthStencilStateWriteMask::All);
    dSPass1->SetComparison(DepthStencilStateComparison::Always);
    dSPass1->SetStencilEnable(true);
    dSPass1->SetFrontFaceFail(DepthStencilStateOperation::Keep);
    dSPass1->SetFrontFaceDepthFail(DepthStencilStateOperation::Keep);
    dSPass1->SetFrontFacePass(DepthStencilStateOperation::Keep);
    dSPass1->SetFrontFaceComparison(DepthStencilStateComparison::Equal);
    dSPass1->SetBackFaceFail(DepthStencilStateOperation::Keep);
    dSPass1->SetBackFaceDepthFail(DepthStencilStateOperation::Keep);
    dSPass1->SetBackFacePass(DepthStencilStateOperation::Keep);
    dSPass1->SetBackFaceComparison(DepthStencilStateComparison::Equal);

    dSPass2->SetDepthEnable(true);
    dSPass2->SetWriteMask(DepthStencilStateWriteMask::All);
    dSPass2->SetComparison(DepthStencilStateComparison::LessEqual);
    dSPass2->SetStencilEnable(true);
    dSPass2->SetFrontFaceFail(DepthStencilStateOperation::Keep);
    dSPass2->SetFrontFaceDepthFail(DepthStencilStateOperation::Keep);
    dSPass2->SetFrontFacePass(DepthStencilStateOperation::Keep);
    dSPass2->SetFrontFaceComparison(DepthStencilStateComparison::Equal);
    dSPass2->SetBackFaceFail(DepthStencilStateOperation::Keep);
    dSPass2->SetBackFaceDepthFail(DepthStencilStateOperation::Keep);
    dSPass2->SetBackFacePass(DepthStencilStateOperation::Keep);
    dSPass2->SetBackFaceComparison(DepthStencilStateComparison::Equal);

    dSPass3->SetDepthEnable(true);
    dSPass3->SetWriteMask(DepthStencilStateWriteMask::All);
    dSPass3->SetComparison(DepthStencilStateComparison::LessEqual);
    dSPass3->SetStencilEnable(true);
    dSPass3->SetFrontFaceFail(DepthStencilStateOperation::Keep);
    dSPass3->SetFrontFaceDepthFail(DepthStencilStateOperation::Keep);
    dSPass3->SetFrontFacePass(DepthStencilStateOperation::Invert);
    dSPass3->SetFrontFaceComparison(DepthStencilStateComparison::Equal);
    dSPass3->SetBackFaceFail(DepthStencilStateOperation::Keep);
    dSPass3->SetBackFaceDepthFail(DepthStencilStateOperation::Keep);
    dSPass3->SetBackFacePass(DepthStencilStateOperation::Invert);
    dSPass3->SetBackFaceComparison(DepthStencilStateComparison::Equal);

    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, PlanarReflectionEffectImpl)

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26415)
#include SYSTEM_WARNING_DISABLE(26418)

void Rendering::PlanarReflectionEffectImpl::Draw(const BaseRendererSharedPtr& engine, ProjectionViewWorldUpdater& projectionViewWorldMatrices)
{
    RENDERING_CLASS_IS_VALID_9;

    const auto saveBlendState = engine->GetBlendState();
    const auto saveDepthStencilState = engine->GetDepthStencilState();
    const auto saveRasterizerState = engine->GetRasterizerState();

    const auto depth = engine->GetDepthRange();

    const auto camera = projectionViewWorldMatrices.GetCamera();

    if (saveRasterizerState->GetCull() == RasterizerStateCull::Back)
    {
        cullReverse->SetCull(RasterizerStateCull::Front);
    }
    else if (saveRasterizerState->GetCull() == RasterizerStateCull::Front)
    {
        cullReverse->SetCull(RasterizerStateCull::Back);
    }
    else
    {
        cullReverse->SetCull(RasterizerStateCull::None);
    }
    engine->Bind(cullReverse);

    const auto numPlanes = boost::numeric_cast<int>(planeVisuals.size());
    for (auto i = 0, reference = 1; i < numPlanes; ++i, ++reference)
    {
        const auto& plane = planeVisuals.at(i);

        dSPass0->SetReference(reference);
        engine->SetDepthStencilState(dSPass0);
        engine->SetBlendState(noColorWrites);
        auto drawResult = engine->Draw(*plane);

        dSPass1->SetReference(reference);
        engine->SetDepthStencilState(dSPass1);
        engine->SetDefaultBlendState();
        engine->SetDepthRange(DepthRange{ depth.GetZMax(), depth.GetZMax() });
        drawResult = engine->Draw(*plane);

        const auto wMatrix = plane->GetWorldTransform().GetMatrix();
        Mathematics::Matrix4<float>::ContainerType container{ wMatrix.begin(), wMatrix.end() };
        const Mathematics::Matrix4<float> result{ container, Mathematics::MatrixMajorFlags::Row };
        const Vector4 origin = result * planeOrigins.at(i);
        Vector4 normal = result * planeNormals.at(i);
        normal.Normalize();
        Mathematics::Matrix<float> preViewMatrix{};
        preViewMatrix.MakeReflection(Mathematics::APoint<float>(origin.GetX(), origin.GetY(), origin.GetZ()), Mathematics::AVector<float>(normal.GetX(), normal.GetY(), normal.GetZ()));

        camera->SetPreViewMatrix(preViewMatrix);
        projectionViewWorldMatrices.Update();
        engine->SetDepthRange(depth);
        dSPass2->SetReference(reference);
        engine->SetDepthStencilState(dSPass2);
        engine->SetRasterizerState(cullReverse);
        drawResult = engine->Draw(casterVisuals);
        engine->SetRasterizerState(saveRasterizerState);
        camera->SetPreViewMatrix(Mathematics::Matrix<float>::GetIdentityMatrix());
        projectionViewWorldMatrices.Update();

        dSPass3->SetReference(reference);
        reflectanceBlend->SetBlendColor(Colour{ reflectances.at(i), reflectances.at(i), reflectances.at(i), reflectances.at(i) });
        engine->SetDepthStencilState(dSPass3);
        engine->SetBlendState(reflectanceBlend);
        drawResult = engine->Draw(*plane);
    }

    engine->SetBlendState(saveBlendState);
    engine->SetDepthStencilState(saveDepthStencilState);
    engine->SetRasterizerState(saveRasterizerState);

    MAYBE_UNUSED const auto casterVisualsDrawResult = engine->Draw(casterVisuals);
}

#include SYSTEM_WARNING_POP

void Rendering::PlanarReflectionEffectImpl::GatherVisuals(const SpatialSharedPtr& spatial)
{
    RENDERING_CLASS_IS_VALID_9;

    if (const auto visual = std::dynamic_pointer_cast<Visual>(spatial);
        visual != nullptr)
    {
        casterVisuals.emplace_back(visual);
        return;
    }

    if (const auto node = std::dynamic_pointer_cast<Node>(spatial);
        node != nullptr)
    {
        for (auto i = 0; i < node->GetNumChildren(); ++i)
        {
            if (const auto child = node->GetChild(i);
                child != nullptr)
            {
                GatherVisuals(child);
            }
        }
    }
}

void Rendering::PlanarReflectionEffectImpl::GetModelSpacePlanes()
{
    RENDERING_CLASS_IS_VALID_9;

    for (const auto& visual : planeVisuals)
    {
        const auto vertexBuffer = visual->GetVertexBuffer();
        const auto vertexFormat = vertexBuffer->GetFormat();

        const auto index = vertexFormat.GetIndex(VertexFormatFlags::Semantic::Position, 0);
        if (index < 0)
        {
            THROW_EXCEPTION(SYSTEM_TEXT("POSITION语义必须与单元0一起出现。"))
        }

        const auto posType = vertexFormat.GetAttributeType(index);
        if (posType != DataFormatType::R32G32B32Float && posType != DataFormatType::R32G32B32A32Float)
        {
            THROW_EXCEPTION(SYSTEM_TEXT("POSITION必须是3元组或4元组浮点值。"))
        }

        const auto offset = vertexFormat.GetOffset(index);
        if (offset != 0)
        {
            THROW_EXCEPTION(SYSTEM_TEXT("POSITION必须首先出现在顶点格式中。"))
        }

        const auto indexBuffer = visual->GetIndexBuffer();
        const auto primitiveType = indexBuffer->GetPrimitiveType();
        if (primitiveType != IndexFormatType::TriangleMesh)
        {
            THROW_EXCEPTION(SYSTEM_TEXT("visual必须具有TRIMESH拓扑结构。"))
        }

        auto triangleTuple = indexBuffer->GetTriangle(0);

        std::vector<int32_t> triangle{ get<0>(triangleTuple), get<1>(triangleTuple), get<2>(triangleTuple) };

        const auto stride = vertexFormat.GetVertexSize();
        std::array<Vector4, 3> p{};
        for (auto j = 0; j < 3; ++j)
        {
            auto vertices = vertexBuffer->GetStorage(triangle.at(j) * stride);

            Mathematics::Vector3<float> vector3{};
            vector3.SetX(vertices.Increase<float>());
            vector3.SetY(vertices.Increase<float>());
            vector3.SetZ(vertices.Increase<float>());

            p.at(j) = Mathematics::Vector3Tools<float>::LiftHomogeneous(vector3, 1.0f);
        }

        planeOrigins.emplace_back(p.at(0));
        planeNormals.emplace_back(Mathematics::Vector4Tools<float>::UnitCrossProduct(p.at(2) - p.at(0), p.at(1) - p.at(0)));

        visual->SetCullingMode(CullingMode::Always);
    }
}

Rendering::PlanarReflectionEffectImpl::VisualContainer Rendering::PlanarReflectionEffectImpl::GetPlaneVisuals() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return planeVisuals;
}

Rendering::PlanarReflectionEffectImpl::Vector4Container Rendering::PlanarReflectionEffectImpl::GetPlaneOrigins() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return planeOrigins;
}

Rendering::PlanarReflectionEffectImpl::Vector4Container Rendering::PlanarReflectionEffectImpl::GetPlaneNormals() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return planeNormals;
}

void Rendering::PlanarReflectionEffectImpl::SetReflectance(int index, float reflectance)
{
    RENDERING_CLASS_IS_VALID_9;

    reflectances.at(index) = reflectance;
}

float Rendering::PlanarReflectionEffectImpl::GetReflectance(int index) const
{
    RENDERING_CLASS_IS_VALID_9;

    return reflectances.at(index);
}
