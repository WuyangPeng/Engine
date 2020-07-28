// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/19 13:41)

#ifndef CORE_TOOLS_FILE_MANAGER_IFSTREAM_SEEK_MANAGER_H
#define CORE_TOOLS_FILE_MANAGER_IFSTREAM_SEEK_MANAGER_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"

#include <boost/noncopyable.hpp>
#include <fstream>

namespace CoreTools
{
	class CORE_TOOLS_HIDDEN_DECLARE IFStreamSeekManager : private boost::noncopyable
	{
	public:
		using ClassType = IFStreamSeekManager;
		using MasterType = System::IFileStream;
		using MasterTypeReference = System::IFileStream&;

	public:
		explicit IFStreamSeekManager(MasterTypeReference master);
		~IFStreamSeekManager() noexcept;

		IFStreamSeekManager(const IFStreamSeekManager&) = delete;
		IFStreamSeekManager operator=(const IFStreamSeekManager&) = delete;
		IFStreamSeekManager(IFStreamSeekManager&&) = delete;
		IFStreamSeekManager operator=(IFStreamSeekManager&&) = delete;

		CLASS_INVARIANT_DECLARE;

	private:
		void SeekBeginPosition();

	private:
		using MasterPosType = MasterType::pos_type;

	private:
		static const MasterPosType sm_ErrorPosition;

	private:
		MasterTypeReference m_Master;
		MasterPosType m_CurrentPosition;
	};
}

#endif // CORE_TOOLS_FILE_MANAGER_IFSTREAM_SEEK_MANAGER_H
