/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/11/21 09:10)

#ifndef RENDERING_CONTROLLERS_CONTROLLED_OBJECT_IMPL_H
#define RENDERING_CONTROLLERS_CONTROLLED_OBJECT_IMPL_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/ObjectSystems/ObjectAssociated.h"
#include "Rendering/Controllers/ControllerInterface.h"

#include <vector>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE ControlledObjectImpl
    {
    public:
        using ClassType = ControlledObjectImpl;

        using Object = CoreTools::Object;
        using ObjectLink = CoreTools::ObjectLink;
        using ObjectRegister = CoreTools::ObjectRegister;
        using BufferSource = CoreTools::BufferSource;
        using BufferTarget = CoreTools::BufferTarget;

        using ControllerWeakPtr = std::weak_ptr<ControllerInterface>;
        using ControllerSharedPtr = std::shared_ptr<ControllerInterface>;
        using ConstControllerSharedPtr = std::shared_ptr<const ControllerInterface>;

    public:
        ControlledObjectImpl() noexcept;
        ~ControlledObjectImpl() noexcept;

        ControlledObjectImpl(const ControlledObjectImpl& rhs) = default;
        ControlledObjectImpl& operator=(const ControlledObjectImpl& rhs) = default;
        ControlledObjectImpl(ControlledObjectImpl&& rhs) noexcept = default;
        ControlledObjectImpl& operator=(ControlledObjectImpl&& rhs) noexcept = default;

        CLASS_INVARIANT_DECLARE;

        CORE_TOOLS_NAMES_IMPL_DECLARE;

        NODISCARD bool Update(double applicationTime);

        // 访问控制器控制该对象。
        NODISCARD int GetNumControllers() const;
        NODISCARD ConstControllerInterfaceSharedPtr GetConstController(int index) const;
        NODISCARD ControllerInterfaceSharedPtr GetController(int index);
        void AttachController(const ControllerInterfaceSharedPtr& aController, const ControllerInterfaceSharedPtr& self);
        void DetachController(const ControllerInterfaceSharedPtr& aController);
        void DetachAllControllers();

        void Load(BufferSource& source);
        void Save(BufferTarget& target) const;
        NODISCARD int GetStreamingSize() const;
        void Register(ObjectRegister& target) const;
        void Link(ObjectLink& source);

    private:
        using ObjectAssociated = CoreTools::ObjectAssociated<ControllerInterface>;
        using ControllerContainer = std::vector<ObjectAssociated>;

    private:
        // 控制器控制该对象的数组。
        ControllerContainer controllers;
    };
}

#endif  // RENDERING_CONTROLLERS_CONTROLLED_OBJECT_IMPL_H
