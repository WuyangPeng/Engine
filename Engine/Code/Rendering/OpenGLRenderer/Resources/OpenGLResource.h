/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2024/01/08 14:23)

#ifndef RENDERING_OPENGL_RENDERER_OPENGL_RESOURCE_H
#define RENDERING_OPENGL_RENDERER_OPENGL_RESOURCE_H

#include "Rendering/RenderingDll.h"

#include "System/OpenGL/OpenGLFwd.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "Rendering/OpenGLRenderer/OpenGLRendererObject.h"
#include "Rendering/Resources/Resource.h"

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE OpenGLResource : public OpenGLRendererObject
    {
    public:
        using ClassType = OpenGLResource;
        using ParentType = OpenGLRendererObject;

        using BindBuffer = System::BindBuffer;
        using BufferLocking = System::BufferLocking;

    public:
        OpenGLResource(const ResourceSharedPtr& resource, const std::string& name);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD ConstResourceSharedPtr GetResource() const;

        void* MapForWrite(BindBuffer target) const noexcept;
        void Unmap(BindBuffer target) const noexcept;

        NODISCARD bool CopyCpuToGpu() override = 0;
        NODISCARD bool CopyGpuToCpu() override = 0;

    protected:
        NODISCARD bool PreparedForCopy(BufferLocking access) const;
    };
}

#endif  // RENDERING_OPENGL_RENDERER_OPENGL_RESOURCE_H
