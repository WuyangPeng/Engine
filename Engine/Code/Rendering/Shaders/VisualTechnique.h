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

#include "CoreTools/ObjectSystems/Object.h"

 
EXPORT_SHARED_PTR(Rendering, VisualTechniqueImpl, RENDERING_DEFAULT_DECLARE);
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
        void Swap(VisualTechnique& rhs) noexcept;
        
            public:
                TYPE_DECLARE(VisualTechnique);
                using ClassShareType = CoreTools::CopyUnsharedClasses;
                ~VisualTechnique() noexcept;
                VisualTechnique(const VisualTechnique& rhs);
                VisualTechnique& operator=(const VisualTechnique& rhs);
                VisualTechnique(VisualTechnique&& rhs) noexcept;
                VisualTechnique& operator=(VisualTechnique&& rhs) noexcept;
        using ParentType = Object;
        using WriteFileManager = CoreTools::WriteFileManager;
        using ReadFileManager = CoreTools::ReadFileManager;

    public:
        VisualTechnique(); 

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(VisualTechnique);
        CORE_TOOLS_NAMES_OVERRIDE_DECLARE;

        // 支持延迟构造。函数追加新的pass到数组的末尾。
        void InsertPass(const VisualPassSharedPtr& pass);

        int GetNumPasses() const;
        const ConstVisualPassSharedPtr GetPass(int passIndex) const;

        // 访问pass的组件。
        const ConstVertexShaderSharedPtr GetVertexShader(int passIndex) const;
        const ConstPixelShaderSharedPtr GetPixelShader(int passIndex) const;
        const ConstAlphaStateSharedPtr GetAlphaState(int passIndex) const;
        const ConstCullStateSharedPtr GetCullState(int passIndex) const;
        const ConstDepthStateSharedPtr GetDepthState(int passIndex) const;
        const ConstOffsetStateSharedPtr GetOffsetState(int passIndex) const;
        const ConstStencilStateSharedPtr GetStencilState(int passIndex) const;
        const ConstWireStateSharedPtr GetWireState(int passIndex) const;

        void SaveVisualPass(WriteFileManager& manager) const;
        void LoadVisualPass(ReadFileManager& manager);
        ObjectInterfaceSharedPtr CloneObject() const override;
    private:
        using ImplPtr = std::shared_ptr<ImplType>;    private:        ImplPtr impl;
    };
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
    CORE_TOOLS_STREAM_REGISTER(VisualTechnique);
#include STSTEM_WARNING_POP
    CORE_TOOLS_SHARED_PTR_DECLARE( VisualTechnique);
}

#endif  // RENDERING_SHADERS_VISUAL_TECHNIQUE_H
