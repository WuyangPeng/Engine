/////////////////////////////////////////////////////////////////////////////
//
// 3D Math Primer for Games and Graphics Development
//
// WinMain.cpp - Windows common stuff
//
// Visit gamemath.com for the latest version of this file.
//
/////////////////////////////////////////////////////////////////////////////

#include "WinMain.h"
#include "Renderer.h"
#include "Input.h"

#include "System/Helper/PragmaWarning/NumericCast.h" 
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26461)
#include SYSTEM_WARNING_DISABLE(26482)
#include SYSTEM_WARNING_DISABLE(26485)
 
namespace ThreeDMathPrimerForGraphicsAndGameDevelopment
{
	/////////////////////////////////////////////////////////////////////////////
	//
	// global variables
	//
	/////////////////////////////////////////////////////////////////////////////

	HWND gHwndApp = nullptr;
	HINSTANCE gHInstApp;
	bool gQuitFlag = false;
	bool gIdleInBackground = true;

	/////////////////////////////////////////////////////////////////////////////
	//
	// local stuff
	//
	/////////////////////////////////////////////////////////////////////////////

	// Is our app in the foreground?

	static bool appInForeground = true;

	// Change the current directory to the one containing the executable.
	// This simplifies a lot of stuff

	static void	switchToDirectory()
	{

		// Get the directory of the command line filename and module

		char programDir[256];
		GetModuleFileNameA(gHInstApp, programDir, 256);

		// Strip off the program name from programDir

		int i = boost::numeric_cast<int>(strlen(programDir));
		while (i > 0)
		{
			if (programDir[i] == '\\')
			{
				programDir[i] = 0;
				break;
			}
			i--;
		}

		// Switch to the program directory

		SetCurrentDirectoryA(programDir);
	}

	/////////////////////////////////////////////////////////////////////////////
	//
	// Externals
	//
	/////////////////////////////////////////////////////////////////////////////

	// mainProgram() - this is the function that your app defines

	extern void	mainProgram();

	/////////////////////////////////////////////////////////////////////////////
	//
	// Global code
	//
	/////////////////////////////////////////////////////////////////////////////

	/*

		WindowProc - The windows message routine

	*/

	LRESULT FAR PASCAL WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)  
	{

		// Make sure this message is for our app

		if (hWnd != gHwndApp)
		{
			return DefWindowProc(hWnd, message, wParam, lParam);
		}

		// Process the message

		switch (message)
		{
		case WM_ACTIVATEAPP:
			appInForeground = wParam;
			if (appInForeground)
			{
				gRenderer.videoRestore();
			}
			else
			{
				gRenderer.videoSave();
			}
			break;

		case WM_CLOSE:
		case WM_DESTROY:
			gQuitFlag = true;
			break;

		case WM_KEYDOWN:
		case WM_SYSKEYDOWN:
		{
			// Extract keyboard scan code

			const int keyCode = (lParam >> 16) & 511;

			// Press the key

			gKeyboard.press(keyCode);

			// Queue an event

			KeyEvent event;
			event.type = eKeyEventPressed;
			event.keyCode = keyCode;
			event.modifiers = gKeyboard.getModifiers();
			gKeyboard.queueEvent(event);

			// Disable default windows message processing for
			// a few keys.  We don't want F10 to activate the
			// system menu, or alt-F4 to terminate the app.

			switch (keyCode)
			{
			case kKeyF4:
			case kKeyF10:
			case kKeyLeftAlt:
			case kKeyRightAlt:
				return 0;
			}

		} break;

		case WM_CHAR:
		{

			// Queue an event

			KeyEvent event;
			event.type = eKeyEventChar;
			event.asciiCode = boost::numeric_cast<char>(wParam);
			if (event.asciiCode != 0)
			{
				event.modifiers = gKeyboard.getModifiers();
				gKeyboard.queueEvent(event);
			}
		} break;

		case WM_KEYUP:
		case WM_SYSKEYUP:
		{

			// Extract keyboard scan code

			const int keyCode = (lParam >> 16) & 511;

			// Release the key

			gKeyboard.debounce(keyCode);

			// Queue an event

			KeyEvent event;
			event.type = eKeyEventReleased;
			event.keyCode = keyCode;
			event.modifiers = gKeyboard.getModifiers();
			gKeyboard.queueEvent(event);
		} break;
		}

		// Return the default window procedure

		return DefWindowProc(hWnd, message, wParam, lParam);

	}

	/*

		idle - Perform frame-time processing tasks

	*/

	void idle() noexcept
	{

		// Check if there is a message for us, repeat if program is not
		// in the foreground

		for (;;)
		{

			// Process all pending Windows messages

			MSG	msg{ };
			while (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}

			// If we're in the foreground, return to normal message processing

			if (appInForeground) break;

			// If we've been told to quit the app, then bail this loop

			if (gQuitFlag) break;

			// We're in the background - always give back some time

			Sleep(20);

			// Check if we're supposed to idle in the background

			if (!gIdleInBackground) break;

			// Repeat until program is in the foreground,
			// or we signal program termination
		}

	}


	/*

		createAppWindow - Create a new window for the application

	*/

	void createAppWindow(const char* title) noexcept
	{

		// Register the window class

		WNDCLASSA wc;
		wc.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;
		wc.lpfnWndProc = WindowProc;
		wc.cbClsExtra = 0;
		wc.cbWndExtra = 0;
		wc.hInstance = gHInstApp;
		wc.hIcon = nullptr;
		wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
		wc.hbrBackground = nullptr;
		wc.lpszMenuName = nullptr;
		wc.lpszClassName = title;
		RegisterClassA(&wc);

		// Create our window

		gHwndApp = CreateWindowExA(WS_EX_APPWINDOW | WS_EX_DLGMODALFRAME, title, title, WS_POPUP | WS_CLIPCHILDREN | WS_OVERLAPPEDWINDOW,
								   0, 0, 0, 0, nullptr, nullptr, gHInstApp, nullptr);
	}


	/*

		destroyAppWindow - Destroy the application window

	*/

	void destroyAppWindow() noexcept
	{

		// Make sure we exist

		if (gHwndApp != nullptr)
		{

			// Destroy it

			DestroyWindow(gHwndApp);
			gHwndApp = nullptr;
		}
	}

	/*

		WinMain - Windows entry point

	*/

	int PASCAL WinMain(HINSTANCE hInstance, [[maybe_unused]] HINSTANCE hPrevInstance, [[maybe_unused]] LPSTR lpCmdLine, [[maybe_unused]] int nCmdShow)
	{
		 
		// Save off our instance

		gHInstApp = hInstance;

		// Switch directory to the one containing the executable

		switchToDirectory();

		// Run the app initialization

		mainProgram();

		// Done

		return 0;
	}
}
#include STSTEM_WARNING_POP