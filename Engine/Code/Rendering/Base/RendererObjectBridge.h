///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 14:07)

#ifndef RENDERING_BASE_RENDERER_OBJECT_BRIDGE_H
#define RENDERING_BASE_RENDERER_OBJECT_BRIDGE_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/DelayCopyUnsharedMacro.h"
#include "Rendering/Base/BaseFwd.h"
#include "Rendering/Renderers/RenderersFwd.h"

#include <map>
#include <memory>

RENDERING_DELAY_COPY_UNSHARED_EXPORT_IMPL(RendererObjectBridge, RendererObjectBridgeImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE RendererObjectBridge
    {
    public:
        DELAY_COPY_UNSHARED_TYPE_DECLARE(RendererObjectBridge);

        using RendererObjectBridgeSharedPtr = std::shared_ptr<RendererObjectBridge>;
        using GraphicsObjectSharedPtr = std::shared_ptr<GraphicsObject>;
        using RendererObjectSharedPtr = std::shared_ptr<RendererObject>;
        using ConstRendererObjectSharedPtr = std::shared_ptr<const RendererObject>;

    public:
        NODISCARD static RendererObjectBridgeSharedPtr Create();
        explicit RendererObjectBridge(CoreTools::DisableNotThrow disableNotThrow);

        CLASS_INVARIANT_DECLARE;

        NODISCARD RendererObjectSharedPtr BindRendererObject(RendererTypes rendererTypes, const GraphicsObjectSharedPtr& graphicsObject);
        void UnbindRendererObject(const GraphicsObjectSharedPtr& graphicsObject);
        NODISCARD RendererObjectSharedPtr GetRendererObject(const GraphicsObjectSharedPtr& graphicsObject);
        NODISCARD ConstRendererObjectSharedPtr GetRendererObject(const GraphicsObjectSharedPtr& graphicsObject) const;

    private:
        PackageType impl;
    };
}

#endif  // RENDERING_BASE_RENDERER_OBJECT_BRIDGE_H
