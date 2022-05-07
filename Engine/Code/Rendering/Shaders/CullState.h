///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/13 13:33)

#ifndef RENDERING_SHADERS_CULL_STATE_H
#define RENDERING_SHADERS_CULL_STATE_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/FileManager/FileManagerFwd.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/ObjectSystems/Object.h"
#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"

RENDERING_COPY_UNSHARED_EXPORT_IMPL(CullState, CullStateImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE CullState : public CoreTools::Object
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(CullState);
        using ParentType = Object;
        using WriteFileManager = CoreTools::WriteFileManager;
        using ReadFileManager = CoreTools::ReadFileManager;

    public:
        explicit CullState(MAYBE_UNUSED CoreTools::DisableNotThrow disableNotThrow);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(CullState);

        NODISCARD bool IsEnabled() const noexcept;
        void SetEnabled(bool enabled) noexcept;
        NODISCARD bool IsCCWOrder() const noexcept;
        void SetCCWOrder(bool cCWOrder) noexcept;

        void SaveState(WriteFileManager& manager) const;
        void LoadState(ReadFileManager& manager);
        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;

    private:
        PackageType impl;
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_STREAM_REGISTER(CullState);

#include STSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(CullState);
}

#endif  // RENDERING_SHADERS_CULL_STATE_H
