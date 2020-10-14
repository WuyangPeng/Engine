// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/23 10:46)

#include "Rendering/RenderingExport.h"

#include "ControlledObjectImpl.h"
#include "Rendering/Controllers/ControllerInterface.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/ObjectLinkDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/ObjectRegisterDetail.h"

#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Contract/Noexcept.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26451)
#include SYSTEM_WARNING_DISABLE(26418)
#include SYSTEM_WARNING_DISABLE(26415)
using std::string;
using std::vector;

Rendering::ControlledObjectImpl
    ::ControlledObjectImpl (ControllerInterface* realThis) noexcept
	:m_Controllers{}, m_RealThis{ realThis }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::ControlledObjectImpl
    ::~ControlledObjectImpl ()
{
    RENDERING_SELF_CLASS_IS_VALID_1;
    
  CoreTools::NoexceptNoReturn(*this,&ClassType::DetachAllControllers);
}

#ifdef OPEN_CLASS_INVARIANT
bool Rendering::ControlledObjectImpl
    ::IsValid() const noexcept
{
    if(m_RealThis != nullptr)
        return true;
    else
        return false;
}
#endif // OPEN_CLASS_INVARIANT


bool Rendering::ControlledObjectImpl
    ::Update (double applicationTime)
{
    RENDERING_CLASS_IS_VALID_1;
    
    return UpdateControllers(applicationTime);
}

int Rendering::ControlledObjectImpl
    ::GetNumControllers () const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return boost::numeric_cast<int>(m_Controllers.size());
}

Rendering::ConstControllerInterfaceSharedPtr Rendering::ControlledObjectImpl
      ::GetConstController (int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    RENDERING_ASSERTION_0(0 <= index && index < GetNumControllers(), "索引错误在GetController\n");
 
     return m_Controllers[index];
}

Rendering::ControllerInterfaceSharedPtr	Rendering::ControlledObjectImpl
	::GetController (int index) 
{
	RENDERING_CLASS_IS_VALID_CONST_1;
	RENDERING_ASSERTION_0(0 <= index && index < GetNumControllers(),"索引错误在GetController\n");

	return m_Controllers[index];
}

void Rendering::ControlledObjectImpl
    ::AttachController (ControllerInterfaceSharedPtr controller)
{
    RENDERING_CLASS_IS_VALID_1;
    
    // 测试控制器是否已经在数组中。
    for (auto i = 0u; i < m_Controllers.size(); ++i)
    {
        if (controller == m_Controllers[i])
        {
            return;
        }
    }
    
    controller->SetObject(m_RealThis);
    
    m_Controllers.push_back(controller);
}

void Rendering::ControlledObjectImpl
	::AttachControllerInCopy(ControllerInterfaceSharedPtr controller) 
{
	RENDERING_CLASS_IS_VALID_1;
    
    // 测试控制器是否已经在数组中。
    for (auto i = 0u; i < m_Controllers.size(); ++i)
    {
        if (controller == m_Controllers[i])
        {
            return;
        }
    }
    
    controller->SetObjectInCopy(m_RealThis);
    
    m_Controllers.push_back(controller);
}

void Rendering::ControlledObjectImpl
    ::DetachController (ControllerInterfaceSharedPtr controller)
{
    RENDERING_CLASS_IS_VALID_1;
    
    auto findIndex = -1;
    
    for (auto i = 0u; i < m_Controllers.size(); ++i)
    {
        if (controller == m_Controllers[i])
        {
            // 取消绑定的控制器对象。
            controller->SetObject(nullptr);
            
            findIndex = i;
            break;
        }
    }
    
    if(findIndex != -1)
    {
        // 删除数组中的控制器对象，保持数组连续
        for (auto i = findIndex + 1; i < boost::numeric_cast<int>(m_Controllers.size());++i)
        {
            m_Controllers[i - 1] = m_Controllers[i];
        }
        m_Controllers.pop_back();
    }
}

void Rendering::ControlledObjectImpl
    ::DetachAllControllers ()
{
    RENDERING_CLASS_IS_VALID_1;
    
    for (auto i = 0u; i < m_Controllers.size(); ++i)
    {
        // 取消绑定的控制器对象。
        m_Controllers[i]->SetObject(nullptr);
    }
    
    m_Controllers.clear();
}

