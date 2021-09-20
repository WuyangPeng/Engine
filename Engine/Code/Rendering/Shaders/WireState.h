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

 
EXPORT_SHARED_PTR(Rendering, WireStateImpl, RENDERING_DEFAULT_DECLARE);
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
        void Swap(WireState& rhs) noexcept;
       
           public:
               TYPE_DECLARE(WireState);
               using ClassShareType = CoreTools::CopyUnsharedClasses;
               ~WireState() noexcept= default;
               WireState(const WireState& rhs);
               WireState& operator=(const WireState& rhs);
               WireState(WireState&& rhs) noexcept;
               WireState& operator=(WireState&& rhs) noexcept;
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
        using ImplPtr = std::shared_ptr<ImplType>;    private:        ImplPtr impl;
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
    CORE_TOOLS_STREAM_REGISTER(WireState);
#include STSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE( WireState);
}

#endif  // RENDERING_SHADERS_WIRE_STATE_H
