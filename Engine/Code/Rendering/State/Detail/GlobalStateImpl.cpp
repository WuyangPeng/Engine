/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2023/12/26 11:21)

#include "Rendering/RenderingExport.h"

#include "GlobalStateImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Rendering/Base/RendererObjectBridge.h"
#include "Rendering/State/BlendState.h"
#include "Rendering/State/DepthStencilState.h"
#include "Rendering/State/RasterizerState.h"

Rendering::GlobalStateImpl::GlobalStateImpl(const std::string& blendStateName, const std::string& depthStencilStateName, const std::string& rasterizerStateName, const RendererObjectBridgeSharedPtr& rendererObjectBridge)
    : defaultBlendState{ BlendState::Create(blendStateName) },
      activeBlendState{ defaultBlendState },
      defaultDepthStencilState{ DepthStencilState::Create(depthStencilStateName) },
      activeDepthStencilState{ defaultDepthStencilState },
      defaultRasterizerState{ RasterizerState::Create(rasterizerStateName) },
      activeRasterizerState{ defaultRasterizerState },
      rendererObjectBridge{ rendererObjectBridge }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool Rendering::GlobalStateImpl::IsValid() const noexcept
{
    if (defaultBlendState != nullptr &&
        activeBlendState != nullptr &&
        defaultDepthStencilState != nullptr &&
        activeDepthStencilState != nullptr &&
        defaultRasterizerState != nullptr &&
        activeRasterizerState != nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

#endif  // OPEN_CLASS_INVARIANT

void Rendering::GlobalStateImpl::CreateDefaultGlobalState()
{
    RENDERING_CLASS_IS_VALID_1;

    SetActiveBlendState(defaultBlendState);
    SetActiveDepthStencilState(defaultDepthStencilState);
    SetActiveRasterizerState(defaultRasterizerState);
}

void Rendering::GlobalStateImpl::DestroyDefaultGlobalState()
{
    RENDERING_CLASS_IS_VALID_1;

    UnbindRendererObject(defaultBlendState);
    UnbindRendererObject(defaultDepthStencilState);
    UnbindRendererObject(defaultRasterizerState);
}

void Rendering::GlobalStateImpl::SetActiveBlendState(const BlendStateSharedPtr& state)
{
    RENDERING_CLASS_IS_VALID_1;

    if (!state)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("stateָ��Ϊ�ա�"s))
    }

    activeBlendState = state;
}

void Rendering::GlobalStateImpl::SetActiveDepthStencilState(const DepthStencilStateSharedPtr& state)
{
    RENDERING_CLASS_IS_VALID_1;

    if (!state)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("stateָ��Ϊ�ա�"s))
    }

    activeDepthStencilState = state;
}

void Rendering::GlobalStateImpl::SetActiveRasterizerState(const RasterizerStateSharedPtr& state)
{
    RENDERING_CLASS_IS_VALID_1;

    if (!state)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("stateָ��Ϊ�ա�"s))
    }

    activeRasterizerState = state;
}

Rendering::GlobalStateImpl::BlendStateSharedPtr Rendering::GlobalStateImpl::GetActiveBlendState() noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return activeBlendState;
}

Rendering::GlobalStateImpl::DepthStencilStateSharedPtr Rendering::GlobalStateImpl::GetActiveDepthStencilState() noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return activeDepthStencilState;
}

Rendering::GlobalStateImpl::RasterizerStateSharedPtr Rendering::GlobalStateImpl::GetActiveRasterizerState() noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return activeRasterizerState;
}

Rendering::GlobalStateImpl::BlendStateSharedPtr Rendering::GlobalStateImpl::GetDefaultBlendState() noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return defaultBlendState;
}

Rendering::GlobalStateImpl::DepthStencilStateSharedPtr Rendering::GlobalStateImpl::GetDefaultDepthStencilState() noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return defaultDepthStencilState;
}

Rendering::GlobalStateImpl::RasterizerStateSharedPtr Rendering::GlobalStateImpl::GetDefaultRasterizerState() noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return defaultRasterizerState;
}

Rendering::GlobalStateImpl::RendererObjectSharedPtr Rendering::GlobalStateImpl::BindRendererObject(RendererTypes rendererTypes, const GraphicsObjectSharedPtr& graphicsObject)
{
    RENDERING_CLASS_IS_VALID_9;

    return GetRendererObjectBridge()->BindRendererObject(rendererTypes, graphicsObject);
}

void Rendering::GlobalStateImpl::UnbindRendererObject(const GraphicsObjectSharedPtr& graphicsObject)
{
    RENDERING_CLASS_IS_VALID_9;

    return GetRendererObjectBridge()->UnbindRendererObject(graphicsObject);
}

Rendering::GlobalStateImpl::RendererObjectSharedPtr Rendering::GlobalStateImpl::GetRendererObject(const GraphicsObjectSharedPtr& graphicsObject)
{
    RENDERING_CLASS_IS_VALID_9;

    return GetRendererObjectBridge()->GetRendererObject(graphicsObject);
}

Rendering::GlobalStateImpl::ConstRendererObjectSharedPtr Rendering::GlobalStateImpl::GetRendererObject(const GraphicsObjectSharedPtr& graphicsObject) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    const auto result = rendererObjectBridge.lock();
    if (result == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("rendererObjectBridge���ͷš�"s))
    }

    return result->GetRendererObject(graphicsObject);
}

Rendering::GlobalStateImpl::RendererObjectBridgeSharedPtr Rendering::GlobalStateImpl::GetRendererObjectBridge()
{
    auto result = rendererObjectBridge.lock();
    if (result == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("rendererObjectBridge���ͷš�"s))
    }

    return result;
}

void Rendering::GlobalStateImpl::SetDefaultBlendState()
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    SetActiveBlendState(defaultBlendState);
}

void Rendering::GlobalStateImpl::SetDefaultDepthStencilState()
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    SetActiveDepthStencilState(defaultDepthStencilState);
}

void Rendering::GlobalStateImpl::SetDefaultRasterizerState()
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    SetActiveRasterizerState(defaultRasterizerState);
}