bool Rendering::ControlledObjectImpl
    ::UpdateControllers (double applicationTime)
{
     RENDERING_CLASS_IS_VALID_1;
    
	 auto someoneUpdated = false;
    for (auto i = 0u; i < m_Controllers.size(); ++i)
    {
        if (m_Controllers[i]->Update(applicationTime))
        {
            someoneUpdated = true;
        }
    }
    return someoneUpdated;
}

const CoreTools::ObjectSharedPtr Rendering::ControlledObjectImpl
    ::GetObjectByName(const string& name)  
{
    RENDERING_CLASS_IS_VALID_1;
    
    for (auto i = 0u; i < m_Controllers.size(); ++i)
    {
		if (m_Controllers[i]->GetName() == name)
		{
			return m_Controllers[i];
		}           
    }

    CoreTools::DisableNoexcept();
    
    return CoreTools::ObjectSharedPtr();
}

const vector<CoreTools::ObjectSharedPtr> Rendering::ControlledObjectImpl
    ::GetAllObjectsByName(const string& name)
{
    RENDERING_CLASS_IS_VALID_1;
    
    vector<CoreTools::ObjectSharedPtr> objects;
    
    for (auto i = 0u; i < m_Controllers.size(); ++i)
    {
        if(m_Controllers[i]->GetName() == name)
		{
			objects.push_back(m_Controllers[i]);
		}            
    }
    
    return objects;
}

const CoreTools::ConstObjectSharedPtr Rendering::ControlledObjectImpl
    ::GetConstObjectByName(const string& name) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    CoreTools::DisableNoexcept();
    for (auto i = 0u; i < m_Controllers.size(); ++i)
    {
		if (m_Controllers[i]->GetName() == name)
		{
			return m_Controllers[i];
		}           
    }
    
    return CoreTools::ConstObjectSharedPtr();
}

const vector<CoreTools::ConstObjectSharedPtr> Rendering::ControlledObjectImpl
    ::GetAllConstObjectsByName(const string& name) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    
    vector<CoreTools::ConstObjectSharedPtr> objects;
    
    for (auto i = 0u; i < m_Controllers.size(); ++i)
    {
		if (m_Controllers[i]->GetName() == name)
		{
			objects.push_back(m_Controllers[i]);
		}            
    }
    
    return objects;
}

int Rendering::ControlledObjectImpl
    ::GetStreamingSize () const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
    
	auto size = CORE_TOOLS_STREAM_SIZE(int());

	if(!m_Controllers.empty())
	{
		size += boost::numeric_cast<int>(CORE_TOOLS_STREAM_SIZE(m_Controllers[0]) * m_Controllers.size());
	}
  
	return size;
}

void Rendering::ControlledObjectImpl
    ::Register( const CoreTools::ObjectRegisterSharedPtr& target ) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
    CoreTools::DisableNoexcept();
	if(!m_Controllers.empty())
        {
            target;
		//target.RegisterSharedPtr(boost::numeric_cast<int>(m_Controllers.size()),&m_Controllers[0]);	
	}
}

void Rendering::ControlledObjectImpl
    ::Save (const CoreTools::BufferTargetSharedPtr& target) const
{
	RENDERING_CLASS_IS_VALID_CONST_1; 

	if(!m_Controllers.empty())
	{
		//target.WriteSharedPtrWithNumber(boost::numeric_cast<int>(m_Controllers.size()),&m_Controllers[0]);
	}
	else
	{
            constexpr int zero = 0;
                target->Write(zero);
	}
}

void Rendering::ControlledObjectImpl ::Link(const CoreTools::ObjectLinkSharedPtr& source)
{ 
	RENDERING_CLASS_IS_VALID_1;    
    CoreTools::DisableNoexcept();
   if(!m_Controllers.empty())
        {
       source;
	 //  source.ResolveObjectSharedPtrLink(boost::numeric_cast<int>(m_Controllers.size()),&m_Controllers[0]);
   }
}

void Rendering:: ControlledObjectImpl
    ::Load (const CoreTools::BufferSourceSharedPtr& source)
{   
	RENDERING_CLASS_IS_VALID_1;  
	    
	uint32_t size{ 0 };
    source->Read(size);
    
    m_Controllers.resize(size);
	
	if(!m_Controllers.empty())
	{
//		source.ReadSharedPtr(boost::numeric_cast<int>(m_Controllers.size()),&m_Controllers[0]);
	}
}


 



 #include STSTEM_WARNING_POP