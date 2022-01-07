// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/23 10:10)

#ifndef RENDERING_CONTROLLERS_CONTROLLED_OBJECT_IMPL_H
#define RENDERING_CONTROLLERS_CONTROLLED_OBJECT_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Controllers/ControllerInterface.h"
#include "Rendering/Controllers/Flags/ControllerFlags.h"

#include <boost/noncopyable.hpp>
#include <vector>

namespace Rendering
{
    class ControllerInterface;

    class RENDERING_HIDDEN_DECLARE ControlledObjectImpl : private boost::noncopyable
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
        ~ControlledObjectImpl();

        ControlledObjectImpl(const ControlledObjectImpl&) = delete;
        ControlledObjectImpl& operator=(const ControlledObjectImpl&) = delete;
        ControlledObjectImpl(ControlledObjectImpl&&) = delete;
        ControlledObjectImpl& operator=(ControlledObjectImpl&&) = delete;
        
        CLASS_INVARIANT_DECLARE;
        
        bool Update (double applicationTime);
        
        // 访问控制器控制该对象。
        int GetNumControllers () const;
        ConstControllerInterfaceSharedPtr GetConstController (int index) const;
		ControllerInterfaceSharedPtr GetController (int index);
        void AttachController (ControllerInterfaceSharedPtr controller);
        void DetachController (ControllerInterfaceSharedPtr controller);
        void DetachAllControllers ();
        bool UpdateControllers (double applicationTime);
		void AttachControllerInCopy(ControllerInterfaceSharedPtr controller);
        
        void Load(CoreTools::BufferSource& source);
		void Save (CoreTools::BufferTarget& target) const;
		int GetStreamingSize () const;
                void Register(CoreTools::ObjectRegister& target) const;
                void Link(CoreTools::ObjectLink& source);
        
		const ObjectSharedPtr GetObjectByName(const std::string& name); 
		const std::vector<ObjectSharedPtr> GetAllObjectsByName(const std::string& name); 
		const ConstObjectSharedPtr GetConstObjectByName(const std::string& name) const;
		const std::vector<ConstObjectSharedPtr> GetAllConstObjectsByName(const std::string& name) const;

    private:
        // 控制器控制该对象的数组。
        std::vector<ControllerInterfaceSharedPtr> m_Controllers;
        
        ControllerInterface* m_RealThis;
    };
}

#endif // RENDERING_CONTROLLERS_CONTROLLED_OBJECT_IMPL_H
