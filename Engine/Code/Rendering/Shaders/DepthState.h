///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 10:42)

#ifndef RENDERING_SHADERS_DEPTH_STATE_H
#define RENDERING_SHADERS_DEPTH_STATE_H

#include "Rendering/RenderingDll.h"

#include "Flags/DepthStateFlags.h"
#include "CoreTools/FileManager/FileManagerFwd.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/ObjectSystems/Object.h"
#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"

RENDERING_COPY_UNSHARED_EXPORT_IMPL(DepthState, DepthStateImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE DepthState : public CoreTools::Object
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(DepthState);
        using ParentType = Object;
        using CompareMode = DepthStateFlags::CompareMode;
        using WriteFileManager = CoreTools::WriteFileManager;
        using ReadFileManager = CoreTools::ReadFileManager;

    public:
        explicit DepthState(MAYBE_UNUSED CoreTools::DisableNotThrow disableNotThrow);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(DepthState);

        NODISCARD bool IsEnabled() const noexcept;
        NODISCARD bool IsWritable() const noexcept;
        NODISCARD CompareMode GetCompare() const noexcept;

        void SetEnabled(bool enabled) noexcept;
        void SetWritable(bool writable) noexcept;
        void SetCompare(CompareMode compare) noexcept;

        void SaveState(WriteFileManager& manager) const;
        void LoadState(ReadFileManager& manager);
        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;

    private:
        PackageType impl;
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(DepthState);

#include STSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(DepthState);
}

#endif  // RENDERING_SHADERS_DEPTH_STATE_H
