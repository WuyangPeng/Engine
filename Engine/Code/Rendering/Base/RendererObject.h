///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 14:07)

#ifndef RENDERING_BASE_RENDERER_OBJECT_H
#define RENDERING_BASE_RENDERER_OBJECT_H

#include "Rendering/RenderingDll.h"

#include "BaseFwd.h"
#include "System/OpenGL/Using/OpenGLUsing.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"
#include "CoreTools/Helper/ExportMacro.h"

#include <string>

RENDERING_COPY_UNSHARED_EXPORT_IMPL(RendererObject, RendererObjectImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE RendererObject
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(RendererObject);
        using GraphicsObjectSharedPtr = std::shared_ptr<GraphicsObject>;
        using ConstGraphicsObjectSharedPtr = std::shared_ptr<const GraphicsObject>;
        using OpenGLUInt = System::OpenGLUInt;

    public:
        explicit RendererObject(const GraphicsObjectSharedPtr& graphicsObject, const std::string& name = "");
        virtual ~RendererObject() noexcept = default;
        RendererObject(const RendererObject& rhs) = default;
        RendererObject& operator=(const RendererObject& rhs) = default;
        RendererObject(RendererObject&& rhs) noexcept = default;
        RendererObject& operator=(RendererObject&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD GraphicsObjectSharedPtr GetGraphicsObject();
        NODISCARD ConstGraphicsObjectSharedPtr GetGraphicsObject() const;
        NODISCARD std::string GetName() const;

        virtual void Enable() = 0;

        NODISCARD OpenGLUInt GetGLHandle() const noexcept;

    protected:
        void SetGLHandle(OpenGLUInt handler) noexcept;

    private:
        PackageType impl;
    };
}

#endif  // RENDERING_BASE_RENDERER_OBJECT_H
