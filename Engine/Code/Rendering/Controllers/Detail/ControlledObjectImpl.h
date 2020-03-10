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
		using ObjectSmartPointer = CoreTools::ObjectSmartPointer;
		using ConstObjectSmartPointer = CoreTools::ConstObjectSmartPointer;

    public:
        explicit ControlledObjectImpl(ControllerInterface* realThis);
        ~ControlledObjectImpl();
        
        CLASS_INVARIANT_DECLARE;
        
        bool Update (double applicationTime);
        
        // 访问控制器控制该对象。
        int GetNumControllers () const;
        ConstControllerInterfaceSmartPointer GetConstController (int index) const;
		ControllerInterfaceSmartPointer GetController (int index);
        void AttachController (ControllerInterfaceSmartPointer& controller);
        void DetachController (ControllerInterfaceSmartPointer& controller);
        void DetachAllControllers ();
        bool UpdateControllers (double applicationTime);
		void AttachControllerInCopy(ControllerInterfaceSmartPointer& controller);
        
        void Load (BufferSource& source);
		void Save (BufferTarget& target) const;
		int GetStreamingSize () const;
        void Register (ObjectRegister& target) const;
        void Link (ObjectLink& source);
        
		const ObjectSmartPointer GetObjectByName(const std::string& name); 
		const std::vector<ObjectSmartPointer> GetAllObjectsByName(const std::string& name); 
		const ConstObjectSmartPointer GetConstObjectByName(const std::string& name) const;
		const std::vector<ConstObjectSmartPointer> GetAllConstObjectsByName(const std::string& name) const;

    private:
        // 控制器控制该对象的数组。
        std::vector<ControllerInterfaceSmartPointer> m_Controllers;
        
        ControllerInterface* m_RealThis;
    };
}

#endif // RENDERING_CONTROLLERS_CONTROLLED_OBJECT_IMPL_H
