
/* ---------------------------------------------------------------  /

	 ██╗  ██╗  █████╗  ████████╗  █████╗  ███╗   ██╗  █████╗
	 ██║ ██╔╝ ██╔══██╗ ╚══██╔══╝ ██╔══██╗ ████╗  ██║ ██╔══██╗
	 █████╔╝  ███████║    ██║    ███████║ ██╔██╗ ██║ ███████║
	 ██╔═██╗  ██╔══██║    ██║    ██╔══██║ ██║╚██╗██║ ██╔══██║
	 ██║  ██╗ ██║  ██║    ██║    ██║  ██║ ██║ ╚████║ ██║  ██║
	 ╚═╝  ╚═╝ ╚═╝  ╚═╝/\  ╚═╝    ╚═╝  ╚═╝ ╚═╝  ╚═══╝ ╚═╝  ╚═╝
   /vvvvvvvvvvvvvvvvvvv \====================== Game Engine ======,
   `^^^^^^^^^^^^^^^^^^^ /----------------- © 2012 - Ryan Appel -"
					  \/
/  --------------------------------------------------------------- */

#pragma once

namespace KatanaEngine
{
	/** @brief Base class for all games. Provides graphics initialization, game loop, and rendering code. 
		Inherit from this class when creating your own game. */
	class Game : public ServiceContainer
	{

	public:

		Game();
		virtual ~Game();

		/** @brief Runs the game instance.
			@return Error code for exit status. */
		virtual int Run();

		/** @brief Gets the screen width in pixels.
			@return The width in pixels. */
		static int GetScreenWidth() { return s_screenWidth; }

		/** @brief Gets the screen width in pixels.
			@return The width in pixels. */
		static int GetScreenHeight() { return s_screenHeight; }

		/** @brief Gets the screen size in pixels.
			@return A Vector2 representing the width and height of the screen. */
		static Vector2 GetScreenSize() { return (Vector2(s_screenWidth, s_screenHeight)); }

		/** @brief Gets the screen center in pixels.
			@return A Vector2 representing the center of the screen. */
		static Vector2 GetScreenCenter() { return (Vector2(s_screenWidth, s_screenHeight) / 2); }

		/** @brief Gets the name of the game.
			@return The name of the game. */
		virtual std::string GetName() const = 0;

		/** @brief Sets the color used to clear the back buffer. */
		virtual void SetClearColor(const Color &color) { m_clearColor = color; }

		/** @brief Called when resources need to be loaded.
			@param pResourceManager The game's resource manager, used for loading
			and managing game resources. */
		virtual void LoadContent(ResourceManager *pResourceManager) { }

		/** @brief Called when resources need to be unloaded. Override this method to unload
			any game-specific resources. */
		virtual void UnloadContent() { }

		/** @brief Exits the game. */
		virtual void Exit() { m_isRunning = false; }

		/** @brief Add a service to the service container.
			@remark This is an overload of ServiceContainer::AddService, so that
			any added services can have a pointer to the game set.*/
		virtual bool AddService(IService *pService);

		/** @brief Gets a pointer to the ResourceManager, for loading game resources.
			@return A pointer to the game's ResourceManager instance. */
		virtual ResourceManager *GetResourceManager() const { return m_pResourceManager; }

	protected:

		/** @brief Gets a pointer to the SpriteBatch, for rendering.
			@return A pointer to the game's SpriteBatch instance. */
		virtual SpriteBatch *GetSpriteBatch() const { return m_pSpriteBatch; }

		/** @brief Sets the screen resolution.
			@param width The width of the screen in pixels.
			@param height The height of the screen in pixels. */
		static void SetScreenResolution(int width, int height) { s_screenWidth = width; s_screenHeight = height; }

		/** @brief Sets the title of the game window.
			@param title The window title.
			@remark If the window title is not set, the game's name will be displayed in the title. */
		static void SetWindowTitle(std::string title) { s_windowTitle = title; }

		/** @brief Sets the location of the directory where the game's resources are stored.
			@param path The relative path to the resource directory. */
		virtual void SetResourceDirectory(const std::string &path) { m_pResourceManager->SetContentPath(path); }

		/** @brief Sets the target frame rate for the game.
			@param frames The target number of frames per second. */
		virtual void SetTargetFramesPerSecond(int const frames);

		/** @brief Sets the font for the frame counter.
			@param pFont A pointer to the font. */
		virtual void SetFrameCounterFont(Font *pFont) { m_pFrameCounterFont = pFont; }

		/** @brief Displays the game's current frame rate. */
		virtual void DisplayFrameRate();

		/** @brief Sets the game to display in fullscreen mode. */
		virtual void SetFullScreen(bool isFullScreen) { m_isFullScreen = isFullScreen; }

		/** @brief Sets the OpenGL flag, which forces OpenGL rendering. */
		virtual void SetOpenGLFlag() { m_requireOpenGL = true; }

		/** @brief Resets the game's timing values. */
		virtual void ResetGameTime() { m_pGameTime = new GameTime(); }

		/** @brief Creates and adds a screen manager service.
			@returns A pointer to the screen manager instance. */
		virtual ScreenManager *InitializeScreenManager();

	private:

		static int s_screenWidth;
		static int s_screenHeight;

		static std::string s_windowTitle;
		static std::string s_contentDirectory;

		bool m_isInitialized;
		bool m_isRunning;
		bool m_isFullScreen;
		bool m_requireOpenGL;

		double m_targetFramesPerSecond;
		double m_inverseTargetFrames;
		double m_actualFramesPerSec;
		double m_currentTime;
		double m_previousTime;
		float m_frameCounter;

		ALLEGRO_DISPLAY *m_pDisplay;

		Color m_clearColor = Color::BLACK;

		GameTime *m_pGameTime = nullptr;
		InputState *m_pInput = nullptr;
		SpriteBatch *m_pSpriteBatch = nullptr;
		ResourceManager *m_pResourceManager = nullptr;

		Font *m_pFrameCounterFont = nullptr;

		bool IsRunning() { return m_isRunning; }
	};
}