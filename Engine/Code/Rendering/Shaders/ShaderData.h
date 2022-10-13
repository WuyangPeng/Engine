///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.1 (2022/08/19 13:50)

#ifndef RENDERING_SHADERS_SHADER_DATA_H
#define RENDERING_SHADERS_SHADER_DATA_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"
#include "CoreTools/ObjectSystems/ObjectAssociated.h"
#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"
#include "Rendering/Base/BaseFwd.h"
#include "Rendering/Base/GraphicsObject.h"

#include <string>

RENDERING_COPY_UNSHARED_EXPORT_IMPL(ShaderData, ShaderDataImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE ShaderData
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(ShaderData);

    public:
        ShaderData(GraphicsObjectType inType, const std::string& inName, int inBindPoint, int inNumBytes, int inExtra, bool inIsGpuWritable);

        CLASS_INVARIANT_DECLARE;

        NODISCARD GraphicsObjectType GetType() const noexcept;

        NODISCARD std::string GetName() const;
        NODISCARD int GetBindPoint() const noexcept;
        NODISCARD int GetNumBytes() const noexcept;
        NODISCARD int GetExtra() const noexcept;
        NODISCARD bool IsGpuWritable() const noexcept;

        void SetObject(const GraphicsObjectSharedPtr& graphicsObject) noexcept;
        NODISCARD ConstGraphicsObjectSharedPtr GetGraphicsObject() const noexcept;

        void Load(CoreTools::BufferSource& source);
        void Save(CoreTools::BufferTarget& target) const;
        NODISCARD int GetStreamingSize() const;
        void Link(CoreTools::ObjectLink& source);
        void Register(CoreTools::ObjectRegister& target) const;

    private:
        PackageType impl;
    };
}

#endif  // RENDERING_SHADERS_SHADER_DATA_H
