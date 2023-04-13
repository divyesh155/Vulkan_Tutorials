#pragma once

#include "lve_device.h"
#include "lve_pipeline.h"
#include "lve_swap_chain.h"
#include "lve_window.h"
#include "lve_model.h"

#include <memory>
#include <vector>

namespace lve
{
	class FirstApp
	{
	public:
		static constexpr int WIDTH = 800;
		static constexpr int HEIGHT = 600;

		FirstApp();
		~FirstApp();

		FirstApp(const FirstApp&) = delete;
		FirstApp& operator=(const FirstApp&) = delete; //RAII Resource Acquisition Is Initialization


		void run();

	private:
		void loadModels();
		void createPipelineLayout();
		void createPipeline();
		void createCommandBuffers();
		void drawFrame();

		void sierpinski(std::vector<LveModel::Vertex>& vertices, int depth, glm::vec2 left, glm::vec2 right, glm::vec2 top);

		LveWindow lveWindow{ WIDTH, HEIGHT, "Hail Vulkan!" };
		LveDevice lveDevice{ lveWindow };
		LveSwapChain lveSwapChain{ lveDevice, lveWindow.getExtent() };
		std::unique_ptr<LvePipeline> lvePipeline;
		VkPipelineLayout pipelineLayout;
		std::vector<VkCommandBuffer> commandBuffers;
		std::unique_ptr<LveModel> lveModel;

	};

}