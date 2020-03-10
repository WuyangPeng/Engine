// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.1 (2020/01/20 16:41)

#ifndef CORE_TOOLS_MEMORY_TOOLS_MD5_CONTEXT_H
#define CORE_TOOLS_MEMORY_TOOLS_MD5_CONTEXT_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include <boost/noncopyable.hpp>

EXPORT_NONCOPYABLE_CLASS(CORE_TOOLS);
CORE_TOOLS_EXPORT_SHARED_PTR(MD5ContextImpl);

namespace CoreTools
{
	class CORE_TOOLS_DEFAULT_DECLARE MD5Context : private boost::noncopyable
	{
	public:
		NON_COPY_CLASSES_TYPE_DECLARE(MD5Context);

	public:
		MD5Context();

		CLASS_INVARIANT_DECLARE;

		void MD5Init();

		// 允许多次调用MD5Update用于对多个数组进行更新
		void MD5Update(uint8_t const* buffer, uint32_t length);

		void MD5Final(uint8_t* digest);

	private:
		IMPL_TYPE_DECLARE(MD5Context);
	};
}
#endif // CORE_TOOLS_MEMORY_TOOLS_MD5_CONTEXT_H
