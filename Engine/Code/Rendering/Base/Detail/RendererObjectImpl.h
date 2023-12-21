/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.2 (2023/12/08 17:41)

#ifndef RENDERING_BASE_RENDERER_OBJECT_IMPL_H
#define RENDERING_BASE_RENDERER_OBJECT_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Base/BaseFwd.h"

#include <memory>
#include <string>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE RendererObjectImpl
    {
    public:
        using ClassType = RendererObjectImpl;

        using GraphicsObjectWeakPtr = std::weak_ptr<GraphicsObject>;
        using GraphicsObjectSharedPtr = std::shared_ptr<GraphicsObject>;
        using ConstGraphicsObjectSharedPtr = std::shared_ptr<const GraphicsObject>;

    public:
        RendererObjectImpl(const GraphicsObjectSharedPtr& graphicsObject, const std::string& name);

        CLASS_INVARIANT_DECLARE;

        NODISCARD GraphicsObjectSharedPtr GetGraphicsObject();
        NODISCARD ConstGraphicsObjectSharedPtr GetGraphicsObject() const;
        NODISCARD std::string GetName() const;

    private:
        GraphicsObjectWeakPtr graphicsObject;
        std::string name;
    };
}

#endif  // RENDERING_BASE_RENDERER_OBJECT_IMPL_H
