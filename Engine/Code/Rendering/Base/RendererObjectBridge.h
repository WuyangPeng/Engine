/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.2 (2023/12/08 17:43)

#ifndef RENDERING_BASE_RENDERER_OBJECT_BRIDGE_H
#define RENDERING_BASE_RENDERER_OBJECT_BRIDGE_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/DelayCopyUnsharedMacro.h"
#include "Rendering/Base/BaseFwd.h"
#include "Rendering/RendererEngine/RendererEngineFwd.h"
#include "Rendering/Resources/Textures/DrawTarget.h"

#include <map>
#include <memory>

RENDERING_DELAY_COPY_UNSHARED_EXPORT_IMPL(RendererObjectBridge, RendererObjectBridgeImpl);
template class RENDERING_DEFAULT_DECLARE std::weak_ptr<Rendering::RendererObjectBridge>;
template class RENDERING_DEFAULT_DECLARE std::enable_shared_from_this<Rendering::RendererObjectBridge>;

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE RendererObjectBridge : public std::enable_shared_from_this<RendererObjectBridge>
    {
    public:
        DELAY_COPY_UNSHARED_TYPE_DECLARE(RendererObjectBridge);

        using RendererObjectBridgeSharedPtr = std::shared_ptr<RendererObjectBridge>;
        using GraphicsObjectSharedPtr = std::shared_ptr<GraphicsObject>;
        using RendererObjectSharedPtr = std::shared_ptr<RendererObject>;
        using ConstRendererObjectSharedPtr = std::shared_ptr<const RendererObject>;

    public:
        NODISCARD static RendererObjectBridgeSharedPtr Create();

        CLASS_INVARIANT_DECLARE;

        NODISCARD RendererObjectSharedPtr BindRendererObject(RendererTypes rendererTypes, const GraphicsObjectSharedPtr& graphicsObject);
        void UnbindRendererObject(const GraphicsObjectSharedPtr& graphicsObject);
        NODISCARD RendererObjectSharedPtr GetRendererObject(const GraphicsObjectSharedPtr& graphicsObject);
        NODISCARD ConstRendererObjectSharedPtr GetRendererObject(const GraphicsObjectSharedPtr& graphicsObject) const;
        NODISCARD TotalAllocation GetTotalAllocation() const;
        void Release();

    private:
        enum class RendererObjectBridgeCreate
        {
            Init,
        };

    public:
        explicit RendererObjectBridge(RendererObjectBridgeCreate rendererObjectBridgeCreate);

    private:
        PackageType impl;
    };
}

#endif  // RENDERING_BASE_RENDERER_OBJECT_BRIDGE_H
