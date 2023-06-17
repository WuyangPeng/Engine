///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 14:07)

#ifndef RENDERING_BASE_RENDERER_OBJECT_IMPL_H
#define RENDERING_BASE_RENDERER_OBJECT_IMPL_H

#include "Rendering/RenderingDll.h"

#include "System/OpenGL/Using/OpenGLUsing.h"
#include "Rendering/Base/BaseFwd.h"

#include <memory>
#include <string>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE RendererObjectImpl
    {
    public:
        using ClassType = RendererObjectImpl;
        using GraphicsObjectSharedPtr = std::shared_ptr<GraphicsObject>;
        using ConstGraphicsObjectSharedPtr = std::shared_ptr<const GraphicsObject>;
        using GraphicsObjectWeakPtr = std::weak_ptr<GraphicsObject>;
        using OpenGLUInt = System::OpenGLUInt;

    public:
        RendererObjectImpl(const GraphicsObjectSharedPtr& graphicsObject, const std::string& name);

        CLASS_INVARIANT_DECLARE;

        NODISCARD GraphicsObjectSharedPtr GetGraphicsObject();
        NODISCARD ConstGraphicsObjectSharedPtr GetGraphicsObject() const;
        NODISCARD std::string GetName() const;

        NODISCARD OpenGLUInt GetGLHandle() const noexcept;
        void SetGLHandle(OpenGLUInt handler) noexcept;

    private:
        GraphicsObjectWeakPtr graphicsObject;
        std::string name;
        OpenGLUInt glHandle;
    };
}

#endif  // RENDERING_BASE_RENDERER_OBJECT_IMPL_H
