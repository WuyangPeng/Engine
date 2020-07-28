// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.1.1.0 (2020/05/02 13:35)

#ifndef CORE_TOOLS_FILE_MANAGER_DIRECTORY_IMPL_H
#define CORE_TOOLS_FILE_MANAGER_DIRECTORY_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include <boost/noncopyable.hpp>
#include "System/Helper/UnicodeUsing.h"

namespace CoreTools
{
	class CORE_TOOLS_HIDDEN_DECLARE DirectoryImpl : private boost::noncopyable
	{
	public:
		using ClassType = DirectoryImpl;
		using String = System::String;

	public:
		explicit DirectoryImpl(const String& directoryName);
		~DirectoryImpl();

		DirectoryImpl(const DirectoryImpl&) = delete;
		DirectoryImpl& operator=(const DirectoryImpl&) = delete;
		DirectoryImpl(DirectoryImpl&&) noexcept = delete;
		DirectoryImpl& operator=(DirectoryImpl&&) noexcept = delete;

		CLASS_INVARIANT_DECLARE;

	private:
		System::String m_DirectoryName;
	};
}

#endif // CORE_TOOLS_FILE_MANAGER_DIRECTORY_IMPL_H
