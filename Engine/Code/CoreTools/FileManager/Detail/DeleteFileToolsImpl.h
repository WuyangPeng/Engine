// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/19 13:39)

#ifndef CORE_TOOLS_FILE_MANAGER_DELETE_FILE_TOOLS_IMPL_H
#define CORE_TOOLS_FILE_MANAGER_DELETE_FILE_TOOLS_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "System/FileManager/Using/CFileUsing.h"

#include <boost/noncopyable.hpp>
#include <string>

namespace CoreTools
{
	class CORE_TOOLS_HIDDEN_DECLARE DeleteFileToolsImpl : private boost::noncopyable
	{
	public:
		using ClassType = DeleteFileToolsImpl;
		using String = System::String;
		using CFileString = System::CFileString;		

	public:
		explicit DeleteFileToolsImpl(const String& fileName);
		~DeleteFileToolsImpl();

		DeleteFileToolsImpl(const DeleteFileToolsImpl&) = delete;
		DeleteFileToolsImpl& operator=(const DeleteFileToolsImpl&) = delete;
		DeleteFileToolsImpl(DeleteFileToolsImpl&&) noexcept = delete;
		DeleteFileToolsImpl& operator=(DeleteFileToolsImpl&&) noexcept = delete;

		CLASS_INVARIANT_DECLARE;

	private:
		CFileString m_FileName;
		bool m_Deleted;
	};
}

#endif // CORE_TOOLS_FILE_MANAGER_DELETE_FILE_TOOLS_IMPL_H
