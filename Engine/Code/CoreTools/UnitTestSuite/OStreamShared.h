// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.1.0.0 (2020/04/08 14:31)
 
#ifndef CORE_TOOLS_UNIT_TEST_SUITE_OSTREAM_SHARED_H
#define CORE_TOOLS_UNIT_TEST_SUITE_OSTREAM_SHARED_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/ExportMacro.h"

CORE_TOOLS_EXPORT_SHARED_PTR(OStreamImpl);

#include <string>
#include <iostream>

namespace CoreTools
{
	class CORE_TOOLS_DEFAULT_DECLARE OStreamShared
	{
	public:	
		using OStreamSharedImpl = OStreamImpl;
		SHARE_CLASSES_TYPE_DECLARE(OStreamShared);

	public:
		explicit OStreamShared(bool isCout = true);
		explicit OStreamShared(const std::string& fileName); 

		CLASS_INVARIANT_DECLARE;

		template<typename T>
		OStreamShared& operator<<(const T& value)
		{
			GetStream() << value;

			return *this;
		}
		 
		std::ostream& GetStream(); 

		bool IsCout() const noexcept;
		bool IsCerr() const noexcept;
		bool IsFile() const noexcept;

	private:
		IMPL_TYPE_DECLARE(OStreamShared);
	};
}

#endif // CORE_TOOLS_UNIT_TEST_SUITE_OSTREAM_SHARED_H
