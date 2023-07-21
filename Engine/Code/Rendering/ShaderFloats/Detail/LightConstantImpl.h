///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 10:58)

#ifndef RENDERING_SHADER_FLOATS_LIGHT_CONSTANT_IMPL_H
#define RENDERING_SHADER_FLOATS_LIGHT_CONSTANT_IMPL_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/ObjectSystems/ObjectAssociated.h"
#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"
#include "Rendering/LocalEffects/Light.h"

#include <string>
#include <vector>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE LightConstantImpl
    {
    public:
        using ClassType = LightConstantImpl;
        using BufferSource = CoreTools::BufferSource;
        using BufferTarget = CoreTools::BufferTarget;
        using ObjectLink = CoreTools::ObjectLink;
        using ObjectRegister = CoreTools::ObjectRegister;
        using Object = CoreTools::Object;
        using ObjectSharedPtr = CoreTools::ObjectSharedPtr;
        using ConstObjectSharedPtr = CoreTools::ConstObjectSharedPtr;

    public:
        explicit LightConstantImpl(const LightSharedPtr& light) noexcept;
        LightConstantImpl() noexcept;

        CLASS_INVARIANT_DECLARE;

        void Load(CoreTools::BufferSource& source);
        void Save(CoreTools::BufferTarget& target) const;
        NODISCARD int GetStreamingSize() const noexcept;
        void Link(CoreTools::ObjectLink& source);
        void Register(CoreTools::ObjectRegister& target) const;

        NODISCARD ObjectSharedPtr GetObjectByName(const std::string& name);
        NODISCARD std::vector<ObjectSharedPtr> GetAllObjectsByName(const std::string& name);
        NODISCARD ConstObjectSharedPtr GetConstObjectByName(const std::string& name) const;
        NODISCARD std::vector<ConstObjectSharedPtr> GetAllConstObjectsByName(const std::string& name) const;

        NODISCARD ConstLightSharedPtr GetLight() const noexcept;

    private:
        CoreTools::ObjectAssociated<Light> light;
    };
}

#endif  // RENDERING_SHADER_FLOATS_LIGHT_CONSTANT_IMPL_H
