// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ����汾��0.0.0.3 (2019/07/24 15:34)

#ifndef RENDERING_SHADERS_WIRE_STATE_H
#define RENDERING_SHADERS_WIRE_STATE_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include "CoreTools/ObjectSystems/Object.h"

RENDERING_EXPORT_SHARED_PTR(WireStateImpl);

namespace CoreTools
{
    class WriteFileManager;
    class ReadFileManager;
}

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE WireState : public CoreTools::Object
    {
    public:
        COPY_UNSHARE_CLASSES_TYPE_DECLARE(WireState, DESTRUCTOR_DEFAULT);
        using ParentType = Object;
        using WriteFileManager = CoreTools::WriteFileManager;
        using ReadFileManager = CoreTools::ReadFileManager;

    public:
        WireState(); 

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(WireState);

        bool IsEnabled() const noexcept;
        void SetEnabled(bool enabled) noexcept;

        void SaveState(WriteFileManager& manager) const;
        void LoadState(ReadFileManager& manager);
        ObjectInterfaceSharedPtr CloneObject() const override;
    private:
        IMPL_TYPE_DECLARE(WireState);
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
    CORE_TOOLS_STREAM_REGISTER(WireState);
#include STSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE( WireState);
}

#endif  // RENDERING_SHADERS_WIRE_STATE_H
