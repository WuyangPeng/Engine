///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/28 10:24)

#include "Rendering/RenderingExport.h"

#include "RendererObjectBridgeImpl.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Rendering/Base/GraphicsObject.h"
#include "Rendering/Base/RendererObject.h"
#include "Rendering/Base/TotalAllocation.h"
#include "Rendering/Resources/Resource.h"

Rendering::RendererObjectBridgeImpl::RendererObjectBridgeImpl() noexcept
    : container{}
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, RendererObjectBridgeImpl);

Rendering::RendererObjectBridgeImpl::RendererObjectSharedPtr Rendering::RendererObjectBridgeImpl::BindRendererObject(RendererTypes rendererTypes, const GraphicsObjectSharedPtr& graphicsObject)
{
    RENDERING_CLASS_IS_VALID_9;

    if (auto iter = container.find(graphicsObject);
        iter == container.end())
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

    if (const auto iter = container.find(graphicsObject);
        iter != container.end())
    {
        return iter->second;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("RendererObject未绑定。"s))
    }
}

Rendering::TotalAllocation Rendering::RendererObjectBridgeImpl::GetTotalAllocation() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    TotalAllocation totalAllocation{};

    for (const auto& element : container)
    {
        const auto& object = element.second;

        const auto resource = boost::polymorphic_pointer_downcast<const Resource>(object->GetGraphicsObject());
        totalAllocation.AddNumObjects(1);
        totalAllocation.AddNumBytes(resource->GetNumBytes());
    }

    return totalAllocation;
}

void Rendering::RendererObjectBridgeImpl::Release() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    container.clear();
}