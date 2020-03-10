// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.1 (2020/01/21 15:49)

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
		THROW_EXCEPTION(SYSTEM_TEXT("object指针没有注册！"));
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
	CORE_TOOLS_ASSERTION_0(0 <= index && index < GetOrderedSize(), "索引错误！");

	return m_Ordered[index];
}

uint64_t CoreTools::ObjectRegisterImpl
	::RegisterRoot(const ConstObjectInterfaceSmartPointer& smartPointer)
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	if (m_Registered.find(smartPointer) == m_Registered.cend())
	{
		// 这是对象第一次在图表对象中遇到。
		// 我们需要使加载——连接器系统正常工作写入一个唯一的标识符到磁盘。最简单的就是写对象的地址，
		// 所以我们可以使用Object::Save保存在一组地址在set中（“注册”）。但这有两个问题：

		// 1. 地址在两次应用程序运行时改变。两次运行，相同的场景图将导致不同的对象的排序，
		// 因为在“注册”地址的顺序发生了变化。一个解决方案是存储地址的数组（ordered）并保存对象存储顺序在数组中。

		// 2. 即使保障了对象的顺序，两次运行，相同的场景图将导致文件不逐字节匹配。地址本身改变。
		// 一个解决办法是指定一个“虚拟地址”到每个对象，因为它被注册。最简单的就是使用“ordered”对象的索引。
		// 为了避免零地址和零指数之间的混淆，我们使用索引是数组的索引加一。
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

