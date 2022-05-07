///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/07 18:07)

#ifndef RENDERING_SHADER_FLOATS_PROJECTOR_CONSTANT_IMPL_H
#define RENDERING_SHADER_FLOATS_PROJECTOR_CONSTANT_IMPL_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/ObjectSystems/ObjectAssociated.h"
#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"
#include "Rendering/SceneGraph/Projector.h"

#include <string>
#include <vector>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE ProjectorConstantImpl
    {
    public:
        using ClassType = ProjectorConstantImpl;
        using BufferSource = CoreTools::BufferSource;
        using BufferTarget = CoreTools::BufferTarget;
        using ObjectLink = CoreTools::ObjectLink;
        using ObjectRegister = CoreTools::ObjectRegister;
        using Object = CoreTools::Object;
        using ObjectSharedPtr = CoreTools::ObjectSharedPtr;
        using ConstObjectSharedPtr = CoreTools::ConstObjectSharedPtr;

    public:
        explicit ProjectorConstantImpl(const ProjectorSharedPtr& projector) noexcept;
        ProjectorConstantImpl() noexcept;

        virtual ~ProjectorConstantImpl() noexcept = default;
        ProjectorConstantImpl(const ProjectorConstantImpl& rhs) = default;
        ProjectorConstantImpl& operator=(const ProjectorConstantImpl& rhs) = default;
        ProjectorConstantImpl(ProjectorConstantImpl&& rhs) noexcept = default;
        ProjectorConstantImpl& operator=(ProjectorConstantImpl&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        virtual void Load(CoreTools::BufferSource& source);
        virtual void Save(CoreTools::BufferTarget& target) const;
        NODISCARD virtual int GetStreamingSize() const noexcept;
        void Link(CoreTools::ObjectLink& source);
        void Register(CoreTools::ObjectRegister& target) const;

        NODISCARD ObjectSharedPtr GetObjectByName(const std::string& name);
        NODISCARD std::vector<ObjectSharedPtr> GetAllObjectsByName(const std::string& name);
        NODISCARD ConstObjectSharedPtr GetConstObjectByName(const std::string& name) const;
        NODISCARD std::vector<ConstObjectSharedPtr> GetAllConstObjectsByName(const std::string& name) const;

        NODISCARD ConstProjectorSharedPtr GetProjector() const noexcept;

    private:
        CoreTools::ObjectAssociated<Projector> projector;
    };
}

#endif  // RENDERING_SHADER_FLOATS_PROJECTOR_CONSTANT_IMPL_H
