// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/21 15:28)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_BUFFER_IN_STREAM_IMPL_H
#define CORE_TOOLS_OBJECT_SYSTEMS_BUFFER_IN_STREAM_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/ObjectSystems/InTopLevel.h"
#include "CoreTools/ObjectSystems/ObjectLink.h"
#include "CoreTools/ObjectSystems/BufferSource.h"
#include "CoreTools/FileManager/FileManagerFwd.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
namespace CoreTools
{
	class CORE_TOOLS_HIDDEN_DECLARE BufferInStreamImpl : private boost::noncopyable
	{
	public:
		using ClassType = BufferInStreamImpl;
		using FileBufferPtr = std::shared_ptr<FileBuffer>;

	public:
                explicit BufferInStreamImpl(const ConstFileBufferSharedPtr& fileBuffer, int startPoint = 0);
 
		CLASS_INVARIANT_DECLARE;

		const InTopLevel GetTopLevel() const noexcept;

	private:
		void AnalysisBuffer();
            void IncrementBytesProcessed() noexcept(g_Assert < 2 || g_CoreToolsAssert < 2);
		void ReadObject();
		void CreateObject(bool isTopLevel, const std::string& name);
		void DoCreateObject(bool isTopLevel, const std::string& name);
		void Link();
		void PostLink();

	private:
		int m_StartPoint;
		InTopLevel m_TopLevel;
                BufferSourceSharedPtr m_Source;
		ObjectLinkSharedPtr m_ObjectLink;
	};
}

#endif // CORE_TOOLS_OBJECT_SYSTEMS_BUFFER_IN_STREAM_IMPL_H
