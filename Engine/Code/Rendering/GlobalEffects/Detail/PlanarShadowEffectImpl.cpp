///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/17 15:54)

#include "Rendering/RenderingExport.h"

#include "PlanarShadowEffectImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Mathematics/Algebra/MatrixDetail.h"
#include "Mathematics/Algebra/PlaneDetail.h"
#include "Mathematics/Algebra/Vector3Tools.h"
#include "Mathematics/Algebra/Vector4Tools.h"
#include "Rendering/GlobalEffects/LightProjector.h"
#include "Rendering/LocalEffects/ConstantColorEffect.h"
#include "Rendering/RendererEngine/BaseRenderer.h"
#include "Rendering/Resources/Buffers/ConstantBufferDetail.h"
#include "Rendering/SceneGraph/Node.h"
#include "Rendering/SceneGraph/ProjectionViewWorldUpdater.h"
#include "Rendering/Shaders/ProgramFactory.h"
#include "Rendering/State/BlendState.h"
#include "Rendering/State/DepthStencilState.h"
#include "Rendering/State/Flags/BlendStateColorWrite.h"
#include "Rendering/State/Flags/BlendStateMode.h"
#include "Rendering/State/Flags/BlendStateOperation.h"
#include "Rendering/State/Flags/DepthStencilStateComparison.h"
#include "Rendering/State/Flags/DepthStencilStateOperation.h"
#include "Rendering/State/Flags/DepthStencilStateWriteMask.h"
#include "Rendering/Visibility/Flags/CullingModeFlags.h"

Rendering::PlanarShadowEffectImpl::PlanarShadowEffectImpl(const BaseRendererSharedPtr& engine,
                                                          const ProgramFactorySharedPtr& factory,
                                                          const NodeSharedPtr& shadowCaster,
                                                          const LightProjectorSharedPtr& lightProjector,
                                                          const VisualContainer& planeVisuals,
                                                          const Vector4Container& shadowColors)
    : shadowCaster{ shadowCaster },
      lightProjector{ lightProjector },
      planeVisuals{ planeVisuals },
      shadowColors{ shadowColors },

      casterVisuals{},
      casterEffects{},
      saveVisualEffects{},

      modelSpaceTriangles{ planeVisuals.size() },

      shadowBlend{ BlendState::Create("shadowBlend") },
      dSPass0{ DepthStencilState::Create("dSPass0") },
      dSPass1{ DepthStencilState::Create("dSPass0") },

      shaderAPIType{ factory->GetAPI() }
{
    GatherVisuals(engine, factory, shadowCaster);
    saveVisualEffects.resize(casterEffects.size());

    GetModelSpaceTriangles();

    BlendStateTarget blendStateTarget{};
    blendStateTarget.SetEnable(true);
    blendStateTarget.SetSourceColor(BlendStateMode::SourceAlpha);
    blendStateTarget.SetDestinationColor(BlendStateMode::OneMinusSourceAlpha);
    blendStateTarget.SetOperationColor(BlendStateOperation::Add);
    blendStateTarget.SetSourceAlpha(BlendStateMode::SourceAlpha);
    blendStateTarget.SetDestinationAlpha(BlendStateMode::OneMinusSourceAlpha);
    blendStateTarget.SetOperationAlpha(BlendStateOperation::Add);
    blendStateTarget.SetMask(BlendStateColorWrite::EnableAll);

    shadowBlend->SetBlendStateTarget(0, blendStateTarget);

    dSPass0->SetDepthEnable(true);
    dSPass0->SetWriteMask(DepthStencilStateWriteMask::All);
    dSPass0->SetComparison(DepthStencilStateComparison::LessEqual);
    dSPass0->SetStencilEnable(true);
    dSPass0->SetStencilReadMask(0xFF);
    dSPass0->SetStencilWriteMask(0xFF);
    dSPass0->SetFrontFaceFail(DepthStencilStateOperation::Keep);
    dSPass0->SetFrontFaceDepthFail(DepthStencilStateOperation::Keep);
    dSPass0->SetFrontFacePass(DepthStencilStateOperation::Replace);
    dSPass0->SetFrontFaceComparison(DepthStencilStateComparison::Always);
    dSPass0->SetBackFaceFail(DepthStencilStateOperation::Keep);
    dSPass0->SetBackFaceDepthFail(DepthStencilStateOperation::Keep);
    dSPass0->SetBackFacePass(DepthStencilStateOperation::Replace);
    dSPass0->SetBackFaceComparison(DepthStencilStateComparison::Always);

    dSPass1->SetDepthEnable(false);
    dSPass1->SetWriteMask(DepthStencilStateWriteMask::All);
    dSPass1->SetComparison(DepthStencilStateComparison::LessEqual);
    dSPass1->SetStencilEnable(true);
    dSPass1->SetStencilReadMask(0xFF);
    dSPass1->SetStencilWriteMask(0xFF);
    dSPass1->SetFrontFaceFail(DepthStencilStateOperation::Keep);
    dSPass1->SetFrontFaceDepthFail(DepthStencilStateOperation::Keep);
    dSPass1->SetFrontFacePass(DepthStencilStateOperation::Zero);
    dSPass1->SetFrontFaceComparison(DepthStencilStateComparison::Equal);
    dSPass1->SetBackFaceFail(DepthStencilStateOperation::Keep);
    dSPass1->SetBackFaceDepthFail(DepthStencilStateOperation::Keep);
    dSPass1->SetBackFacePass(DepthStencilStateOperation::Zero);
    dSPass1->SetBackFaceComparison(DepthStencilStateComparison::Equal);

    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, PlanarShadowEffectImpl)

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26415)
#include SYSTEM_WARNING_DISABLE(26418)

