/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.2 (2023/12/08 17:41)

#ifndef RENDERING_BASE_GRAPHICS_OBJECT_H
#define RENDERING_BASE_GRAPHICS_OBJECT_H

#include "Rendering/RenderingDll.h"

#include "BaseFwd.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/ObjectSystems/Object.h"
#include "Rendering/RendererEngine/RendererEngineFwd.h"

RENDERING_COPY_UNSHARED_EXPORT_IMPL(GraphicsObject, GraphicsObjectImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE GraphicsObject : public CoreTools::Object
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(GraphicsObject);
        using ParentType = Object;

        using ObjectLink = CoreTools::ObjectLink;
        using BufferSource = CoreTools::BufferSource;
        using BufferTarget = CoreTools::BufferTarget;
        using ObjectRegister = CoreTools::ObjectRegister;
        using RendererObjectSharedPtr = std::shared_ptr<RendererObject>;
        using RendererObjectBridgeSharedPtr = std::shared_ptr<RendererObjectBridge>;

    public:
        GraphicsObject(const std::string& name, GraphicsObjectType graphicsObjectType);
        ~GraphicsObject() noexcept;
        GraphicsObject(const GraphicsObject& rhs) = default;
        GraphicsObject& operator=(const GraphicsObject& rhs) = default;
        GraphicsObject(GraphicsObject&& rhs) noexcept = default;
        GraphicsObject& operator=(GraphicsObject&& rhs) noexcept = default;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(GraphicsObject);

        NODISCARD GraphicsObjectType GetType() const noexcept;

        NODISCARD bool IsBuffer() const noexcept;
        NODISCARD bool IsTexture() const noexcept;
        NODISCARD bool IsTextureArray() const noexcept;
        NODISCARD bool IsShader() const noexcept;
        NODISCARD bool IsDrawingState() const noexcept;

        NODISCARD virtual RendererObjectSharedPtr CreateRendererObject(RendererTypes rendererTypes) = 0;

        void SetRendererObjectBridge(const RendererObjectBridgeSharedPtr& aRendererObjectBridge) noexcept;

    private:
        void Release();

    private:
        PackageType impl;
    };

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(GraphicsObject);

#include SYSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(GraphicsObject);
}

#endif  // RENDERING_BASE_GRAPHICS_OBJECT_H
