// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/21 15:49)

#include "CoreTools/CoreToolsExport.h"

#include "ObjectRegisterImpl.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/MemoryTools/ConstFirstSubclassSmartPointerDetail.h"

#include <boost/numeric/conversion/cast.hpp> 

CoreTools::ObjectRegisterImpl
	::ObjectRegisterImpl()
	:m_Registered{}, m_Ordered{}
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::ObjectRegisterImpl
	::IsValid() const noexcept
{
	if (m_Registered.size() == m_Ordered.size())
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

uint64_t CoreTools::ObjectRegisterImpl
	::GetUniqueID(const ConstObjectInterfaceSmartPointer& smartPointer) const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	auto iter = m_Registered.find(smartPointer);

	if (iter != m_Registered.cend())
	{
		return iter->second;
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("objectָ��û��ע�ᣡ"));
	}
}

int CoreTools::ObjectRegisterImpl
	::GetOrderedSize() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return boost::numeric_cast<int>(m_Ordered.size());
}

const CoreTools::ConstObjectInterfaceSmartPointer& CoreTools::ObjectRegisterImpl
	::operator[](int index) const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;
	CORE_TOOLS_ASSERTION_0(0 <= index && index < GetOrderedSize(), "��������");

	return m_Ordered[index];
}

uint64_t CoreTools::ObjectRegisterImpl
	::RegisterRoot(const ConstObjectInterfaceSmartPointer& smartPointer)
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	if (m_Registered.find(smartPointer) == m_Registered.cend())
	{
		// ���Ƕ����һ����ͼ�������������
		// ������Ҫʹ���ء���������ϵͳ��������д��һ��Ψһ�ı�ʶ�������̡���򵥵ľ���д����ĵ�ַ��
		// �������ǿ���ʹ��Object::Save������һ���ַ��set�У���ע�ᡱ�����������������⣺

		// 1. ��ַ������Ӧ�ó�������ʱ�ı䡣�������У���ͬ�ĳ���ͼ�����²�ͬ�Ķ��������
		// ��Ϊ�ڡ�ע�ᡱ��ַ��˳�����˱仯��һ����������Ǵ洢��ַ�����飨ordered�����������洢˳���������С�

		// 2. ��ʹ�����˶����˳���������У���ͬ�ĳ���ͼ�������ļ������ֽ�ƥ�䡣��ַ����ı䡣
		// һ������취��ָ��һ���������ַ����ÿ��������Ϊ����ע�ᡣ��򵥵ľ���ʹ�á�ordered�������������
		// Ϊ�˱������ַ����ָ��֮��Ļ���������ʹ�������������������һ��
		auto uniqueID = GetOriginalUniqueID(smartPointer);

		m_Registered.insert({ smartPointer, uniqueID });
		m_Ordered.push_back(smartPointer);

		return uniqueID;
	}
	else
	{
		return 0;
	}
}

// private
uint64_t CoreTools::ObjectRegisterImpl
	::GetOriginalUniqueID(const ConstObjectInterfaceSmartPointer& smartPointer) const
{
	uint64_t uniqueID{ 0 };

	if (smartPointer != nullptr)
	{
		uniqueID = smartPointer->GetUniqueID();
	}

	if (uniqueID == 0)
	{
		uniqueID = m_Ordered.size();
	}

	return uniqueID;
}

