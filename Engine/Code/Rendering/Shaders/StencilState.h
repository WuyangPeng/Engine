///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/13 18:05)

#ifndef RENDERING_SHADERS_STENCIL_STATE_H
#define RENDERING_SHADERS_STENCIL_STATE_H

#include "Rendering/RenderingDll.h"

#include "Flags/StencilStateFlags.h"
#include "CoreTools/FileManager/FileManagerFwd.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/ObjectSystems/Object.h"
#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"

RENDERING_COPY_UNSHARED_EXPORT_IMPL(StencilState, StencilStateImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE StencilState : public CoreTools::Object
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(StencilState);
        using ParentType = Object;
        using CompareMode = StencilStateFlags::CompareMode;
        using OperationType = StencilStateFlags::OperationType;
        using WriteFileManager = CoreTools::WriteFileManager;
        using ReadFileManager = CoreTools::ReadFileManager;

    public:
        explicit StencilState(MAYBE_UNUSED CoreTools::DisableNotThrow disableNotThrow);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(StencilState);

        NODISCARD bool IsEnabled() const noexcept;
        NODISCARD CompareMode GetCompare() const noexcept;
        NODISCARD uint32_t GetReference() const noexcept;
        NODISCARD uint32_t GetMask() const noexcept;
        NODISCARD uint32_t GetWriteMask() const noexcept;
        NODISCARD OperationType GetOnFail() const noexcept;
        NODISCARD OperationType GetOnZFail() const noexcept;
        NODISCARD OperationType GetOnZPass() const noexcept;

        void SetEnabled(bool enabled) noexcept;
        void SetCompare(CompareMode compare) noexcept;
        void SetReference(uint32_t reference) noexcept;
        void SetMask(uint32_t mask) noexcept;
        void SetWriteMask(uint32_t writeMask) noexcept;
        void SetOnFail(OperationType onFail) noexcept;
        void SetOnZFail(OperationType onZFail) noexcept;
        void SetOnZPass(OperationType onZPass) noexcept;

        void SaveState(WriteFileManager& manager) const;
        void LoadState(ReadFileManager& manager);
        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;

    private:
        PackageType impl;
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(StencilState);

#include STSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(StencilState);
}

#endif  // RENDERING_SHADERS_STENCIL_STATE_H
