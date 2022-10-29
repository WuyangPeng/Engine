///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.3 (2022/10/16 22:18)

#ifndef RENDERING_OPENGL_RENDERER_OPENGL_RESOURCE_H
#define RENDERING_OPENGL_RENDERER_OPENGL_RESOURCE_H

#include "Rendering/RenderingDll.h"

#include "System/OpenGL/OpenGLFwd.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "Rendering/Base/RendererObject.h"
#include "Rendering/Resources/Resource.h"

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE OpenGLResource : public RendererObject
    {
    public:
        using ClassType = OpenGLResource;
        using ParentType = RendererObject;
        using BufferLocking = System::BufferLocking;

    public:
        OpenGLResource(const ResourceSharedPtr& resource, const std::string& name);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD ConstResourceSharedPtr GetResource() const;

        NODISCARD virtual bool Update() = 0;
        NODISCARD virtual bool CopyCpuToGpu() = 0;
        NODISCARD virtual bool CopyGpuToCpu() = 0;

    protected:
        NODISCARD bool PreparedForCopy(BufferLocking access) const;
    };
}

#endif  // RENDERING_OPENGL_RENDERER_OPENGL_RESOURCE_H
