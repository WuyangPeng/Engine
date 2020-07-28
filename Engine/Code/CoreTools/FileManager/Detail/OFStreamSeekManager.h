// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/19 13:41)

#ifndef CORE_TOOLS_FILE_MANAGER_OFSTREAM_SEEK_MANAGER_H
#define CORE_TOOLS_FILE_MANAGER_OFSTREAM_SEEK_MANAGER_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"

#include <boost/noncopyable.hpp>
#include <fstream>

namespace CoreTools
{
	class CORE_TOOLS_HIDDEN_DECLARE OFStreamSeekManager : private boost::noncopyable
	{
	public:
		using ClassType = OFStreamSeekManager;
		using MasterType = System::OFileStream;
		using MasterTypeReference = System::OFileStream&;

	public:
		explicit OFStreamSeekManager(MasterTypeReference master);
		~OFStreamSeekManager();

		OFStreamSeekManager(const OFStreamSeekManager&) = delete;
		OFStreamSeekManager operator=(const OFStreamSeekManager&) = delete;
		OFStreamSeekManager(OFStreamSeekManager&&) = delete;
		OFStreamSeekManager operator=(OFStreamSeekManager&&) = delete;

		CLASS_INVARIANT_DECLARE;

	private:
		using MasterPosType = MasterType::pos_type;

	private:
		static const MasterPosType sm_ErrorPosition;

	private:
		void SeekBeginPosition();

	private:
		MasterTypeReference m_Master;
		MasterPosType m_CurrentPosition;
	};
}

#endif // CORE_TOOLS_FILE_MANAGER_OFSTREAM_SEEK_MANAGER_H
