///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.0 (2022/08/07 13:33)

#ifndef RENDERING_BASE_GRAPHICS_OBJECT_H
#define RENDERING_BASE_GRAPHICS_OBJECT_H

#include "Rendering/RenderingDll.h"

#include "BaseFwd.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/ObjectSystems/Object.h"

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE GraphicsObject : public CoreTools::Object
    {
    public:
        using ClassType = GraphicsObject;
        using ParentType = Object;

    public:
        explicit GraphicsObject(GraphicsObjectType type, const std::string& name = "");

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(GraphicsObject);

        NODISCARD GraphicsObjectType GetType() const noexcept;

        NODISCARD bool IsBuffer() const noexcept;

        NODISCARD bool IsTexture() const noexcept;

        NODISCARD bool IsTextureArray() const noexcept;

        NODISCARD bool IsShader() const noexcept;

        NODISCARD bool IsDrawingState() const noexcept;

    private:
        GraphicsObjectType graphicsObjectType;
    };
}

#endif  // RENDERING_BASE_GRAPHICS_OBJECT_H
