#pragma once

#define GLFW_INCLUDE_VULKAN // Signal that we want glfw to also include the Vulkan headers with it
#include <GLFW/glfw3.h>
#include <string>

namespace lve
{
	class LveWindow
	{
	public:
		LveWindow(int w, int h, std::string name);
		~LveWindow();

		LveWindow(const LveWindow&) = delete;
		LveWindow& operator=(const LveWindow&) = delete; //RAII Resource Acquisition Is Initialization

		bool shouldClose() { return glfwWindowShouldClose(window); }
		VkExtent2D getExtent() { return { static_cast<uint32_t>(width), static_cast<uint32_t>(height) }; }

		void createWindowSurface(VkInstance instance, VkSurfaceKHR* surface);

	private:

		void initWindow();

		const int width;
		const int height;

		std::string windowName;
		GLFWwindow* window;
	};
}