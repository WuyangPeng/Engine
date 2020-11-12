// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/25 15:54)

#ifndef RENDERING_CURVES_SURFACES_FLOAT2_ARRAY_H
#define RENDERING_CURVES_SURFACES_FLOAT2_ARRAY_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include "CoreTools/ObjectSystems/Object.h"
#include "Mathematics/Base/Float.h"

#include <vector>

RENDERING_EXPORT_SHARED_PTR(Float2ArrayImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE Float2Array : public CoreTools::Object
    {
    public:
        COPY_UNSHARE_CLASSES_TYPE_DECLARE(Float2Array, = default);
        using ParentType = Object;
        using Float2 = Mathematics::Float2;
        using Float2Vector = std::vector<Float2>;

    public:
        explicit Float2Array(const Float2Vector& data);
        

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(Float2Array);

        int GetNumElements() const;
        const Float2* GetData() const noexcept;

        const Float2& operator[](int index) const;
        Float2& operator[](int index);
        ObjectInterfaceSharedPtr CloneObject() const override;
    private:
        IMPL_TYPE_DECLARE(Float2Array);
    };
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
    CORE_TOOLS_STREAM_REGISTER(Float2Array);
#include STSTEM_WARNING_POP
    CORE_TOOLS_SHARED_PTR_DECLARE( Float2Array);
}

#endif  // RENDERING_CURVES_SURFACES_FLOAT2_ARRAY_H