void Rendering::PlanarShadowEffectImpl::Draw(const BaseRendererSharedPtr& engine, ProjectionViewWorldUpdater& projectionViewWorldMatrices)
{
    RENDERING_CLASS_IS_VALID_9;

    const auto saveBlendState = engine->GetBlendState();
    const auto saveDepthStencilState = engine->GetDepthStencilState();

    const auto camera = projectionViewWorldMatrices.GetCamera();

    auto drawResult = engine->Draw(casterVisuals);

    for (auto i = 0; i < boost::numeric_cast<int>(planeVisuals.size()); ++i)
    {
        const auto& plane = planeVisuals.at(i);
        const auto reference = i + 1;

        dSPass0->SetReference(reference);
        engine->SetDepthStencilState(dSPass0);
        engine->SetBlendState(saveBlendState);
        drawResult = engine->Draw(*plane);

        dSPass1->SetReference(reference);
        engine->SetDepthStencilState(dSPass1);
        engine->SetBlendState(shadowBlend);

        Mathematics::Matrix<float> projectionMatrix{};
        if (!GetProjectionMatrix(i, projectionMatrix))
        {
            continue;
        }

        camera->SetPreViewMatrix(projectionMatrix);

        for (auto j = 0; j < boost::numeric_cast<int>(casterVisuals.size()); ++j)
        {
            const auto& visual = casterVisuals.at(j);
            saveVisualEffects.at(j) = visual->GetVisualEffect();

            const auto constantBuffer = casterEffects.at(j)->GetColorConstant();
            auto color = constantBuffer->GetStorage();

            for (const auto& value : shadowColors)
            {
                color.Increase(value[0]);
                color.Increase(value[1]);
                color.Increase(value[2]);
                color.Increase(value[3]);
            }

            auto updateResult = engine->Update(constantBuffer);

            updateResult = projectionViewWorldMatrices.Unsubscribe(visual);
            visual->SetVisualEffect(casterEffects.at(j));
            updateResult = projectionViewWorldMatrices.Subscribe(visual);
        }

        projectionViewWorldMatrices.Update();

        drawResult = engine->Draw(casterVisuals);

        for (auto j = 0; j < boost::numeric_cast<int>(casterVisuals.size()); ++j)
        {
            const auto& visual = casterVisuals.at(j);
            auto updateResult = projectionViewWorldMatrices.Unsubscribe(visual);
            visual->SetVisualEffect(saveVisualEffects.at(j));
            updateResult = projectionViewWorldMatrices.Subscribe(visual);
        }

        camera->SetPreViewMatrix(Mathematics::Matrix<float>::GetIdentityMatrix());

        projectionViewWorldMatrices.Update();

        if (shaderAPIType == ShaderAPIType::GLSL)
        {
            engine->ClearStencilBuffer();
        }
    }

    engine->SetBlendState(saveBlendState);
    engine->SetDepthStencilState(saveDepthStencilState);
}

#include SYSTEM_WARNING_POP

