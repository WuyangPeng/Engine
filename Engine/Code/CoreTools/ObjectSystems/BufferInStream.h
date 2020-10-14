// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/21 15:37)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_BUFFER_IN_STREAM_H
#define CORE_TOOLS_OBJECT_SYSTEMS_BUFFER_IN_STREAM_H

#include "CoreTools/CoreToolsDll.h"

#include "InTopLevel.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/FileManager/FileManagerFwd.h"

#include <boost/noncopyable.hpp>
#include "../FileManager/FileBuffer.h"

CORE_TOOLS_EXPORT_SHARED_PTR(BufferInStreamImpl);
EXPORT_NONCOPYABLE_CLASS(CORE_TOOLS);

namespace CoreTools
{
	class CORE_TOOLS_DEFAULT_DECLARE BufferInStream : private boost::noncopyable
	{
	public:
		NON_COPY_CLASSES_TYPE_DECLARE(BufferInStream);
		using FileBufferPtr = std::shared_ptr<FileBuffer>;

	public:
                explicit BufferInStream(const ConstFileBufferSharedPtr&  bufferInformation, int startPoint = 0);

		CLASS_INVARIANT_DECLARE;

		const InTopLevel GetTopLevel() const noexcept;

	private:
		IMPL_TYPE_DECLARE(BufferInStream);
	};
}

#endif // CORE_TOOLS_OBJECT_SYSTEMS_BUFFER_IN_STREAM_H
