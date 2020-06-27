// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.2.2 (2020/01/22 13:08)

#include "CoreTools/CoreToolsExport.h"

#include "CommonDataResourceImpl.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

#include "System/Helper/PragmaWarning/NumericCast.h"

CoreTools::CommonDataResourceImpl
	::CommonDataResourceImpl(uint32_t size)
	:m_DataSize{ size }, m_Data(size)
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::CommonDataResourceImpl
	::IsValid() const noexcept
{
	if (m_Data.size() == m_DataSize || m_Data.size() == 0)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

uint32_t CoreTools::CommonDataResourceImpl
	::GetSize() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_DataSize;
}

bool CoreTools::CommonDataResourceImpl
	::IsDisposed() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return m_Data.size() == m_DataSize ? false : true;
}

void CoreTools::CommonDataResourceImpl
	::Recreate()
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	Dispose();
	m_Data.resize(m_DataSize);
}

void CoreTools::CommonDataResourceImpl
	::Dispose() noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	m_Data.clear();
}

void CoreTools::CommonDataResourceImpl
	::SetData(int index, uint8_t value)
{
	CORE_TOOLS_CLASS_IS_VALID_1;
	CORE_TOOLS_ASSERTION_0(0 <= index && index < boost::numeric_cast<int>(m_DataSize), "Ë÷Òý´íÎó£¡");

	m_Data[index] = value;
}

uint8_t CoreTools::CommonDataResourceImpl
	::GetData(int index) const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;
	CORE_TOOLS_ASSERTION_0(0 <= index && index < boost::numeric_cast<int>(m_DataSize), "Ë÷Òý´íÎó£¡");

	return m_Data[index];
}