void Rendering::PlanarShadowEffectImpl::GatherVisuals(const BaseRendererSharedPtr& engine, const ProgramFactorySharedPtr& factory, const SpatialSharedPtr& spatial)
{
    if (const auto visual = std::dynamic_pointer_cast<Visual>(spatial);
        visual != nullptr)
    {
        Colour<float> black{ 0.0f, 0.0f, 0.0f, 1.0f };
        auto effect = std::make_shared<ConstantColorEffect>("ConstantColorEffect", *factory, engine, black);
        casterVisuals.emplace_back(visual);
        casterEffects.emplace_back(effect);
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
                GatherVisuals(engine, factory, child);
            }
        }
    }
}

void Rendering::PlanarShadowEffectImpl::GetModelSpaceTriangles()
{
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
        auto& point = modelSpaceTriangles.at(index);
        for (auto j = 0; j < 3; ++j)
        {
            auto vertices = vertexBuffer->GetStorage(triangle.at(j) * stride);

            Mathematics::Vector3<float> vector3{};
            vector3.SetX(vertices.Increase<float>());
            vector3.SetY(vertices.Increase<float>());
            vector3.SetZ(vertices.Increase<float>());

            point.at(j) = Mathematics::Vector3Tools<float>::LiftHomogeneous(vector3, 1.0f);
        }

        visual->SetCullingMode(CullingMode::Always);
    }
}

bool Rendering::PlanarShadowEffectImpl::GetProjectionMatrix(int index, Matrix& projectionMatrix)
{
    const auto wMatrix = planeVisuals.at(index)->GetWorldTransform().GetMatrix();
    const auto& msTriangle = modelSpaceTriangles.at(index);
    std::array<Vector4, 3> wsTriangle{};
    const Mathematics::Matrix4<float>::ContainerType container{ wMatrix.begin(), wMatrix.end() };
    const Mathematics::Matrix4<float> result{ container, Mathematics::MatrixMajorFlags::Row };

    for (auto j = 0; j < 3; ++j)
    {
        wsTriangle.at(j) = result * msTriangle.at(j);
    }
    const Mathematics::Plane<float> wPlane{ Mathematics::APointF{ wsTriangle.at(0).GetX(), wsTriangle.at(0).GetY(), wsTriangle.at(0).GetZ() },
                                            Mathematics::APointF{ wsTriangle.at(1).GetX(), wsTriangle.at(1).GetY(), wsTriangle.at(1).GetZ() },
                                            Mathematics::APointF{ wsTriangle.at(2).GetX(), wsTriangle.at(2).GetY(), wsTriangle.at(2).GetZ() } };

    if (shadowCaster->GetWorldBound().WhichSide(wPlane) == Mathematics::NumericalValueSymbol::Negative)
    {
        projectionMatrix = Matrix::GetIdentityMatrix();
        return false;
    }

    const auto normal = wPlane.GetNormal();
    if (lightProjector->IsPointLight())
    {
        const auto ndE = Dot(normal, Mathematics::AVectorF{ lightProjector->GetPosition().GetX(), lightProjector->GetPosition().GetY(), lightProjector->GetPosition().GetZ() });
        if (ndE <= 0.0f)
        {
            projectionMatrix = Matrix::GetIdentityMatrix();
            return false;
        }

        projectionMatrix.MakePerspectiveProjection(
            Mathematics::APoint<float>{ wsTriangle.at(0).GetX(), wsTriangle.at(0).GetY(), wsTriangle.at(0).GetZ() },
            Mathematics::AVector<float>{ normal.GetX(), normal.GetY(), normal.GetZ() },
            Mathematics::APoint<float>{ lightProjector->GetPosition().GetX(), lightProjector->GetPosition().GetY(), lightProjector->GetPosition().GetZ() });
    }
    else
    {
        const auto ndD = Dot(normal, Mathematics::AVectorF{ lightProjector->GetPosition().GetX(), lightProjector->GetPosition().GetY(), lightProjector->GetPosition().GetZ() });
        if (ndD >= 0.0f)
        {
            projectionMatrix = Matrix::GetIdentityMatrix();
            return false;
        }

        projectionMatrix.MakeObliqueProjection(Mathematics::APoint<float>{ wsTriangle.at(0).GetX(), wsTriangle.at(0).GetY(), wsTriangle.at(0).GetZ() },
                                               Mathematics::AVector<float>{ normal.GetX(), normal.GetY(), normal.GetZ() },
                                               Mathematics::AVector<float>{ lightProjector->GetDirection().GetX(), lightProjector->GetDirection().GetY(), lightProjector->GetDirection().GetZ() });
    }

    return true;
}
