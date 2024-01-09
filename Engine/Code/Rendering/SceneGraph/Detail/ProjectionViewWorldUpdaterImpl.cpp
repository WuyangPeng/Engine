/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/28 17:50)

#include "Rendering/RenderingExport.h"

#include "ProjectionViewWorldUpdaterImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Rendering/Resources/Buffers/ConstantBufferDetail.h"

Rendering::ProjectionViewWorldUpdaterImpl::ProjectionViewWorldUpdaterImpl(CameraSharedPtr camera, const BaseRendererSharedPtr& baseRenderer)
    : camera{ std::move(camera) }, baseRenderer{ baseRenderer }, subscribers{}
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, ProjectionViewWorldUpdaterImpl)

bool Rendering::ProjectionViewWorldUpdaterImpl::Subscribe(const VisualSharedPtr& visual, const ConstantBufferSharedPtr& constantBuffer, const std::string& projectionViewWorldMatrixName)
{
    RENDERING_CLASS_IS_VALID_9;

    if (constantBuffer && constantBuffer->HasMember(projectionViewWorldMatrixName))
    {
        if (!subscribers.contains(visual))
        {
            subscribers.emplace(visual, std::make_pair(constantBuffer, projectionViewWorldMatrixName));
            return true;
        }
    }

    return false;
}

bool Rendering::ProjectionViewWorldUpdaterImpl::Subscribe(const VisualSharedPtr& visual, const std::string& projectionViewWorldMatrixName)
{
    RENDERING_CLASS_IS_VALID_9;

    if (visual != nullptr)
    {
        if (const auto effect = visual->GetVisualEffect();
            effect != nullptr)
        {
            const auto constantBuffer = effect->GetProjectionViewWorldMatrixConstant();

            return Subscribe(visual, constantBuffer, projectionViewWorldMatrixName);
        }
    }
    return false;
}

bool Rendering::ProjectionViewWorldUpdaterImpl::Unsubscribe(const VisualSharedPtr& visual) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return 0 < subscribers.erase(visual);
}

void Rendering::ProjectionViewWorldUpdaterImpl::UnsubscribeAll() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    subscribers.clear();
}

void Rendering::ProjectionViewWorldUpdaterImpl::Update()
{
    RENDERING_CLASS_IS_VALID_9;

    if (camera != nullptr)
    {
        const auto cameraProjectionViewMatrix = camera->GetProjectionViewMatrix();
        for (const auto& [visual, constant] : subscribers)
        {
            const auto matrix = visual->GetWorldTransform().GetMatrix();

            const auto projectionViewMatrix = cameraProjectionViewMatrix * matrix;

            auto constantBuffer = constant.first;
            const auto& name = constant.second;
            constantBuffer->SetMember(name, projectionViewMatrix);

            if (const auto lock = baseRenderer.lock();
                lock != nullptr)
            {
                MAYBE_UNUSED const auto result = lock->Update(constantBuffer);
            }
        }
    }
}

void Rendering::ProjectionViewWorldUpdaterImpl::Update(const VisualContainer& updateSet)
{
    RENDERING_CLASS_IS_VALID_9;

    if (camera != nullptr)
    {
        const auto cameraProjectionViewMatrix = camera->GetProjectionViewMatrix();
        for (auto& visual : updateSet)
        {
            if (visual != nullptr)
            {
                if (const auto& effect = visual->GetVisualEffect();
                    effect != nullptr)
                {
                    const auto matrix = visual->GetWorldTransform().GetMatrix();
                    const auto constantBuffer = effect->GetProjectionViewWorldMatrixConstant();

                    const auto projectionViewMatrix = cameraProjectionViewMatrix * matrix;

                    effect->SetProjectionViewWorldMatrix(Mathematics::Matrix4F{ projectionViewMatrix.GetColumnMajor(), Mathematics::MatrixMajorFlags::Column });

                    if (const auto lock = baseRenderer.lock();
                        lock != nullptr)
                    {
                        MAYBE_UNUSED const auto result = lock->Update(constantBuffer);
                    }
                }
            }
        }
    }
}

Rendering::CameraSharedPtr Rendering::ProjectionViewWorldUpdaterImpl::GetCamera() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return camera;
}
