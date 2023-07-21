///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/05 12:36)

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

        using BufferSource = CoreTools::BufferSource;
        using BufferTarget = CoreTools::BufferTarget;
        using ObjectLink = CoreTools::ObjectLink;
        using ObjectRegister = CoreTools::ObjectRegister;

    public:
        ShaderData(GraphicsObjectType inType, const std::string& inName, int inBindPoint, int inNumBytes, int inExtra, bool inIsGpuWritable);

        CLASS_INVARIANT_DECLARE;

        NODISCARD GraphicsObjectType GetType() const noexcept;

        NODISCARD std::string GetName() const;
        NODISCARD int GetBindPoint() const noexcept;
        NODISCARD int GetNumBytes() const noexcept;
        NODISCARD int GetExtra() const noexcept;
        NODISCARD bool IsGpuWritable() const noexcept;

        void SetGraphicsObject(const GraphicsObjectSharedPtr& graphicsObject) noexcept;
        NODISCARD ConstGraphicsObjectSharedPtr GetGraphicsObject() const noexcept;
        NODISCARD GraphicsObjectSharedPtr GetGraphicsObject() noexcept;

        void Load(BufferSource& source);
        void Save(BufferTarget& target) const;
        NODISCARD int GetStreamingSize() const;
        void Link(ObjectLink& source);
        void Register(ObjectRegister& target) const;

    private:
        PackageType impl;
    };
}

#endif  // RENDERING_SHADERS_SHADER_DATA_H
