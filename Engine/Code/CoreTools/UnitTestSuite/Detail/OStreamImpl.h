// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.1.0.0 (2020/04/08 14:31)
 
#ifndef CORE_TOOLS_UNIT_TEST_SUITE_OSTREAM_IMPL_H
#define CORE_TOOLS_UNIT_TEST_SUITE_OSTREAM_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include <boost/noncopyable.hpp>
#include <string>
#include <iostream>

namespace CoreTools
{
	class CORE_TOOLS_HIDDEN_DECLARE OStreamImpl : private boost::noncopyable
	{
	public:
		using ClassType = OStreamImpl; 

	public:
		explicit OStreamImpl(bool isCout);
		explicit OStreamImpl(const std::string& fileName);
		~OStreamImpl() = default;

		OStreamImpl(OStreamImpl&& rhs) noexcept = delete;
		OStreamImpl& operator=(OStreamImpl&& rhs) noexcept = delete;

		CLASS_INVARIANT_DECLARE;
		 
		std::ostream& GetStream();

		bool IsCout() const noexcept;
		bool IsCerr() const noexcept;
		bool IsFile() const noexcept;

	private:
		using OstreamSharedPtr = std::shared_ptr<std::ostream>;

	private:
		OstreamSharedPtr m_OStream;
		bool m_IsCout;
	};
}

#endif // CORE_TOOLS_UNIT_TEST_SUITE_OSTREAM_IMPL_H
