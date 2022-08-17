///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.0 (2022/08/04 11:54)

#ifndef RENDERING_RENDERERS_BLEND_STATE_H
#define RENDERING_RENDERERS_BLEND_STATE_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/ObjectSystems/Object.h"

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE BlendState
    {
    public:
        using ClassType = BlendState;

    public:
        void SetName(const std::string& name) noexcept;
    };
}

#endif  // RENDERING_RENDERERS_BLEND_STATE_H
