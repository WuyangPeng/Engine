///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/13 14:20)

#ifndef RENDERING_SHADERS_OFFSET_STATE_H
#define RENDERING_SHADERS_OFFSET_STATE_H

#include "Rendering/RenderingDll.h"

#include "Flags/DepthStateFlags.h"
#include "CoreTools/FileManager/FileManagerFwd.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/ObjectSystems/Object.h"
#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"

RENDERING_COPY_UNSHARED_EXPORT_IMPL(OffsetState, OffsetStateImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE OffsetState : public CoreTools::Object
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(OffsetState);
        using ParentType = Object;
        using WriteFileManager = CoreTools::WriteFileManager;
        using ReadFileManager = CoreTools::ReadFileManager;

    public:
        explicit OffsetState(MAYBE_UNUSED CoreTools::DisableNotThrow disableNotThrow);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(OffsetState);

        NODISCARD bool IsFillEnabled() const noexcept;
        NODISCARD bool IsLineEnabled() const noexcept;
        NODISCARD bool IsPointEnabled() const noexcept;
        NODISCARD float GetScale() const noexcept;
        NODISCARD float GetBias() const noexcept;

        void SetFillEnabled(bool fillEnabled) noexcept;
        void SetLineEnabled(bool lineEnabled) noexcept;
        void SetPointEnabled(bool pointEnabled) noexcept;
        void SetScale(float scale) noexcept;
        void SetBias(float bias) noexcept;

        void SaveState(WriteFileManager& manager) const;
        void LoadState(ReadFileManager& manager);
        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;

    private:
        PackageType impl;
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
    CORE_TOOLS_STREAM_REGISTER(OffsetState);

#include STSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(OffsetState);
}

#endif  // RENDERING_SHADERS_OFFSET_STATE_H
