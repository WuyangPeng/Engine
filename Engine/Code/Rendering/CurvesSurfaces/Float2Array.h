///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:58)

#ifndef RENDERING_CURVES_SURFACES_FLOAT2_ARRAY_H
#define RENDERING_CURVES_SURFACES_FLOAT2_ARRAY_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/ObjectSystems/Object.h"
#include "Mathematics/Base/Float.h"

#include <vector>

RENDERING_COPY_UNSHARED_EXPORT_IMPL(Float2Array, Float2ArrayImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE Float2Array : public CoreTools::Object
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(Float2Array);
        using ParentType = Object;
        using Float2 = Mathematics::Float2;
        using Float2Vector = std::vector<Float2>;

    public:
        explicit Float2Array(const Float2Vector& data);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(Float2Array);

        NODISCARD int GetNumElements() const;
        NODISCARD const Float2* GetData() const noexcept;

        NODISCARD const Float2& operator[](int index) const;
        NODISCARD Float2& operator[](int index);
        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;

    private:
        PackageType impl;
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(Float2Array);

#include STSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(Float2Array);
}

#endif  // RENDERING_CURVES_SURFACES_FLOAT2_ARRAY_H
