/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.2 (2023/12/08 17:41)

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

        using OpenGLUInt = System::OpenGLUnsignedInt;

        using GraphicsObjectSharedPtr = std::shared_ptr<GraphicsObject>;
        using ConstGraphicsObjectSharedPtr = std::shared_ptr<const GraphicsObject>;

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
        virtual void Disable() = 0;
        NODISCARD virtual bool Update() = 0;
        NODISCARD virtual bool Update(int level) = 0;
        NODISCARD virtual bool Update(int item, int level) = 0;

        NODISCARD virtual bool CopyGpuToCpu() = 0;
        NODISCARD virtual bool CopyGpuToCpu(int level) = 0;
        NODISCARD virtual bool CopyGpuToCpu(int item, int level) = 0;

        NODISCARD virtual bool CopyCpuToGpu() = 0;
        NODISCARD virtual bool CopyCpuToGpu(int level) = 0;
        NODISCARD virtual bool CopyCpuToGpu(int item, int level) = 0;

        NODISCARD virtual bool GetNumActiveElements() = 0;

        NODISCARD virtual OpenGLUInt GetGLHandle() const noexcept;

    private:
        PackageType impl;
    };
}

#endif  // RENDERING_BASE_RENDERER_OBJECT_H
