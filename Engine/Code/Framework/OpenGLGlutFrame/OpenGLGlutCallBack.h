// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 15:57)

#ifndef FRAMEWORK_OPENGL_GLUT_FRAME_OPENGL_GLUT_CALL_BACK_H
#define FRAMEWORK_OPENGL_GLUT_FRAME_OPENGL_GLUT_CALL_BACK_H

#include "OpenGLGlutCallBackInterface.h"
#include "CoreTools/Time/CustomTime.h"
#include "Framework/WindowProcess/VirtualKeysTypes.h"

namespace Framework
{
	template <typename MiddleLayer>
	class OpenGLGlutCallBack : public OpenGLGlutCallBackInterface
	{
	public:
		using MiddleLayerType = MiddleLayer;
		using ClassType = OpenGLGlutCallBack<MiddleLayerType>;
		using ParentType = OpenGLGlutCallBackInterface;
		using CustomTime = CoreTools::CustomTime;

	public:
		explicit OpenGLGlutCallBack(int64_t delta);

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		bool RenderScene() override;
		bool ChangeSize(int width, int height) override;
		bool SpecialKeysDown(int key, int xCoordinate, int yCoordinate) override;
		bool KeyboardDown(int key, int xCoordinate, int yCoordinate) override;
		bool SpecialKeysUp(int key, int xCoordinate, int yCoordinate) override;
		bool KeyboardUp(int key, int xCoordinate, int yCoordinate) override;
		bool MotionFunction(int xCoordinate, int yCoordinate) override;
		bool PassiveMotion(int xCoordinate, int yCoordinate) override;
		bool MouseClick(int button, int state, int xCoordinate, int yCoordinate) override;
		bool IdleFunction() override;
		bool TimerFunction(TimerFunctionCallback callback) override;
		bool ProcessMenu(int menuValue) override;
		void DestroyWindow() override;

	private:
		using MiddleLayerTypeSharedPtr = std::shared_ptr<MiddleLayerType>;

	private:
		void SetGLUTModifiers(int button, int state) noexcept;

	private:
		MiddleLayerTypeSharedPtr m_MiddleLayer;
		CustomTime m_LastTime;
		VirtualKeysTypes m_GLUTModifiers;
		MouseButtonsTypes m_Button;
		int64_t m_Accumulative;
	};
}

#endif // FRAMEWORK_OPENGL_GLUT_FRAME_OPENGL_GLUT_CALL_BACK_H
