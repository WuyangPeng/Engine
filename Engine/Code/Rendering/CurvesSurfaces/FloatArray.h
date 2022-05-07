///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/16 18:03)

#ifndef RENDERING_CURVES_SURFACES_FLOAT_ARRAY_H
#define RENDERING_CURVES_SURFACES_FLOAT_ARRAY_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/ObjectSystems/Object.h"

#include <vector>

RENDERING_COPY_UNSHARED_EXPORT_IMPL(FloatArray, FloatArrayImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE FloatArray : public CoreTools::Object
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(FloatArray);
        using ParentType = Object;
        using FloatVector = std::vector<float>;

    public:
        explicit FloatArray(const FloatVector& data);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(FloatArray);

        NODISCARD int GetNumElements() const;
        NODISCARD const float* GetData() const noexcept;

        NODISCARD const float& operator[](int index) const;
        NODISCARD float& operator[](int index);

        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;

    private:
        PackageType impl;
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_STREAM_REGISTER(FloatArray);

#include STSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(FloatArray);
}

#endif  // RENDERING_CURVES_SURFACES_FLOAT_ARRAY_H
