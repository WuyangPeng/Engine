/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/28 17:54)

#ifndef RENDERING_SCENE_GRAPH_LIGHT_H
#define RENDERING_SCENE_GRAPH_LIGHT_H

#include "Rendering/RenderingDll.h"

#include "ViewVolume.h"
#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"

#include <string>

RENDERING_COPY_UNSHARED_EXPORT_IMPL(Light, LightImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE Light : public ViewVolume
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(Light);
        using ParentType = ViewVolume;

    public:
        Light(bool isPerspective, DepthType depthType, float epsilon);

        CLASS_INVARIANT_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(Light);

        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;

    private:
        PackageType impl;
    };
}

#endif  // RENDERING_SCENE_GRAPH_LIGHT_H
