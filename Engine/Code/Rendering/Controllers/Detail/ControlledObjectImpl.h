///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 14:01)

#ifndef RENDERING_CONTROLLERS_CONTROLLED_OBJECT_IMPL_H
#define RENDERING_CONTROLLERS_CONTROLLED_OBJECT_IMPL_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/ObjectSystems/ObjectAssociated.h"
#include "Rendering/Controllers/ControllerInterface.h"
#include "Rendering/Controllers/Flags/ControllerFlags.h"

#include <vector>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE ControlledObjectImpl
    {
    public:
        using ClassType = ControlledObjectImpl;
        using BufferSource = CoreTools::BufferSource;
        using BufferTarget = CoreTools::BufferTarget;
        using ObjectRegister = CoreTools::ObjectRegister;
        using ObjectLink = CoreTools::ObjectLink;
        using Object = CoreTools::Object;
        using ObjectSharedPtr = CoreTools::ObjectSharedPtr;
        using ConstObjectSharedPtr = CoreTools::ConstObjectSharedPtr;

    public:
        explicit ControlledObjectImpl(ControllerInterface* realThis) noexcept;
        ~ControlledObjectImpl() noexcept;

        ControlledObjectImpl(const ControlledObjectImpl& rhs) = default;
        ControlledObjectImpl& operator=(const ControlledObjectImpl& rhs) = default;
        ControlledObjectImpl(ControlledObjectImpl&& rhs) noexcept = default;
        ControlledObjectImpl& operator=(ControlledObjectImpl&& rhs) noexcept = default;

        CLASS_INVARIANT_DECLARE;

        NODISCARD bool Update(double applicationTime);

        // ���ʿ��������Ƹö���
        NODISCARD int GetNumControllers() const;
        NODISCARD ConstControllerInterfaceSharedPtr GetConstController(int index) const;
        NODISCARD ControllerInterfaceSharedPtr GetController(int index);
        void AttachController(const ControllerInterfaceSharedPtr& controller);
        void DetachController(const ControllerInterfaceSharedPtr& controller);
        void DetachAllControllers();
        bool UpdateControllers(double applicationTime);
        void AttachControllerInCopy(const ControllerInterfaceSharedPtr& controller);

        NODISCARD const ControllerInterface* GetControllerObject() const noexcept;
        NODISCARD ControllerInterface* GetControllerObject() noexcept;
        void SetObject(ControllerInterface* aObject);

        void Load(CoreTools::BufferSource& source);
        void Save(CoreTools::BufferTarget& target) const;
        NODISCARD int GetStreamingSize() const;
        void Register(CoreTools::ObjectRegister& target) const;
        void Link(CoreTools::ObjectLink& source);

        NODISCARD ObjectSharedPtr GetObjectByName(const std::string& name);
        NODISCARD std::vector<ObjectSharedPtr> GetAllObjectsByName(const std::string& name);
        NODISCARD ConstObjectSharedPtr GetConstObjectByName(const std::string& name) const;
        NODISCARD std::vector<ConstObjectSharedPtr> GetAllConstObjectsByName(const std::string& name) const;

    private:
        // ���������Ƹö�������顣
        std::vector<CoreTools::ObjectAssociated<ControllerInterface>> controllers;

        ControllerInterface* realThis;

        CoreTools::ObjectAssociated<ControllerInterface> object;
    };
}

#endif  // RENDERING_CONTROLLERS_CONTROLLED_OBJECT_IMPL_H
