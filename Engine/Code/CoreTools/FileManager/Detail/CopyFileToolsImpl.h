// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/19 13:39)

#ifndef CORE_TOOLS_FILE_MANAGER_COPY_FILE_TOOLS_IMPL_H
#define CORE_TOOLS_FILE_MANAGER_COPY_FILE_TOOLS_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"

#include <boost/noncopyable.hpp>

namespace CoreTools
{
	class CORE_TOOLS_HIDDEN_DECLARE CopyFileToolsImpl : private boost::noncopyable
	{
	public:
		using ClassType = CopyFileToolsImpl;
		using String = System::String;

	public:
		CopyFileToolsImpl() noexcept;
		virtual ~CopyFileToolsImpl() noexcept = default;

		CopyFileToolsImpl(const CopyFileToolsImpl&) = delete;
		CopyFileToolsImpl& operator=(const CopyFileToolsImpl&) = delete;
		CopyFileToolsImpl(CopyFileToolsImpl&&) noexcept = delete;
		CopyFileToolsImpl& operator=(CopyFileToolsImpl&&) noexcept = delete;

		CLASS_INVARIANT_VIRTUAL_DECLARE;
	};
}

#endif // CORE_TOOLS_FILE_MANAGER_COPY_FILE_TOOLS_IMPL_H
