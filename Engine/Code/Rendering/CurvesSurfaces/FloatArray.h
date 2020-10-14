// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/25 15:55)

#ifndef RENDERING_CURVES_SURFACES_FLOAT_ARRAY_H
#define RENDERING_CURVES_SURFACES_FLOAT_ARRAY_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include "CoreTools/ObjectSystems/Object.h"

#include <vector>

RENDERING_EXPORT_SHARED_PTR(FloatArrayImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE FloatArray : public CoreTools::Object
    {
    public:
        COPY_UNSHARE_CLASSES_TYPE_DECLARE(FloatArray, = default);
        using ParentType = Object;
        using FloatVector = std::vector<float>;

    public:
        explicit FloatArray(const FloatVector& data);
        

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(FloatArray);

        int GetNumElements() const;
        const float* GetData() const noexcept;

        const float& operator[](int index) const;
        float& operator[](int index);

         ObjectInterfaceSharedPtr CloneObject() const  override;

    private:
        IMPL_TYPE_DECLARE(FloatArray);
    };
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
    CORE_TOOLS_STREAM_REGISTER(FloatArray);
#include STSTEM_WARNING_POP
    CORE_TOOLS_SHARED_PTR_DECLARE( FloatArray);
}

#endif  // RENDERING_CURVES_SURFACES_FLOAT_ARRAY_H
