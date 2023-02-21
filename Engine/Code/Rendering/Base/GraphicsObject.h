///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.2 (2022/09/21 14:02)

#ifndef RENDERING_BASE_GRAPHICS_OBJECT_H
#define RENDERING_BASE_GRAPHICS_OBJECT_H

#include "Rendering/RenderingDll.h"

#include "BaseFwd.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/ObjectSystems/Object.h"
#include "Rendering/Renderers/RenderersFwd.h"

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE GraphicsObject : public CoreTools::Object
    {
    public:
        using ClassType = GraphicsObject;
        using ParentType = Object;

        using ObjectLink = CoreTools::ObjectLink;
        using BufferSource = CoreTools::BufferSource;
        using BufferTarget = CoreTools::BufferTarget;
        using ObjectRegister = CoreTools::ObjectRegister;
        using RendererObjectSharedPtr = std::shared_ptr<RendererObject>;

    public:
        GraphicsObject(const std::string& name, GraphicsObjectType type);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(GraphicsObject);

        NODISCARD GraphicsObjectType GetType() const noexcept;

        NODISCARD bool IsBuffer() const noexcept;

        NODISCARD bool IsTexture() const noexcept;

        NODISCARD bool IsTextureArray() const noexcept;

        NODISCARD bool IsShader() const noexcept;

        NODISCARD bool IsDrawingState() const noexcept;

        NODISCARD virtual RendererObjectSharedPtr CreateRendererObject(RendererTypes rendererTypes) = 0;

    private:
        GraphicsObjectType graphicsObjectType;
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(GraphicsObject);

#include STSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(GraphicsObject);
}

#endif  // RENDERING_BASE_GRAPHICS_OBJECT_H
