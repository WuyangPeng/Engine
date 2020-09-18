// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.0.3 (2019/07/23 13:41)

#include "Rendering/RenderingExport.h"

#include "IKControllerImpl.h"
#include "Rendering/DataTypes/SpecializedIO.h"
#include "Mathematics/Algebra/AlgebraAggregate.h"
#include "Mathematics/Algebra/AlgebraStreamSize.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/ObjectLinkDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/ObjectRegisterDetail.h"
#include "CoreTools/MemoryTools/SubclassSmartPointerDetail.h" 
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/ClassInvariant/Noexcept.h"

using std::string;
using std::vector;
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26418)
#include SYSTEM_WARNING_DISABLE(26415)
Rendering::IKControllerImpl ::IKControllerImpl() noexcept
    : m_Iterations{ 128 }, m_OrderEndToRoot{ true }, m_Joints{}
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::IKControllerImpl
	::IKControllerImpl(const IKJointSmartPointerVector& joints) 
	:m_Iterations{ 128 }, m_OrderEndToRoot{ true }, m_Joints{ joints }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool Rendering::IKControllerImpl
	::IsValid() const  noexcept
{
	if (0 <= m_Iterations)
		return true;
	else 
		return false;
}
#endif // OPEN_CLASS_INVARIANT	

int Rendering::IKControllerImpl
	::GetStreamingSize() const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	auto size = CORE_TOOLS_STREAM_SIZE(m_Iterations);
	size += CORE_TOOLS_STREAM_SIZE(m_OrderEndToRoot);

	auto jointSize = boost::numeric_cast<int>(m_Joints.size());
	size += CORE_TOOLS_STREAM_SIZE(jointSize);

	if (0 < jointSize)
	{
		size += jointSize * CORE_TOOLS_STREAM_SIZE(m_Joints.at(0));
	}		

	return size;
}

void Rendering::IKControllerImpl
	::Save(const CoreTools::BufferTargetSharedPtr& target) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	target->Write(m_Iterations);
	target->Write(m_OrderEndToRoot);

	if (!m_Joints.empty())
	{
		//target.WriteSmartPointerWithNumber(boost::numeric_cast<int>(m_Joints.size()), &m_Joints[0]);
	}		
}

void Rendering::IKControllerImpl
	::Load(CoreTools::BufferSource& source)
{
	RENDERING_CLASS_IS_VALID_1;

	source.Read(m_Iterations);
	m_OrderEndToRoot = source.ReadBool();

	auto size = 0;
	source.Read(size);

	if (0 < size)
	{
		m_Joints.resize(size);
		//source.ReadSmartPointer(size, &m_Joints[0]);
	}
}

void Rendering::IKControllerImpl
	::Link(CoreTools::ObjectLink& source)
{
	RENDERING_CLASS_IS_VALID_1;

	CoreTools::DoNothing();

	if (0 < m_Joints.size())
        {
            source;
		//source.ResolveObjectSmartPointerLink(boost::numeric_cast<int>(m_Joints.size()), &m_Joints[0]);
	}
}

void Rendering::IKControllerImpl
	::Register(const CoreTools::ObjectRegisterSharedPtr& target) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
    CoreTools::DoNothing();
	if (0 < m_Joints.size())
        {
            target;
	//	target.RegisterSmartPointer(boost::numeric_cast<int>(m_Joints.size()), &m_Joints[0]);
	}
}

const CoreTools::ObjectSmartPointer Rendering::IKControllerImpl
	::GetObjectByName(const string& name)
{
	RENDERING_CLASS_IS_VALID_1;

	for(auto& pointer: m_Joints)
	{
		auto found  = pointer->GetObjectByName(name);
		if (found != nullptr)
		{
			return found;
		}				
	}

	return CoreTools::ObjectSmartPointer{};
}

const vector<CoreTools::ObjectSmartPointer> Rendering::IKControllerImpl
	::GetAllObjectsByName(const string& name)
{
	RENDERING_CLASS_IS_VALID_1;

	vector<CoreTools::ObjectSmartPointer> objects;

	for (auto& pointer : m_Joints)
	{
		auto pointerObjects = pointer->GetAllObjectsByName(name);
 
		objects.insert(objects.end(), pointerObjects.begin(), pointerObjects.end());	 
	}

	return objects;
}

const CoreTools::ConstObjectSmartPointer Rendering::IKControllerImpl
	::GetConstObjectByName(const string& name) const
{
	RENDERING_CLASS_IS_VALID_1;

	for (const auto& pointer : m_Joints)
	{
		auto found  = pointer->GetConstObjectByName(name);
		if (found != nullptr)
		{
			return found;
		}				
	}

	return CoreTools::ConstObjectSmartPointer{};
}

const vector<CoreTools::ConstObjectSmartPointer> Rendering::IKControllerImpl
	::GetAllConstObjectsByName(const string& name) const
{
	RENDERING_CLASS_IS_VALID_1;

	vector<CoreTools::ConstObjectSmartPointer> objects;

	for (const auto& pointer : m_Joints)
	{
		auto pointerObjects = pointer->GetAllConstObjectsByName(name);
 
		objects.insert(objects.end(), pointerObjects.begin(), pointerObjects.end());	 
	}

	return objects;
}

int Rendering::IKControllerImpl
	::GetIterations() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_Iterations;
}

void Rendering::IKControllerImpl ::SetIterations(int iterations) noexcept
{
	RENDERING_CLASS_IS_VALID_1;

	m_Iterations = iterations;
}

bool Rendering::IKControllerImpl ::IsOrderEndToRoot() const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_OrderEndToRoot;
}

void Rendering::IKControllerImpl ::SetOrderEndToRoot(bool orderEndToRoot) noexcept
{
	RENDERING_CLASS_IS_VALID_1;

	m_OrderEndToRoot = orderEndToRoot;
}

int Rendering::IKControllerImpl
	::GetJointsNum() const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return boost::numeric_cast<int>(m_Joints.size());
}

const Rendering::IKJointSmartPointer Rendering::IKControllerImpl
	::GetJointsSmartPointer(int index)
{
	RENDERING_CLASS_IS_VALID_CONST_1;
	RENDERING_ASSERTION_0(0 <= index && index < boost::numeric_cast<int>(m_Joints.size()), "Ë÷Òý´íÎó£¡");

	return m_Joints.at(index);
}
#include STSTEM_WARNING_POP