// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.2 (2020/01/22 10:44)

#ifndef CORE_TOOLS_TEMPLATE_TOOLS_SIMPLE_INCREMENTER_DETAIL_H
#define CORE_TOOLS_TEMPLATE_TOOLS_SIMPLE_INCREMENTER_DETAIL_H 

#include "SimpleIncrementer.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

#ifdef OPEN_CLASS_INVARIANT
template <typename T>
bool CoreTools::SimpleIncrementer<T>
	::IsValid() const  noexcept
{
	return true;
}
#endif // OPEN_CLASS_INVARIANT

template <typename T>
void CoreTools::SimpleIncrementer<T>
	::operator()(T& value)
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	++value;
}

#endif //  CORE_TOOLS_TEMPLATE_TOOLS_SIMPLE_INCREMENTER_DETAIL_H

