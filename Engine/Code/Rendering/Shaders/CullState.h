// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ����汾��0.0.0.3 (2019/07/24 15:15)

#ifndef RENDERING_SHADERS_CULL_STATE_H
#define RENDERING_SHADERS_CULL_STATE_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include "CoreTools/ObjectSystems/Object.h"

namespace CoreTools
{
    class WriteFileManager;
    class ReadFileManager;
}

RENDERING_EXPORT_SHARED_PTR(CullStateImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE CullState : public CoreTools::Object
    {
    public:
        COPY_UNSHARE_CLASSES_TYPE_DECLARE(CullState, DESTRUCTOR_STATEMENT);
        using ParentType = Object;
        using WriteFileManager = CoreTools::WriteFileManager;
        using ReadFileManager = CoreTools::ReadFileManager;

    public:
        CullState(); 

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(CullState);

        bool IsEnabled() const noexcept;
        void SetEnabled(bool enabled) noexcept;
        bool IsCCWOrder() const noexcept;
        void SetCCWOrder(bool cCWOrder) noexcept;

        void SaveState(WriteFileManager& manager) const;
        void LoadState(ReadFileManager& manager);
         ObjectInterfaceSharedPtr CloneObject() const override;
    private:
        IMPL_TYPE_DECLARE(CullState);
    };
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
    CORE_TOOLS_STREAM_REGISTER(CullState);
#include STSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE( CullState);
}

#endif  // RENDERING_SHADERS_CULL_STATE_H
