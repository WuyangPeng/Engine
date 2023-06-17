///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 14:07)

#include "Rendering/RenderingExport.h"

#include "RendererObjectBridgeImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Rendering/Base/GraphicsObject.h"

Rendering::RendererObjectBridgeImpl::RendererObjectBridgeImpl() noexcept
    : container{}
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, RendererObjectBridgeImpl);

Rendering::RendererObjectBridgeImpl::RendererObjectSharedPtr Rendering::RendererObjectBridgeImpl::BindRendererObject(RendererTypes rendererTypes, const GraphicsObjectSharedPtr& graphicsObject)
{
    RENDERING_CLASS_IS_VALID_9;

    auto iter = container.find(graphicsObject);
    if (iter == container.end())
    {
        auto rendererObject = graphicsObject->CreateRendererObject(rendererTypes);

        iter = container.emplace(graphicsObject, rendererObject).first;

        return iter->second;
    }
    else
    {
        return iter->second;
    }
}

void Rendering::RendererObjectBridgeImpl::UnbindRendererObject(const GraphicsObjectSharedPtr& graphicsObject)
{
    RENDERING_CLASS_IS_VALID_9;

    container.erase(graphicsObject);
}

Rendering::RendererObjectBridgeImpl::RendererObjectSharedPtr Rendering::RendererObjectBridgeImpl::GetRendererObject(const GraphicsObjectSharedPtr& graphicsObject)
{
    RENDERING_CLASS_IS_VALID_9;

    return const_pointer_cast<RendererObject>(static_cast<const ClassType>(*this).GetRendererObject(graphicsObject));
}

Rendering::RendererObjectBridgeImpl::ConstRendererObjectSharedPtr Rendering::RendererObjectBridgeImpl::GetRendererObject(const GraphicsObjectSharedPtr& graphicsObject) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    const auto iter = container.find(graphicsObject);
    if (iter != container.end())
    {
        return iter->second;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("RendererObjectδ�󶨡�"s));
    }
}
