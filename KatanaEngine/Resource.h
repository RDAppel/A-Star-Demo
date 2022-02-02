
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
	class ResourceManager;

	/** @brief Base class for all resource types to be managed by the ResourceManager class. */
	class Resource
	{
		friend class ResourceManager;

	public:

		virtual ~Resource() { }

		/** @brief Load the desired resource into memory.
			@param path The path to the desired resource.
			@param pManager A pointer to the ResourceManager that will manage the resource.
			@return Returns true if the resource was loaded, false otherwise. */
		virtual bool Load(const std::string &path, ResourceManager *pManager) = 0;

		/** @brief Unloads the resource from the resource manager.
			@remark Unloading does not delete the object or it's clones. Unload should be called
			before deleting any resources. */
		virtual void Unload();

		/** @brief Gets the ID of the resource.
			@return The id of the resource. */
		unsigned short GetResourceID() const { return m_id; }


	protected:

		/** @brief Splits a string into a vector of the specified type T.
			@param line The string that will be split.
			@param elements The vector where the elements will be stored.
			@param delimeter The character that will determine the split locations. */
		template <typename T>
		bool TryParse(const std::string &text, std::vector<T> &elements,
			const char delimeter = ',')
		{
			if (text.empty()) return false;
			std::stringstream ss(text);
			std::string item;
			while (std::getline(ss, item, delimeter))
				elements.push_back(fromString<T>(item));
			return true;
		}


		/** @brief Splits a string of integers into a point.
			@param line The string that will be parsed.
			@param point The point reference that will be modified. */
		bool TryParsePoint(const std::string &text, Point &point)
		{
			std::vector<int> elements;
			if (!TryParse<int>(text, elements)) return false;
			if (elements.size() < 2) return false;
			point.Set(&elements[0]);
			return true;
		}


		/** @brief Splits a string of integers into a region.
			@param line The string that will be parsed.
			@param region The region reference that will be modified. */
		bool TryParseRegion(const std::string &text, Region &region)
		{
			std::vector<int> elements;
			if (!TryParse<int>(text, elements)) return false;
			if (elements.size() < 4) return false;
			region.Set(&elements[0]);
			return true;
		}


		/** @brief Splits a string of floats into a color.
			@param line The string that will be parsed.
			@param color The color reference that will be modified. */
		bool TryParseColor(const std::string &text, Color &color)
		{
			std::vector<float> elements;
			if (!TryParse<float>(text, elements)) return false;
			if (elements.size() < 3) return false;
			// if there is no alpha value, default it to one
			if (elements.size() == 3) elements.push_back(1.0f);
			color.Set(&elements[0]);
			return true;
		}


		/** @brief Removes c-style, single-line comments from a line of text.
			@param line The line to remove the comments from. */
		void StripComments(std::string &line);

		/** @brief Removes WHITE-space at the front and end of a line of text.
			@param line The line to remove the WHITE-space from. */
		void TrimLine(std::string &line);

		/** @brief Gets a pointer to the ResourceManager that was used to load the resource.
			@return Returns a pointer to the ResourceManager. */
		ResourceManager *GetResourceManager() { return m_pResourceManager; }

		/** @brief Used to determine if the resource is cloneable.
			@return Returns true if the resource is clonable, false otherwise.
			@remark Resources that are stateless should not be cloneable; i.e. Fonts, Textures, etc. Resources
			that do contain state should be cloned to prevent state duplication. For example, an %Animation that
			is shared (not cloned) would share the current frame. This would mean that they would always be
			playing in sync.*/
		virtual bool IsCloneable() const = 0;

		/** @brief Clones a resource.
			@return Returns a pointer to a clone if the resource is cloneable.
			Otherwise a pointer to \"this\" is returned. */
		virtual Resource *Clone() { return this; };


	private:

		unsigned short m_id = 0;

		ResourceManager *m_pResourceManager = nullptr;


		template<typename T>
		T fromString(const std::string &str);

		// Implementations
		template<>
		int fromString(const std::string &str)
		{
			return std::stoi(str);
		}

		template<>
		float fromString(const std::string &str)
		{
			return std::stof(str);
		}

		template<>
		std::string fromString(const std::string &str)
		{
			return str;
		}
	};
}