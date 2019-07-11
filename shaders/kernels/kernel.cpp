#include "kernel.h"

template <typename Type>
std::shared_ptr<Kernel<Type>>
KernelFactory::create_kernel(const KernelType &kernel_type)
{
    std::shared_ptr<Kernel<Type>> ptr;
    switch (kernel_type)
    {
    case GaussianKernelT:
        ptr.reset(new GaussianKernel());
        break;
    default:
        ptr.reset(new GaussianKernel());
        break;
    }
    return ptr;
}

class GaussianKernel : public Kernel<float>
{
public:
    GaussianKernel(float mean, float sigma);
    virtual ~GaussianKernel() = default;
};
