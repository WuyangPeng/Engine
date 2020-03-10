// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/19 11:14)

#ifndef CORE_TOOLS_THREADING_EVENT_H
#define CORE_TOOLS_THREADING_EVENT_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include <boost/noncopyable.hpp>

CORE_TOOLS_EXPORT_SHARED_PTR(EventImpl);
EXPORT_NONCOPYABLE_CLASS(CORE_TOOLS);

namespace CoreTools
{
	class CORE_TOOLS_DEFAULT_DECLARE Event : private boost::noncopyable
	{
	public:
		NON_COPY_CLASSES_TYPE_DECLARE(Event);

	public:
		Event(bool manualReset, bool initialState);

		CLASS_INVARIANT_DECLARE;

		void SetEvent();
		void ResetEvent();
		void Wait();

	private:
		IMPL_TYPE_DECLARE(Event);
	};
}

#endif // CORE_TOOLS_THREADING_EVENT_H
