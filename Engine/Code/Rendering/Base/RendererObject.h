///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.0 (2022/08/04 11:54)

#ifndef RENDERING_BASE_RENDERER_OBJECT_H
#define RENDERING_BASE_RENDERER_OBJECT_H

#include "Rendering/RenderingDll.h"

#include "BaseFwd.h"
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

    public:
        explicit RendererObject(const GraphicsObjectSharedPtr& graphicsObject, const std::string& name = "");
        virtual ~RendererObject() noexcept = default;
        RendererObject(const RendererObject& rhs) = default;
        RendererObject& operator=(const RendererObject& rhs) = default;
        RendererObject(RendererObject&& rhs) noexcept = default;
        RendererObject& operator=(RendererObject&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD GraphicsObjectSharedPtr GetGraphicsObject() const;
        NODISCARD std::string GetName() const;

    private:
        PackageType impl;
    };
}

#endif  // RENDERING_BASE_RENDERER_OBJECT_H
