// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/24 15:16)

#ifndef RENDERING_SHADERS_DEPTH_STATE_H
#define RENDERING_SHADERS_DEPTH_STATE_H

#include "Rendering/RenderingDll.h"

#include "Flags/DepthStateFlags.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/Helper/SubclassSmartPointerMacro.h"
#include "CoreTools/ObjectSystems/Object.h"

namespace CoreTools
{
    class WriteFileManager;
    class ReadFileManager;
}

RENDERING_EXPORT_SHARED_PTR(DepthStateImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE DepthState : public CoreTools::Object
    {
    public:
        COPY_UNSHARE_CLASSES_TYPE_DECLARE(DepthState);
        using ParentType = Object;
        using CompareMode = DepthStateFlags::CompareMode;
        using WriteFileManager = CoreTools::WriteFileManager;
        using ReadFileManager = CoreTools::ReadFileManager;

    public:
        DepthState();
        ~DepthState();
        DepthState(DepthState&&) noexcept = default;
        DepthState& operator=(DepthState&&) noexcept = default;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(DepthState);

        bool IsEnabled() const;
        bool IsWritable() const;
        CompareMode GetCompare() const;

        void SetEnabled(bool enabled);
        void SetWritable(bool writable);
        void SetCompare(CompareMode compare);

        void SaveState(WriteFileManager& manager) const;
        void LoadState(ReadFileManager& manager);

    private:
        IMPL_TYPE_DECLARE(DepthState);
    };
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
    CORE_TOOLS_STREAM_REGISTER(DepthState);
#include STSTEM_WARNING_POP
    CORE_TOOLS_SUBCLASS_SMART_POINTER_DECLARE(Third, DepthState);
}

#endif  // RENDERING_SHADERS_DEPTH_STATE_H
