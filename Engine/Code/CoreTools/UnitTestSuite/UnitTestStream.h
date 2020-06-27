// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 10:16)

#ifndef CORE_TOOLS_UNIT_TEST_SUITE_UNIT_TEST_STREAM_H
#define CORE_TOOLS_UNIT_TEST_SUITE_UNIT_TEST_STREAM_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include <boost/noncopyable.hpp>
#include <iosfwd>
#include "OStreamShared.h"

EXPORT_NONCOPYABLE_CLASS(CORE_TOOLS);

namespace CoreTools
{
	class CORE_TOOLS_DEFAULT_DECLARE UnitTestStream : private boost::noncopyable
	{
	public:
		using ClassType = UnitTestStream;

	public:
		explicit UnitTestStream(const OStreamShared& osPtr);
		virtual ~UnitTestStream();

		CLASS_INVARIANT_VIRTUAL_DECLARE;

		OStreamShared& GetStream();
		bool IsStreamSharedFile() const noexcept;

	private:
		OStreamShared m_OsPtr;
	};
}
#endif // CORE_TOOLS_UNIT_TEST_SUITE_UNIT_TEST_STREAM_H
