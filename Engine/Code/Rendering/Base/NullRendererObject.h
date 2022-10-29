///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.3 (2022/10/10 23:42)

#ifndef RENDERING_BASE_NULL_RENDERER_OBJECT_H
#define RENDERING_BASE_NULL_RENDERER_OBJECT_H

#include "Rendering/RenderingDll.h"

#include "RendererObject.h"

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE NullRendererObject : public RendererObject
    {
    public:
        using ClassType = NullRendererObject;
        using ParentType = RendererObject;

    public:
        explicit NullRendererObject(const GraphicsObjectSharedPtr& graphicsObject, const std::string& name = "");

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        void Enable() noexcept override;
    };
}

#endif  // RENDERING_BASE_NULL_RENDERER_OBJECT_H
