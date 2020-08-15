// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎版本：0.0.0.3 (2019/07/24 15:34)

#ifndef RENDERING_SHADERS_VISUAL_TECHNIQUE_H
#define RENDERING_SHADERS_VISUAL_TECHNIQUE_H

#include "Rendering/RenderingDll.h"

#include "VisualPass.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/Helper/SubclassSmartPointerMacro.h"
#include "CoreTools/ObjectSystems/Object.h"

RENDERING_EXPORT_SHARED_PTR(VisualTechniqueImpl);

namespace CoreTools
{
    class WriteFileManager;
    class ReadFileManager;
}

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE VisualTechnique : public CoreTools::Object
    {
    public:
        COPY_UNSHARE_CLASSES_TYPE_DECLARE(VisualTechnique);
        using ParentType = Object;
        using WriteFileManager = CoreTools::WriteFileManager;
        using ReadFileManager = CoreTools::ReadFileManager;

    public:
        VisualTechnique();
        ~VisualTechnique();
        VisualTechnique(VisualTechnique&&) noexcept = default;
        VisualTechnique& operator=(VisualTechnique&&) noexcept = default;
        CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(VisualTechnique);
        CORE_TOOLS_NAMES_OVERRIDE_DECLARE;

        // 支持延迟构造。函数追加新的pass到数组的末尾。
        void InsertPass(const VisualPassSmartPointer& pass);

        int GetNumPasses() const;
        const ConstVisualPassSmartPointer GetPass(int passIndex) const;

        // 访问pass的组件。
        const ConstVertexShaderSmartPointer GetVertexShader(int passIndex) const;
        const ConstPixelShaderSmartPointer GetPixelShader(int passIndex) const;
        const ConstAlphaStateSmartPointer GetAlphaState(int passIndex) const;
        const ConstCullStateSmartPointer GetCullState(int passIndex) const;
        const ConstDepthStateSmartPointer GetDepthState(int passIndex) const;
        const ConstOffsetStateSmartPointer GetOffsetState(int passIndex) const;
        const ConstStencilStateSmartPointer GetStencilState(int passIndex) const;
        const ConstWireStateSmartPointer GetWireState(int passIndex) const;

        void SaveVisualPass(WriteFileManager& manager) const;
        void LoadVisualPass(ReadFileManager& manager);

    private:
        IMPL_TYPE_DECLARE(VisualTechnique);
    };
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
    CORE_TOOLS_STREAM_REGISTER(VisualTechnique);
#include STSTEM_WARNING_POP
    CORE_TOOLS_SUBCLASS_SMART_POINTER_DECLARE(Third, VisualTechnique);
}

#endif  // RENDERING_SHADERS_VISUAL_TECHNIQUE_H
