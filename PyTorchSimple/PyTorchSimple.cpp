// PyTorchSimple.cpp : Defines the entry point for the application.
//

#include "PyTorchSimple.h"

#include <torch/torch.h>
using namespace std;

int main()
{
	torch::Tensor eye = torch::eye(2);
	std::cout << eye << std::endl;

	std::cout <<"cuda available: " << torch::cuda::is_available() << std::endl;
	return 0;
}
